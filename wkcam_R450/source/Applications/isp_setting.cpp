

#include <isp_setting.h>
#include <sys_utils.h>
#include <VideoList.h>

#include "wk_corner_algorithm.h"


// 是否把录像与拍照的ISP参数区分开 0:使用同一套参数 1:使用不同的参数
#define SENSOR_ISP_SWITCH_MODE 1

tagSetStreamInfoStru m_TagMain;
bool mMainRestBit = false;
bool m_bMainInit = false;

tagSetStreamInfoStru m_TagSecond;
bool mSecondRestBit = false;
bool m_bSecondInit = false;

int wk_scence_mode;

CameraIspParams CameraParams;

int imp_system_init(void)
{
	int i, ret;

    OnInitStreamParam();

    wk_mpp_start(0); //上电初始化为4K@30FPS

    usleep(500*1000);

    OnInitCameraParams();

    wk_scence_mode = 0;
	
	middle_test();
    return 1;
}

//================ Get Camera Params ================//
void OnGetCamParams(CameraIspParams *param)
{
    wk_mpp_get_ExpInfo(&CameraParams.auto_shutter, &CameraParams.auto_iso);

    memcpy(param,&CameraParams,sizeof(CameraIspParams));
}

//================ Set Camera Params ================//
//set AwbAttr
bool OnSetAwbAttr(unsigned char awbvalue)
{
    CameraParams.awbmode = awbvalue;
    
    wk_mpp_set_WBAttr(awbvalue);

    // return SysSetConfig(SET_SYSTEM_CONFIG_COMM,0,(void*)&CameraParams); 
    return true;
}

//set brightness/contrast/sharpness/saturation
bool OnSetCSCAttr(unsigned char param, int value)
{
    int ret;

    switch(param)
    {
    case WK_CSC_BRIGTHNESS:
        if(value == 0){
            CameraParams.ev_value = value;
        }
        else{
            CameraParams.ev_value = value + 132 - DEFAULT_EV_VALUE;
        }
        break;

    // case WK_CSC_CONTRAST:
    //     CameraParams.contrast = value;
    //     break;

    // case WK_CSC_SATURATION:
    //     CameraParams.saturation = value;
    //     break;

    // case WK_CSC_SHARPNESS:
    //     CameraParams.sharpness = value;
    //     break;

    default:
        break;
    }

    if(value > 255){
        value = 255;
    }
    else if(value < 0){
        value = 0;
    }
    wk_mpp_set_CSCAttr(param, (unsigned char)value);

    // return SysSetConfig(SET_SYSTEM_CONFIG_COMM,0,(void*)&CameraParams);
    return true;
}

//set AeExposureInfo
bool OnSetAeExposureInfo(unsigned char ntype, unsigned int value)
{ 
    switch(ntype)
    {
    case WK_AE_EXPOSURE_MODE:
        CameraParams.aemode = value;

        //自动曝光模式下，把其他参数设回初值
        if(CameraParams.aemode == 0){
            CameraParams.iso_value = 100;
            CameraParams.shutter_value = 10000;
            CameraParams.ev_value = 132;
        }
        else{
            CameraParams.iso_value = 100;
            CameraParams.shutter_value = 10000;
        }
        
        wk_mpp_set_ExposureAttr(WK_AE_EXPOSURE_MODE,value);
        wk_mpp_set_ExposureAttr(WK_AE_EXPOSURE_ISO,CameraParams.iso_value/100);
        wk_mpp_set_ExposureAttr(WK_AE_EXPOSURE_TIME,CameraParams.shutter_value);
        OnSetCSCAttr(WK_CSC_BRIGTHNESS, DEFAULT_EV_VALUE);
        break;

    case WK_AE_EXPOSURE_ISO:
        CameraParams.iso_value = value*100;   //设置ISO的时候是使用value/100的值，记录的时候要乘回来
        if(value > 21){
            value = 21;
        }
        wk_mpp_set_ExposureAttr(WK_AE_EXPOSURE_ISO,value);
        break;

    case WK_AE_EXPOSURE_TIME:
        CameraParams.shutter_value = (int)value;
        if(value < 100){
            value = 100;
        }
        wk_mpp_set_ExposureAttr(WK_AE_EXPOSURE_TIME,value);
        break;

    case WK_AE_EXPOSURE_TARGETCOMP:
        CameraParams.ev_value = (int)value;
        wk_mpp_set_ExposureAttr(WK_AE_EXPOSURE_TARGETCOMP,value);  
        break;

    default:
        break;
    }

    // return SysSetConfig(SET_SYSTEM_CONFIG_COMM,0,(void*)&CameraParams);
    return true;
}

