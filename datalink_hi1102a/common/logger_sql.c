

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include "logger_sql.h"

sqlite3 *logger_db;

static void logger_sql_open(void)
{
    int result;

    result = sqlite3_open("/mnt/fcs_log/LoggerLib.db",&logger_db);
    if (result == SQLITE_OK) {
        printf("open database success\n");
    } else {
        printf("open database failed\n");
    }
}

int logger_sql_close(void)
{
    int result;

    result = sqlite3_close(logger_db);
    if (result == SQLITE_OK) {
        printf("close database success\n");
    } else{
        printf("close database failed\n");
    }

    return result;
}

void logger_sql_init(void)
{
    // 删除原来的飞控日志，重新创建数据库
    if( 0 != access("/mnt/fcs_log/LoggerLib.db" ,F_OK) ){
        system("rm //mnt/fcs_log/*");
        usleep(1*1000);
    }

    logger_sql_open();
    logger_sql_create_table();
}

void logger_sql_create_table(void)
{
    int result;
    char *sql_item;
    char *sql_cmd;
    char *errmsg = NULL;

    sql_item = "FILEID INT NOT NULL,FILENAME TEXT NOT NULL,SIZE INT8 NOT NULL,DATE TEXT NOT NULL,DURATION INT NOT NULL,FIXTYPE INT NOT NULL);";
    sql_cmd = (char *)malloc(strlen(sql_item) + 60);
    sprintf(sql_cmd, "CREATE TABLE IF NOT EXISTS LOGGERLIB (%s", sql_item);
    // printf("%s cmd: %s\n", __func__, sql_cmd);

    result = sqlite3_exec(logger_db, sql_cmd, NULL, NULL, &errmsg);
    if (result == SQLITE_OK) {
        printf("create LOGGERLIB success\n");
    } else {
        printf("create LOGGERLIB failed:%s\n", errmsg);
    }

    if(sql_cmd != NULL){
        free(sql_cmd);
    }

    sqlite3_free(errmsg);
}

int logger_sql_get_file_count(void)
{
    int filecount;
    char *sql_cmd;
    sqlite3_stmt *stmt = NULL;

    filecount = 0;
    sql_cmd = "SELECT * FROM LOGGERLIB;";
    // printf("%s cmd: %s\n", __func__, sql_cmd);

    if (sqlite3_prepare_v2(logger_db, sql_cmd, -1, &stmt, NULL) == SQLITE_OK) {
        // 每调一次sqlite3_step()函数，stmt就会指向下一条记录      
        while(sqlite3_step(stmt) == SQLITE_ROW) {
            filecount += 1;
            printf("============ get file count[%d]\n",filecount);
        }
        
        sqlite3_finalize(stmt);
    } else {
        printf("sqlite3_prepare failed \n");
    }

    return filecount;
}

void logger_sql_insert_item(LOG_FILELIST_E *fileinfo)
{
    int result;
    char *sql_cmd;
    char *errmsg = NULL;

    //FILEID FILENAME SIZE FLIGHT_TIME FLIGHT_DURATION FIX_TYPE
    sql_cmd = (char *)malloc(512);

    sprintf(sql_cmd, "INSERT INTO LOGGERLIB VALUES(%d, '%s', %d, '%s', %d, %d);",
            fileinfo->fcs_index, fileinfo->filename,  \
            fileinfo->file_size, fileinfo->flight_time, \
            fileinfo->flight_duration, fileinfo->fix_type);
    // printf("%s cmd: %s\n",__func__,sql_cmd);

    result = sqlite3_exec(logger_db, sql_cmd, NULL, NULL, &errmsg);
    if (result == SQLITE_OK) {
        // printf("insert LoggerLib[%s] item success\n", fileinfo->filename);
    } else {
        printf("insert LoggerLib[%s] item failed:%s\n", fileinfo->filename, errmsg);
    }

    if(sql_cmd != NULL){
        free(sql_cmd);
    }
    
    sqlite3_free(errmsg);
}

