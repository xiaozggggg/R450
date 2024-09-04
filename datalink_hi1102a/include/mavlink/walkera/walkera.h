/** @file
 *  @brief MAVLink comm protocol generated from walkera.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_WALKERA_H
#define MAVLINK_WALKERA_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_WALKERA.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 4

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{0, 50, 9, 9, 0, 0, 0}, {1, 124, 31, 31, 0, 0, 0}, {2, 137, 12, 12, 0, 0, 0}, {4, 237, 14, 14, 3, 12, 13}, {5, 217, 28, 28, 1, 0, 0}, {6, 104, 3, 3, 0, 0, 0}, {7, 119, 32, 32, 0, 0, 0}, {8, 117, 36, 36, 0, 0, 0}, {11, 89, 6, 6, 1, 4, 0}, {20, 214, 20, 20, 3, 2, 3}, {21, 159, 2, 2, 3, 0, 1}, {22, 220, 25, 25, 0, 0, 0}, {23, 168, 23, 23, 3, 4, 5}, {24, 24, 30, 50, 0, 0, 0}, {25, 23, 101, 101, 0, 0, 0}, {26, 170, 22, 24, 0, 0, 0}, {27, 144, 26, 29, 0, 0, 0}, {28, 67, 16, 16, 0, 0, 0}, {29, 115, 14, 14, 0, 0, 0}, {30, 39, 28, 28, 0, 0, 0}, {31, 246, 32, 48, 0, 0, 0}, {32, 185, 28, 28, 0, 0, 0}, {33, 104, 28, 28, 0, 0, 0}, {34, 237, 22, 22, 0, 0, 0}, {35, 244, 22, 22, 0, 0, 0}, {36, 222, 21, 37, 0, 0, 0}, {37, 212, 6, 7, 3, 4, 5}, {38, 9, 6, 7, 3, 4, 5}, {39, 254, 37, 38, 3, 32, 33}, {40, 230, 4, 5, 3, 2, 3}, {41, 28, 4, 4, 3, 2, 3}, {42, 28, 2, 2, 0, 0, 0}, {43, 132, 2, 3, 3, 0, 1}, {44, 221, 4, 5, 3, 2, 3}, {45, 232, 2, 3, 3, 0, 1}, {46, 11, 2, 2, 0, 0, 0}, {47, 153, 3, 4, 3, 0, 1}, {48, 41, 13, 21, 1, 12, 0}, {49, 39, 12, 20, 0, 0, 0}, {50, 78, 37, 37, 3, 18, 19}, {51, 196, 4, 5, 3, 2, 3}, {52, 132, 7, 7, 0, 0, 0}, {54, 15, 27, 27, 3, 24, 25}, {55, 3, 25, 25, 0, 0, 0}, {61, 167, 72, 72, 0, 0, 0}, {62, 183, 26, 26, 0, 0, 0}, {63, 119, 181, 181, 0, 0, 0}, {64, 191, 225, 225, 0, 0, 0}, {65, 118, 42, 42, 0, 0, 0}, {66, 148, 6, 6, 3, 2, 3}, {67, 21, 4, 4, 0, 0, 0}, {69, 243, 11, 11, 1, 10, 0}, {70, 124, 18, 38, 3, 16, 17}, {73, 38, 37, 38, 3, 32, 33}, {74, 20, 20, 20, 0, 0, 0}, {75, 158, 35, 35, 3, 30, 31}, {76, 152, 33, 33, 3, 30, 31}, {77, 143, 3, 10, 3, 8, 9}, {81, 106, 22, 22, 0, 0, 0}, {82, 49, 39, 39, 3, 36, 37}, {83, 22, 37, 37, 0, 0, 0}, {84, 143, 53, 53, 3, 50, 51}, {85, 140, 51, 51, 0, 0, 0}, {86, 5, 53, 53, 3, 50, 51}, {87, 150, 51, 51, 0, 0, 0}, {89, 231, 28, 28, 0, 0, 0}, {90, 183, 56, 56, 0, 0, 0}, {91, 63, 42, 42, 0, 0, 0}, {92, 54, 33, 33, 0, 0, 0}, {93, 47, 81, 81, 0, 0, 0}, {100, 175, 26, 34, 0, 0, 0}, {101, 102, 32, 117, 0, 0, 0}, {102, 158, 32, 117, 0, 0, 0}, {103, 208, 20, 57, 0, 0, 0}, {104, 56, 32, 116, 0, 0, 0}, {105, 93, 62, 63, 0, 0, 0}, {106, 138, 44, 44, 0, 0, 0}, {107, 108, 64, 64, 0, 0, 0}, {108, 32, 84, 84, 0, 0, 0}, {109, 185, 9, 9, 0, 0, 0}, {110, 84, 254, 254, 3, 1, 2}, {111, 34, 16, 16, 0, 0, 0}, {112, 174, 12, 12, 0, 0, 0}, {113, 124, 36, 36, 0, 0, 0}, {114, 237, 44, 44, 0, 0, 0}, {115, 4, 64, 64, 0, 0, 0}, {116, 76, 22, 24, 0, 0, 0}, {117, 128, 6, 6, 3, 4, 5}, {118, 56, 14, 14, 0, 0, 0}, {119, 116, 12, 12, 3, 10, 11}, {120, 134, 97, 97, 0, 0, 0}, {121, 237, 2, 2, 3, 0, 1}, {122, 203, 2, 2, 3, 0, 1}, {123, 250, 113, 113, 3, 0, 1}, {124, 87, 35, 35, 0, 0, 0}, {125, 203, 6, 6, 0, 0, 0}, {126, 220, 79, 79, 0, 0, 0}, {127, 25, 35, 35, 0, 0, 0}, {128, 226, 35, 35, 0, 0, 0}, {129, 46, 22, 24, 0, 0, 0}, {130, 29, 13, 13, 0, 0, 0}, {131, 223, 255, 255, 0, 0, 0}, {132, 85, 14, 38, 0, 0, 0}, {133, 6, 18, 18, 0, 0, 0}, {134, 229, 43, 43, 0, 0, 0}, {135, 203, 8, 8, 0, 0, 0}, {136, 1, 22, 22, 0, 0, 0}, {137, 195, 14, 14, 0, 0, 0}, {138, 109, 36, 120, 0, 0, 0}, {139, 168, 43, 43, 3, 41, 42}, {140, 181, 41, 41, 0, 0, 0}, {141, 47, 32, 32, 0, 0, 0}, {142, 72, 243, 243, 0, 0, 0}, {143, 131, 14, 14, 0, 0, 0}, {144, 127, 93, 93, 0, 0, 0}, {146, 103, 100, 100, 0, 0, 0}, {147, 154, 36, 41, 0, 0, 0}, {148, 178, 60, 78, 0, 0, 0}, {149, 200, 30, 60, 0, 0, 0}, {162, 189, 8, 9, 0, 0, 0}, {230, 163, 42, 42, 0, 0, 0}, {231, 105, 40, 40, 0, 0, 0}, {232, 151, 63, 65, 0, 0, 0}, {233, 35, 182, 182, 0, 0, 0}, {234, 150, 40, 40, 0, 0, 0}, {235, 179, 42, 42, 0, 0, 0}, {241, 90, 32, 32, 0, 0, 0}, {242, 104, 52, 60, 0, 0, 0}, {243, 85, 53, 61, 1, 52, 0}, {244, 95, 6, 6, 0, 0, 0}, {245, 130, 2, 2, 0, 0, 0}, {246, 184, 38, 38, 0, 0, 0}, {247, 81, 19, 19, 0, 0, 0}, {248, 8, 254, 254, 3, 3, 4}, {249, 204, 36, 36, 0, 0, 0}, {250, 49, 30, 30, 0, 0, 0}, {251, 170, 18, 18, 0, 0, 0}, {252, 44, 18, 18, 0, 0, 0}, {253, 83, 51, 51, 0, 0, 0}, {254, 46, 9, 9, 0, 0, 0}, {256, 71, 42, 42, 3, 8, 9}, {257, 131, 9, 9, 0, 0, 0}, {258, 187, 32, 232, 3, 0, 1}, {259, 92, 235, 235, 0, 0, 0}, {260, 146, 5, 13, 0, 0, 0}, {261, 179, 27, 27, 0, 0, 0}, {262, 12, 18, 18, 0, 0, 0}, {263, 133, 255, 255, 0, 0, 0}, {264, 49, 28, 28, 0, 0, 0}, {265, 26, 16, 20, 0, 0, 0}, {266, 193, 255, 255, 3, 2, 3}, {267, 35, 255, 255, 3, 2, 3}, {268, 14, 4, 4, 3, 2, 3}, {269, 109, 213, 213, 0, 0, 0}, {270, 59, 19, 19, 0, 0, 0}, {299, 19, 96, 96, 0, 0, 0}, {300, 217, 22, 22, 0, 0, 0}, {301, 243, 58, 58, 0, 0, 0}, {310, 28, 17, 17, 0, 0, 0}, {311, 95, 116, 116, 0, 0, 0}, {320, 243, 20, 20, 3, 2, 3}, {321, 88, 2, 2, 3, 0, 1}, {322, 243, 149, 149, 0, 0, 0}, {323, 78, 147, 147, 3, 0, 1}, {324, 132, 146, 146, 0, 0, 0}, {330, 23, 158, 167, 0, 0, 0}, {331, 91, 230, 232, 0, 0, 0}, {332, 236, 239, 239, 0, 0, 0}, {333, 231, 109, 109, 0, 0, 0}, {334, 135, 14, 14, 0, 0, 0}, {335, 225, 24, 24, 0, 0, 0}, {340, 99, 70, 70, 0, 0, 0}, {350, 232, 20, 252, 0, 0, 0}, {360, 11, 25, 25, 0, 0, 0}, {365, 36, 255, 255, 0, 0, 0}, {370, 98, 73, 73, 0, 0, 0}, {371, 161, 50, 50, 0, 0, 0}, {375, 251, 140, 140, 0, 0, 0}, {380, 232, 20, 20, 0, 0, 0}, {385, 147, 133, 133, 3, 2, 3}, {390, 156, 238, 238, 0, 0, 0}, {395, 231, 222, 222, 0, 0, 0}, {400, 110, 254, 254, 3, 4, 5}, {401, 183, 6, 6, 3, 4, 5}, {8000, 248, 162, 162, 0, 0, 0}, {8001, 222, 12, 12, 0, 0, 0}, {8002, 223, 33, 33, 0, 0, 0}, {8003, 13, 38, 38, 0, 0, 0}, {8004, 9, 24, 24, 0, 0, 0}, {8005, 166, 21, 21, 0, 0, 0}, {8006, 66, 1, 1, 0, 0, 0}, {8007, 205, 121, 121, 0, 0, 0}, {8008, 235, 4, 4, 0, 0, 0}, {8009, 111, 34, 34, 0, 0, 0}, {8010, 166, 46, 46, 0, 0, 0}, {8011, 235, 6, 6, 0, 0, 0}, {8012, 220, 26, 26, 0, 0, 0}, {8013, 212, 10, 10, 0, 0, 0}, {8014, 1, 250, 250, 0, 0, 0}, {8015, 126, 7, 7, 0, 0, 0}, {8016, 94, 13, 13, 0, 0, 0}, {8017, 206, 6, 6, 0, 0, 0}, {8018, 52, 6, 6, 0, 0, 0}, {8020, 111, 17, 17, 0, 0, 0}, {8021, 39, 1, 1, 0, 0, 0}, {8022, 142, 16, 16, 0, 0, 0}, {8023, 185, 15, 15, 0, 0, 0}, {8024, 96, 3, 3, 0, 0, 0}, {8025, 203, 76, 76, 0, 0, 0}, {8026, 241, 243, 243, 0, 0, 0}, {8027, 103, 91, 91, 0, 0, 0}, {8028, 139, 27, 27, 0, 0, 0}, {8029, 79, 16, 16, 0, 0, 0}, {8030, 119, 34, 34, 0, 0, 0}, {8031, 217, 165, 166, 3, 32, 33}, {8032, 116, 10, 10, 0, 0, 0}, {8033, 252, 18, 18, 0, 0, 0}, {8034, 137, 10, 10, 0, 0, 0}, {8035, 19, 28, 28, 0, 0, 0}, {8036, 134, 184, 184, 0, 0, 0}, {8040, 175, 55, 55, 0, 0, 0}, {8041, 26, 41, 41, 0, 0, 0}, {8042, 30, 41, 41, 0, 0, 0}, {8043, 191, 6, 6, 0, 0, 0}, {8044, 47, 2, 2, 0, 0, 0}, {8045, 178, 34, 34, 0, 0, 0}, {8046, 57, 1, 1, 0, 0, 0}, {8047, 254, 7, 7, 0, 0, 0}, {8048, 237, 64, 64, 0, 0, 0}, {8049, 233, 5, 5, 0, 0, 0}, {8050, 241, 2, 2, 0, 0, 0}, {8051, 41, 2, 2, 0, 0, 0}, {8052, 154, 4, 4, 0, 0, 0}, {8053, 175, 4, 4, 0, 0, 0}, {8054, 218, 1, 1, 0, 0, 0}, {8055, 51, 1, 1, 0, 0, 0}, {8056, 225, 1, 1, 0, 0, 0}, {8057, 175, 4, 4, 0, 0, 0}, {8058, 190, 2, 2, 0, 0, 0}, {8059, 206, 16, 16, 0, 0, 0}, {8060, 104, 21, 21, 0, 0, 0}, {8061, 184, 31, 31, 0, 0, 0}, {8062, 156, 52, 52, 0, 0, 0}, {8063, 18, 33, 33, 0, 0, 0}, {8064, 166, 54, 54, 0, 0, 0}, {8065, 200, 8, 8, 0, 0, 0}, {8066, 210, 8, 8, 0, 0, 0}, {8067, 79, 4, 4, 0, 0, 0}, {8068, 162, 7, 7, 0, 0, 0}, {8069, 171, 10, 10, 0, 0, 0}, {8070, 5, 21, 21, 0, 0, 0}, {8071, 103, 13, 13, 0, 0, 0}, {8072, 57, 17, 17, 0, 0, 0}, {8073, 82, 20, 20, 0, 0, 0}, {8074, 124, 8, 8, 0, 0, 0}, {8075, 230, 15, 15, 0, 0, 0}, {8076, 128, 17, 17, 0, 0, 0}, {8077, 149, 17, 17, 0, 0, 0}, {8078, 151, 33, 33, 0, 0, 0}, {8079, 213, 33, 33, 0, 0, 0}, {8300, 166, 234, 234, 0, 0, 0}, {8301, 228, 30, 30, 0, 0, 0}, {8302, 42, 24, 24, 0, 0, 0}, {8304, 17, 207, 207, 0, 0, 0}, {8500, 145, 134, 134, 0, 0, 0}, {8501, 127, 72, 72, 0, 0, 0}, {8502, 122, 44, 44, 0, 0, 0}, {8503, 131, 84, 84, 0, 0, 0}, {8504, 114, 42, 42, 0, 0, 0}, {8505, 230, 24, 24, 0, 0, 0}, {8506, 149, 32, 32, 0, 0, 0}, {8507, 35, 44, 44, 0, 0, 0}, {8508, 206, 160, 160, 0, 0, 0}, {8509, 179, 10, 10, 0, 0, 0}, {8510, 231, 56, 56, 0, 0, 0}, {8511, 48, 36, 36, 0, 0, 0}, {8512, 48, 238, 238, 0, 0, 0}, {8513, 215, 2, 2, 0, 0, 0}, {8514, 87, 205, 205, 0, 0, 0}, {8515, 208, 29, 29, 0, 0, 0}, {8516, 80, 11, 11, 0, 0, 0}, {8517, 25, 2, 2, 0, 0, 0}, {8518, 20, 208, 208, 0, 0, 0}, {8519, 116, 13, 13, 0, 0, 0}, {8520, 199, 10, 10, 0, 0, 0}, {8521, 30, 10, 10, 0, 0, 0}, {8522, 251, 8, 8, 0, 0, 0}, {8523, 68, 1, 1, 0, 0, 0}, {9000, 113, 137, 137, 0, 0, 0}, {12900, 197, 22, 22, 0, 0, 0}, {12901, 16, 37, 37, 0, 0, 0}, {12902, 181, 31, 31, 0, 0, 0}, {12903, 149, 24, 24, 0, 0, 0}, {12904, 238, 21, 21, 0, 0, 0}, {12905, 56, 21, 21, 0, 0, 0}, {12915, 67, 252, 252, 0, 0, 0}}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_WALKERA

// ENUM DEFINITIONS


/** @brief  */
#ifndef HAVE_ENUM_WK_UPGRADE_RESULT
#define HAVE_ENUM_WK_UPGRADE_RESULT
typedef enum WK_UPGRADE_RESULT
{
   WK_UPGRADE_RESULT_OK=0, /*  | */
   WK_UPGRADE_RESULT_ERR_DISK=1, /*  | */
   WK_UPGRADE_RESULT_ERR_CRC32=2, /*  | */
   WK_UPGRADE_RESULT_ENUM_END=3, /*  | */
} WK_UPGRADE_RESULT;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WK_PARAM_ATTRIBUTE
#define HAVE_ENUM_WK_PARAM_ATTRIBUTE
typedef enum WK_PARAM_ATTRIBUTE
{
   WK_PARAM_ATTRIBUTE_RDWR=1, /*  | */
   WK_PARAM_ATTRIBUTE_RDONLY=2, /*  | */
   WK_PARAM_ATTRIBUE_NOT_COVERED=3, /*  | */
   WK_PARAM_ATTRIBUTE_ENUM_END=4, /*  | */
} WK_PARAM_ATTRIBUTE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WK_MOUNT_STATUS
#define HAVE_ENUM_WK_MOUNT_STATUS
typedef enum WK_MOUNT_STATUS
{
   WK_MOUNT_STATUS_OFF=0, /*  | */
   WK_MOUNT_STATUS_ON=1, /*  | */
   WK_MOUNT_STATUS_ENUM_END=2, /*  | */
} WK_MOUNT_STATUS;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WK_MOUNT_CTRL_CMD
#define HAVE_ENUM_WK_MOUNT_CTRL_CMD
typedef enum WK_MOUNT_CTRL_CMD
{
   WK_MOUNT_CTRL_CMD_JETTISON_A=1, /*  | */
   WK_MOUNT_CTRL_CMD_JETTISON_B=2, /*  | */
   WK_MOUNT_CTRL_CMD_JETTISON_C=3, /*  | */
   WK_MOUNT_CTRL_CMD_JETTISON_D=4, /*  | */
   WK_MOUNT_CTRL_CMD_FIRE_POT_1=5, /*  | */
   WK_MOUNT_CTRL_CMD_FIRE_POT_2=6, /*  | */
   WK_MOUNT_CTRL_CMD_FIRE_BULLET=7, /*  | */
   WK_MOUNT_CTRL_CMD_LASER_LIGHT=8, /*  | */
   WK_MOUNT_CTRL_CMD_SERVO=9, /*  | */
   WK_MOUNT_CTRL_CMD_LIGHT=10, /*  | */
   WK_MOUNT_CTRL_CMD_ENUM_END=11, /*  | */
} WK_MOUNT_CTRL_CMD;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WK_RC_CUSTOM_CMD
#define HAVE_ENUM_WK_RC_CUSTOM_CMD
typedef enum WK_RC_CUSTOM_CMD
{
   GIMBAL_FAST_CONTROL=1, /*  | */
   CRUISE_CONTROLS=2, /*  | */
   FPV_MODE=3, /*  | */
   WK_RC_CUSTOM_CMD_ENUM_END=4, /*  | */
} WK_RC_CUSTOM_CMD;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WKCAM_ISO_TYPE
#define HAVE_ENUM_WKCAM_ISO_TYPE
typedef enum WKCAM_ISO_TYPE
{
   WKCAM_ISO_TYPE_100=100, /*  | */
   WKCAM_ISO_TYPE_300=300, /*  | */
   WKCAM_ISO_TYPE_600=600, /*  | */
   WKCAM_ISO_TYPE_1300=1300, /*  | */
   WKCAM_ISO_TYPE_3200=3200, /*  | */
   WKCAM_ISO_TYPE_7000=7000, /*  | */
   WKCAM_ISO_TYPE_11000=11000, /*  | */
   WKCAM_ISO_TYPE_24000=24000, /*  | */
   WKCAM_ISO_TYPE_50000=50000, /*  | */
   WKCAM_ISO_TYPE_100000=100000, /*  | */
   WKCAM_ISO_TYPE_200000=200000, /*  | */
   WKCAM_ISO_TYPE_280000=280000, /*  | */
   WKCAM_ISO_TYPE_ENUM_END=280001, /*  | */
} WKCAM_ISO_TYPE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WKCAM_STREAM_RESOLUTION_FPS_TYPE
#define HAVE_ENUM_WKCAM_STREAM_RESOLUTION_FPS_TYPE
typedef enum WKCAM_STREAM_RESOLUTION_FPS_TYPE
{
   WKCAM_STREAM_RESOLUTION_FPS_TYPE_720P_25FPS=1, /* 720p@25fps | */
   WKCAM_STREAM_RESOLUTION_FPS_TYPE_720P_30FPS=2, /* 720p@30fps | */
   WKCAM_STREAM_RESOLUTION_FPS_TYPE_720P_60FPS=3, /* 720p@60fps | */
   WKCAM_STREAM_RESOLUTION_FPS_TYPE_1080P_25FPS=4, /* 1080p@25fps | */
   WKCAM_STREAM_RESOLUTION_FPS_TYPE_1080P_30FPS=5, /* 1080p@30fps | */
   WKCAM_STREAM_RESOLUTION_FPS_TYPE_1080P_60FPS=6, /* 1080p@60fps | */
   WKCAM_STREAM_RESOLUTION_FPS_TYPE_4K_25FPS=7, /* 4k@25fps | */
   WKCAM_STREAM_RESOLUTION_FPS_TYPE_4K_30FPS=8, /* 4k@30fps | */
   WKCAM_STREAM_RESOLUTION_FPS_TYPE_4K_60FPS=9, /* 4k@60fps | */
   WKCAM_STREAM_RESOLUTION_FPS_TYPE_6K_25FPS=10, /* 6k@25fps | */
   WKCAM_STREAM_RESOLUTION_FPS_TYPE_6K_30FPS=11, /* 6k@30fps | */
   WKCAM_STREAM_RESOLUTION_FPS_TYPE_6K_60FPS=12, /* 6k@60fps | */
   WKCAM_STREAM_RESOLUTION_FPS_TYPE_ENUM_END=13, /*  | */
} WKCAM_STREAM_RESOLUTION_FPS_TYPE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WKCAM_ENC_TYPE
#define HAVE_ENUM_WKCAM_ENC_TYPE
typedef enum WKCAM_ENC_TYPE
{
   WKCAM_ENC_TYPE_H264=1, /* H.264 encoding | */
   WKCAM_ENC_TYPE_H265=2, /* H.265 encoding | */
   WKCAM_ENC_TYPE_ENUM_END=3, /*  | */
} WKCAM_ENC_TYPE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WKCAM_CAPABILITY_FLAGS
#define HAVE_ENUM_WKCAM_CAPABILITY_FLAGS
typedef enum WKCAM_CAPABILITY_FLAGS
{
   WKCAM_CAP_FPS_4K_25_FPS=1, /* support 4k@25fps | */
   WKCAM_CAP_FPS_4K_30_FPS=2, /* support 4k@30fps | */
   WKCAM_CAP_FPS_6K_25_FPS=4, /* support 6k@25fps | */
   WKCAM_CAP_ZOOM_OPTICS=8, /* support optical zoom | */
   WKCAM_CAP_ZOOM_DIGITAL=16, /* support digital zoom | */
   WKCAM_CAP_ENC_H264=32, /* support H.264 encoding | */
   WKCAM_CAP_ENC_H265=64, /* support H.265 encoding | */
   WKCAM_CAPABILITY_FLAGS_ENUM_END=65, /*  | */
} WKCAM_CAPABILITY_FLAGS;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WKCAM_AWB_MODE
#define HAVE_ENUM_WKCAM_AWB_MODE
typedef enum WKCAM_AWB_MODE
{
   WKCAM_AWB_MODE_AUTO=0, /*  | */
   WKCAM_AWB_MODE_CANDELA=1, /*  | */
   WKCAM_AWB_MODE_TUNGSTEN=2, /*  | */
   WKCAM_AWB_MODE_FLUORESCENCE=3, /*  | */
   WKCAM_AWB_MODE_DAYLIGHT=4, /*  | */
   WKCAM_AWB_MODE_CLOUDY=5, /*  | */
   WKCAM_AWB_MODE_OVERCAST=6, /*  | */
   WKCAM_AWB_MODE_BLUESKY=7, /*  | */
   WKCAM_AWB_MODE_BUTT=8, /*  | */
   WKCAM_AWB_MODE_ENUM_END=9, /*  | */
} WKCAM_AWB_MODE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WKCAM_SDCARD_FILESYSTEM
#define HAVE_ENUM_WKCAM_SDCARD_FILESYSTEM
typedef enum WKCAM_SDCARD_FILESYSTEM
{
   WKCAM_SDCARD_FILESYSTEM_FAT32=0, /* FAT32 | */
   WKCAM_SDCARD_FILESYSTEM_EXFAT=1, /* exFAT | */
   WKCAM_SDCARD_FILESYSTEM_NTFS=2, /* NTFS | */
   WKCAM_SDCARD_FILESYSTEM_OTHER=3, /* other fs | */
   WKCAM_SDCARD_FILESYSTEM_ENUM_END=4, /*  | */
} WKCAM_SDCARD_FILESYSTEM;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WKCAM_SDCARD_FORMAT_ACK
#define HAVE_ENUM_WKCAM_SDCARD_FORMAT_ACK
typedef enum WKCAM_SDCARD_FORMAT_ACK
{
   WKCAM_SDCARD_FORMAT_ACK_SUCCESS=0, /* success | */
   WKCAM_SDCARD_FORMAT_ACK_FAIL_NO_CARD=1, /* falilure,no sdcard | */
   WKCAM_SDCARD_FORMAT_ACK_FAIL_OTHER_REASON=2, /* failure,other reasons | */
   WKCAM_SDCARD_FORMAT_ACK_ENUM_END=3, /*  | */
} WKCAM_SDCARD_FORMAT_ACK;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WKCAM_SDCARD_FORMAT_TYPE
#define HAVE_ENUM_WKCAM_SDCARD_FORMAT_TYPE
typedef enum WKCAM_SDCARD_FORMAT_TYPE
{
   WKCAM_SDCARD_FORMAT_TYPE_FAT32=0, /* fat32 | */
   WKCAM_SDCARD_FORMAT_TYPE_EXFAT=1, /* exfat | */
   WKCAM_SDCARD_FORMAT_TYPE_NTFS=2, /* ntfs | */
   WKCAM_SDCARD_FORMAT_TYPE_ENUM_END=3, /*  | */
} WKCAM_SDCARD_FORMAT_TYPE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WKCAM_SDCARD_STATUS
#define HAVE_ENUM_WKCAM_SDCARD_STATUS
typedef enum WKCAM_SDCARD_STATUS
{
   WKCAM_SDCARD_STATUS_NO_EXIST=0, /* sdcard no exist | */
   WKCAM_SDCARD_STATUS_MOUNT=1, /* sdcard exist and mount success | */
   WKCAM_SDCARD_STATUS_NO_MOUNT=2, /* sdcard exist and no mount | */
   WKCAM_SDCARD_STATUS_ENUM_END=3, /*  | */
} WKCAM_SDCARD_STATUS;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WKCAM_FOCUS_SET
#define HAVE_ENUM_WKCAM_FOCUS_SET
typedef enum WKCAM_FOCUS_SET
{
   WKCAM_FOCUS_SET_ADD=1, /* add | */
   WKCAM_FOCUS_SET_SUB=2, /* sub | */
   WKCAM_FOCUS_SET_STOP=3, /* stop | */
   WKCAM_FOCUS_SET_ZOOMLEVEL_NOP=4, /* WKCAM_FOCUS_SET_ADD and WKCAM_FOCUS_SET_SUB not operational,only WKCAM_FOCUS_SET_STOP | */
   WKCAM_FOCUS_SET_ENUM_END=5, /*  | */
} WKCAM_FOCUS_SET;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WKCAM_FOCUS_MODE
#define HAVE_ENUM_WKCAM_FOCUS_MODE
typedef enum WKCAM_FOCUS_MODE
{
   WKCAM_FOCUS_MODE_SET=0, /* set value | */
   WKCAM_FOCUS_MODE_SUB=1, /* focus - | */
   WKCAM_FOCUS_MODE_ADD=2, /* focus + | */
   WKCAM_FOCUS_MODE_ENUM_END=3, /*  | */
} WKCAM_FOCUS_MODE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WKCAM_EV_MODE
#define HAVE_ENUM_WKCAM_EV_MODE
typedef enum WKCAM_EV_MODE
{
   WKCAM_EV_MODE_AUTO=0, /* auto mode | */
   WKCAM_EV_MODE_MANUAL=1, /* manual mode | */
   WKCAM_EV_MODE_ENUM_END=2, /*  | */
} WKCAM_EV_MODE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WKCAM_TAKEPHOTO_ACK
#define HAVE_ENUM_WKCAM_TAKEPHOTO_ACK
typedef enum WKCAM_TAKEPHOTO_ACK
{
   WKCAM_TAKEPHOTO_ACK_SUCCESS=0, /* success | */
   WKCAM_TAKEPHOTO_ACK_FAIL_NO_SDCARD=1, /* falilure,no sdcard | */
   WKCAM_TAKEPHOTO_ACK_FAIL_SDCARD_FULL=2, /* failure,sdcard full | */
   WKCAM_TAKEPHOTO_ACK_FAIL_OTHER_REASON=3, /* failure,other reason | */
   WKCAM_TAKEPHOTO_ACK_NONE=255, /*  | */
   WKCAM_TAKEPHOTO_ACK_ENUM_END=256, /*  | */
} WKCAM_TAKEPHOTO_ACK;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WKCAM_VIDEOREC_ACK
#define HAVE_ENUM_WKCAM_VIDEOREC_ACK
typedef enum WKCAM_VIDEOREC_ACK
{
   WKCAM_VIDEO_ACK_SUCCESS=0, /* success | */
   WKCAM_VIDEO_ACK_FAIL_NO_SDCARD=1, /* falilure,no sdcard | */
   WKCAM_VIDEO_ACK_FAIL_SDCARD_FULL=2, /* failure,sdcard full | */
   WKCAM_VIDEO_ACK_FAIL_OTHER_REASON=3, /* failure,other reason | */
   WKCAM_VIDEO_ACK_STOP_SUCCESS=5, /*  | */
   WKCAM_VIDEO_ACK_STOP_FAIL=6, /*  | */
   WKCAM_VIDEO_ACK_NONE=255, /*  | */
   WKCAM_VIDEOREC_ACK_ENUM_END=256, /*  | */
} WKCAM_VIDEOREC_ACK;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WACAM_VIDEO_REC_CMD
#define HAVE_ENUM_WACAM_VIDEO_REC_CMD
typedef enum WACAM_VIDEO_REC_CMD
{
   WACAM_VIDEO_REC_CMD_NONE=0, /* none | */
   WACAM_VIDEO_REC_CMD_START=1, /* video start | */
   WACAM_VIDEO_REC_CMD_STOP=2, /* video stop  | */
   WACAM_VIDEO_REC_CMD_ENUM_END=3, /*  | */
} WACAM_VIDEO_REC_CMD;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WKCAM_CAP_ROTATION
#define HAVE_ENUM_WKCAM_CAP_ROTATION
typedef enum WKCAM_CAP_ROTATION
{
   WKCAM_CAP_ROTATION_4_3=1, /* 4:3 | */
   WKCAM_CAP_ROTATION_16_9=2, /* 16:9 | */
   WKCAM_CAP_ROTATION_ENUM_END=3, /*  | */
} WKCAM_CAP_ROTATION;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WKCAM_CAP_RESOLUTION
#define HAVE_ENUM_WKCAM_CAP_RESOLUTION
typedef enum WKCAM_CAP_RESOLUTION
{
   WKCAM_CAP_RESOLUTION_8M=1, /* 8M  --- 4096*2160 | */
   WKCAM_CAP_RESOLUTION_12M=2, /* 12M --- 4000*3000 | */
   WKCAM_CAP_RESOLUTION_16M=3, /* 16M --- 4658*3456 | */
   WKCAM_CAP_RESOLUTION_21M=4, /* 21M --- 5840*3648 | */
   WKCAM_CAP_RESOLUTION_32M=5, /* 32M --- 6680*4800 | */
   WKCAM_CAP_RESOLUTION_41M=6, /* 41M --- 7728*5368 | */
   WKCAM_CAP_RESOLUTION_ENUM_END=7, /*  | */
} WKCAM_CAP_RESOLUTION;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WKCAM_CAP_SAVE_FORMAT
#define HAVE_ENUM_WKCAM_CAP_SAVE_FORMAT
typedef enum WKCAM_CAP_SAVE_FORMAT
{
   WKCAM_CAP_SAVE_FORMAT_JPG=1, /* JPG | */
   WKCAM_CAP_SAVE_FORMAT_RAW=2, /* RAW | */
   WKCAM_CAP_SAVE_FORMAT_JPG_RAW=3, /* JPG/RAW | */
   WKCAM_CAP_SAVE_FORMAT_ENUM_END=4, /*  | */
} WKCAM_CAP_SAVE_FORMAT;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WKCAM_CAP_MODE
#define HAVE_ENUM_WKCAM_CAP_MODE
typedef enum WKCAM_CAP_MODE
{
   WKCAM_CAP_MODE_SINGLE=1, /* single | */
   WKCAM_CAP_MODE_CONTINE=2, /* continue | */
   WKCAM_CAP_MODE_TIME_TOKEN=3, /* time token | */
   WKCAM_CAP_MODE_TIME_DELAY=4, /* time delay | */
   WKCAM_CAP_MODE_PANORAMA=5, /* panorama | */
   WKCAM_CAP_MODE_ENUM_END=6, /*  | */
} WKCAM_CAP_MODE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WKCAM_CAMERA_CONTROL_TYPE
#define HAVE_ENUM_WKCAM_CAMERA_CONTROL_TYPE
typedef enum WKCAM_CAMERA_CONTROL_TYPE
{
   WKCAM_CAMERA_CONTROL_TYPE_CAPTURE=1, /* capture | */
   WKCAM_CAMERA_CONTROL_TYPE_RECORD_START=2, /* record start | */
   WKCAM_CAMERA_CONTROL_TYPE_RECORD_STOP=3, /* record stop | */
   WKCAM_CAMERA_CONTROL_TYPE_CAPTURE_CONTINUE=4, /* Capture continue | */
   WKCAM_CAMERA_CONTROL_TYPE_CAPTURE_TIME_TOKEN=5, /* time token | */
   WKCAM_CAMERA_CONTROL_TYPE_CAPTURE_TIME_LAPSE_START=6, /* time lapse start | */
   WKCAM_CAMERA_CONTROL_TYPE_CAPTURE_TIME_LAPSE_STOP=7, /* time lapse stop | */
   WKCAM_CAMERA_CONTROL_TYPE_PANORAMA_SHOT_START=8, /* time panorama shot box | */
   WKCAM_CAMERA_CONTROL_TYPE_PANORAMA_SHOT_STOP=9, /* time panorama stop | */
   WKCAM_CAMERA_CONTROL_TYPE_PANORAMA_INTURRUPT=10, /* time panorama inturrupt | */
   WKCAM_CAMERA_CONTROL_TYPE_ENUM_END=11, /*  | */
} WKCAM_CAMERA_CONTROL_TYPE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WK_TIME_LAPSE_MODE
#define HAVE_ENUM_WK_TIME_LAPSE_MODE
typedef enum WK_TIME_LAPSE_MODE
{
   WK_TIME_LAPSE_MODE_FREE=1, /* time lapse free | */
   WK_TIME_LAPSE_MODE_FIX_DIRECTION=2, /* time lapse fix direction | */
   WK_TIME_LAPSE_MODE_CIRCLE=3, /* time lapse circle | */
   WK_TIME_LAPSE_MODE_TRACK=4, /* time lapse track | */
   WK_TIME_LAPSE_MODE_ENUM_END=5, /*  | */
} WK_TIME_LAPSE_MODE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WK_PANORAMA_MODE
#define HAVE_ENUM_WK_PANORAMA_MODE
typedef enum WK_PANORAMA_MODE
{
   WK_PANORAMA_MODE_720=1, /* panorama box shot | */
   WK_PANORAMA_MODE_180=2, /* panorama 180бу shot | */
   WK_PANORAMA_MODE_WIDE_ANGLE=3, /* panorama wide angle shot | */
   WK_PANORAMA_MODE_VERTICAL=4, /* panorama vertical shot | */
   WK_PANORAMA_MODE_ENUM_END=5, /*  | */
} WK_PANORAMA_MODE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WKCAM_RECORD_RESOLUTION
#define HAVE_ENUM_WKCAM_RECORD_RESOLUTION
typedef enum WKCAM_RECORD_RESOLUTION
{
   WKCAM_RECORD_RESOLUTION_4K25=0, /* 3840*2160 25frame | */
   WKCAM_RECORD_RESOLUTION_4K30=1, /* 3840*2160 30frame | */
   WKCAM_RECORD_RESOLUTION_4K60=2, /* 3840*2160 30frame | */
   WKCAM_RECORD_RESOLUTION_6K25=3, /* 5480*3648 25frame | */
   WKCAM_RECORD_RESOLUTION_ENUM_END=4, /*  | */
} WKCAM_RECORD_RESOLUTION;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WKCAM_RECORD_BITRATE
#define HAVE_ENUM_WKCAM_RECORD_BITRATE
typedef enum WKCAM_RECORD_BITRATE
{
   WKCAM_RECORD_BITRATE_8M=0, /* 8M | */
   WKCAM_RECORD_BITRATE_16M=1, /* 16M | */
   WKCAM_RECORD_BITRATE_32M=2, /* 32M | */
   WKCAM_RECORD_BITRATE_64M=3, /* 64M | */
   WKCAM_RECORD_BITRATE_50M=4, /* 50M | */
   WKCAM_RECORD_BITRATE_100M=5, /* 100M | */
   WKCAM_RECORD_BITRATE_ENUM_END=6, /*  | */
} WKCAM_RECORD_BITRATE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WKCAM_PREVIEW_RESOLUTION
#define HAVE_ENUM_WKCAM_PREVIEW_RESOLUTION
typedef enum WKCAM_PREVIEW_RESOLUTION
{
   WKCAM_PREVIEW_RESOLUTION_1080P_30F=0, /* 1920*1080 30frame | */
   WKCAM_PREVIEW_RESOLUTION_720P_30F=1, /* 1280*720 30frame | */
   WKCAM_PREVIEW_RESOLUTION_ENUM_END=2, /*  | */
} WKCAM_PREVIEW_RESOLUTION;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WKCAM_PREVIEW_BITRATE
#define HAVE_ENUM_WKCAM_PREVIEW_BITRATE
typedef enum WKCAM_PREVIEW_BITRATE
{
   WKCAM_PREVIEW_BITRATE_1M=0, /* 1M | */
   WKCAM_PREVIEW_BITRATE_2M=1, /* 2M | */
   WKCAM_PREVIEW_BITRATE_4M=2, /* 4M | */
   WKCAM_PREVIEW_BITRATE_ENUM_END=3, /*  | */
} WKCAM_PREVIEW_BITRATE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WKCAM_SHUTTER
#define HAVE_ENUM_WKCAM_SHUTTER
typedef enum WKCAM_SHUTTER
{
   WKCAM_SHUTTER_1_10000=99, /* 1/10000 | */
   WKCAM_SHUTTER_1_5000=199, /* 1/5000 | */
   WKCAM_SHUTTER_1_3000=333, /* 1/3000 | */
   WKCAM_SHUTTER_1_2500=399, /* 1/2500 | */
   WKCAM_SHUTTER_1_2000=500, /* 1/2000 | */
   WKCAM_SHUTTER_1_1800=555, /* 1/1800 | */
   WKCAM_SHUTTER_1_1500=666, /* 1/1500 | */
   WKCAM_SHUTTER_1_1200=833, /* 1/1200 | */
   WKCAM_SHUTTER_1_1000=1000, /* 1/1000 | */
   WKCAM_SHUTTER_1_500=2000, /* 1/500 | */
   WKCAM_SHUTTER_1_250=4000, /* 1/250 | */
   WKCAM_SHUTTER_1_200=5000, /* 1/200 | */
   WKCAM_SHUTTER_1_125=8000, /* 1/125 | */
   WKCAM_SHUTTER_1_100=10000, /* 1/100 | */
   WKCAM_SHUTTER_1_50=20000, /* 1/50 | */
   WKCAM_SHUTTER_1_30=33333, /* 1/30 | */
   WKCAM_SHUTTER_1_25=40000, /* 1/25 | */
   WKCAM_SHUTTER_1_20=50000, /* 1/20 | */
   WKCAM_SHUTTER_1_15=66666, /* 1/15 | */
   WKCAM_SHUTTER_1_13=76923, /* 1/13 | */
   WKCAM_SHUTTER_1_10=100000, /* 1/10 | */
   WKCAM_SHUTTER_1_5=200000, /* 1/5 | */
   WKCAM_SHUTTER_1_2=500000, /* 1/2 | */
   WKCAM_SHUTTER_1=1000000, /* 1.0 | */
   WKCAM_SHUTTER_2=2000000, /* 2.0 | */
   WKCAM_SHUTTER_ENUM_END=2000001, /*  | */
} WKCAM_SHUTTER;
#endif