bool OnInitCameraParams(void)
{
    int getsize;

    memset(&CameraParams,0,sizeof(CameraIspParams));
    if(!SysGetConfig(GET_SYSTEM_CONFIG_COMM,(char *)&CameraParams,&getsize)){
        CameraParams.aemode = 0;
        CameraParams.awbmode = 0;
        CameraParams.iso_value = 100;
        CameraParams.shutter_value = 10000;
        CameraParams.ev_value = 132;
        CameraParams.brightness = 138;
        CameraParams.contrast = 172;
        CameraParams.sharpness = 128;
        CameraParams.saturation = 128;
        CameraParams.brightness_photo = 138;
        CameraParams.contrast_photo = 135;
        CameraParams.sharpness_photo = 128;
        CameraParams.saturation_photo = 142;
        SysSetConfig(SET_SYSTEM_CONFIG_COMM,0,(void*)&CameraParams);
    }

    if(CameraParams.shutter_value < 0 || CameraParams.iso_value < 0){
        printf("=============== param data error and reset =========== \n");
        CameraParams.aemode = 0;
        CameraParams.awbmode = 0;
        CameraParams.iso_value = 100;
        CameraParams.shutter_value = 10000;
        CameraParams.ev_value = 132;
        CameraParams.brightness = 138;
        CameraParams.contrast = 172;
        CameraParams.sharpness = 128;
        CameraParams.saturation = 128;
        CameraParams.brightness_photo = 138;
        CameraParams.contrast_photo = 135;
        CameraParams.sharpness_photo = 128;
        CameraParams.saturation_photo = 142;
        SysSetConfig(SET_SYSTEM_CONFIG_COMM,0,(void*)&CameraParams);
    }

    printf("CameraParams.aemode = [%d] \n",CameraParams.aemode);
    printf("CameraParams.awbmode = [%d] \n",CameraParams.awbmode);
    printf("CameraParams.iso_value = [%d] \n",CameraParams.iso_value);
    printf("CameraParams.shutter_value = [%d] \n",CameraParams.shutter_value);
    printf("CameraParams.ev_value = [%d] \n",CameraParams.ev_value);
    printf("CameraParams.brightness = [%d] \n",CameraParams.brightness);
    printf("CameraParams.contrast = [%d] \n",CameraParams.contrast);
    printf("CameraParams.sharpness = [%d] \n",CameraParams.sharpness);
    printf("CameraParams.saturation = [%d] \n",CameraParams.saturation);
    printf("CameraParams.brightness_photo = [%d] \n",CameraParams.brightness_photo);
    printf("CameraParams.contrast_photo = [%d] \n",CameraParams.contrast_photo);
    printf("CameraParams.sharpness_photo = [%d] \n",CameraParams.sharpness_photo);
    printf("CameraParams.saturation_photo = [%d] \n",CameraParams.saturation_photo);

    OnSetAeExposureInfo(WK_AE_EXPOSURE_MODE,CameraParams.aemode);
    OnSetAeExposureInfo(WK_AE_EXPOSURE_ISO,CameraParams.iso_value / 100);
    OnSetAeExposureInfo(WK_AE_EXPOSURE_TIME,CameraParams.shutter_value);   
    OnSetAeExposureInfo(WK_AE_EXPOSURE_TARGETCOMP,CameraParams.ev_value);

    OnSetCSCAttr(WK_CSC_BRIGTHNESS,CameraParams.brightness);
    OnSetCSCAttr(WK_CSC_CONTRAST,CameraParams.contrast);
    OnSetCSCAttr(WK_CSC_SATURATION,CameraParams.saturation);
    OnSetCSCAttr(WK_CSC_SHARPNESS,CameraParams.sharpness);
    OnSetAwbAttr(CameraParams.awbmode);

    wk_mpp_scene_start(0);

    return true;
}

