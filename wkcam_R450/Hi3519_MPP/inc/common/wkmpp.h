#ifndef __WKMPP_H__
#define __WKMPP_H__

#include "sample_comm.h"
#include "VideoList.h"
#include "ini_parser.h"

//cfg;
typedef struct {
    char  snsname[32];  // sensor imx335
    int   snscnt;       // sensor count
    int   lane;         // lane mode
    int   wdr;          // wdr mode
    int   res;          // resolution
    int   fps;          // frame rate
    int   slave;        // slave mode
    int   second;       // second channel;
    char  type[32];     // cpu type;
}wk_mpp_cfg_t;

//vi;
typedef struct {
    td_bool bLowDelay;
    td_u32 u32SupplementConfig;
    ot_vi_stitch_grp_attr stStitchGrpAttr; // 3516DV300 no-support
}wk_mpp_vi_t;

typedef struct {
    void *uargs;
    int (*cb)(td_u32 Fv1, td_u32 Fv2, td_u32 Gain, void* uargs);
}wk_mpp_af_t;

//vpss;
typedef struct {
    ot_vpss_grp    VpssGrp;

    ot_mod_id  srcModId;
    union{
        td_s32  ViPipe;
    };
    union{
        ot_vi_chn  ViChn;
    };

    td_bool     enable[OT_VPSS_MAX_PHYS_CHN_NUM];
    ot_pic_size  enSize[OT_VPSS_MAX_PHYS_CHN_NUM];
}wk_mpp_vpss_t;

enum {
    WK_MPP_VPSS_CTL_PAUSE = 0, //HI_MPI_VPSS_StartGrp(VpssGrp);
    WK_MPP_VPSS_CTL_RESUM = 1, //HI_MPI_VPSS_StopGrp(VpssGrp);
    WK_MPP_VPSS_CTL_CROP  = 2, //HI_MPI_VPSS_SetGrpCrop(VpssGrp, VPSS_CROP_INFO_S *args);
};

enum {
    WK_VIDEO_CHANNEL_RECORD = 0,
    WK_VIDEO_CHANNEL_PREVIEW,
    WK_VIDEO_CHANNEL_SNAP,
    WK_VIDEO_CHANNEL_THUMBNAIL,
    WK_VIDEO_CHANNEL_BUTT
};

//双目避障
enum {
    WK_DOUBLE_CHANNEL_LEFT = 10,
    WK_DOUBLE_CHANNEL_RIGHT,
};

//venc;
typedef struct 
{  
    ot_venc_chn  VencChn;

    ot_mod_id  srcModId;
    union {
        ot_vpss_grp  VpssGrp;
        ot_avs_grp   AVSGrp;
        ot_vi_pipe   ViPipe;
        ot_vo_layer  VoLayer;
    };
    union {
        ot_vpss_chn  VpssChn; // VPSS
        ot_avs_chn   AVSChn;  // AVS
        ot_vdec_chn  VdChn;   // VDEC
        ot_vi_chn    ViChn;   // VI
        ot_vo_chn    VoChn;   // VO
    };
  
    ot_payload_type  enPayLoad;
    ot_pic_size      enSize;
    td_s32          enRcMode;
    td_u32          u32Profile;
    td_bool         bRcnRefShareBuf;
    ot_venc_gop_mode enGopMode;
    td_u32          u32FrameRate;
    td_u32          u32Gop;
    td_u32          u32BitRate;
    td_u32          u32LowDelay;
}wk_mpp_venc_t;

typedef struct {
    td_s32 s32Cnt;
    ot_venc_chn VeChn[OT_VENC_MAX_CHN_NUM];
    void *uargs;
    int (*cb)(ot_venc_chn VeChn, ot_payload_type PT, ot_venc_stream* pstStream, void* uargs);
}wk_mpp_recv_t;

enum {
    WK_MPP_VENC_REC_NORMAL = 0,
    WK_MPP_VENC_REC_IDR = 1,
};

typedef struct {
    int filp;
    int a;
}wk_mpp_img_attr;


typedef struct {
    void *uargs;
    int (*cds)(int ViPipe, void* uargs);
    int (*cb)(int ViPipe, int night, void* uargs);
}wk_mpp_ir_t;


enum {
    WK_MPP_ISP_CTL_IR  = 0,    // 0: Day, 1: Night, x: wk_mpp_ir_t
    WK_MPP_ISP_CTL_IMG = 1,    // wk_mpp_img_attr;
};

typedef enum {
    WK_CSC_BRIGTHNESS = 0,
    WK_CSC_CONTRAST,
    WK_CSC_SATURATION,
    WK_CSC_SHARPNESS,
    WK_CSC__BUTT
}WK_CSC_PARAM_E;