/** @brief  */
#ifndef HAVE_ENUM_SIM_CARD_STATUS
#define HAVE_ENUM_SIM_CARD_STATUS
typedef enum SIM_CARD_STATUS
{
   SIM_CARD_STATUS_READY=0, /*  | */
   SIM_CARD_STATUS_NO_EXIST=1, /*  | */
   SIM_CARD_STATUS_OTHER_REASON=2, /*  | */
   SIM_CARD_STATUS_ENUM_END=3, /*  | */
} SIM_CARD_STATUS;
#endif

/** @brief  */
#ifndef HAVE_ENUM_NETWORK_STATUS
#define HAVE_ENUM_NETWORK_STATUS
typedef enum NETWORK_STATUS
{
   NETWORK_STATUS_OFFLINE=0, /*  | */
   NETWORK_STATUS_ONLINE=1, /*  | */
   NETWORK_STATUS_ENUM_END=2, /*  | */
} NETWORK_STATUS;
#endif

/** @brief  */
#ifndef HAVE_ENUM_CAMERA_STATUS
#define HAVE_ENUM_CAMERA_STATUS
typedef enum CAMERA_STATUS
{
   CAMERA_STATUS_CONNECT_FAIL=0, /*  | */
   CAMERA_STATUS_READ_FAIL=1, /*  | */
   CAMERA_STATUS_READ_OK=2, /*  | */
   CAMERA_STATUS_ENUM_END=3, /*  | */
} CAMERA_STATUS;
#endif