//================ Set Stream Params ================//
int OnInitStreamParam(void)
{
    int getsizeMain;
    int getsizeSecond;

    memset(&m_TagMain,0,sizeof(tagSetStreamInfoStru));
    if(!SysGetConfig(GET_SYSTEM_MAINSTREAM_COMM,(char*)&m_TagMain,&getsizeMain)){
        m_TagMain.nEncodeMode = 1;//h264
        m_TagMain.nWidth = 3840;
        m_TagMain.nHeigth = 2160;
        m_TagMain.nframe_rate = 30;
        m_TagMain.nBitrate = 50*1024;
        SysSetConfig(SET_SYSTEM_RESET_MAINSTREAM_COMM,0,(void*)&m_TagMain);
    }
    printf("m_TagMain.nWidth = [%d] \n",m_TagMain.nWidth);
    printf("m_TagMain.nHeigth = [%d] \n",m_TagMain.nHeigth);
    printf("m_TagMain.nEncodeMode = [%d] \n",m_TagMain.nEncodeMode);
    printf("m_TagMain.nframe_rate = [%d] \n",m_TagMain.nframe_rate);
    printf("m_TagMain.nBitrate = [%d] \n",m_TagMain.nBitrate);

    wk_mpp_venc_set_param(WK_VIDEO_CHANNEL_RECORD,PIC_3840X2160,m_TagMain.nframe_rate,m_TagMain.nBitrate);
 
    memset(&m_TagSecond,0,sizeof(tagSetStreamInfoStru));
    if(!SysGetConfig(GET_SYSTEM_SECONDTREAM_COMM,(char *)&m_TagSecond,&getsizeSecond)){
        m_TagSecond.nEncodeMode = 1;
        m_TagSecond.nWidth = 1280;
        m_TagSecond.nHeigth = 720;
        m_TagSecond.nframe_rate = 30;
        m_TagSecond.nBitrate = 1*1024;
        SysSetConfig(SET_SYSTEM_RESET_SECONDSTREAM_COMM,0,(void*)&m_TagSecond);
    }
    printf("m_TagSecond.nWidth = [%d] \n",m_TagSecond.nWidth);
    printf("m_TagSecond.nHeigth = [%d] \n",m_TagSecond.nHeigth);
    printf("m_TagSecond.nEncodeMode = [%d] \n",m_TagSecond.nEncodeMode);
    printf("m_TagSecond.nframe_rate = [%d] \n",m_TagSecond.nframe_rate);
    printf("m_TagSecond.nBitrate = [%d] \n",m_TagSecond.nBitrate);

    wk_mpp_venc_set_payload(0); //0:h264 1:h265

    wk_mpp_venc_set_param(WK_VIDEO_CHANNEL_PREVIEW, PIC_576P, m_TagSecond.nframe_rate,m_TagSecond.nBitrate);

    return 0;
}

void OnSwitchCameraStatus(int mode)
{
#if SENSOR_ISP_SWITCH_MODE
    if(mode < 0){
        return;
    }

    if(mode == wk_scence_mode){
        return;
    }

    wk_scence_mode = mode;
    wk_mpp_scene_stop();

    if(mode == 0){
        OnSetCSCAttr(WK_CSC_BRIGTHNESS,CameraParams.brightness);
        OnSetCSCAttr(WK_CSC_CONTRAST,CameraParams.contrast);
        OnSetCSCAttr(WK_CSC_SATURATION,CameraParams.saturation);
        OnSetCSCAttr(WK_CSC_SHARPNESS,CameraParams.sharpness);
        
        printf("CameraParams.brightness = [%d] \n",CameraParams.brightness);
        printf("CameraParams.contrast = [%d] \n",CameraParams.contrast);
        printf("CameraParams.sharpness = [%d] \n",CameraParams.sharpness);
        printf("CameraParams.saturation = [%d] \n",CameraParams.saturation);
    }
    else{
        OnSetCSCAttr(WK_CSC_BRIGTHNESS,CameraParams.brightness_photo);
        OnSetCSCAttr(WK_CSC_CONTRAST,CameraParams.contrast_photo);
        OnSetCSCAttr(WK_CSC_SATURATION,CameraParams.saturation_photo);
        OnSetCSCAttr(WK_CSC_SHARPNESS,CameraParams.sharpness_photo);
        
        printf("CameraParams.brightness_photo = [%d] \n",CameraParams.brightness_photo);
        printf("CameraParams.contrast_photo = [%d] \n",CameraParams.contrast_photo);
        printf("CameraParams.sharpness_photo = [%d] \n",CameraParams.sharpness_photo);
        printf("CameraParams.saturation_photo = [%d] \n",CameraParams.saturation_photo);
    }

    wk_mpp_scene_start(mode);
#endif
}

