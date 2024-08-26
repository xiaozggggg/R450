

#ifndef __ISP_SETTING_H__
#define __ISP_SETTING_H__

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>

#include "iniparser.h"
#include <sample_comm.h>
#include "wk_log.h"

#define   NOTFOUND (-1)

#define   IMP_MAIN_STREAM_CHN                   0
#define   IMP_SECOND_STREAM_CHN                 1
#define   IMP_THIRD_STREAM_CHN                  2

#define   SET_SYSTEM_CONFIG_COMM                0x0100   //系统配置命令
#define   SET_SYSTEM_RESET_MAINSTREAM_COMM      0x0102   //主码流重新配置命令
#define   SET_SYSTEM_RESET_SECONDSTREAM_COMM    0x0104   //次码流重新配置命令
#define   SET_SYSTEM_SET_THIRDSTREAM_COMM       0x0105   //第三码配置命令
#define   SET_SYSTEM_RESET_THIRDSTREAM_COMM     0x0106   //重新设置第三码流
#define   GET_SYSTEM_MAINSTREAM_COMM            0x0107   //读取主码流配置参数
#define   GET_SYSTEM_SECONDTREAM_COMM           0x0108   //读取第二码流配置参数
#define   GET_SYSTEM_THIRDSTREAM_COMM           0x0109   //读取第三码流配置参数
#define   GET_SYSTEM_CONFIG_COMM                0x010a   //读取系统配置命令

#define   DEFAULT_EV_VALUE                      138

#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */

typedef struct _TAG_CaptureImage
{
    unsigned char       CapMode;            //拍照模式 1为单拍2为连拍
    unsigned char       CapContinue;        //连拍张数
    unsigned char       CapSave;            //图片储存格式1为JPG;2为RAW;3为JPG/RAW
    unsigned char       CapResolution;      //图像分辩率1为8M;2为12M;3为16M
    unsigned char       CapRation;          //图像比例 1为4:3;2为16:9
}__attribute__((packed)) TagCaptureImage,*pTagCaptureImage;

typedef struct _SetStreamInfoStru
{
    unsigned char  nEncodeMode;//编码模式 1、H264 2、H265
    unsigned short nWidth;//分辨率宽度
    unsigned short nHeigth;//分辨率高度
    unsigned char  nrate_speed;//速率
    unsigned char  nframe_rate;//帧率
    unsigned  int  nBitrate;//码率
    unsigned char  nIFrameInter;//I帧间隔
}__attribute__((packed))tagSetStreamInfoStru;

typedef struct _StreamEncode_ATTR_S
{
    unsigned int  Identifier;//标识0xAAAAAAAA
    unsigned char EncodeType;//编码模式
    unsigned char FreamRate;//帧率
    unsigned short Width;//宽度
    unsigned short Height;//高度
}tagStreamEncode_ATTR_S;

typedef struct {
    unsigned char  reserved;  //保留
    unsigned char  major;     //主版本
    unsigned char  minor;     //次版本
    unsigned char  revision;  //修订版本
}VersionInfo;

typedef struct {
    unsigned char aemode;     //自动/手动调节曝光参数
    unsigned char awbmode;    //白平衡模式
    unsigned char brightness; //亮度_视频
    unsigned char contrast;   //对比度_视频
    unsigned char sharpness;  //锐度_视频
    unsigned char saturation; //饱和度_视频
    unsigned char brightness_photo; //亮度_照片
    unsigned char contrast_photo;   //对比度_照片
    unsigned char sharpness_photo;  //锐度_照片
    unsigned char saturation_photo; //饱和度_照片
    unsigned char ev_value;   //曝光补偿
    int iso_value;            //曝光值
    int shutter_value;        //曝光时间
    int auto_shutter;         //自动调节的曝光时间
    int auto_iso;             //自动调节的ISO
}CameraIspParams;

typedef enum {
    ENCODER_OUTPUT_START,
    ENCODER_OUTPUT_GETSTREAM,
    ENCODER_OUTPUT_STOP,
    ENCODER_OUTPUT_DELAY,
    ENCODER_OUTPUT_BUTT
}STREAM_ENCODER_S;

extern tagSetStreamInfoStru m_TagMain;
extern tagSetStreamInfoStru m_TagSecond;

//======= 初始化码流及相机参数 ======//
int imp_system_init(void);
int OnInitStreamParam(void);
bool OnInitCameraParams(void);

//======= 切换码流配置 =======//
int CheckStreamChange(int chnNum,tagSetStreamInfoStru *tag);

//======= 获取及设置相机参数 ======//
void OnGetCamParams(CameraIspParams *param);
bool OnSetAwbAttr(unsigned char awbvalue);
bool OnSetCSCAttr(unsigned char param, int value);
bool OnSetAeExposureInfo(unsigned char ntype, unsigned int value);

//======= 保存参数到文件、从文件中读取参数配置 =======//
bool OnReSetMainStream(void* pCommPare);
bool OnWriteMainStreamConfig(void* pParam);
bool OnReSetSecondStream(void* pCommPare);
bool OnWriteSecondStreamConfig(void* pParam);
bool OnWriteSysParamConfig(void* pParam);
void OnSwitchCameraStatus(int mode);

bool SysSetConfig_OnReSetMainStream(void* pCommPare);
bool SysSetConfig_OnReSetSecondStream(void* pCommPare);
bool SysSetConfig_OnReSetSysConfig(void* pCommPare);

bool OnGetMainStream(char* pParam,int *Resize);
bool OnGetSecondStream(char* pParam,int *Resize);
bool OnGetSysParamConfig(char* pParam,int *Resize);
bool OnSteram_LoadConfigFile(const char* pszFILENAME);

bool SysSetConfig(unsigned int dwComm,unsigned int dwSetVaule,void* pCommPare);
bool SysGetConfig(unsigned int dwComm,char* pCommPare,int *nGetSize);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __ISP_SETTING_H__ */