/** @brief  */
#ifndef HAVE_ENUM_UART_STATUS
#define HAVE_ENUM_UART_STATUS
typedef enum UART_STATUS
{
   UART_STATUS_READ_FAIL=0, /*  | */
   UART_STATUS_READ_OK=1, /*  | */
   UART_STATUS_ENUM_END=2, /*  | */
} UART_STATUS;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WKCAM_SDCARD_FORMAT_STATUS
#define HAVE_ENUM_WKCAM_SDCARD_FORMAT_STATUS
typedef enum WKCAM_SDCARD_FORMAT_STATUS
{
   WKCAM_SDCARD_FORMAT_STATUS_NONE=0, /*  | */
   WKCAM_SDCARD_FORMAT_STATUS_ING=1, /*  | */
   WKCAM_SDCARD_FORMAT_STATUS_OK=2, /*  | */
   WKCAM_SDCARD_FORMAT_STATUS_FAIL=3, /*  | */
   WKCAM_SDCARD_FORMAT_STATUS_ENUM_END=4, /*  | */
} WKCAM_SDCARD_FORMAT_STATUS;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WKCAM_RECORD_STATUS
#define HAVE_ENUM_WKCAM_RECORD_STATUS
typedef enum WKCAM_RECORD_STATUS
{
   WKCAM_RECORD_STATUS_END=0, /*  | */
   WKCAM_RECORD_STATUS_ING=1, /*  | */
   WKCAM_RECORD_STATUS_ING_SDCARD_FULL=7, /*  | */
   WKCAM_RECORD_STATUS_ING_MP4FILE_TO_LARGE=8, /*  | */
   WKCAM_RECORD_STATUS_ENUM_END=9, /*  | */
} WKCAM_RECORD_STATUS;
#endif