typedef enum {
    WK_AE_EXPOSURE_MODE = 0,
    WK_AE_EXPOSURE_ISO,
    WK_AE_EXPOSURE_TIME,
    WK_AE_EXPOSURE_TARGETCOMP,
    WK_AE_EXPOSURE_TIME_AUTO_RANG_MAX,
    WK_AE_EXPOSURE_TIME_AUTO_RANG_MIN,
    WK_AE_EXPOSURE_ISPD_GAIN_AUTO_RANG_MAX,
    WK_AE_EXPOSURE_BUTT
}WK_AE_EXPOSURE_PARAM_E;

typedef enum {
    WK_WB_AUTO= 0,
    WK_WB_CANDELA,         //烛光
    WK_WB_TUNGSTEN,        //钨丝灯
    WK_WB_FLUORESCENCE,    //荧光灯
    WK_WB_DAYLIGHT,        //标准
    WK_WB_CLOUDY,          //多云
    WK_WB_OVERCAST,        //阴天
    WK_WB_BLUESKY,         //蓝天，万里无云的晴天
    WK_WB_BUTT,
}WK_WB_MODE_E;

typedef struct {
    int AeChn;
    ot_payload_type enPayLoad;
    int adtype; // 0:INNER, 1:I2S, 2:PCM;
    int stereo, sp, br;//channels, sampleRate, bitRate;
    void *uargs;
    int (*cb)(int AeChn, ot_payload_type PT, ot_audio_stream *pstStream, void *uargs);
}wk_mpp_aenc_t;

//private for mpp;
extern int SENSOR_TYPE;
extern int SENSOR0_TYPE;
extern int SENSOR1_TYPE;
extern sample_sns_type g_enSnsType[MAX_SENSOR_NUM];
extern ot_isp_sns_obj *g_pstSnsObj[MAX_SENSOR_NUM];
ot_isp_sns_obj *SAMPLE_COMM_ISP_GetSnsObj(td_u32 u32SnsId);

int wk_mpp_start(int mode);
int wk_mpp_cfg(char *path, wk_mpp_cfg_t *cfg, int cfg_num);

//SAMPLE_COMM_VI_StartVi
int wk_mpp_vi_start(wk_mpp_vi_t *vi);
int wk_mpp_vi_stop();
int wk_mpp_vi_get(int ViPipe, int ViChn, ot_video_frame_info *pstFrameInfo, int s32MilliSec);
void wk_mpp_vi_switch_mode(int mode);

//SAMPLE_COMM_VI_Bind_VPSS
int wk_mpp_vpss_start(wk_mpp_vpss_t *vpss);
int wk_mpp_vpss_stop(wk_mpp_vpss_t *vpss);
int wk_mpp_vpss_set_param(int index,td_bool enable,ot_pic_size ensize);
int wk_mpp_vpss_set_filename(char *filename);
void wk_mpp_vpss_get_frame(unsigned char *getbuf, ot_vpss_chn chn);
void wk_mpp_vpss_vgs_scale(unsigned char scale_opt);
int wk_mpp_digital_zoom(unsigned char zoom_step);

//SAMPLE_COMM_VPSS_Bind_VENC
void wk_mpp_record_debug(int option);
int wk_mpp_venc_set_param(int chn_type,ot_pic_size pic_size,td_u32 framerate,td_u32 bitrate);
void wk_mpp_venc_set_payload(int payload_type);
int wk_mpp_venc_start(wk_mpp_venc_t *venc);
int wk_mpp_venc_stop(void);
int wk_mpp_venc_stream_start(ot_venc_chn VencChn);
void wk_mpp_venc_stream_stop(ot_venc_chn VencChn);
int wk_mpp_record_handle(int rec_type,int check_idr);
int wk_mpp_snap_handle(int vencChn, char* snap_path);

//SAMPLE_COMM_VENC_StartGetStream
void wk_mpp_venc_preview_reset(void);
void wk_mpp_set_preview_callback(int (*callback)(unsigned char *pBuf, int length ,WK_FRAME_FLAG_E FrameFlag));
void wk_mpp_set_record_callback(int (*callback)(unsigned char *pBuf, int length));

//isp;
int wk_mpp_scene_start(int scenemode);
int wk_mpp_scene_stop();
void wk_mpp_set_CSCAttr(unsigned char param,unsigned char value);
void wk_mpp_set_ExposureAttr(unsigned char ntype, unsigned int value);
void wk_mpp_set_WBAttr(unsigned char awbmode);
void wk_mpp_get_ExpInfo(int *pshutter, int *piso);
void wk_mpp_get_black_level(int iso);

#endif