bool OnReSetSecondStream(void* pCommPare)
{
    printf("-----------------OnReSetSecondStream-------------------\n");
    memcpy(&m_TagSecond,(char*)pCommPare,sizeof(tagSetStreamInfoStru));
    mSecondRestBit=true;

    printf("m_TagSecond.nWidth = [%d] \n",m_TagSecond.nWidth);
    printf("m_TagSecond.nHeigth = [%d] \n",m_TagSecond.nHeigth);
    printf("m_TagSecond.nEncodeMode = [%d] \n",m_TagSecond.nEncodeMode);
    printf("m_TagSecond.nframe_rate = [%d] \n",m_TagSecond.nframe_rate);
    printf("m_TagSecond.nBitrate = [%d] \n",m_TagSecond.nBitrate);

    wk_mpp_venc_set_payload(0); //0:h264 1:h265

    if(m_TagSecond.nWidth == 1280 && m_TagSecond.nHeigth == 720){
        wk_mpp_venc_set_param(WK_VIDEO_CHANNEL_PREVIEW,PIC_720P,m_TagSecond.nframe_rate,m_TagSecond.nBitrate);
    }
    else{
        wk_mpp_venc_set_param(WK_VIDEO_CHANNEL_PREVIEW,PIC_D1_NTSC,m_TagSecond.nframe_rate,m_TagSecond.nBitrate);
    }

    wk_mpp_venc_preview_reset();
    
    return true;
}

bool OnWriteSecondStreamConfig(void* pParam)
{
    tagSetStreamInfoStru m_TagSys;
    memcpy(&m_TagSys,pParam,sizeof(tagSetStreamInfoStru));

    char *file ="/root/previewconfig.ini";
    char buf[10];
    memset(buf,0,10);
    sprintf(buf,"%d",m_TagSys.nEncodeMode);
    write_profile_string("second", "EncodeMode", buf,file);
    memset(buf,0,10);
    sprintf(buf,"%d",m_TagSys.nWidth);
    write_profile_string("second", "Width", buf,file);
    memset(buf,0,10);
    sprintf(buf,"%d",m_TagSys.nHeigth);
    write_profile_string("second", "Heigth", buf,file);
    memset(buf,0,10);
    sprintf(buf,"%d",m_TagSys.nrate_speed);
    write_profile_string("second", "rate_speed", buf,file);
    memset(buf,0,10);
    sprintf(buf,"%d",m_TagSys.nframe_rate);
    write_profile_string("second", "frame_rate", buf,file);
    memset(buf,0,10);
    sprintf(buf,"%d",m_TagSys.nBitrate);
    write_profile_string("second", "Bitrate", buf,file);
    memset(buf,0,10);
    sprintf(buf,"%d",m_TagSys.nIFrameInter);
    write_profile_string("second", "IFrameInter", buf,file);

    return true;
}

bool OnReSetMainStream(void* pCommPare)
{
    printf("-----------------OnReSetMainStream-------------------\n");
    memcpy(&m_TagMain,(char*)pCommPare,sizeof(tagSetStreamInfoStru));
    mMainRestBit=true;

    if(m_TagMain.nframe_rate == 60){
        wk_mpp_vi_switch_mode(2);
    }
    else{
        wk_mpp_vi_switch_mode(0);
    }

    // OnInitCameraParams();

    return true;
}

