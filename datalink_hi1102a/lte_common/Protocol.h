#ifndef _PROTOCOLMACRODEF_H_
#define _PROTOCOLMACRODEF_H_


#define ONLINE_IP   "183.56.243.150"  //"fly.walkera.cn" // "app.walkera.cn"

// cmd channel
#define SERVER_CMDCHN_PORT  17591

// video channel1
#if SERVER_ONLINE

#endif

//////////////////////////////////////////////////////////////
#define UAVID_LENGTH   (15)
#define UAVID_FRAME_HEAD1           0xDF
#define UAVID_FRAME_HEAD2           0xDE
#define UAVID_FRAME_GET_FUNCBYTE    0x00  
#define UAVID_FRAME_SET_FUNCBYTE    0x01 

typedef enum{
    WK_FAILED  = -1,
    WK_SUCCESS = 0,
}WK_E;

typedef enum{
    WK_SELECT_MODE_READ   = 0,
    WK_SELECT_MODE_WRITE  = 1,
    WK_SELECT_MODE_EXECPT = 2,
} WK_SELECT_MODE_E;

typedef enum{
    WK_SELECT_STATUS_NONE    = -1,
    WK_SELECT_STATUS_ERROR   = 0,
    WK_SELECT_STATUS_TIMEOUT = 1,
    WK_SELECT_STATUS_READ    = 2,
    WK_SELECT_STATUS_WRITE   = 3,
    WK_SELECT_STATUS_EXECPT  = 4,
    WK_SELECT_STATUS_OTHER   = 5,
} WK_SELECT_STATUS_E;

typedef enum{
    WK_BLOCK_MODE_ENABLE  = 0,
    WK_BLOCK_MODE_DISABLE = 1,
} WK_BLOCK_MODE_E;

typedef enum{
    FRAME_RECEIVE_UNCOMPLETE = 0,
    FRAME_RECEIVE_COMPLETE   = 1,
}FRAME_RECEIVE_E;

// ------------------------------ mavlink ------------------------------
#define WK_MAVLINK_FRAME_MAXSIZE                    300

#define WK_MAVLINK_LOCAL_CMD_CHANNEL                0
#define WK_MAVLINK_LOCAL_DRONE_VIDEO_CHANNEL        1
#define WK_MAVLINK_LOCAL_INTERNAL_VIDEO_CHANNEL     2
#define WK_MAVLINK_LOCAL_EXTERNAL_VIDEO_CHANNEL     3

#define WK_MAVLINK_REMOTE_CMD_CHANNEL               4
#define WK_MAVLINK_REMOTE_DRONE_VIDEO_CHANNEL       5
#define WK_MAVLINK_REMOTE_INTERNAL_VIDEO_CHANNEL    6
#define WK_MAVLINK_REMOTE_EXTERNAL_VIDEO_CHANNEL    7

#define WK_MAVLINK_ROCKER_CHANNEL                   8
#define WK_MAVLINK_DRONE_CMD_CHANNEL                9

#define WK_MAVLINK_LOCAL_CMD1_CHANNEL               10
#define WK_MAVLINK_REMOTE_CMD1_CHANNEL              11


/////////////////////////////////////////////////////

typedef enum{
    CMD_TRANSMIT_DISABLE = 0,
    CMD_TRANSMIT_ENABLE = 1,
} CMD_TRANSMIT_E;

typedef enum{
    DATA_TRANSMIT_DISABLE = 0,
    DATA_TRANSMIT_ENABLE = 1,
} DATA_TRANSMIT_E;

typedef enum{
    SEND_UAV_STOP = 0,
    SEND_UAV_START = 1,
} SEND_UAV_STATUS_E;

#endif
