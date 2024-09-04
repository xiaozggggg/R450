
#ifndef __LOGGER_SQL_H__
#define __LOGGER_SQL_H__

#include <sqlite3/sqlite3.h>

#define SCLISE_MAXSIZE       	(6*1024)
#define FILE_MAXLENGTH       	(64)
#define PAKCET_BASE_LEN          10

typedef enum{
    LOG_COL_DURATION = 0,
    LOG_COL_SIZE,
    LOG_COL_FLIGHT_TIME
}LOG_FILE_LIST_E;

typedef struct {
    int  filecount;         //记录条数
    int  fcs_index;         //飞控日志最新的序号
    char filename[40];      //开始记录日志文件名
    int  file_size;         //文件大小
    char flight_time[40];   //起飞时间
    int  flight_duration;   //飞行时长
    int  fix_type;          //飞机是否定位
}LOG_FILELIST_E;

int  logger_sql_close(void);
void logger_sql_init(void);
void logger_sql_create_table(void);
int  logger_sql_get_file_count(void);
void logger_sql_insert_item(LOG_FILELIST_E *fileinfo);
void logger_sql_update_item(int type, LOG_FILELIST_E *fileinfo);
void logger_sql_get_item(int type, int file_id, LOG_FILELIST_E *fileinfo);
void logger_sql_delete_item(int file_id);
void logger_sql_deinit(void);
void logger_sql_get_timestampcollection_item(uint64_t starttimestamp, uint64_t endtimestamp, uint64_t *outtimestamp, int filetype);
void logger_sql_get_timestamp_fixcount(uint64_t endtimestamp, uint64_t *outtimestamp, uint16_t *outcount, int filetype);

#endif /*  */