bool OnWriteMainStreamConfig(void* pParam)
{
    tagSetStreamInfoStru m_TagSys;
    memcpy(&m_TagSys,pParam,sizeof(tagSetStreamInfoStru));

    char *file ="/root/recordconfig.ini";
    char buf[10];
    memset(buf,0,10);
    sprintf(buf,"%d",m_TagSys.nEncodeMode);
    write_profile_string("main", "EncodeMode", buf,file);
    memset(buf,0,10);
    sprintf(buf,"%d",m_TagSys.nWidth);
    write_profile_string("main", "Width", buf,file);
    memset(buf,0,10);
    sprintf(buf,"%d",m_TagSys.nHeigth);
    write_profile_string("main", "Heigth", buf,file);
    memset(buf,0,10);
    sprintf(buf,"%d",m_TagSys.nrate_speed);
    write_profile_string("main", "rate_speed", buf,file);
    memset(buf,0,10);
    sprintf(buf,"%d",m_TagSys.nframe_rate);
    write_profile_string("main", "frame_rate", buf,file);
    memset(buf,0,10);
    sprintf(buf,"%d",m_TagSys.nBitrate);
    write_profile_string("main", "Bitrate", buf,file);
    memset(buf,0,10);
    sprintf(buf,"%d",m_TagSys.nIFrameInter);
    write_profile_string("main", "IFrameInter", buf,file);

    return true;
}

bool OnWriteSysParamConfig(void* pParam)
{
    CameraIspParams m_TagSys;
    memcpy(&m_TagSys,pParam,sizeof(CameraIspParams));

    char *file ="/root/ispconfig.ini";
    char buf[10];
    memset(buf,0,10);
    sprintf(buf,"%d",m_TagSys.aemode);
    write_profile_string("AeAttr", "AeMode", buf,file);
    memset(buf,0,10);
    sprintf(buf,"%d",m_TagSys.awbmode);
    write_profile_string("AeAttr", "AwbMode", buf,file);
    memset(buf,0,10);
    sprintf(buf,"%d",m_TagSys.iso_value);
    write_profile_string("AeAttr", "ISO", buf,file);
    memset(buf,0,10);
    sprintf(buf,"%d",m_TagSys.shutter_value);
    write_profile_string("AeAttr", "Shutter", buf,file);
    memset(buf,0,10);
    sprintf(buf,"%d",m_TagSys.ev_value);
    write_profile_string("AeAttr", "AeTargetComp", buf,file);
    memset(buf,0,10);
    sprintf(buf,"%d",m_TagSys.brightness);
    write_profile_string("AeAttr", "Brightness", buf,file);
    memset(buf,0,10);
    sprintf(buf,"%d",m_TagSys.contrast);
    write_profile_string("AeAttr", "Contrast", buf,file);
    memset(buf,0,10);
    sprintf(buf,"%d",m_TagSys.sharpness);
    write_profile_string("AeAttr", "Sharpness", buf,file);
    memset(buf,0,10);
    sprintf(buf,"%d",m_TagSys.saturation);
    write_profile_string("AeAttr", "Saturation", buf,file);
    memset(buf,0,10);
    sprintf(buf,"%d",m_TagSys.brightness_photo);
    write_profile_string("AeAttr", "PhotoBri", buf,file);
    memset(buf,0,10);
    sprintf(buf,"%d",m_TagSys.contrast_photo);
    write_profile_string("AeAttr", "PhotoCon", buf,file);
    memset(buf,0,10);
    sprintf(buf,"%d",m_TagSys.sharpness_photo);
    write_profile_string("AeAttr", "PhotoHue", buf,file);
    memset(buf,0,10);
    sprintf(buf,"%d",m_TagSys.saturation_photo);
    write_profile_string("AeAttr", "PhotoSat", buf,file);

    printf("============== write isp param ==============\n");

    return true;
}

bool SysSetConfig_OnReSetSecondStream(void* pCommPare)
{
    if( OnReSetSecondStream(pCommPare) ){
        if( !OnWriteSecondStreamConfig(pCommPare) ){
            return false;
        }
    }else
        return false;

    return true;
}

bool SysSetConfig_OnReSetMainStream(void* pCommPare)
{
    if( OnReSetMainStream(pCommPare) ){
        // if( !OnWriteMainStreamConfig(pCommPare) ){
        //     return false;
        // }
        printf("====== OnReSetMainStream successful ======\n");
    }else{
        return false;
    }

    return true;
}

bool SysSetConfig_OnReSetSysConfig(void* pCommPare)
{
    if( !OnWriteSysParamConfig(pCommPare) ){
        return false;
    }

    return true;
}