void logger_sql_update_item(int type, LOG_FILELIST_E *fileinfo)
{
    int result;
    char *sql_cmd;
    char *errmsg = NULL;

    //FILEID FILENAME SIZE FLIGHT_TIME DURATION FIX_TYPE
    sql_cmd = (char *)malloc(512);

    switch (type)
    {
    case LOG_COL_DURATION:
        sprintf(sql_cmd, "UPDATE LOGGERLIB SET DURATION = %d WHERE FILEID = %d;",
                fileinfo->flight_duration, fileinfo->fcs_index);
        break;

    case LOG_COL_SIZE:
        sprintf(sql_cmd, "UPDATE LOGGERLIB SET SIZE = %d WHERE FILEID = %d;",
                fileinfo->file_size, fileinfo->fcs_index);
        break;

    case LOG_COL_FLIGHT_TIME:
        sprintf(sql_cmd, "UPDATE LOGGERLIB SET DATE = '%s' WHERE FILEID = %d;",
                fileinfo->flight_time, fileinfo->fcs_index);
        break;
    
    default:
        break;
    }
    // printf("%s cmd: %s\n",__func__,sql_cmd);

    result = sqlite3_exec(logger_db, sql_cmd, NULL, NULL, &errmsg);
    if (result == SQLITE_OK) {
        // printf("update LoggerLib item[%d] success\n", fileinfo->fcs_index);
    } else {
        printf("insert LoggerLib item[%d] failed:%s\n", fileinfo->fcs_index, errmsg);
    }

    if(sql_cmd != NULL){
        free(sql_cmd);
    }
    
    sqlite3_free(errmsg);
}

void logger_sql_get_item(int type, int file_id, LOG_FILELIST_E *fileinfo)
{
    int result;
    int itemcount;
    char sql_cmd[100];
    const unsigned char *filename;
    const unsigned char *flight_time;
    sqlite3_stmt *stmt = NULL;

    itemcount = 1;
    //FILEID FILENAME SIZE FLIGHT_TIME DURATION FIX_TYPE
    memset(sql_cmd, 0x00 ,sizeof(sql_cmd));
    switch (type)
    {
    case 0:
        sprintf(sql_cmd, "SELECT * FROM LOGGERLIB ORDER BY FILEID DESC LIMIT %d;", itemcount);
        break;

    case 1:
        sprintf(sql_cmd, "SELECT * FROM LOGGERLIB ORDER BY FILEID ASC LIMIT %d;", itemcount);
        break;

    case 2:
        sprintf(sql_cmd, "SELECT * FROM LOGGERLIB WHERE FILEID = %d;",file_id);
        break;

    default:
        break;
    }
    //printf("%s cmd: %s\n",__func__,sql_cmd);

    if (sqlite3_prepare_v2(logger_db, sql_cmd, -1, &stmt, NULL) == SQLITE_OK) {
        // 每调一次sqlite3_step()函数，stmt就会指向下一条记录
        while(sqlite3_step(stmt) == SQLITE_ROW) {
            //日志文件名
            memcpy(fileinfo->filename, sqlite3_column_text(stmt, 1), sizeof(fileinfo->filename));

            //飞行时间
            flight_time = sqlite3_column_text(stmt, 3);
            memcpy(fileinfo->flight_time, sqlite3_column_text(stmt, 3), sizeof(fileinfo->flight_time));

            fileinfo->fcs_index = sqlite3_column_int(stmt, 0);  
            fileinfo->file_size = sqlite3_column_int(stmt, 2);
            fileinfo->flight_duration = sqlite3_column_int(stmt, 4);
            fileinfo->fix_type = sqlite3_column_int(stmt, 5);
        }
        sqlite3_finalize(stmt);
    } else {
        printf("sqlite3_prepare failed \n");
    }
}

void logger_sql_delete_item(int file_id)
{
    int result;
    char *sql_cmd;
    char *errmsg = NULL;

    sql_cmd = (char *)malloc(60);
    sprintf(sql_cmd, "DELETE FROM LOGGERLIB WHERE FILEID = %d;", file_id);
    // printf("%s cmd: %s\n",__func__,sql_cmd);

    result = sqlite3_exec(logger_db, sql_cmd, NULL, NULL, &errmsg);
    if (result == SQLITE_OK) {
        // printf("delete LoggerLib[%d] item success\n", file_id);
    } else {
        printf("delete LoggerLib[%d] item failed:%s\n", file_id, errmsg);
    }

    if(sql_cmd != NULL){
        free(sql_cmd);
    }
    
    sqlite3_free(errmsg);
}

void logger_sql_deinit(void)
{
    sqlite3_close(logger_db);
}