/** @brief  */
#ifndef HAVE_ENUM_HSYK_CAM_PIP_MODE
#define HAVE_ENUM_HSYK_CAM_PIP_MODE
typedef enum HSYK_CAM_PIP_MODE
{
   HSYK_CAM_PIP_MODE_IR_PIP=0, /* IR PIP mode | */
   HSYK_CAM_PIP_MODE_IR_ONLY=1, /* IR Only | */
   HSYK_CAM_PIP_MODE_VISIBLE_ONLY=2, /* visible only | */
   HSYK_CAM_PIP_MODE_VISIBLE_PIP=3, /* visible pip mode | */
   HSYK_CAM_PIP_MODE_VISIBLE_PIP2=4, /* visibal pip2 mode | */
   HSYK_CAM_PIP_MODE_ENUM_END=5, /*  | */
} HSYK_CAM_PIP_MODE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_HSYK_CAM_PCOLOR_MODE
#define HAVE_ENUM_HSYK_CAM_PCOLOR_MODE
typedef enum HSYK_CAM_PCOLOR_MODE
{
   HSYK_CAM_PCOLOR_WHITE_HOT=0, /* white hot pcolor | */
   HSYK_CAM_PCOLOR_MAGMA=1, /* magma pcolor | */
   HSYK_CAM_PCOLOR_RED_IRON=2, /* red iron pcolor | */
   HSYK_CAM_PCOLOR_HOT_IRON=3, /* hot iron pcolor | */
   HSYK_CAM_PCOLOR_RAINBOW1=4, /* rainbow1 pcolor | */
   HSYK_CAM_PCOLOR_RAINBOW2=5, /* rainbow2 pcolor | */
   HSYK_CAM_PCOLOR_NORTHPOLE=6, /* northpole pcolor | */
   HSYK_CAM_PCOLOR_BLACK_HOT=7, /* black hot pcolor | */
   HSYK_CAM_PCOLOR_MODE_RED1=8, /* red pcolor | */
   HSYK_CAM_PCOLOR_MODE_RED2=9, /* red pcolor2 | */
   HSYK_CAM_PCOLOR_MODE_ENUM_END=10, /*  | */
} HSYK_CAM_PCOLOR_MODE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WK_CAMERA_MINI_DUAL_PIP_MODE
#define HAVE_ENUM_WK_CAMERA_MINI_DUAL_PIP_MODE
typedef enum WK_CAMERA_MINI_DUAL_PIP_MODE
{
   WK_CAMERA_MINI_DUAL_PIP_MODE_VL_SINGLE=0, /*  | */
   WK_CAMERA_MINI_DUAL_PIP_MODE_IR_SINGLE=1, /*  | */
   WK_CAMERA_MINI_DUAL_PIP_MODE_VL_LITTLE_LEFT=2, /*  | */
   WK_CAMERA_MINI_DUAL_PIP_MODE_IR_LITTLE_LEFT=3, /*  | */
   WK_CAMERA_MINI_DUAL_PIP_MODE_IR_PIP=4, /*  | */
   WK_CAMERA_MINI_DUAL_PIP_MODE_ENUM_END=5, /*  | */
} WK_CAMERA_MINI_DUAL_PIP_MODE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WK_CAMERA_MINI_DUAL_MEASURE_MODE
#define HAVE_ENUM_WK_CAMERA_MINI_DUAL_MEASURE_MODE
typedef enum WK_CAMERA_MINI_DUAL_MEASURE_MODE
{
   WK_CAMERA_MINI_DUAL_MEASURE_MODE_FULL=0, /*  | */
   WK_CAMERA_MINI_DUAL_MEASURE_MODE_AREA=1, /*  | */
   WK_CAMERA_MINI_DUAL_MEASURE_MODE_SINGLE=2, /*  | */
   WK_CAMERA_MINI_DUAL_MEASURE_MODE_ENUM_END=3, /*  | */
} WK_CAMERA_MINI_DUAL_MEASURE_MODE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WK_CMD_DIRECTION
#define HAVE_ENUM_WK_CMD_DIRECTION
typedef enum WK_CMD_DIRECTION
{
   WK_CMD_DIRECTION_GCS_MODULE=0, /*  | */
   WK_CMD_DIRECTION_MODULE_GCS=1, /*  | */
   WK_CMD_DIRECTION_ENUM_END=2, /*  | */
} WK_CMD_DIRECTION;
#endif

/** @brief walkera product type definitions */
#ifndef HAVE_ENUM_WK_PRODUCT_TYPE
#define HAVE_ENUM_WK_PRODUCT_TYPE
typedef enum WK_PRODUCT_TYPE
{
   WK_PRODUCT_TYPE_F420=1, /* F420  | */
   WK_PRODUCT_TYPE_R400=2, /* R400 | */
   WK_PRODUCT_TYPE_R500=3, /* R500 | */
   WK_PRODUCT_TYPE_R1000=4, /* R1000 | */
   WK_PRODUCT_TYPE_F210=5, /* F210 | */
   WK_PRODUCT_TYPE_WK1500=6, /* WK1500 | */
   WK_PRODUCT_TYPE_WK1800=7, /* WK1800 | */
   WK_PRODUCT_TYPE_WK1900=8, /* WK1900 | */
   WK_PRODUCT_TYPE_V1100PRO=9, /* V1100PRO | */
   WK_PRODUCT_TYPE_QL1600=10, /* QL1600 | */
   WK_PRODUCT_TYPE_QL1800=11, /* QL1800 | */
   WK_PRODUCT_TYPE_AG16=12, /* AG16 | */
   WK_PRODUCT_TYPE_AG18=13, /* AG18 | */
   WK_PRODUCT_TYPE_QL1800_ISREAL=14, /* QL1800 ISREAl | */
   WK_PRODUCT_TYPE_T210_MINI=15, /* T210 MINI | */
   WK_PRODUCT_TYPE_T210_MINI_SE=16, /* T210 MINI SE | */
   WK_PRODUCT_TYPE_T210_MINI_SE_V2=17, /* T210 MINI SE(V2) | */
   WK_PRODUCT_TYPE_T210_MINI_PRO=18, /* T210 MINI PRO | */
   WK_MODULE_TYPE_AC100_NEST_R500=19, /* WK AC100 NEST R500 | */
   WK_PRODUCT_TYPE_FCS_F8=20, /* WK FCS F8 | */
   WK_PRODUCT_TYPE_WK2000=21, /* WK WK2000 | */
   WK_PRODUCT_TYPE_QL2100=22, /* WK QL2100 | */
   WK_MODULE_TYPE_R450_FOLD=23, /* WK R450 FLOD | */
   WK_MODULE_TYPE_T210MINISE_3519=24, /* WK T210MINI SE 3519 | */
   WK_PRODUCT_TYPE_ENUM_END=25, /*  | */
} WK_PRODUCT_TYPE;
#endif

/** @brief walkera product sub-type definitions */
#ifndef HAVE_ENUM_WK_PRODUCT_SUB_TYPE
#define HAVE_ENUM_WK_PRODUCT_SUB_TYPE
typedef enum WK_PRODUCT_SUB_TYPE
{
   WK_PRODUCT_SUBTYPE_GENERAL=1, /* general version | */
   WK_PRODUCT_SUBTYPE_F210_WOFEI=3, /* wofei f210 | */
   WK_PRODUCT_SUBTYPE_F210_HI=4, /* hi3516 version | */
   WK_PRODUCT_SUBTYPE_V1100PRO_LOGISTICS=5, /* V1100PRO_LOGISTICS | */
   WK_PRODUCT_SUB_TYPE_ENUM_END=6, /*  | */
} WK_PRODUCT_SUB_TYPE;
#endif

/** @brief walkera fcs module type definitions */
#ifndef HAVE_ENUM_WK_MODULE_TYPE
#define HAVE_ENUM_WK_MODULE_TYPE
typedef enum WK_MODULE_TYPE
{
   WK_MODULE_TYPE_FCS=1, /* fly controller system | */
   WK_MODULE_TYPE_SLAVE_MCU=2, /* slave mcu of fly controller | */
   WK_MODULE_TYPE_WKV8_CONTROL=3, /* WKV8 control | */
   WK_MODULE_TYPE_WKV8_DISPLAY=4, /* WKV8 display | */
   WK_MODULE_TYPE_FCS_N32G=10, /* fly controller system based on N32G MCU | */
   WK_MODULE_TYPE_GIMBAL_F420_4K=100, /* walkera gimbal F420 4K | */
   WK_MODULE_TYPE_GIMBAL_F420_6K_25MM=101, /* walkera gimbal F420 6K(25MM) | */
   WK_MODULE_TYPE_GIMBAL_F420_6K_9MM=102, /* walkera gimbal F420  6K(9MM) | */
   WK_MODULE_TYPE_GIMBAL_F420_NIGHT=103, /* walkera gimbal F420 night | */
   WK_MODULE_TYPE_GIMBAL_R500_6K_25MM=104, /* walkera gimbal R500(25MM) | */
   WK_MODULE_TYPE_GIMBAL_R500_6K_9MM=105, /* walkera gimbal R500 6K(9MM) | */
   WK_MODULE_TYPE_GIMBAL_WKTN35=106, /* walkera gimbal WKTN35 | */
   WK_MODULE_TYPE_GIMBAL_WK30X=107, /* walkera gimbal WK30X | */
   WK_MODULE_TYPE_GIMBAL_WK30TIR=108, /* walkera gimbal WK30TIR | */
   WK_MODULE_TYPE_GIMBAL_R500_DUAL=109, /* walkera gimbal R500 Dual camera | */
   WK_MODULE_TYPE_GIMBAL_T210=110, /* walkera gimbal T210 | */
   WK_MODULE_TYPE_GIMBAL_T210_MINI=111, /* walkera gimbal T210 MINI | */
   WK_MODULE_TYPE_GIMBAL_T210_MINI_DUAL=112, /* walkera gimbal T210 MINI DUAL | */
   WK_MODULE_TYPE_GIMBAL_END=199, /* walkera gimbal END flag | */
   WK_MODULE_TYPE_CAMERA_F420_4K=200, /* walkera camera F420 4K | */
   WK_MODULE_TYPE_CAMERA_F420_6K_25MM=201, /* walkera camera F420 6K(25MM) | */
   WK_MODULE_TYPE_CAMERA_F420_6K_9MM=202, /* walkera camera F420  6K(9MM) | */
   WK_MODULE_TYPE_CAMERA_F420_NIGHT=203, /* walkera camera F420 night | */
   WK_MODULE_TYPE_CAMERA_R500_6K_25MM=204, /* walkera camera R500(25MM) | */
   WK_MODULE_TYPE_CAMERA_R500_6K_9MM=205, /* walkera camera R500 6K(9MM) | */
   WK_MODULE_TYPE_CAMERA_R400_4K=206, /* walkera camera R400 4K | */
   WK_MODULE_TYPE_CAMERA_WKTN35_NIGHT_VISION=207, /* walkera camera WKTN35 NIGHT VISION | */
   WK_MODULE_TYPE_CAMERA_WK30X_4K=208, /* walkera camera WK30X 4K | */
   WK_MODULE_TYPE_CAMERA_WK30TIR_DOUBLE_LIGHT=209, /* walkera camera WK30TIR DOUBLE LIGHT | */
   WK_MODULE_TYPE_CAMERA_F210_T40=210, /* walkera camera  F210 T40 | */
   WK_MODULE_TYPE_CAMERA_F320=211, /* walkera camera F320 4K | */
   WK_MODULE_TYPE_CAMERA_WK30TIR_HSYK=212, /* walkera camera WK30TIR(hsyk) | */
   WK_MODULE_TYPE_CAMERA_R500_6K_10P2MM=213, /* walkera camera R500 6K 10.2mm | */
   WK_MODULE_TYPE_CAMERA_R500_DUAL=214, /* walkera camera R500 DUAL | */
   WK_MODULE_TYPE_CAMERA_THREE_LIGHT=215, /* walkera camera three light | */
   WK_MODULE_TYPE_CAMERA_MINI_DUAL=216, /* walkera camera MINI DUAL | */
   WK_MODULE_TYPE_CAMERA_END=299, /* walkera camera END flag | */
   WK_MODULE_TYPE_NETWORK_R500_4G=300, /* R500_4G | */
   WK_MODULE_TYPE_NETWORK_R1000_5G=301, /* R1000_5G | */
   WK_MODULE_TYPE_NETWORK_R500_HB=302, /* R500_HB | */
   WK_MODULE_TYPE_NETWORK_R1000_HB=303, /* R1000_HB | */
   WK_MODULE_TYPE_NETWORK_END=399, /* walkera 4G 5G END flag | */
   WK_MODULE_TYPE_BMS_R1000_12S_13000MAH=400, /* R1000 BMS(13000mah) | */
   WK_MODULE_TYPE_BMS_V1100PRO_12S_13000MAH=401, /* V1100 BMS(13000mah) | */
   WK_MODULE_TYPE_BMS_T210_2200MAH=402, /* T210 BMS(2200mah) | */
   WK_MODULE_TYPE_BMS_T210_MINI_2200MAH=403, /* T210 MINI BMS(2200mah) | */
   WK_MODULE_TYPE_BMS_R400_6400MAH=404, /* R400 BMS(6400mah) | */
   WK_MODULE_TYPE_BMS_R500_6400MAH=405, /* R500 BMS(6400mah) | */
   WK_MODULE_TYPE_BMS_T210_MINI_2200MAH_V2=406, /* T210 MINI BMS V2(2200mah) | */
   WK_MODULE_TYPE_BMS_T210_MINI_2200MAH_V3=407, /* T210 MINI BMS V3(2200mah) | */
   WK_MODULE_TYPE_BMS_END=499, /* walkera bms END flag | */
   WK_MODULE_TYPE_RC_WKRC_H9=500, /* WKRC-H9 | */
   WK_MODULE_TYPE_RC_WKRC_H9_IMG_TRANSMISSION=501, /* WKRC-H9 Image Transmission | */
   WK_MODULE_TYPE_RC_P2=502, /* WKRC-P2 | */
   WK_MODULE_TYPE_RC_P2_IMG_TRANSMISSION=503, /* WKRC-P2 image transmission | */
   WK_MODULE_TYPE_RC_SMART_MOBILEPHINE_CONNECT=504, /* WKRC-P2 | */
   WK_MODULE_TYPE_RC_END=599, /* walkera RC type end | */
   WK_MODULE_TYPE_T210MINI_ESC_4IN=600, /* walkera T210MINI ESC 4IN transmission | */
   WK_MODULE_TYPE_ESC_END=699, /* walkera ESC type end | */
   WK_NEST_AC100_F427_DRIVE=700, /* walkera AC100 F407 drive | */
   WK_NEST_AC100_RPI=701, /* walkera AC100 RPI | */
   WK_NEST_AC100_END=799, /* walkera nest ac100 end | */
   WK_MODULE_TYPE_ENUM_END=800, /*  | */
} WK_MODULE_TYPE;
#endif

/** @brief walkera obstacle radar type */
#ifndef HAVE_ENUM_WK_OBSTACLE_AVOID_RADAR_TYPE
#define HAVE_ENUM_WK_OBSTACLE_AVOID_RADAR_TYPE
typedef enum WK_OBSTACLE_AVOID_RADAR_TYPE
{
   WK_OBSTACLE_RADAR_TYPE_FRONT=0, /* front obstacle avoidance type | */
   WK_OBSTACLE_RADAR_TYPE_360=1, /* 360-degrees obstacle avoidance type | */
   WK_OBSTACLE_RADAR_TYPE_MINI_PRO=2, /* mini pro obstacle avoidance type | */
   WK_OBSTACLE_AVOID_RADAR_TYPE_ENUM_END=3, /*  | */
} WK_OBSTACLE_AVOID_RADAR_TYPE;
#endif

/** @brief obstacle warning flag */
#ifndef HAVE_ENUM_WK_AVOID_WARNING_TYPE
#define HAVE_ENUM_WK_AVOID_WARNING_TYPE
typedef enum WK_AVOID_WARNING_TYPE
{
   WK_AVOID_WARNING_NONE=0, /*  | */
   WK_AVOID_WARNIG_SLOW_MODE=1, /*  | */
   WK_AVOID_WARNIG_FAST_MODE=2, /*  | */
   WK_AVOID_WARNIG_AMBIENT_LIGHT_HIDDEN=3, /*  | */
   WK_AVOID_WARNING_TYPE_ENUM_END=4, /*  | */
} WK_AVOID_WARNING_TYPE;
#endif