bool SysSetConfig(unsigned int dwComm,unsigned int dwSetVaule,void* pCommPare)
{
    switch(dwComm){
    case SET_SYSTEM_RESET_MAINSTREAM_COMM:{
        return SysSetConfig_OnReSetMainStream(pCommPare);
        break;}
    case SET_SYSTEM_RESET_SECONDSTREAM_COMM:{
        return SysSetConfig_OnReSetSecondStream(pCommPare);
        break;}
    case SET_SYSTEM_CONFIG_COMM:{
        return SysSetConfig_OnReSetSysConfig(pCommPare);
        break;} 
    default:
        break;
    }

    return true;
}

//================ Get Stream Params ================//
dictionary*         g_StreamConfig = NULL;
bool OnSteram_LoadConfigFile(const char* pszFILENAME)
{
    if (NULL == g_StreamConfig)
    {
        g_StreamConfig = iniparser_load(pszFILENAME);
        if (NULL == g_StreamConfig)
        {
            printf("%s ini load failed\n", pszFILENAME);
            return false;
        }
    }

    return true;
}

bool OnGetSysParamConfig(char* pParam,int *Resize)
{
    int nvaue=0;
    int f_size = 0;
    struct stat sbuf;

    CameraIspParams m_TagSys;
    memset(&m_TagSys,0,sizeof(CameraIspParams));

    if(stat("/root/ispconfig.ini", &sbuf) < 0) {
        printf("Get file size failed.\n");
        return false;
    } else {
        f_size = (int)sbuf.st_size;
        if(f_size <= 10){
            return false;
        }
    }

    if(OnSteram_LoadConfigFile("/root/ispconfig.ini")){
        nvaue = iniparser_getint(g_StreamConfig, "AeAttr:AeMode", NOTFOUND);
        m_TagSys.aemode = nvaue;

        nvaue = iniparser_getint(g_StreamConfig, "AeAttr:AwbMode", NOTFOUND);
        m_TagSys.awbmode = nvaue;

        nvaue = iniparser_getint(g_StreamConfig, "AeAttr:ISO", NOTFOUND);
        m_TagSys.iso_value = nvaue;

        nvaue = iniparser_getint(g_StreamConfig, "AeAttr:Shutter", NOTFOUND);
        m_TagSys.shutter_value = nvaue;

        nvaue = iniparser_getint(g_StreamConfig, "AeAttr:AeTargetComp", NOTFOUND);
        m_TagSys.ev_value = nvaue;

        nvaue = iniparser_getint(g_StreamConfig, "AeAttr:Brightness", NOTFOUND);
        m_TagSys.brightness = nvaue;

        nvaue = iniparser_getint(g_StreamConfig, "AeAttr:Contrast", NOTFOUND);
        m_TagSys.contrast = nvaue;

        nvaue = iniparser_getint(g_StreamConfig, "AeAttr:Sharpness", NOTFOUND);
        m_TagSys.sharpness = nvaue;

        nvaue = iniparser_getint(g_StreamConfig, "AeAttr:Saturation", NOTFOUND);
        m_TagSys.saturation = nvaue;

        nvaue = iniparser_getint(g_StreamConfig, "AeAttr:PhotoBri", NOTFOUND);
        m_TagSys.brightness_photo = nvaue;

        nvaue = iniparser_getint(g_StreamConfig, "AeAttr:PhotoCon", NOTFOUND);
        m_TagSys.contrast_photo = nvaue;

        nvaue = iniparser_getint(g_StreamConfig, "AeAttr:PhotoHue", NOTFOUND);
        m_TagSys.sharpness_photo = nvaue;

        nvaue = iniparser_getint(g_StreamConfig, "AeAttr:PhotoSat", NOTFOUND);
        m_TagSys.saturation_photo = nvaue;

        *Resize=sizeof(CameraIspParams);
        memcpy(pParam,&m_TagSys,sizeof(CameraIspParams));

        if (NULL != g_StreamConfig){
            iniparser_freedict(g_StreamConfig);
        }
        g_StreamConfig = NULL;
        return true;
    }else{
        return false;
    }
}

