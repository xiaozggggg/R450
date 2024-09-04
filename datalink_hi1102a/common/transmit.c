/*
 * Copyright (C) 2021, Soren Friis
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Open Drone ID Linux transmitter example.
 *
 * Maintainer: Soren Friis
 * friissoren2@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <errno.h>
#include <sys/resource.h>
#include "bluetooth.h"
#include "sys_utils.h"

#define MINIMUM(a,b) (((a)<(b))?(a):(b))

#define BASIC_ID_POS_ZERO 0
#define BASIC_ID_POS_ONE 1
#define DRONE_ID_UPDATE  20

static struct config_data config = { 0 };
static int message_type = 0;
struct ODID_UAS_Data wkdrone_data;
int message_update;
uint8_t gps_numSV = 0;
uint8_t bt_init_flag = false;

void transmit_cleanup(void) {
    if (config.use_btl || config.use_bt4 || config.use_bt5){
        close_bluetooth(&config);
    }
    
    system("hciconfig hci0 down");
}

static void fill_example_data(struct ODID_UAS_Data *uasData) {
    uasData->BasicID[BASIC_ID_POS_ZERO].UAType = ODID_UATYPE_HELICOPTER_OR_MULTIROTOR;
    uasData->BasicID[BASIC_ID_POS_ZERO].IDType = ODID_IDTYPE_SERIAL_NUMBER;
    char uas_id[] = "WKAUCT010123456789A";
    strncpy(uasData->BasicID[BASIC_ID_POS_ZERO].UASID, uas_id,
            MINIMUM(sizeof(uas_id), sizeof(uasData->BasicID[BASIC_ID_POS_ZERO].UASID)));

    // uasData->BasicID[BASIC_ID_POS_ONE].UAType = ODID_UATYPE_HELICOPTER_OR_MULTIROTOR;
    // uasData->BasicID[BASIC_ID_POS_ONE].IDType = ODID_IDTYPE_SPECIFIC_SESSION_ID;
    // char uas_caa_id[] = "WKAUCT010123456789A"; //"FD3454B778E565C24B70";
    // strncpy(uasData->BasicID[BASIC_ID_POS_ONE].UASID, uas_caa_id,
    //         MINIMUM(sizeof(uas_caa_id), sizeof(uasData->BasicID[BASIC_ID_POS_ONE].UASID)));

    uasData->Auth[0].AuthType = ODID_AUTH_UAS_ID_SIGNATURE;
    uasData->Auth[0].DataPage = 0;
    uasData->Auth[0].LastPageIndex = 2;
    uasData->Auth[0].Length = 63;
    uasData->Auth[0].Timestamp = 28000000;
    char auth0_data[] = "12345678901234567";
    memcpy(uasData->Auth[0].AuthData, auth0_data,
           MINIMUM(sizeof(auth0_data), sizeof(uasData->Auth[0].AuthData)));

    // uasData->Auth[1].AuthType = ODID_AUTH_UAS_ID_SIGNATURE;
    // uasData->Auth[1].DataPage = 1;
    // char auth1_data[] = "12345678901234567890123";
    // memcpy(uasData->Auth[1].AuthData, auth1_data,
    //        MINIMUM(sizeof(auth1_data), sizeof(uasData->Auth[1].AuthData)));

    // uasData->Auth[2].AuthType = ODID_AUTH_UAS_ID_SIGNATURE;
    // uasData->Auth[2].DataPage = 2;
    // char auth2_data[] = "12345678901234567890123";
    // memcpy(uasData->Auth[2].AuthData, auth2_data,
    //        MINIMUM(sizeof(auth2_data), sizeof(uasData->Auth[2].AuthData)));

    uasData->SelfID.DescType = ODID_DESC_TYPE_TEXT;
    char description[] = "Drone ID";
    strncpy(uasData->SelfID.Desc, description,
            MINIMUM(sizeof(description), sizeof(uasData->SelfID.Desc)));

    uasData->System.OperatorLocationType = ODID_OPERATOR_LOCATION_TYPE_TAKEOFF;
    uasData->System.ClassificationType = ODID_CLASSIFICATION_TYPE_EU;
    // uasData->System.OperatorLatitude = uasData->Location.Latitude + 0.001;
    // uasData->System.OperatorLongitude = uasData->Location.Longitude - 0.001;
    uasData->System.AreaCount = 1;
    uasData->System.AreaRadius = 0;
    uasData->System.AreaCeiling = 0;
    uasData->System.AreaFloor = 0;
    uasData->System.CategoryEU = ODID_CATEGORY_EU_OPEN;
    uasData->System.ClassEU = ODID_CLASS_EU_CLASS_1;
    // uasData->System.OperatorAltitudeGeo = 20.5f;
    uasData->System.Timestamp = 28056789;

    uasData->OperatorID.OperatorIdType = ODID_OPERATOR_ID;
    char operatorId[] = "WKAU";
    strncpy(uasData->OperatorID.OperatorId, operatorId,
            MINIMUM(sizeof(operatorId), sizeof(uasData->OperatorID.OperatorId)));
}

static void fill_example_gps_data(struct ODID_UAS_Data *uasData) {
    uasData->Location.Status = ODID_STATUS_AIRBORNE;
    uasData->Location.Latitude = 22.873657;
    uasData->Location.Longitude = 113.455539;
    uasData->Location.HeightType = ODID_HEIGHT_REF_OVER_GROUND;
    uasData->Location.Height = 100;
    uasData->Location.TimeStamp = 360.52f;
}

static void send_message(union ODID_Message_encoded *encoded, struct config_data *config, uint8_t msg_counter) {
    if (config->use_btl)
        send_bluetooth_message(encoded, msg_counter, config);
    if (config->use_bt4 || config->use_bt5)
        send_bluetooth_message_extended_api(encoded, msg_counter, config);
    usleep(100*000);
}

// When using the WiFi Beacon transport method, the standards require that all messages are wrapped
// in a message pack and sent together. This single message send function is only for testing purposes.
static void send_single_messages(struct ODID_UAS_Data *uasData, struct config_data *config, int type) {
    union ODID_Message_encoded encoded;
    memset(&encoded, 0, sizeof(union ODID_Message_encoded));

    // printf("===== send message type[%d]\n", type);
    switch (type)
    {
    case 0:
        if (encodeBasicIDMessage((ODID_BasicID_encoded *) &encoded, &uasData->BasicID[BASIC_ID_POS_ZERO]) != ODID_SUCCESS)
            printf("Error: Failed to encode Basic ID\n");
        send_message(&encoded, config, config->msg_counters[ODID_MSG_COUNTER_BASIC_ID]++);
        break;

    case 1:
        if (encodeLocationMessage((ODID_Location_encoded *) &encoded, &uasData->Location) != ODID_SUCCESS)
            printf("Error: Failed to encode Location\n");
        send_message(&encoded, config, config->msg_counters[ODID_MSG_COUNTER_LOCATION]++);
        break;

    case 2:
        if (encodeAuthMessage((ODID_Auth_encoded *) &encoded, &uasData->Auth[0]) != ODID_SUCCESS)
            printf("Error: Failed to encode Auth 0\n");
        send_message(&encoded, config, config->msg_counters[ODID_MSG_COUNTER_AUTH]++);
        break;

    case 3:
        if (encodeSelfIDMessage((ODID_SelfID_encoded *) &encoded, &uasData->SelfID) != ODID_SUCCESS)
            printf("Error: Failed to encode Self ID\n");
        send_message(&encoded, config, config->msg_counters[ODID_MSG_COUNTER_SELF_ID]++);
        break;

    case 4:
        if (encodeSystemMessage((ODID_System_encoded *) &encoded, &uasData->System) != ODID_SUCCESS)
            printf("Error: Failed to encode System\n");
        send_message(&encoded, config, config->msg_counters[ODID_MSG_COUNTER_SYSTEM]++);
        break;

    case 5:
        if (encodeOperatorIDMessage((ODID_OperatorID_encoded *) &encoded, &uasData->OperatorID) != ODID_SUCCESS)
            printf("Error: Failed to encode Operator ID\n");
        send_message(&encoded, config, config->msg_counters[ODID_MSG_COUNTER_OPERATOR_ID]++);
        break;
    
    default:
        break;
    }
}

void transmitter_setGPSdata(int32_t lat, int32_t lon, int32_t height, uint8_t numSV)
{
    // float time_test = (float)timeStamp/1000000;

    // printf("========== lat[%d] lon[%d] height[%d] \n", lat, lon, height);
    // printf("========== lat[%f] lon[%f] height[%f] \n", (double)lat/10000000, (double)lon/10000000, (float)height/100.0f);

    gps_numSV = numSV;

    wkdrone_data.Location.Status = ODID_STATUS_AIRBORNE;
    wkdrone_data.Location.Latitude = (double)lat/10000000;
    wkdrone_data.Location.Longitude = (double)lon/10000000;
    wkdrone_data.Location.HeightType = ODID_HEIGHT_REF_OVER_GROUND;
    wkdrone_data.Location.Height = (float)height/100.0f;
    // wkdrone_data.Location.TimeStamp = time_test;
}

void transmitter_setSYSdata(char *droneid)
{
    char uas_id[20];

    if(++message_update >= DRONE_ID_UPDATE){
        message_update = 0;

        printf("======= transmitter_setSYSdata [%d] droneid[%s]\n", strlen(droneid), droneid);
        wkdrone_data.BasicID[BASIC_ID_POS_ZERO].UAType = ODID_UATYPE_HELICOPTER_OR_MULTIROTOR;
        wkdrone_data.BasicID[BASIC_ID_POS_ZERO].IDType = ODID_IDTYPE_SERIAL_NUMBER;

        memset(uas_id, 0x00, sizeof(uas_id));
        sprintf(uas_id, "%s", "WKAU");
        memcpy(uas_id+4, droneid, 16);

        strncpy(wkdrone_data.BasicID[BASIC_ID_POS_ZERO].UASID, uas_id,
            MINIMUM(sizeof(uas_id), sizeof(wkdrone_data.BasicID[BASIC_ID_POS_ZERO].UASID)));
    }
}

int transmitter_handle(void)
{
    if(gps_numSV > 14 && !bt_init_flag){ //GPS搜星完成，但蓝牙没启动则开启蓝牙
        bt_init_flag = true;
        system("hciconfig hci0 up");
        sleep(1);

        memset(&config, 0x00, sizeof(config));
        config.use_gps    = 0;
        config.use_btl    = true;
        config.use_bt4    = false;
        config.use_bt5    = false;
        config.handle_bt4 = 1; // The Extended Advertising set number used for BT4
        config.handle_bt5 = 0; // The Extended Advertising set number used for BT5

        if (config.use_btl || config.use_bt4 || config.use_bt5){
            init_bluetooth(&config);
            printf("====== init_bluetooth success \n");
        }

        message_type = 0;
        message_update = DRONE_ID_UPDATE-4;
        odid_initUasData(&wkdrone_data);
        fill_example_data(&wkdrone_data);
    }
    else if(gps_numSV > 14 && bt_init_flag){ //GPS搜星完成，蓝牙已启动则发送信息
        send_single_messages(&wkdrone_data, &config, message_type);

        if(++message_type >= 6){
            message_type = 0;
        }
    }
    else{ //GPS搜星未完成或蓝牙没开启
        printf("bt state[%d] and gps_sv[%d]\n", bt_init_flag, gps_numSV);
    }
}