/** @brief warning position flag */
#ifndef HAVE_ENUM_WK_AVOID_WARNING_POSITION_TYPE
#define HAVE_ENUM_WK_AVOID_WARNING_POSITION_TYPE
typedef enum WK_AVOID_WARNING_POSITION_TYPE
{
   WK_AVOID_WARNING_POSITION_LEFT_FRONT=1, /*  | */
   WK_AVOID_WARNING_POSITION_MID_FRONT=2, /*  | */
   WK_AVOID_WARNING_POSITION_RIGHT_FRONT=3, /*  | */
   WK_AVOID_WARNING_POSITION_LEFT_BEHIND=4, /*  | */
   WK_AVOID_WARNING_POSITION_MID_BEHIND=5, /*  | */
   WK_AVOID_WARNING_POSITION_RIGHT_BEHIND=6, /*  | */
   WK_AVOID_WARNING_POSITION_BELOW=7, /*  | */
   WK_AVOID_WARNING_POSITION_TYPE_ENUM_END=8, /*  | */
} WK_AVOID_WARNING_POSITION_TYPE;
#endif

/** @brief mission_state */
#ifndef HAVE_ENUM_WK_MISSION_STATE
#define HAVE_ENUM_WK_MISSION_STATE
typedef enum WK_MISSION_STATE
{
   WK_MISSION_STATE_IDLE=0, /* mission idle state | */
   WK_MISSION_STATE_RUNNING=1, /* running state | */
   WK_MISSION_STATE_STOP=2, /* mission stop state | */
   WK_MISSION_STATE_COMPLETE=3, /* mission complete | */
   WK_MISSION_STATE_ENUM_END=4, /*  | */
} WK_MISSION_STATE;
#endif

/** @brief gyro calibrate state */
#ifndef HAVE_ENUM_WK_GYRO_CALIBRATE_STATE
#define HAVE_ENUM_WK_GYRO_CALIBRATE_STATE
typedef enum WK_GYRO_CALIBRATE_STATE
{
   WK_GYRO_CALIBRATE_IDLE=0, /* no start | */
   WK_GYRO_CALIBRATING=1, /* calibrating | */
   WK_GYRO_CALIBRATE_SUCCESS=2, /* calibrating | */
   WK_GYRO_CALIBRATE_FAILURE=3, /* running state | */
   WK_GYRO_CALIBRATE_TIMEOUT=4, /* calibrate timeout | */
   WK_GYRO_CALIBRATE_STATE_ENUM_END=5, /*  | */
} WK_GYRO_CALIBRATE_STATE;
#endif

/** @brief accel calibrate state */
#ifndef HAVE_ENUM_WK_ACCEL_CALIBRATE_STATE
#define HAVE_ENUM_WK_ACCEL_CALIBRATE_STATE
typedef enum WK_ACCEL_CALIBRATE_STATE
{
   WK_ACCEL_CALIBRATE_IDLE=0, /* no start | */
   WK_ACCEL_CALIBRATE_UP=1, /* calibrating up face | */
   WK_ACCEL_CALIBRATE_DOWN=2, /* calibrating down face | */
   WK_ACCEL_CALIBRATE_LEFT=3, /* calibrating left face | */
   WK_ACCEL_CALIBRATE_RIGHT=4, /* calibrating right face | */
   WK_ACCEL_CALIBRATE_FRONT=5, /* calibrating front face | */
   WK_ACCEL_CALIBRATE_BACK=6, /* calibrating back face | */
   WK_ACCEL_CALIBRATE_SUCCESS=7, /* calibrate successfully | */
   WK_ACCEL_CALIBRATE_FAILURE=8, /* calibrate failure | */
   WK_ACCEL_CALIBRATE_TIMEOUT=9, /* calibrate timeout | */
   WK_ACCEL_CALIBRATE_STATE_ENUM_END=10, /*  | */
} WK_ACCEL_CALIBRATE_STATE;
#endif

/** @brief compass calibrate state */
#ifndef HAVE_ENUM_WK_COMPASS_CALIBRATE_STATE
#define HAVE_ENUM_WK_COMPASS_CALIBRATE_STATE
typedef enum WK_COMPASS_CALIBRATE_STATE
{
   WK_COMPASS_CALIBRATE_IDLE=0, /* no start | */
   WK_COMPASS_CALIBRATE_VERTICAL=1, /* calibrating vertical | */
   WK_COMPASS_CALIBRATE_HORIZONTAL=2, /* calibrating horizontal | */
   WK_COMPASS_CALIBRATE_SUCCESS=3, /* calibrate successfully | */
   WK_COMPASS_CALIBRATE_FAILURE=4, /* calibrate failure | */
   WK_COMPASS_CALIBRATE_TIMEOUT=5, /* calibrate timeout | */
   WK_COMPASS_CALIBRATE_STATE_ENUM_END=6, /*  | */
} WK_COMPASS_CALIBRATE_STATE;
#endif

/** @brief gimbal calibrate state */
#ifndef HAVE_ENUM_WK_GIMBAL_CALIBRATE_STATE
#define HAVE_ENUM_WK_GIMBAL_CALIBRATE_STATE
typedef enum WK_GIMBAL_CALIBRATE_STATE
{
   WK_GIMBAL_CALIBRATE_IDLE=0, /* no start | */
   WK_GIMBAL_CALIBRATE_ROLL_PIT=1, /* calibrating roll and pitch | */
   WK_GIMBAL_CALIBRATE_YAW=2, /* calibrating yaw | */
   WK_GIMBAL_CALIBRATE_SUCCESS=3, /* calibrate successfully | */
   WK_GIMBAL_CALIBRATE_FAILURE=4, /* calibrate failure | */
   WK_GIMBAL_CALIBRATE_TIMEOUT=5, /* calibrate timeout | */
   WK_GIMBAL_CALIBRATE_STATE_ENUM_END=6, /*  | */
} WK_GIMBAL_CALIBRATE_STATE;
#endif

/** @brief RC control mode */
#ifndef HAVE_ENUM_WK_RC_CONTROL_MODE
#define HAVE_ENUM_WK_RC_CONTROL_MODE
typedef enum WK_RC_CONTROL_MODE
{
   WK_RC_CONTROL_MODE_AMERICA=0, /*  | */
   WK_RC_CONTROL_MODE_CHINA=1, /*  | */
   WK_RC_CONTROL_MODE_JEPAN=2, /*  | */
   WK_RC_CONTROL_MODE_ENUM_END=3, /*  | */
} WK_RC_CONTROL_MODE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_WK_TOF_CALI_TYPE
#define HAVE_ENUM_WK_TOF_CALI_TYPE
typedef enum WK_TOF_CALI_TYPE
{
   WK_MAG_CALIBRATE=1, /* panorama box shot | */
   WK_XTALK_CALIBRATE=2, /* panorama 180бу shot | */
   WK_DISTANCE_CALIBRATE=3, /* panorama wide angle shot | */
   WK_TEMP_CALIBRATE=4, /* panorama vertical shot | */
   WK_LIGTH_CALIBRATE=5, /* panorama box shot | */
   WK_TOF_CALI_TYPE_ENUM_END=6, /*  | */
} WK_TOF_CALI_TYPE;
#endif

/** @brief gnss svid enum */
#ifndef HAVE_ENUM_WK_GNSS_SVID_ENUM
#define HAVE_ENUM_WK_GNSS_SVID_ENUM
typedef enum WK_GNSS_SVID_ENUM
{
   WK_GNSS_SVID_GPS_G1=1, /* GPS system G1 | */
   WK_GNSS_SVID_GPS_G32=32, /* GPS system G32 | */
   WK_GNSS_SVID_BDS_B6=33, /* BALILEO System B6 | */
   WK_GNSS_SVID_BDS_B32=64, /* BALILEO System B32 | */
   WK_GNSS_SVID_GLONASS_R1=65, /* BALILEO System GLONASS R1 | */
   WK_GNSS_SVID_GLONASS_R32=96, /* BALILEO System GLONASS R32 | */
   WK_GNSS_SVID_SBAS_S120=120, /* SBAS system G32 | */
   WK_GNSS_SVKD_SBAS_S158=158, /* SBAS system S120 | */
   WK_GNSS_SVID_BDS_B1=159, /* BALILEO System E36 | */
   WK_GNSS_SVID_BDS_B5=163, /* BALILEO System B5 | */
   WK_GNSS_SVID_GALILEO_E1=211, /* GALILEO System S158 | */
   WK_GNSS_SVID_GALILEO_E36=246, /* BALILEO System E1 | */
   WK_GNSS_SVID_ENUM_ENUM_END=247, /*  | */
} WK_GNSS_SVID_ENUM;
#endif

/** @brief gnss sigid enum */
#ifndef HAVE_ENUM_WK_GNSS_SIGID_ENUM
#define HAVE_ENUM_WK_GNSS_SIGID_ENUM
typedef enum WK_GNSS_SIGID_ENUM
{
   WK_GNSS_SIGID_GPS_L1C_A=1, /* GPS L1C/A* | */
   WK_GNSS_SIGID_GPS_L2_CL=2, /* GPS L2 CL | */
   WK_GNSS_SIGID_GPS_L2_CM=3, /* GPS L2 CM | */
   WK_GNSS_SIGID_GALILEO_E1_C=4, /* Galileo E1 C* | */
   WK_GNSS_SIGID_GALILEO_E1_B=5, /* Galileo E1 B* | */
   WK_GNSS_SIGID_GALILEO_E5_bl=6, /* Galileo E5 bl | */
   WK_GNSS_SIGID_GALILEO_E5_bQ=7, /* Galileo E5 bQ | */
   WK_GNSS_SIGID_BEIDOU_B1l_D1=8, /* BeiDou B1l D1* | */
   WK_GNSS_SIGID_BEIDOU_B1l_D2=9, /* BeiDou B1l D2* | */
   WK_GNSS_SIGID_BEIDOU_B2l_D1=10, /* BeiDou B2l D1 | */
   WK_GNSS_SIGID_BEIDOU_B2l_D2=11, /* BeiDou B2l D2 | */
   WK_GNSS_SIGID_GLONASS_L1=12, /* GLONASS_L1 | */
   WK_GNSS_SIGID_GLONASS_L2=13, /* GLONASS L2 | */
   WK_GNSS_SIGID_ENUM_ENUM_END=14, /*  | */
} WK_GNSS_SIGID_ENUM;
#endif

/** @brief wkbms warning type */
#ifndef HAVE_ENUM_WK_BMS_WARNING_TYPE
#define HAVE_ENUM_WK_BMS_WARNING_TYPE
typedef enum WK_BMS_WARNING_TYPE
{
   WK_BMS_WARNING_TYPE_CELL_OVER_VOLT=1, /* cell over voltage warning | */
   WK_BMS_WARNING_TYPE_CELL_UNDER_VOLT=2, /* cell under voltage warning | */
   WK_BMS_WARNING_TYPE_OVER_VOLT=4, /* over voltage warning | */
   WK_BMS_WARNING_TYPE_UNDER_VOLT=8, /* under voltage warnig | */
   WK_BMS_WARNING_TYPE_OVER_TEMPERATURE=16, /* over temperature warning | */
   WK_BMS_WARNING_TYPE_AFE_COMM_ERR=32, /* bms analog-front-ene commuication err | */
   WK_BMS_WARNING_TYPE_BALANCING=64, /* bms balancing | */
   WK_BMS_WARNING_TYPE_SOC_CALIB=128, /* soc learn flag | */
   WK_BMS_WARNING_TYPE_CHARGER_DETECT=256, /* charger detect | */
   WK_BMS_WARNING_TYPE_LONGTIME_NO_SYNC=512, /* long time no sync | */
   WK_BMS_WARNING_TYPE_POWERUP_BY_KEY=1024, /* powerup by key | */
   WK_BMS_WARNING_TYPE_ENUM_END=1025, /*  | */
} WK_BMS_WARNING_TYPE;
#endif

/** @brief TACKING MODE TYPE */
#ifndef HAVE_ENUM_WK_TACKING_MODE_CMD
#define HAVE_ENUM_WK_TACKING_MODE_CMD
typedef enum WK_TACKING_MODE_CMD
{
   WK_TACKING_MODE_IDLE=0, /*  | */
   WK_TACKING_MODE_LOCK=1, /*  | */
   WK_TACKING_MODE_FOLLOW_TARGET=2, /*  | */
   WK_TACKING_MODE_FOLLOW_TARGET_SIDEWAYS=3, /*  | */
   WK_TACKING_MODE_END=4, /*  | */
   WK_TACKING_MODE_CMD_ENUM_END=5, /*  | */
} WK_TACKING_MODE_CMD;
#endif

/** @brief CALI CSV TYPE */
#ifndef HAVE_ENUM_WK_TOF_CALI_CSV_TYPE
#define HAVE_ENUM_WK_TOF_CALI_CSV_TYPE
typedef enum WK_TOF_CALI_CSV_TYPE
{
   WK_TOF_TEMP_CSV=0, /*  | */
   WK_TOF_LIGHT_CSV=1, /*  | */
   WK_TOF_CALI_CSV_TYPE_ENUM_END=2, /*  | */
} WK_TOF_CALI_CSV_TYPE;
#endif

/** @brief followme command types */
#ifndef HAVE_ENUM_WK_FOLLOWME_CMD_TYPE
#define HAVE_ENUM_WK_FOLLOWME_CMD_TYPE
typedef enum WK_FOLLOWME_CMD_TYPE
{
   WK_FOLLOWME_CMD_NONE=0, /* do nothing | */
   WK_FOLLOWME_CMD_AUTO_TAKEOFF=1, /* auto takeoff in followme mode | */
   WK_FOLLOWME_CMD_AUTO_LOCK=2, /* auto lock the beacon in followme mode | */
   WK_FOLLOWME_CMD_AUTO_RTL_AND_LAND=3, /* auto rtl and land in followme mode | */
   WK_FOLLOWME_CMD_TYPE_ENUM_END=4, /*  | */
} WK_FOLLOWME_CMD_TYPE;
#endif

/** @brief flight state enum types */
#ifndef HAVE_ENUM_WK_FLIGHT_STATE
#define HAVE_ENUM_WK_FLIGHT_STATE
typedef enum WK_FLIGHT_STATE
{
   WK_FLIGHT_STATE_IDLE=0, /*  | */
   WK_FLIGHT_STATE_DO_TAKEOFF=1, /*  | */
   WK_FLIGHT_STATE_TAKEOFF_COMPLETE=2, /*  | */
   WK_FLIGHT_STATE_LANDING=3, /*  | */
   WK_FLIGHT_STATE_LAND_COMPLETE=4, /*  | */
   WK_FLIGHT_STATE_FOLLOWME_LOCK=5, /*  | */
   WK_FLIGHT_STATE_FOLLOWME_RTL=6, /*  | */
   WK_FLIGHT_STATE_UNUSED=7, /*  | */
   WK_FLIGHT_STATE_RETURN_TO_LANUCH=8, /*  | */
   WK_FLIGHT_STATE_ENUM_END=9, /*  | */
} WK_FLIGHT_STATE;
#endif

/** @brief connect param direction */
#ifndef HAVE_ENUM_CONNECT_PARAM_DIRECTION_E
#define HAVE_ENUM_CONNECT_PARAM_DIRECTION_E
typedef enum CONNECT_PARAM_DIRECTION_E
{
   CONNECT_PARAM_DIRECTION_APP_5G=0, /* APP ---> 5G | */
   CONNECT_PARAM_DIRECTION_5G_APP=1, /* 5G ---> APP | */
   CONNECT_PARAM_DIRECTION_E_ENUM_END=2, /*  | */
} CONNECT_PARAM_DIRECTION_E;
#endif