bool OnGetSecondStream(char* pParam,int *Resize)
{
    int nvaue=0;
    int f_size = 0;
    struct stat sbuf;

    tagSetStreamInfoStru m_TagSys;
    memset(&m_TagSys,0,sizeof(tagSetStreamInfoStru));

    if(stat("/root/previewconfig.ini", &sbuf) < 0) {
        printf("Get file size failed.\n");
        return false;
    } else {
        f_size = (int)sbuf.st_size;
        if(f_size <= 10){
            return false;
        }
    }

    if(OnSteram_LoadConfigFile("/root/previewconfig.ini"))
    {
        nvaue=iniparser_getint(g_StreamConfig, "second:EncodeMode", NOTFOUND);

        m_TagSys.nEncodeMode=nvaue;
        nvaue=iniparser_getint(g_StreamConfig, "second:Width", NOTFOUND);

        m_TagSys.nWidth=nvaue;
        nvaue=iniparser_getint(g_StreamConfig, "second:Heigth", NOTFOUND);

        m_TagSys.nHeigth=nvaue;
        nvaue=iniparser_getint(g_StreamConfig, "second:rate_speed", NOTFOUND);

        m_TagSys.nrate_speed=nvaue;
        nvaue=iniparser_getint(g_StreamConfig, "second:frame_rate", NOTFOUND);
        m_TagSys.nframe_rate=nvaue;
        nvaue=iniparser_getint(g_StreamConfig, "second:Bitrate", NOTFOUND);
        m_TagSys.nBitrate=nvaue;
        nvaue=iniparser_getint(g_StreamConfig, "second:IFrameInter", NOTFOUND);
        m_TagSys.nIFrameInter=nvaue;
        *Resize=sizeof(tagSetStreamInfoStru);
        memcpy(pParam,&m_TagSys,sizeof(tagSetStreamInfoStru));
        if (NULL != g_StreamConfig)
        {
            iniparser_freedict(g_StreamConfig);
        }
        g_StreamConfig = NULL;
        return true;
    }else{
        return false;
    }
}

bool OnGetMainStream(char* pParam,int *Resize)
{
    int nvaue=0;
    int f_size = 0;
    struct stat sbuf;

    tagSetStreamInfoStru m_TagSys;
    memset(&m_TagSys,0,sizeof(tagSetStreamInfoStru));

    if(stat("/root/recordconfig.ini", &sbuf) < 0) {
        printf("Get file size failed.\n");
        return false;
    } else {
        f_size = (int)sbuf.st_size;
        if(f_size <= 10){
            return false;
        }
    }

    if(OnSteram_LoadConfigFile("/root/recordconfig.ini")){

        nvaue=iniparser_getint(g_StreamConfig, "main:EncodeMode", NOTFOUND);

        m_TagSys.nEncodeMode=nvaue;
        nvaue=iniparser_getint(g_StreamConfig, "main:Width", NOTFOUND);

        m_TagSys.nWidth=nvaue;
        nvaue=iniparser_getint(g_StreamConfig, "main:Heigth", NOTFOUND);

        m_TagSys.nHeigth=nvaue;
        nvaue=iniparser_getint(g_StreamConfig, "main:rate_speed", NOTFOUND);

        m_TagSys.nrate_speed=nvaue;
        nvaue=iniparser_getint(g_StreamConfig, "main:frame_rate", NOTFOUND);
        m_TagSys.nframe_rate=nvaue;
        nvaue=iniparser_getint(g_StreamConfig, "main:Bitrate", NOTFOUND);
        m_TagSys.nBitrate=nvaue;
        nvaue=iniparser_getint(g_StreamConfig, "main:IFrameInter", NOTFOUND);
        m_TagSys.nIFrameInter=nvaue;
        *Resize=sizeof(tagSetStreamInfoStru);
        memcpy(pParam,&m_TagSys,sizeof(tagSetStreamInfoStru));
        if (NULL != g_StreamConfig)
        {
            iniparser_freedict(g_StreamConfig);
        }
        g_StreamConfig = NULL;
        return true;
    }else{
        return false;
    }
}

bool SysGetConfig(unsigned int dwComm,char* pCommPare,int *nGetSize)
{
    switch(dwComm){
    case GET_SYSTEM_MAINSTREAM_COMM:{
        return OnGetMainStream(pCommPare,nGetSize);
        break;}
    case GET_SYSTEM_SECONDTREAM_COMM:{
        return OnGetSecondStream(pCommPare,nGetSize);
        break;}
    case GET_SYSTEM_CONFIG_COMM:{
        return OnGetSysParamConfig(pCommPare,nGetSize);
        break;}
    default:
        break;
    }

    return false;
}