/** @brief 4g 5g module connect param type */
#ifndef HAVE_ENUM_CONNECT_PARAM_TYPE_E
#define HAVE_ENUM_CONNECT_PARAM_TYPE_E
typedef enum CONNECT_PARAM_TYPE_E
{
   CONNECT_PARAM_TYPE_WK_TCP_TCP=0, /*  | */
   CONNECT_PARAM_TYPE_WK_TCP_RTMP=1, /*  | */
   CONNECT_PARAM_TYPE_WK_WEBSOCK_TCP=2, /*  | */
   CONNECT_PARAM_TYPE_WK_WEBSOCK_RTMP=3, /*  | */
   CONNECT_PARAM_TYPE_HC_TCP_RTMP=4, /*  | */
   CONNECT_PARAM_TYPE_APP_REQUEST_PARAM=255, /*  | */
   CONNECT_PARAM_TYPE_E_ENUM_END=256, /*  | */
} CONNECT_PARAM_TYPE_E;
#endif

// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_ntrip_config.h"
#include "./mavlink_msg_network_status.h"
#include "./mavlink_msg_wk_product_version.h"
#include "./mavlink_msg_wk_obstacle_avidance.h"
#include "./mavlink_msg_wk_mission_break_point.h"
#include "./mavlink_msg_wk_mission_state.h"
#include "./mavlink_msg_wk_flight_state.h"
#include "./mavlink_msg_wk_smart_battery_status.h"
#include "./mavlink_msg_wk_mount_status.h"
#include "./mavlink_msg_wk_module_set_serial_number.h"
#include "./mavlink_msg_wk_module_version.h"
#include "./mavlink_msg_wk_upgrade_request.h"
#include "./mavlink_msg_wk_upgrade_request_ack.h"
#include "./mavlink_msg_wk_upgrade_fw_info.h"
#include "./mavlink_msg_wk_upgrade_frag_request.h"
#include "./mavlink_msg_wk_upgrade_frag_data.h"
#include "./mavlink_msg_wk_upgrade_end_report.h"
#include "./mavlink_msg_wk_upgrade_end_ack.h"
#include "./mavlink_msg_wk_selfchk_state.h"
#include "./mavlink_msg_wk_target_posvel.h"
#include "./mavlink_msg_wk_followme_cmd.h"
#include "./mavlink_msg_wk_oilmass_state.h"
#include "./mavlink_msg_wk_rtk_beacon_state.h"
#include "./mavlink_msg_wk_heartbeat_ext.h"
#include "./mavlink_msg_wk_heartbeat_ext_new_rule.h"
#include "./mavlink_msg_wk_buoy_recgonize_state.h"
#include "./mavlink_msg_wk_gnss_signal_strength.h"
#include "./mavlink_msg_wk_rtk_beacon_inav_data.h"
#include "./mavlink_msg_wk_rtk_beacon_antenna_offset.h"
#include "./mavlink_msg_wk_param_value.h"
#include "./mavlink_msg_mission_item_int_ext.h"
#include "./mavlink_msg_wk_camera_state.h"
#include "./mavlink_msg_wk_camera_capture_state.h"
#include "./mavlink_msg_wk_camera_time_lapse_state.h"
#include "./mavlink_msg_wk_camera_hardware_params.h"
#include "./mavlink_msg_wk_camera_takephoto_record_info.h"
#include "./mavlink_msg_wk_camera_params_rpt.h"
#include "./mavlink_msg_wk_camera_cmd_common_params.h"
#include "./mavlink_msg_wk_camera_cmd_takephoto.h"
#include "./mavlink_msg_wk_camera_cmd_video_rec.h"
#include "./mavlink_msg_wk_camera_cmd_sdcard_format.h"
#include "./mavlink_msg_wk_camera_status_report.h"
#include "./mavlink_msg_wk_camera_cmd_focus.h"
#include "./mavlink_msg_wk_camera_cmd_utc_time_sync.h"
#include "./mavlink_msg_wk_camera_cmd_create_folder.h"
#include "./mavlink_msg_wk_camera_cmd_cap_param.h"
#include "./mavlink_msg_wk_camera_cmd_preview_param.h"
#include "./mavlink_msg_wk_camera_cmd_record_param.h"
#include "./mavlink_msg_wk_camera_cmd_iso.h"
#include "./mavlink_msg_wk_camera_cmd_shutter.h"
#include "./mavlink_msg_wk_camera_cmd_ev_mode.h"
#include "./mavlink_msg_wk_camera_cmd_ev_value.h"
#include "./mavlink_msg_wk_camera_cmd_awb_mode.h"
#include "./mavlink_msg_wk_camera_cmd_csc.h"
#include "./mavlink_msg_wk_camera_cmd_hsyk_dualcam_params.h"
#include "./mavlink_msg_wk_camera_qrcode_pos.h"
#include "./mavlink_msg_wk_5ginfo_status.h"
#include "./mavlink_msg_wk_product_id.h"
#include "./mavlink_msg_wk_product_bound.h"
#include "./mavlink_msg_wk_product_lock.h"
#include "./mavlink_msg_wk_product_active.h"
#include "./mavlink_msg_wk_test.h"
#include "./mavlink_msg_wk_camera_cmd_camera_control.h"
#include "./mavlink_msg_wk_time_lapse_dire_param.h"
#include "./mavlink_msg_wk_time_lapse_dire_param_ack.h"
#include "./mavlink_msg_wk_camera_cmd_focus2.h"
#include "./mavlink_msg_wk_camera_mini_dual_parameter.h"
#include "./mavlink_msg_wk_camera_mini_dual_measure_mode.h"
#include "./mavlink_msg_wk_camera_mini_dual_state.h"
#include "./mavlink_msg_wk_scout_state.h"
#include "./mavlink_msg_wk_rc_parameter.h"
#include "./mavlink_msg_wk_engine_control_state.h"
#include "./mavlink_msg_wk_camera_cmd_utc_time_sync1.h"
#include "./mavlink_msg_wk_camera_focusing.h"
#include "./mavlink_msg_wk_camera_laser_ranging.h"
#include "./mavlink_msg_wk_camera_laser_ranging_state.h"
#include "./mavlink_msg_wk_set_connect_param.h"
#include "./mavlink_msg_wk_set_ai_tracking_cmd.h"
#include "./mavlink_msg_wk_set_vr_param.h"
#include "./mavlink_msg_wk_mini_4g_authentication.h"
#include "./mavlink_msg_wk_log_flight_state.h"
#include "./mavlink_msg_wk_log_gnss.h"
#include "./mavlink_msg_wk_log_gps_raw.h"
#include "./mavlink_msg_wk_log_rtk_raw.h"
#include "./mavlink_msg_wk_log_beacon.h"
#include "./mavlink_msg_wk_log_mission.h"
#include "./mavlink_msg_wk_log_motors.h"
#include "./mavlink_msg_wk_log_rcin.h"
#include "./mavlink_msg_wk_log_sensor_raw.h"
#include "./mavlink_msg_wk_log_mode.h"
#include "./mavlink_msg_wk_log_pos_ctrl.h"
#include "./mavlink_msg_wk_log_image_geo.h"
#include "./mavlink_msg_wk_log_text.h"
#include "./mavlink_msg_wk_log_params_request.h"
#include "./mavlink_msg_wk_log_params_data.h"
#include "./mavlink_msg_wk_20t_ranging_param.h"
#include "./mavlink_msg_wk_assist_function_state.h"
#include "./mavlink_msg_wk_rc_customize.h"
#include "./mavlink_msg_wk_log_ultrasonic_raw_data.h"
#include "./mavlink_msg_wk_r500_nest_landing_state.h"
#include "./mavlink_msg_wk_tof_cali_state.h"
#include "./mavlink_msg_wk_tof_csv_data.h"
#include "./mavlink_msg_wk_tof_cali_value.h"
#include "./mavlink_msg_wk_tof_cali_data_request.h"

// base include
#include "../common/common.h"

#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 4

#if MAVLINK_THIS_XML_IDX == MAVLINK_PRIMARY_XML_IDX
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_HEARTBEAT, MAVLINK_MESSAGE_INFO_SYS_STATUS, MAVLINK_MESSAGE_INFO_SYSTEM_TIME, MAVLINK_MESSAGE_INFO_PING, MAVLINK_MESSAGE_INFO_CHANGE_OPERATOR_CONTROL, MAVLINK_MESSAGE_INFO_CHANGE_OPERATOR_CONTROL_ACK, MAVLINK_MESSAGE_INFO_AUTH_KEY, MAVLINK_MESSAGE_INFO_LINK_NODE_STATUS, MAVLINK_MESSAGE_INFO_SET_MODE, MAVLINK_MESSAGE_INFO_PARAM_REQUEST_READ, MAVLINK_MESSAGE_INFO_PARAM_REQUEST_LIST, MAVLINK_MESSAGE_INFO_PARAM_VALUE, MAVLINK_MESSAGE_INFO_PARAM_SET, MAVLINK_MESSAGE_INFO_GPS_RAW_INT, MAVLINK_MESSAGE_INFO_GPS_STATUS, MAVLINK_MESSAGE_INFO_SCALED_IMU, MAVLINK_MESSAGE_INFO_RAW_IMU, MAVLINK_MESSAGE_INFO_RAW_PRESSURE, MAVLINK_MESSAGE_INFO_SCALED_PRESSURE, MAVLINK_MESSAGE_INFO_ATTITUDE, MAVLINK_MESSAGE_INFO_ATTITUDE_QUATERNION, MAVLINK_MESSAGE_INFO_LOCAL_POSITION_NED, MAVLINK_MESSAGE_INFO_GLOBAL_POSITION_INT, MAVLINK_MESSAGE_INFO_RC_CHANNELS_SCALED, MAVLINK_MESSAGE_INFO_RC_CHANNELS_RAW, MAVLINK_MESSAGE_INFO_SERVO_OUTPUT_RAW, MAVLINK_MESSAGE_INFO_MISSION_REQUEST_PARTIAL_LIST, MAVLINK_MESSAGE_INFO_MISSION_WRITE_PARTIAL_LIST, MAVLINK_MESSAGE_INFO_MISSION_ITEM, MAVLINK_MESSAGE_INFO_MISSION_REQUEST, MAVLINK_MESSAGE_INFO_MISSION_SET_CURRENT, MAVLINK_MESSAGE_INFO_MISSION_CURRENT, MAVLINK_MESSAGE_INFO_MISSION_REQUEST_LIST, MAVLINK_MESSAGE_INFO_MISSION_COUNT, MAVLINK_MESSAGE_INFO_MISSION_CLEAR_ALL, MAVLINK_MESSAGE_INFO_MISSION_ITEM_REACHED, MAVLINK_MESSAGE_INFO_MISSION_ACK, MAVLINK_MESSAGE_INFO_SET_GPS_GLOBAL_ORIGIN, MAVLINK_MESSAGE_INFO_GPS_GLOBAL_ORIGIN, MAVLINK_MESSAGE_INFO_PARAM_MAP_RC, MAVLINK_MESSAGE_INFO_MISSION_REQUEST_INT, MAVLINK_MESSAGE_INFO_MISSION_CHANGED, MAVLINK_MESSAGE_INFO_SAFETY_SET_ALLOWED_AREA, MAVLINK_MESSAGE_INFO_SAFETY_ALLOWED_AREA, MAVLINK_MESSAGE_INFO_ATTITUDE_QUATERNION_COV, MAVLINK_MESSAGE_INFO_NAV_CONTROLLER_OUTPUT, MAVLINK_MESSAGE_INFO_GLOBAL_POSITION_INT_COV, MAVLINK_MESSAGE_INFO_LOCAL_POSITION_NED_COV, MAVLINK_MESSAGE_INFO_RC_CHANNELS, MAVLINK_MESSAGE_INFO_REQUEST_DATA_STREAM, MAVLINK_MESSAGE_INFO_DATA_STREAM, MAVLINK_MESSAGE_INFO_MANUAL_CONTROL, MAVLINK_MESSAGE_INFO_RC_CHANNELS_OVERRIDE, MAVLINK_MESSAGE_INFO_MISSION_ITEM_INT, MAVLINK_MESSAGE_INFO_VFR_HUD, MAVLINK_MESSAGE_INFO_COMMAND_INT, MAVLINK_MESSAGE_INFO_COMMAND_LONG, MAVLINK_MESSAGE_INFO_COMMAND_ACK, MAVLINK_MESSAGE_INFO_MANUAL_SETPOINT, MAVLINK_MESSAGE_INFO_SET_ATTITUDE_TARGET, MAVLINK_MESSAGE_INFO_ATTITUDE_TARGET, MAVLINK_MESSAGE_INFO_SET_POSITION_TARGET_LOCAL_NED, MAVLINK_MESSAGE_INFO_POSITION_TARGET_LOCAL_NED, MAVLINK_MESSAGE_INFO_SET_POSITION_TARGET_GLOBAL_INT, MAVLINK_MESSAGE_INFO_POSITION_TARGET_GLOBAL_INT, MAVLINK_MESSAGE_INFO_LOCAL_POSITION_NED_SYSTEM_GLOBAL_OFFSET, MAVLINK_MESSAGE_INFO_HIL_STATE, MAVLINK_MESSAGE_INFO_HIL_CONTROLS, MAVLINK_MESSAGE_INFO_HIL_RC_INPUTS_RAW, MAVLINK_MESSAGE_INFO_HIL_ACTUATOR_CONTROLS, MAVLINK_MESSAGE_INFO_OPTICAL_FLOW, MAVLINK_MESSAGE_INFO_GLOBAL_VISION_POSITION_ESTIMATE, MAVLINK_MESSAGE_INFO_VISION_POSITION_ESTIMATE, MAVLINK_MESSAGE_INFO_VISION_SPEED_ESTIMATE, MAVLINK_MESSAGE_INFO_VICON_POSITION_ESTIMATE, MAVLINK_MESSAGE_INFO_HIGHRES_IMU, MAVLINK_MESSAGE_INFO_OPTICAL_FLOW_RAD, MAVLINK_MESSAGE_INFO_HIL_SENSOR, MAVLINK_MESSAGE_INFO_SIM_STATE, MAVLINK_MESSAGE_INFO_RADIO_STATUS, MAVLINK_MESSAGE_INFO_FILE_TRANSFER_PROTOCOL, MAVLINK_MESSAGE_INFO_TIMESYNC, MAVLINK_MESSAGE_INFO_CAMERA_TRIGGER, MAVLINK_MESSAGE_INFO_HIL_GPS, MAVLINK_MESSAGE_INFO_HIL_OPTICAL_FLOW, MAVLINK_MESSAGE_INFO_HIL_STATE_QUATERNION, MAVLINK_MESSAGE_INFO_SCALED_IMU2, MAVLINK_MESSAGE_INFO_LOG_REQUEST_LIST, MAVLINK_MESSAGE_INFO_LOG_ENTRY, MAVLINK_MESSAGE_INFO_LOG_REQUEST_DATA, MAVLINK_MESSAGE_INFO_LOG_DATA, MAVLINK_MESSAGE_INFO_LOG_ERASE, MAVLINK_MESSAGE_INFO_LOG_REQUEST_END, MAVLINK_MESSAGE_INFO_GPS_INJECT_DATA, MAVLINK_MESSAGE_INFO_GPS2_RAW, MAVLINK_MESSAGE_INFO_POWER_STATUS, MAVLINK_MESSAGE_INFO_SERIAL_CONTROL, MAVLINK_MESSAGE_INFO_GPS_RTK, MAVLINK_MESSAGE_INFO_GPS2_RTK, MAVLINK_MESSAGE_INFO_SCALED_IMU3, MAVLINK_MESSAGE_INFO_DATA_TRANSMISSION_HANDSHAKE, MAVLINK_MESSAGE_INFO_ENCAPSULATED_DATA, MAVLINK_MESSAGE_INFO_DISTANCE_SENSOR, MAVLINK_MESSAGE_INFO_TERRAIN_REQUEST, MAVLINK_MESSAGE_INFO_TERRAIN_DATA, MAVLINK_MESSAGE_INFO_TERRAIN_CHECK, MAVLINK_MESSAGE_INFO_TERRAIN_REPORT, MAVLINK_MESSAGE_INFO_SCALED_PRESSURE2, MAVLINK_MESSAGE_INFO_ATT_POS_MOCAP, MAVLINK_MESSAGE_INFO_SET_ACTUATOR_CONTROL_TARGET, MAVLINK_MESSAGE_INFO_ACTUATOR_CONTROL_TARGET, MAVLINK_MESSAGE_INFO_ALTITUDE, MAVLINK_MESSAGE_INFO_RESOURCE_REQUEST, MAVLINK_MESSAGE_INFO_SCALED_PRESSURE3, MAVLINK_MESSAGE_INFO_FOLLOW_TARGET, MAVLINK_MESSAGE_INFO_CONTROL_SYSTEM_STATE, MAVLINK_MESSAGE_INFO_BATTERY_STATUS, MAVLINK_MESSAGE_INFO_AUTOPILOT_VERSION, MAVLINK_MESSAGE_INFO_LANDING_TARGET, MAVLINK_MESSAGE_INFO_FENCE_STATUS, MAVLINK_MESSAGE_INFO_ESTIMATOR_STATUS, MAVLINK_MESSAGE_INFO_WIND_COV, MAVLINK_MESSAGE_INFO_GPS_INPUT, MAVLINK_MESSAGE_INFO_GPS_RTCM_DATA, MAVLINK_MESSAGE_INFO_HIGH_LATENCY, MAVLINK_MESSAGE_INFO_HIGH_LATENCY2, MAVLINK_MESSAGE_INFO_VIBRATION, MAVLINK_MESSAGE_INFO_HOME_POSITION, MAVLINK_MESSAGE_INFO_SET_HOME_POSITION, MAVLINK_MESSAGE_INFO_MESSAGE_INTERVAL, MAVLINK_MESSAGE_INFO_EXTENDED_SYS_STATE, MAVLINK_MESSAGE_INFO_ADSB_VEHICLE, MAVLINK_MESSAGE_INFO_COLLISION, MAVLINK_MESSAGE_INFO_V2_EXTENSION, MAVLINK_MESSAGE_INFO_MEMORY_VECT, MAVLINK_MESSAGE_INFO_DEBUG_VECT, MAVLINK_MESSAGE_INFO_NAMED_VALUE_FLOAT, MAVLINK_MESSAGE_INFO_NAMED_VALUE_INT, MAVLINK_MESSAGE_INFO_STATUSTEXT, MAVLINK_MESSAGE_INFO_DEBUG, MAVLINK_MESSAGE_INFO_SETUP_SIGNING, MAVLINK_MESSAGE_INFO_BUTTON_CHANGE, MAVLINK_MESSAGE_INFO_PLAY_TUNE, MAVLINK_MESSAGE_INFO_CAMERA_INFORMATION, MAVLINK_MESSAGE_INFO_CAMERA_SETTINGS, MAVLINK_MESSAGE_INFO_STORAGE_INFORMATION, MAVLINK_MESSAGE_INFO_CAMERA_CAPTURE_STATUS, MAVLINK_MESSAGE_INFO_CAMERA_IMAGE_CAPTURED, MAVLINK_MESSAGE_INFO_FLIGHT_INFORMATION, MAVLINK_MESSAGE_INFO_MOUNT_ORIENTATION, MAVLINK_MESSAGE_INFO_LOGGING_DATA, MAVLINK_MESSAGE_INFO_LOGGING_DATA_ACKED, MAVLINK_MESSAGE_INFO_LOGGING_ACK, MAVLINK_MESSAGE_INFO_VIDEO_STREAM_INFORMATION, MAVLINK_MESSAGE_INFO_VIDEO_STREAM_STATUS, MAVLINK_MESSAGE_INFO_WIFI_CONFIG_AP, MAVLINK_MESSAGE_INFO_PROTOCOL_VERSION, MAVLINK_MESSAGE_INFO_AIS_VESSEL, MAVLINK_MESSAGE_INFO_UAVCAN_NODE_STATUS, MAVLINK_MESSAGE_INFO_UAVCAN_NODE_INFO, MAVLINK_MESSAGE_INFO_PARAM_EXT_REQUEST_READ, MAVLINK_MESSAGE_INFO_PARAM_EXT_REQUEST_LIST, MAVLINK_MESSAGE_INFO_PARAM_EXT_VALUE, MAVLINK_MESSAGE_INFO_PARAM_EXT_SET, MAVLINK_MESSAGE_INFO_PARAM_EXT_ACK, MAVLINK_MESSAGE_INFO_OBSTACLE_DISTANCE, MAVLINK_MESSAGE_INFO_ODOMETRY, MAVLINK_MESSAGE_INFO_TRAJECTORY_REPRESENTATION_WAYPOINTS, MAVLINK_MESSAGE_INFO_TRAJECTORY_REPRESENTATION_BEZIER, MAVLINK_MESSAGE_INFO_CELLULAR_STATUS, MAVLINK_MESSAGE_INFO_ISBD_LINK_STATUS, MAVLINK_MESSAGE_INFO_UTM_GLOBAL_POSITION, MAVLINK_MESSAGE_INFO_DEBUG_FLOAT_ARRAY, MAVLINK_MESSAGE_INFO_ORBIT_EXECUTION_STATUS, MAVLINK_MESSAGE_INFO_STATUSTEXT_LONG, MAVLINK_MESSAGE_INFO_SMART_BATTERY_INFO, MAVLINK_MESSAGE_INFO_SMART_BATTERY_STATUS, MAVLINK_MESSAGE_INFO_ACTUATOR_OUTPUT_STATUS, MAVLINK_MESSAGE_INFO_TIME_ESTIMATE_TO_TARGET, MAVLINK_MESSAGE_INFO_TUNNEL, MAVLINK_MESSAGE_INFO_ONBOARD_COMPUTER_STATUS, MAVLINK_MESSAGE_INFO_COMPONENT_INFORMATION, MAVLINK_MESSAGE_INFO_PLAY_TUNE_V2, MAVLINK_MESSAGE_INFO_SUPPORTED_TUNES, MAVLINK_MESSAGE_INFO_NTRIP_CONFIG, MAVLINK_MESSAGE_INFO_NETWORK_STATUS, MAVLINK_MESSAGE_INFO_WK_PRODUCT_VERSION, MAVLINK_MESSAGE_INFO_WK_OBSTACLE_AVIDANCE, MAVLINK_MESSAGE_INFO_WK_MISSION_BREAK_POINT, MAVLINK_MESSAGE_INFO_WK_MISSION_STATE, MAVLINK_MESSAGE_INFO_WK_FLIGHT_STATE, MAVLINK_MESSAGE_INFO_WK_SMART_BATTERY_STATUS, MAVLINK_MESSAGE_INFO_WK_MOUNT_STATUS, MAVLINK_MESSAGE_INFO_WK_MODULE_SET_SERIAL_NUMBER, MAVLINK_MESSAGE_INFO_WK_MODULE_VERSION, MAVLINK_MESSAGE_INFO_WK_UPGRADE_REQUEST, MAVLINK_MESSAGE_INFO_WK_UPGRADE_FW_INFO, MAVLINK_MESSAGE_INFO_WK_UPGRADE_FRAG_REQUEST, MAVLINK_MESSAGE_INFO_WK_UPGRADE_FRAG_DATA, MAVLINK_MESSAGE_INFO_WK_UPGRADE_END_REPORT, MAVLINK_MESSAGE_INFO_WK_SELFCHK_STATE, MAVLINK_MESSAGE_INFO_WK_UPGRADE_END_ACK, MAVLINK_MESSAGE_INFO_WK_UPGRADE_REQUEST_ACK, MAVLINK_MESSAGE_INFO_WK_TARGET_POSVEL, MAVLINK_MESSAGE_INFO_WK_FOLLOWME_CMD, MAVLINK_MESSAGE_INFO_WK_OILMASS_STATE, MAVLINK_MESSAGE_INFO_WK_RTK_BEACON_STATE, MAVLINK_MESSAGE_INFO_WK_BUOY_RECGONIZE_STATE, MAVLINK_MESSAGE_INFO_WK_HEARTBEAT_EXT, MAVLINK_MESSAGE_INFO_WK_GNSS_SIGNAL_STRENGTH, MAVLINK_MESSAGE_INFO_WK_HEARTBEAT_EXT_NEW_RULE, MAVLINK_MESSAGE_INFO_WK_RTK_BEACON_INAV_DATA, MAVLINK_MESSAGE_INFO_WK_RTK_BEACON_ANTENNA_OFFSET, MAVLINK_MESSAGE_INFO_WK_PARAM_VALUE, MAVLINK_MESSAGE_INFO_MISSION_ITEM_INT_EXT, MAVLINK_MESSAGE_INFO_WK_CAMERA_STATE, MAVLINK_MESSAGE_INFO_WK_CAMERA_CAPTURE_STATE, MAVLINK_MESSAGE_INFO_WK_CAMERA_TIME_LAPSE_STATE, MAVLINK_MESSAGE_INFO_WK_CAMERA_HARDWARE_PARAMS, MAVLINK_MESSAGE_INFO_WK_CAMERA_TAKEPHOTO_RECORD_INFO, MAVLINK_MESSAGE_INFO_WK_CAMERA_PARAMS_RPT, MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_COMMON_PARAMS, MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_TAKEPHOTO, MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_VIDEO_REC, MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_SDCARD_FORMAT, MAVLINK_MESSAGE_INFO_WK_CAMERA_STATUS_REPORT, MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_FOCUS, MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_UTC_TIME_SYNC, MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_CREATE_FOLDER, MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_CAP_PARAM, MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_PREVIEW_PARAM, MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_RECORD_PARAM, MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_ISO, MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_SHUTTER, MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_EV_MODE, MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_EV_VALUE, MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_AWB_MODE, MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_CSC, MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS, MAVLINK_MESSAGE_INFO_WK_CAMERA_QRCODE_POS, MAVLINK_MESSAGE_INFO_WK_5GINFO_STATUS, MAVLINK_MESSAGE_INFO_WK_PRODUCT_ID, MAVLINK_MESSAGE_INFO_WK_PRODUCT_ACTIVE, MAVLINK_MESSAGE_INFO_WK_TEST, MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_CAMERA_CONTROL, MAVLINK_MESSAGE_INFO_WK_TIME_LAPSE_DIRE_PARAM, MAVLINK_MESSAGE_INFO_WK_TIME_LAPSE_DIRE_PARAM_ACK, MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_FOCUS2, MAVLINK_MESSAGE_INFO_WK_CAMERA_MINI_DUAL_PARAMETER, MAVLINK_MESSAGE_INFO_WK_CAMERA_MINI_DUAL_MEASURE_MODE, MAVLINK_MESSAGE_INFO_WK_CAMERA_MINI_DUAL_STATE, MAVLINK_MESSAGE_INFO_WK_SCOUT_STATE, MAVLINK_MESSAGE_INFO_WK_RC_PARAMETER, MAVLINK_MESSAGE_INFO_WK_ENGINE_CONTROL_STATE, MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_UTC_TIME_SYNC1, MAVLINK_MESSAGE_INFO_WK_CAMERA_FOCUSING, MAVLINK_MESSAGE_INFO_WK_CAMERA_LASER_RANGING, MAVLINK_MESSAGE_INFO_WK_CAMERA_LASER_RANGING_STATE, MAVLINK_MESSAGE_INFO_WK_PRODUCT_BOUND, MAVLINK_MESSAGE_INFO_WK_PRODUCT_LOCK, MAVLINK_MESSAGE_INFO_WK_SET_CONNECT_PARAM, MAVLINK_MESSAGE_INFO_WK_SET_AI_TRACKING_CMD, MAVLINK_MESSAGE_INFO_WK_SET_VR_PARAM, MAVLINK_MESSAGE_INFO_WK_MINI_4G_AUTHENTICATION, MAVLINK_MESSAGE_INFO_WK_LOG_FLIGHT_STATE, MAVLINK_MESSAGE_INFO_WK_LOG_GNSS, MAVLINK_MESSAGE_INFO_WK_LOG_GPS_RAW, MAVLINK_MESSAGE_INFO_WK_LOG_RTK_RAW, MAVLINK_MESSAGE_INFO_WK_LOG_BEACON, MAVLINK_MESSAGE_INFO_WK_LOG_MISSION, MAVLINK_MESSAGE_INFO_WK_LOG_MOTORS, MAVLINK_MESSAGE_INFO_WK_LOG_RCIN, MAVLINK_MESSAGE_INFO_WK_LOG_SENSOR_RAW, MAVLINK_MESSAGE_INFO_WK_LOG_MODE, MAVLINK_MESSAGE_INFO_WK_LOG_POS_CTRL, MAVLINK_MESSAGE_INFO_WK_LOG_IMAGE_GEO, MAVLINK_MESSAGE_INFO_WK_LOG_TEXT, MAVLINK_MESSAGE_INFO_WK_LOG_PARAMS_REQUEST, MAVLINK_MESSAGE_INFO_WK_LOG_PARAMS_DATA, MAVLINK_MESSAGE_INFO_WK_20T_RANGING_PARAM, MAVLINK_MESSAGE_INFO_WK_ASSIST_FUNCTION_STATE, MAVLINK_MESSAGE_INFO_WK_RC_CUSTOMIZE, MAVLINK_MESSAGE_INFO_WK_LOG_ULTRASONIC_RAW_DATA, MAVLINK_MESSAGE_INFO_WK_R500_NEST_LANDING_STATE, MAVLINK_MESSAGE_INFO_WK_TOF_CALI_STATE, MAVLINK_MESSAGE_INFO_WK_TOF_CSV_DATA, MAVLINK_MESSAGE_INFO_WK_TOF_CALI_VALUE, MAVLINK_MESSAGE_INFO_WK_TOF_CALI_DATA_REQUEST, MAVLINK_MESSAGE_INFO_WHEEL_DISTANCE, MAVLINK_MESSAGE_INFO_OPEN_DRONE_ID_BASIC_ID, MAVLINK_MESSAGE_INFO_OPEN_DRONE_ID_LOCATION, MAVLINK_MESSAGE_INFO_OPEN_DRONE_ID_AUTHENTICATION, MAVLINK_MESSAGE_INFO_OPEN_DRONE_ID_SELF_ID, MAVLINK_MESSAGE_INFO_OPEN_DRONE_ID_SYSTEM, MAVLINK_MESSAGE_INFO_OPEN_DRONE_ID_OPERATOR_ID, MAVLINK_MESSAGE_INFO_OPEN_DRONE_ID_MESSAGE_PACK}
# define MAVLINK_MESSAGE_NAMES {{ "ACTUATOR_CONTROL_TARGET", 140 }, { "ACTUATOR_OUTPUT_STATUS", 375 }, { "ADSB_VEHICLE", 246 }, { "AIS_VESSEL", 301 }, { "ALTITUDE", 141 }, { "ATTITUDE", 30 }, { "ATTITUDE_QUATERNION", 31 }, { "ATTITUDE_QUATERNION_COV", 61 }, { "ATTITUDE_TARGET", 83 }, { "ATT_POS_MOCAP", 138 }, { "AUTH_KEY", 7 }, { "AUTOPILOT_VERSION", 148 }, { "BATTERY_STATUS", 147 }, { "BUTTON_CHANGE", 257 }, { "CAMERA_CAPTURE_STATUS", 262 }, { "CAMERA_IMAGE_CAPTURED", 263 }, { "CAMERA_INFORMATION", 259 }, { "CAMERA_SETTINGS", 260 }, { "CAMERA_TRIGGER", 112 }, { "CELLULAR_STATUS", 334 }, { "CHANGE_OPERATOR_CONTROL", 5 }, { "CHANGE_OPERATOR_CONTROL_ACK", 6 }, { "COLLISION", 247 }, { "COMMAND_ACK", 77 }, { "COMMAND_INT", 75 }, { "COMMAND_LONG", 76 }, { "COMPONENT_INFORMATION", 395 }, { "CONTROL_SYSTEM_STATE", 146 }, { "DATA_STREAM", 67 }, { "DATA_TRANSMISSION_HANDSHAKE", 130 }, { "DEBUG", 254 }, { "DEBUG_FLOAT_ARRAY", 350 }, { "DEBUG_VECT", 250 }, { "DISTANCE_SENSOR", 132 }, { "ENCAPSULATED_DATA", 131 }, { "ESTIMATOR_STATUS", 230 }, { "EXTENDED_SYS_STATE", 245 }, { "FENCE_STATUS", 162 }, { "FILE_TRANSFER_PROTOCOL", 110 }, { "FLIGHT_INFORMATION", 264 }, { "FOLLOW_TARGET", 144 }, { "GLOBAL_POSITION_INT", 33 }, { "GLOBAL_POSITION_INT_COV", 63 }, { "GLOBAL_VISION_POSITION_ESTIMATE", 101 }, { "GPS2_RAW", 124 }, { "GPS2_RTK", 128 }, { "GPS_GLOBAL_ORIGIN", 49 }, { "GPS_INJECT_DATA", 123 }, { "GPS_INPUT", 232 }, { "GPS_RAW_INT", 24 }, { "GPS_RTCM_DATA", 233 }, { "GPS_RTK", 127 }, { "GPS_STATUS", 25 }, { "HEARTBEAT", 0 }, { "HIGHRES_IMU", 105 }, { "HIGH_LATENCY", 234 }, { "HIGH_LATENCY2", 235 }, { "HIL_ACTUATOR_CONTROLS", 93 }, { "HIL_CONTROLS", 91 }, { "HIL_GPS", 113 }, { "HIL_OPTICAL_FLOW", 114 }, { "HIL_RC_INPUTS_RAW", 92 }, { "HIL_SENSOR", 107 }, { "HIL_STATE", 90 }, { "HIL_STATE_QUATERNION", 115 }, { "HOME_POSITION", 242 }, { "ISBD_LINK_STATUS", 335 }, { "LANDING_TARGET", 149 }, { "LINK_NODE_STATUS", 8 }, { "LOCAL_POSITION_NED", 32 }, { "LOCAL_POSITION_NED_COV", 64 }, { "LOCAL_POSITION_NED_SYSTEM_GLOBAL_OFFSET", 89 }, { "LOGGING_ACK", 268 }, { "LOGGING_DATA", 266 }, { "LOGGING_DATA_ACKED", 267 }, { "LOG_DATA", 120 }, { "LOG_ENTRY", 118 }, { "LOG_ERASE", 121 }, { "LOG_REQUEST_DATA", 119 }, { "LOG_REQUEST_END", 122 }, { "LOG_REQUEST_LIST", 117 }, { "MANUAL_CONTROL", 69 }, { "MANUAL_SETPOINT", 81 }, { "MEMORY_VECT", 249 }, { "MESSAGE_INTERVAL", 244 }, { "MISSION_ACK", 47 }, { "MISSION_CHANGED", 52 }, { "MISSION_CLEAR_ALL", 45 }, { "MISSION_COUNT", 44 }, { "MISSION_CURRENT", 42 }, { "MISSION_ITEM", 39 }, { "MISSION_ITEM_INT", 73 }, { "MISSION_ITEM_INT_EXT", 8031 }, { "MISSION_ITEM_REACHED", 46 }, { "MISSION_REQUEST", 40 }, { "MISSION_REQUEST_INT", 51 }, { "MISSION_REQUEST_LIST", 43 }, { "MISSION_REQUEST_PARTIAL_LIST", 37 }, { "MISSION_SET_CURRENT", 41 }, { "MISSION_WRITE_PARTIAL_LIST", 38 }, { "MOUNT_ORIENTATION", 265 }, { "NAMED_VALUE_FLOAT", 251 }, { "NAMED_VALUE_INT", 252 }, { "NAV_CONTROLLER_OUTPUT", 62 }, { "NETWORK_STATUS", 8001 }, { "NTRIP_CONFIG", 8000 }, { "OBSTACLE_DISTANCE", 330 }, { "ODOMETRY", 331 }, { "ONBOARD_COMPUTER_STATUS", 390 }, { "OPEN_DRONE_ID_AUTHENTICATION", 12902 }, { "OPEN_DRONE_ID_BASIC_ID", 12900 }, { "OPEN_DRONE_ID_LOCATION", 12901 }, { "OPEN_DRONE_ID_MESSAGE_PACK", 12915 }, { "OPEN_DRONE_ID_OPERATOR_ID", 12905 }, { "OPEN_DRONE_ID_SELF_ID", 12903 }, { "OPEN_DRONE_ID_SYSTEM", 12904 }, { "OPTICAL_FLOW", 100 }, { "OPTICAL_FLOW_RAD", 106 }, { "ORBIT_EXECUTION_STATUS", 360 }, { "PARAM_EXT_ACK", 324 }, { "PARAM_EXT_REQUEST_LIST", 321 }, { "PARAM_EXT_REQUEST_READ", 320 }, { "PARAM_EXT_SET", 323 }, { "PARAM_EXT_VALUE", 322 }, { "PARAM_MAP_RC", 50 }, { "PARAM_REQUEST_LIST", 21 }, { "PARAM_REQUEST_READ", 20 }, { "PARAM_SET", 23 }, { "PARAM_VALUE", 22 }, { "PING", 4 }, { "PLAY_TUNE", 258 }, { "PLAY_TUNE_V2", 400 }, { "POSITION_TARGET_GLOBAL_INT", 87 }, { "POSITION_TARGET_LOCAL_NED", 85 }, { "POWER_STATUS", 125 }, { "PROTOCOL_VERSION", 300 }, { "RADIO_STATUS", 109 }, { "RAW_IMU", 27 }, { "RAW_PRESSURE", 28 }, { "RC_CHANNELS", 65 }, { "RC_CHANNELS_OVERRIDE", 70 }, { "RC_CHANNELS_RAW", 35 }, { "RC_CHANNELS_SCALED", 34 }, { "REQUEST_DATA_STREAM", 66 }, { "RESOURCE_REQUEST", 142 }, { "SAFETY_ALLOWED_AREA", 55 }, { "SAFETY_SET_ALLOWED_AREA", 54 }, { "SCALED_IMU", 26 }, { "SCALED_IMU2", 116 }, { "SCALED_IMU3", 129 }, { "SCALED_PRESSURE", 29 }, { "SCALED_PRESSURE2", 137 }, { "SCALED_PRESSURE3", 143 }, { "SERIAL_CONTROL", 126 }, { "SERVO_OUTPUT_RAW", 36 }, { "SETUP_SIGNING", 256 }, { "SET_ACTUATOR_CONTROL_TARGET", 139 }, { "SET_ATTITUDE_TARGET", 82 }, { "SET_GPS_GLOBAL_ORIGIN", 48 }, { "SET_HOME_POSITION", 243 }, { "SET_MODE", 11 }, { "SET_POSITION_TARGET_GLOBAL_INT", 86 }, { "SET_POSITION_TARGET_LOCAL_NED", 84 }, { "SIM_STATE", 108 }, { "SMART_BATTERY_INFO", 370 }, { "SMART_BATTERY_STATUS", 371 }, { "STATUSTEXT", 253 }, { "STATUSTEXT_LONG", 365 }, { "STORAGE_INFORMATION", 261 }, { "SUPPORTED_TUNES", 401 }, { "SYSTEM_TIME", 2 }, { "SYS_STATUS", 1 }, { "TERRAIN_CHECK", 135 }, { "TERRAIN_DATA", 134 }, { "TERRAIN_REPORT", 136 }, { "TERRAIN_REQUEST", 133 }, { "TIMESYNC", 111 }, { "TIME_ESTIMATE_TO_TARGET", 380 }, { "TRAJECTORY_REPRESENTATION_BEZIER", 333 }, { "TRAJECTORY_REPRESENTATION_WAYPOINTS", 332 }, { "TUNNEL", 385 }, { "UAVCAN_NODE_INFO", 311 }, { "UAVCAN_NODE_STATUS", 310 }, { "UTM_GLOBAL_POSITION", 340 }, { "V2_EXTENSION", 248 }, { "VFR_HUD", 74 }, { "VIBRATION", 241 }, { "VICON_POSITION_ESTIMATE", 104 }, { "VIDEO_STREAM_INFORMATION", 269 }, { "VIDEO_STREAM_STATUS", 270 }, { "VISION_POSITION_ESTIMATE", 102 }, { "VISION_SPEED_ESTIMATE", 103 }, { "WHEEL_DISTANCE", 9000 }, { "WIFI_CONFIG_AP", 299 }, { "WIND_COV", 231 }, { "WK_20T_RANGING_PARAM", 8515 }, { "WK_5GINFO_STATUS", 8060 }, { "WK_ASSIST_FUNCTION_STATE", 8516 }, { "WK_BUOY_RECGONIZE_STATE", 8024 }, { "WK_CAMERA_CAPTURE_STATE", 8033 }, { "WK_CAMERA_CMD_AWB_MODE", 8056 }, { "WK_CAMERA_CMD_CAMERA_CONTROL", 8064 }, { "WK_CAMERA_CMD_CAP_PARAM", 8049 }, { "WK_CAMERA_CMD_COMMON_PARAMS", 8041 }, { "WK_CAMERA_CMD_CREATE_FOLDER", 8048 }, { "WK_CAMERA_CMD_CSC", 8057 }, { "WK_CAMERA_CMD_EV_MODE", 8054 }, { "WK_CAMERA_CMD_EV_VALUE", 8055 }, { "WK_CAMERA_CMD_FOCUS", 8046 }, { "WK_CAMERA_CMD_FOCUS2", 8067 }, { "WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS", 8058 }, { "WK_CAMERA_CMD_ISO", 8052 }, { "WK_CAMERA_CMD_PREVIEW_PARAM", 8050 }, { "WK_CAMERA_CMD_RECORD_PARAM", 8051 }, { "WK_CAMERA_CMD_SDCARD_FORMAT", 8044 }, { "WK_CAMERA_CMD_SHUTTER", 8053 }, { "WK_CAMERA_CMD_TAKEPHOTO", 8042 }, { "WK_CAMERA_CMD_UTC_TIME_SYNC", 8047 }, { "WK_CAMERA_CMD_UTC_TIME_SYNC1", 8074 }, { "WK_CAMERA_CMD_VIDEO_REC", 8043 }, { "WK_CAMERA_FOCUSING", 8075 }, { "WK_CAMERA_HARDWARE_PARAMS", 8035 }, { "WK_CAMERA_LASER_RANGING", 8076 }, { "WK_CAMERA_LASER_RANGING_STATE", 8077 }, { "WK_CAMERA_MINI_DUAL_MEASURE_MODE", 8069 }, { "WK_CAMERA_MINI_DUAL_PARAMETER", 8068 }, { "WK_CAMERA_MINI_DUAL_STATE", 8070 }, { "WK_CAMERA_PARAMS_RPT", 8040 }, { "WK_CAMERA_QRCODE_POS", 8059 }, { "WK_CAMERA_STATE", 8032 }, { "WK_CAMERA_STATUS_REPORT", 8045 }, { "WK_CAMERA_TAKEPHOTO_RECORD_INFO", 8036 }, { "WK_CAMERA_TIME_LAPSE_STATE", 8034 }, { "WK_ENGINE_CONTROL_STATE", 8073 }, { "WK_FLIGHT_STATE", 8006 }, { "WK_FOLLOWME_CMD", 8021 }, { "WK_GNSS_SIGNAL_STRENGTH", 8026 }, { "WK_HEARTBEAT_EXT", 8025 }, { "WK_HEARTBEAT_EXT_NEW_RULE", 8027 }, { "WK_LOG_BEACON", 8504 }, { "WK_LOG_FLIGHT_STATE", 8500 }, { "WK_LOG_GNSS", 8501 }, { "WK_LOG_GPS_RAW", 8502 }, { "WK_LOG_IMAGE_GEO", 8511 }, { "WK_LOG_MISSION", 8505 }, { "WK_LOG_MODE", 8509 }, { "WK_LOG_MOTORS", 8506 }, { "WK_LOG_PARAMS_DATA", 8514 }, { "WK_LOG_PARAMS_REQUEST", 8513 }, { "WK_LOG_POS_CTRL", 8510 }, { "WK_LOG_RCIN", 8507 }, { "WK_LOG_RTK_RAW", 8503 }, { "WK_LOG_SENSOR_RAW", 8508 }, { "WK_LOG_TEXT", 8512 }, { "WK_LOG_ULTRASONIC_RAW_DATA", 8518 }, { "WK_MINI_4G_AUTHENTICATION", 8304 }, { "WK_MISSION_BREAK_POINT", 8004 }, { "WK_MISSION_STATE", 8005 }, { "WK_MODULE_SET_SERIAL_NUMBER", 8009 }, { "WK_MODULE_VERSION", 8010 }, { "WK_MOUNT_STATUS", 8008 }, { "WK_OBSTACLE_AVIDANCE", 8003 }, { "WK_OILMASS_STATE", 8022 }, { "WK_PARAM_VALUE", 8030 }, { "WK_PRODUCT_ACTIVE", 8062 }, { "WK_PRODUCT_BOUND", 8078 }, { "WK_PRODUCT_ID", 8061 }, { "WK_PRODUCT_LOCK", 8079 }, { "WK_PRODUCT_VERSION", 8002 }, { "WK_R500_NEST_LANDING_STATE", 8519 }, { "WK_RC_CUSTOMIZE", 8517 }, { "WK_RC_PARAMETER", 8072 }, { "WK_RTK_BEACON_ANTENNA_OFFSET", 8029 }, { "WK_RTK_BEACON_INAV_DATA", 8028 }, { "WK_RTK_BEACON_STATE", 8023 }, { "WK_SCOUT_STATE", 8071 }, { "WK_SELFCHK_STATE", 8016 }, { "WK_SET_AI_TRACKING_CMD", 8301 }, { "WK_SET_CONNECT_PARAM", 8300 }, { "WK_SET_VR_PARAM", 8302 }, { "WK_SMART_BATTERY_STATUS", 8007 }, { "WK_TARGET_POSVEL", 8020 }, { "WK_TEST", 8063 }, { "WK_TIME_LAPSE_DIRE_PARAM", 8065 }, { "WK_TIME_LAPSE_DIRE_PARAM_ACK", 8066 }, { "WK_TOF_CALI_DATA_REQUEST", 8523 }, { "WK_TOF_CALI_STATE", 8520 }, { "WK_TOF_CALI_VALUE", 8522 }, { "WK_TOF_CSV_DATA", 8521 }, { "WK_UPGRADE_END_ACK", 8017 }, { "WK_UPGRADE_END_REPORT", 8015 }, { "WK_UPGRADE_FRAG_DATA", 8014 }, { "WK_UPGRADE_FRAG_REQUEST", 8013 }, { "WK_UPGRADE_FW_INFO", 8012 }, { "WK_UPGRADE_REQUEST", 8011 }, { "WK_UPGRADE_REQUEST_ACK", 8018 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_WALKERA_H
