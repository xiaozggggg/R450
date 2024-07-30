#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/poll.h>
#include <sys/time.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>
#include <math.h>
#include <unistd.h>
#include <signal.h>
#include <sys/mman.h>
#include <sys/prctl.h>
#include <dlfcn.h>
#include <linux/fb.h>

#include "ot_type.h"
#include "ot_scene.h"
#include "scene_loadparam.h"
#include "ot_scenecomm_log.h"

#include "ss_mpi_awb.h"
#include "ss_mpi_ae.h"

//#include "hifb.h"
#include "wkmpp.h"

#define SCRIPT_NAME(type) strcasestr(type, "3519")?"load3519dv500":"load3516dv300"

extern td_void SAMPLE_VGS_SetVbConfig(sample_vb_cal_config *pstVbCalConfig);
extern td_s32 SAMPLE_COMM_VPSS_SetRawFilename(char *filename);
extern td_void SAMPLE_COMM_VPSS_GetOneFrame(unsigned char *getbuf, ot_vpss_grp VpssGrp, ot_vpss_chn VpssChn);
extern td_s32 SAMPLE_VGS_Scale(td_s8 stScaleOpt);

extern td_s32 sample_vio_main();

td_u32 wk_mpp_af_start();
td_u32 wk_mpp_auto_iso_blc();

typedef struct {
    int   type;
    char* name;
    char* lib;
    char* obj;
}SAMPLE_MPP_SENSOR_T;

int SENSOR_TYPE;
int SENSOR0_TYPE;
int SENSOR1_TYPE;
int SENSOR2_TYPE;
sample_sns_type g_enSnsType[MAX_SENSOR_NUM];
ot_isp_sns_obj *g_pstSnsObj[MAX_SENSOR_NUM];

static wk_mpp_vpss_t wk_vpss;

wk_mpp_venc_t venc_record;
wk_mpp_venc_t venc_preview;
wk_mpp_venc_t venc_snap;
wk_mpp_venc_t venc_thumbnail;

int sns_mode = 0;
int m_preview_payload;

//svp_dpu
#include "sample_common_dpu.h"
extern ot_sample_svp_dpu_cfg g_dpu_cfg;
extern td_void sample_svp_dpu_set_pic_buf_attr(td_u32 width, td_u32 height,
    ot_pixel_format pixel_format, ot_pic_buf_attr *pic_buf_attr);
extern td_s32 sample_svp_dpu_create_pool(const ot_size *pic_size);
extern td_s32 sample_svp_dpu_start_dpu_rect(const ot_size *src_size, const ot_size *dst_size,
    td_char *lut_file_name[], td_u32 file_num);
extern td_s32 sample_svp_dpu_start_dpu_match(td_u32 width, td_u32 height); 
extern td_s32 sample_svp_dpu_open_file(td_char *src_file_name[OT_DPU_RECT_MAX_PIPE_NUM],
    td_u32 src_file_num, const td_char *match_file_name);
extern void sample_svp_dpu_close_file(td_void);
extern td_void sample_svp_dpu_uninit_dpu_match(td_void);
extern td_void sample_svp_dpu_uninit_dpu_rect(td_void);
extern td_void sample_svp_dpu_sys_uninit_file_case(td_void);
extern td_s32 sample_svp_dpu_proc_frame_from_file(const ot_size *pic_size);
extern void sample_yuv_8bit_dump(const ot_video_frame *video_frame_buf, FILE *pfd);
extern td_s32 sample_comm_vi_read_file_to_sp42_x(FILE *file, ot_video_frame *frame);

static SAMPLE_MPP_SENSOR_T libsns[SNS_TYPE_BUTT] = {
    //{OV_OS04A10_MIPI_4M_30FPS_12BIT, "ov_os04a10-0-0-8-30", "libsns_os04a10.so", "g_sns_os04a10_obj"},
    {SONY_IMX378_MIPI_8M_30FPS_10BIT, "imx378-0-0-8-30", "libsns_imx378.so", "g_sns_imx378_obj"},
    {SONY_IMX378_MIPI_2M_60FPS_10BIT, "imx378-0-0-2-60", "libsns_imx378.so", "g_sns_imx378_obj"},
    {OV_XC9080_MIPI_8M_30FPS_10BIT, "xc9080-0-0-8-30", NULL, NULL},
    {SONY_IMX582_MIPI_8M_30FPS_10BIT, "imx582-0-0-8-30", "libsns_imx582.so", "g_sns_imx582_obj"},
    {OV7251_MIPI_480P_30FPS_10BIT, "ov7251-0-0-8-30", "libsns_ov7251.so", "g_sns_ov7251_obj"},
};

static sample_vb_param g_vb_param = {
    .vb_size = {640, 480},
    .pixel_format = {OT_PIXEL_FORMAT_RGB_BAYER_10BPP, OT_PIXEL_FORMAT_YVU_SEMIPLANAR_420},
    .compress_mode = {OT_COMPRESS_MODE_LINE, OT_COMPRESS_MODE_SEG},
    .video_format = {OT_VIDEO_FORMAT_LINEAR, OT_VIDEO_FORMAT_LINEAR},
    .blk_num = {4, 6}
};

static SAMPLE_MPP_SENSOR_T* SAMPLE_MPP_SERSOR_GET(char* name)
{
    int i = 0;
    for (i = 0; i < SNS_TYPE_BUTT; i++)
    {
        //printf("libsns[%d].name:%s, name:%s\n", i, libsns[i].name, name);
        if(strstr(libsns[i].name, name))
        {
            return &libsns[i];
        }
    }
    return NULL;
}

ot_isp_sns_obj *SAMPLE_COMM_ISP_GetSnsObj(td_u32 u32SnsId)
{
    sample_sns_type enSnsType;

    enSnsType = g_enSnsType[u32SnsId];
    //return g_pstSnsObj[u32SnsId];
    return g_pstSnsObj[0];
}

static void * dl[3] = {NULL};
static wk_mpp_cfg_t cfg[3];
static int snscnt = 0;
static bool wk_mpp_init_flag; //mpp开始标志位
static int wk_scence_mode;

sample_vi_cfg vi_cfg[3];

#include <signal.h>
void SAMPLE_VENC_HandleSig2(td_s32 signo)
{
    signal(SIGINT, SIG_IGN);
    signal(SIGTERM, SIG_IGN);
    signal(SIGSEGV, SIG_IGN);

    if (SIGINT == signo || SIGTERM == signo || SIGSEGV == signo)
    {
        wk_mpp_scene_stop();
        wk_mpp_venc_stop();
        wk_mpp_vpss_stop(&wk_vpss);
        sample_comm_vi_stop_vi(&vi_cfg[0]);
        sample_comm_all_isp_stop();

        sample_comm_sys_exit();
    }
    exit(-1);
}

void wk_mpp_vi_switch_mode(int mode)
{
    wk_mpp_scene_stop();
    wk_mpp_venc_stop();
    wk_mpp_vpss_stop(&wk_vpss);
    sample_comm_vi_stop_vi(&vi_cfg[0]);
    // sample_comm_vi_stop_vi(&vi_cfg[1]);
    // sample_comm_vi_stop_vi(&vi_cfg[2]);
    sample_comm_sys_exit();

    sns_mode = mode;

    wk_mpp_start(mode);
    wk_mpp_venc_stream_start(WK_VIDEO_CHANNEL_PREVIEW);

    return 0;
}

int wk_mpp_cfg_sns(char *path, wk_mpp_cfg_t *cfg, int cfg_num)
{
    int i = 0;
    char snsstr[64];
    sprintf(snsstr, "%s-%d-%d-%d-%d"
            , cfg->snsname, cfg->lane, cfg->wdr, cfg->res, cfg->fps);
    printf("[%s] --> snsstr[%s]\n",__func__,snsstr);

    SAMPLE_MPP_SENSOR_T* sns = SAMPLE_MPP_SERSOR_GET(snsstr);
    if(!sns)
    {
        printf("%s => snsstr:%s, unknow.\n", __func__, snsstr);
        return -1;
    }

    snscnt = cfg->snscnt;
    char loadstr[256];
    if(strstr(cfg->snsname, "bt1120"))
        sprintf(loadstr, "%s/ko/%s -i -yuv0 1", path, SCRIPT_NAME(cfg->type));
    else
        sprintf(loadstr, "%s/ko/%s -i -sensor0 %s", path, SCRIPT_NAME(cfg->type), "os04a10");

    if(cfg->second && cfg->snscnt == 1 && !strstr(cfg->snsname, "bt1120"))
    {
        sprintf(loadstr, "%s -yuv0 2", loadstr);
    }

    printf("%s => loadstr: %s\n", __func__, loadstr);
    system(loadstr); 

    SENSOR_TYPE = SENSOR0_TYPE = SENSOR1_TYPE = sns->type;
    if(cfg_num == 0) {
        SENSOR_TYPE = SENSOR0_TYPE = sns->type;
    } else if (cfg_num == 1){
        SENSOR_TYPE = SENSOR1_TYPE = sns->type;
    }
    else if (cfg_num == 2){
        SENSOR_TYPE = SENSOR2_TYPE = sns->type;        
    }

    if(dl[cfg_num])
    {
        dlclose(dl[cfg_num]);
        dlerror();
    }

    if(sns->lib)
    {
        dl[cfg_num] = dlopen(sns->lib, RTLD_LAZY);
        if (dl[cfg_num] == NULL)
        {
            printf("err dlopen %s -%s\n", sns->lib, dlerror());
            goto __err;
        }
        printf("========= dlopen success \n");

        if(cfg_num == 0) {
            g_pstSnsObj[0] = dlsym(dl[cfg_num], sns->obj);
        } else if(cfg_num == 1) {
            g_pstSnsObj[1] = dlsym(dl[cfg_num], sns->obj);
        } else if(cfg_num == 2) {
            g_pstSnsObj[2] = dlsym(dl[cfg_num], sns->obj);
        }
        
        if(NULL != dlerror())
        {
            printf("err dlsym %s\n", sns->obj);
            goto __err;
        }
    }
    printf("%s => snsstr:%s, sensor_type:%d, load:%s\n"
        , __func__, snsstr, SENSOR_TYPE, sns->lib?:"");

    signal(SIGINT, SAMPLE_VENC_HandleSig2);
    signal(SIGTERM, SAMPLE_VENC_HandleSig2);
    signal(SIGSEGV, SAMPLE_VENC_HandleSig2);
  
    return 0;
__err:
    if (dl[cfg_num])
    {
        dlclose(dl[cfg_num]);
    }
    dlerror();
    return -1;
}

int wk_mpp_start(int mode)
{
    char home_path[256] = {0};
    
    int cfg_num = 1;
    int i = 0;

    const ot_isp_sns_type *pstSnsObj;

    wk_mpp_vi_t vi = {
        .bLowDelay = TD_FALSE,
        .u32SupplementConfig = OT_VB_SUPPLEMENT_JPEG_MASK,
    };

    wk_mpp_init_flag = false;

    /**********************************imx700************************************/
    strcpy(cfg[0].snsname, "ov7251"); // imx582 imx378 imx415 ov48 imx700 XC9080 ov680
    cfg[0].snscnt = 1;

    char *chipid = "3519"; // [3516a300 3516d300 35590200 3403 3519]
    printf("chipid[%s]-cfg[0].snsname[%s] mode[%d]\n", chipid, cfg[0].snsname, mode);
    strcpy(cfg[0].type, chipid);
    //second channel from bsp_def.json; [0: disable, 1: BT656.PAL, 2:BT656.NTSC, 3: BT601.GD]
    printf("BOARD [type:%s, snscnt:%d]\n", cfg[0].type, cfg[0].snscnt);

    sns_mode = mode;
    wk_scence_mode = 0;
    
    cfg[0].lane = 0;
    cfg[0].wdr = 0;
    cfg[0].res = 8;
    cfg[0].fps = 30;


    sprintf(home_path, "/root");
    printf("home_path:[%s]\n", home_path);

    for(i=0; i<cfg_num; i++) {
        wk_mpp_cfg(home_path, &cfg[i], i);
    }

    // vi start;
    printf("[LIB] ================== start vi ==================\n");
    wk_mpp_vi_start(&vi);

    // vpss start;
    printf("[LIB] ================== start vpss ==================\n");

    for(i=0; i<OT_VPSS_MAX_PHYS_CHN_NUM; i++){
        wk_vpss.enable[i] = TD_FALSE;
    }

    wk_mpp_vpss_set_param(WK_VIDEO_CHANNEL_RECORD, TD_TRUE, PIC_640X480);
    sample_comm_venc_set_src_framerate(30);

    wk_mpp_vpss_set_param(WK_VIDEO_CHANNEL_PREVIEW, TD_TRUE, PIC_640X480);
    // wk_mpp_vpss_set_param(2,TD_TRUE,PIC_CIF);
    wk_mpp_vpss_start(&wk_vpss);

    // printf("[LIB] ================== start DCF ==================\n");
    // WK_COMM_VENC_SetDCFInfo(0);

    wk_mpp_init_flag = true;
}

int wk_mpp_cfg(char *path, wk_mpp_cfg_t *cfg, int cfg_num)
{
    if(cfg && cfg->snscnt > 0){
        return wk_mpp_cfg_sns(path, cfg, cfg_num);
    }
    else{
        return -1;
    }
}

//======================= vi =====================//
/**
 * @brief walkera add for vgs
 * 
 * @param pstVbBaseInfo 
 * @param pstVbCalConfig 
 * @return HI_VOID 
 */
static td_void SAMPLE_VGS_GetYUVBufferCfg(ot_vb_calc_cfg *pstVbCalConfig)
{
    ot_pic_buf_attr buf_attr;

    buf_attr.width         = 1280;
    buf_attr.height        = 720;
    buf_attr.align         = 2;
    buf_attr.bit_width     = OT_DATA_BIT_WIDTH_8;
    buf_attr.pixel_format  = OT_PIXEL_FORMAT_YVU_SEMIPLANAR_420;
    buf_attr.compress_mode = OT_COMPRESS_MODE_NONE;
    buf_attr.video_format  = OT_VIDEO_FORMAT_LINEAR;

    ot_common_get_pic_buf_cfg(&buf_attr, pstVbCalConfig);

    return;
}

static td_void wk_mpp_get_default_vb_config(ot_size *size, ot_vb_cfg *vb_cfg)
{
    ot_pic_buf_attr buf_attr;
    ot_vb_calc_cfg calc_cfg;
    td_s32 i;

    (td_void)memset_s(vb_cfg, sizeof(ot_vb_cfg), 0, sizeof(ot_vb_cfg));
    vb_cfg->max_pool_cnt = 128; /* 128 blks */

    buf_attr.width         = size->width;
    buf_attr.height        = size->height;
    buf_attr.align         = OT_DEFAULT_ALIGN;
    buf_attr.bit_width     = OT_DATA_BIT_WIDTH_8;
    buf_attr.pixel_format  = OT_PIXEL_FORMAT_YVU_SEMIPLANAR_420;
    buf_attr.compress_mode = OT_COMPRESS_MODE_NONE;
    ot_common_get_pic_buf_cfg(&buf_attr, &calc_cfg);

    vb_cfg->common_pool[0].blk_size = calc_cfg.vb_size;
    vb_cfg->common_pool[0].blk_cnt  = 20; /* 42 blks */   

    printf("============ SAMPLE_VGS_GetYUVBufferCfg start\n");
    SAMPLE_VGS_GetYUVBufferCfg(&calc_cfg);
    vb_cfg->common_pool[1].blk_size = calc_cfg.vb_size;
    vb_cfg->common_pool[1].blk_cnt = 2;
    SAMPLE_VGS_SetVbConfig(&calc_cfg);
    printf("============ SAMPLE_VGS_GetYUVBufferCfg blk_size[%d] end\n", calc_cfg.vb_size);
}

static td_s32 wk_mpp_vb_init(ot_vi_vpss_mode_type mode_type, ot_vi_aiisp_mode video_mode)
{
    td_s32 ret;
    ot_size size;
    ot_vb_cfg vb_cfg;
    td_u32 supplement_config;

    size.width = 1280;  /* 3840 pixel */
    size.height = 720; /* 2160 line */

    wk_mpp_get_default_vb_config(&size, &vb_cfg);

    supplement_config = OT_VB_SUPPLEMENT_BNR_MOT_MASK | OT_VB_SUPPLEMENT_MOTION_DATA_MASK | OT_VB_SUPPLEMENT_JPEG_MASK;
    ret = sample_comm_sys_init_with_vb_supplement(&vb_cfg, supplement_config);
    if (ret != TD_SUCCESS) {
        return TD_FAILURE;
    }

    return TD_SUCCESS;
}

int wk_mpp_vi_start(wk_mpp_vi_t *vi)
{  
    td_s32 s32Ret, i;
    ot_vi_vpss_mode_type mode_type = OT_VI_OFFLINE_VPSS_OFFLINE; // OT_VI_ONLINE_VPSS_OFFLINE;
    ot_vi_aiisp_mode video_mode = OT_VI_AIISP_MODE_DEFAULT;
    ot_vi_dev vi_dev = 2;   /* dev3 for xc9080 */
    ot_vi_pipe vi_pipe = 2; /* dev2 bind pipe1 */
    const ot_vi_chn vi_chn = 0;
    ot_vpss_grp vpss_grp = 0;
    const ot_vpss_chn vpss_chn = 0;
    sample_sns_type sns_type[3];

    s32Ret = wk_mpp_vb_init(mode_type, video_mode);
    if (s32Ret != TD_SUCCESS) {
        goto sys_init_failed;
    }

    s32Ret = sample_comm_vi_set_vi_vpss_mode(mode_type, video_mode);
    if (s32Ret != TD_SUCCESS) {
        return TD_FAILURE;
    }

    sns_type[0] = SENSOR0_TYPE;
    sns_type[1] = SENSOR1_TYPE;
    sns_type[2] = SENSOR1_TYPE; //都是SENSOR1_TYPE XC9080前后避障

    sample_comm_vi_get_default_vi_cfg(sns_type[0], &vi_cfg[0]);   

    vi_cfg[0].sns_info.bus_id = 6;

    // xc9080
    vi_cfg[0].mipi_info.divide_mode = LANE_DIVIDE_MODE_0;

    s32Ret = sample_comm_vi_start_vi(&vi_cfg[0]);
    if (s32Ret != TD_SUCCESS) {
        goto start_vi_failed;
    }

    return TD_SUCCESS;

start_vi_failed:
    sample_comm_vi_stop_vi(&vi_cfg[0]);
sys_init_failed:
    return TD_FAILURE;
}

int wk_mpp_vi_stop()
{
    td_s32 s32Ret;

    sample_comm_vi_stop_vi(&vi_cfg);
    sample_comm_sys_exit();

    return s32Ret;
}

//===================== vpss ==================//
int wk_mpp_vpss_set_param(int index,td_bool enable,ot_pic_size ensize)
{
    td_s32 s32Ret;

    wk_vpss.srcModId = OT_ID_VI;
    wk_vpss.VpssGrp = 0;
    wk_vpss.ViChn = 0;
    wk_vpss.ViPipe = 0;

    if(index < OT_VPSS_MAX_PHYS_CHN_NUM){
        wk_vpss.enable[index] = enable;
        wk_vpss.enSize[index] = ensize;

        s32Ret = TD_SUCCESS;
    }
    else{
        s32Ret = TD_FAILURE;
    }

    return s32Ret;
}

int wk_mpp_vpss_set_filename(char *filename)
{
   return SAMPLE_COMM_VPSS_SetRawFilename(filename);
}

//VPSS 获取某一通道图像数据
void wk_mpp_vpss_get_frame(unsigned char *getbuf, ot_vpss_chn chn)
{
    SAMPLE_COMM_VPSS_GetOneFrame(getbuf, 0, chn);
}

void wk_mpp_vpss_vgs_scale(unsigned char scale_opt)
{
    SAMPLE_VGS_Scale(scale_opt);
}

unsigned char m_zoom_step;
int wk_mpp_vpss_ctl(int VpssGrp, int id, void *args)
{
    int ret = -1;
    // switch(id)
    // {
    // case WK_MPP_VPSS_CTL_CROP:
    //     ret = HI_MPI_VPSS_SetGrpCrop(VpssGrp, (VPSS_CROP_INFO_S*)args);
    //     if(ret)
    //         printf("WK_MPP_VPSS_CTL_CROP VpssGrp:%d, err 0x%x\n", VpssGrp, ret);
    //     break;

    // default:
    //     break;
    // }
    return ret;
}

int wk_mpp_digital_zoom(unsigned char zoom_step)
{
    int ret;
    int step;
    // VPSS_CROP_INFO_S stcrop;

    // if(m_zoom_step != zoom_step){
    //     step = zoom_step % ZOOM_STEPS;

    //     //可视光缩放
    //     stcrop.bEnable = HI_TRUE;
    //     stcrop.enCropCoordinate = VPSS_CROP_ABS_COOR;
    //     stcrop.stCropRect.s32X = ALIGN_UP((int)step*VISUAL_STEP_X, 2);
    //     stcrop.stCropRect.s32Y = ALIGN_UP((int)step*VISUAL_STEP_Y, 2);
    //     stcrop.stCropRect.u32Width = ALIGN_UP((int)(3840 - stcrop.stCropRect.s32X*2), 2);
    //     stcrop.stCropRect.u32Height = ALIGN_UP((int)(2160 - stcrop.stCropRect.s32Y*2), 2);
    //     ret = wk_mpp_vpss_ctl(0, WK_MPP_VPSS_CTL_CROP, &stcrop);

    //     m_zoom_step = zoom_step;
    // }

    return m_zoom_step;
}

int wk_mpp_vpss_start(wk_mpp_vpss_t *vpss)
{
    td_s32 i, s32Ret;
    ot_low_delay_info low_delay_info;
    ot_vpss_grp_attr grp_attr;
    ot_vpss_chn_attr chn_attr;
    ot_size in_size;

    sample_vpss_chn_attr vpss_chn_attr;

    sample_comm_vi_bind_vpss(vpss->ViPipe, 0, vpss->VpssGrp, 0);

    for(i=0; i<OT_VPSS_MAX_PHYS_CHN_NUM; i++) {
        if(!vpss->enable[i]){
            vpss_chn_attr.chn_enable[i] = TD_FALSE;
            continue;
        }

        sample_comm_sys_get_pic_size(vpss->enSize[i], &in_size);
        if(i == 0){
            sample_comm_vpss_get_default_grp_attr(&grp_attr);
            grp_attr.max_width = in_size.width;
            grp_attr.max_height = in_size.height;
        }

        sample_comm_vpss_get_default_chn_attr(&chn_attr);
        chn_attr.width = in_size.width;
        chn_attr.height = in_size.height;
        chn_attr.compress_mode = OT_COMPRESS_MODE_NONE;

        memcpy(&vpss_chn_attr.chn_attr[i], &chn_attr, sizeof(ot_vpss_chn_attr));
        vpss_chn_attr.chn_enable[i] = TD_TRUE;
        vpss_chn_attr.chn_array_size = OT_VPSS_MAX_PHYS_CHN_NUM;
        vpss_chn_attr.chn0_wrap = TD_FALSE;

        printf("====== i = [%d] width[%d] height[%d]\n", i, in_size.width, in_size.height);
    }

    s32Ret = sample_common_vpss_start(vpss->VpssGrp, &grp_attr, &vpss_chn_attr);
    if (s32Ret != TD_SUCCESS) {
        return s32Ret;
    }

    low_delay_info.enable     = TD_TRUE;
    low_delay_info.line_cnt   = 200; /* 200: lowdelay line */
    low_delay_info.one_buf_en = TD_FALSE;
    s32Ret = ss_mpi_vpss_set_chn_low_delay(vpss->VpssGrp, 0, &low_delay_info);
    if (s32Ret != TD_SUCCESS) {
        sample_common_vpss_stop(vpss->VpssGrp, vpss_chn_attr.chn_enable, OT_VPSS_MAX_PHYS_CHN_NUM);
        return s32Ret;
    }

    return s32Ret;
}

int wk_mpp_vpss_stop(wk_mpp_vpss_t *vpss)
{
    td_s32 s32Ret = 0;

    if(vpss->ViPipe >= 0){
        sample_comm_vi_un_bind_vpss(vpss->ViPipe, vpss->ViChn, vpss->VpssGrp, 0);
        sample_comm_vi_un_bind_vpss(vpss->ViPipe, vpss->ViChn, vpss->VpssGrp, 1);
    }

    sample_common_vpss_stop(vpss->VpssGrp, vpss->enable, OT_VPSS_MAX_PHYS_CHN_NUM);
    return s32Ret;
}

//================= venc =================//
int wk_mpp_venc_set_param(int chn_type,ot_pic_size pic_size,td_u32 framerate,td_u32 bitrate)
{
    switch(chn_type)
    {
    case WK_VIDEO_CHANNEL_RECORD:
        venc_record.VencChn         = WK_VIDEO_CHANNEL_RECORD;
        venc_record.srcModId        = OT_ID_VPSS;
        venc_record.VpssGrp         = 0;
        venc_record.VpssChn         = WK_VIDEO_CHANNEL_RECORD;
        venc_record.enPayLoad       = OT_PT_H264;
        venc_record.enSize          = pic_size;
        venc_record.enRcMode        = SAMPLE_RC_CBR;
        venc_record.u32Profile      = 0;
        venc_record.bRcnRefShareBuf = TD_TRUE;
        venc_record.enGopMode       = OT_VENC_GOP_MODE_NORMAL_P;
        venc_record.u32FrameRate    = framerate;
        venc_record.u32Gop          = framerate;
        venc_record.u32BitRate      = bitrate;
        venc_record.u32LowDelay     = TD_FALSE;
        break;

    case WK_VIDEO_CHANNEL_PREVIEW:
        venc_preview.VencChn         = WK_VIDEO_CHANNEL_PREVIEW;
        venc_preview.srcModId        = OT_ID_VPSS;
        venc_preview.VpssGrp         = 0;
        venc_preview.VpssChn         = WK_VIDEO_CHANNEL_RECORD;
        // if(m_preview_payload == 0){
        //     venc_preview.enPayLoad   = OT_PT_H264;
        // }
        // else{
        //     venc_preview.enPayLoad   = OT_PT_H265;
        // }
        venc_preview.enPayLoad       = OT_PT_H264;
        venc_preview.enSize          = pic_size;
        venc_preview.enRcMode        = SAMPLE_RC_CBR; //SAMPLE_RC_CVBR;
        venc_preview.u32Profile      = 0;
        venc_preview.bRcnRefShareBuf = TD_FALSE;
        venc_preview.enGopMode       = OT_VENC_GOP_MODE_NORMAL_P;
        venc_preview.u32FrameRate    = framerate;
        venc_preview.u32Gop          = framerate*2;
        venc_preview.u32BitRate      = bitrate;
        venc_preview.u32LowDelay     = TD_FALSE;
        break;

    case WK_VIDEO_CHANNEL_SNAP:
        venc_snap.VencChn         = WK_VIDEO_CHANNEL_SNAP;
        venc_snap.srcModId        = OT_ID_VGS;
        venc_snap.VpssGrp         = 0;
        venc_snap.VpssChn         = WK_VIDEO_CHANNEL_RECORD;
        venc_snap.enPayLoad       = OT_PT_JPEG;
        venc_snap.enSize          = pic_size;
        venc_snap.enRcMode        = SAMPLE_RC_CBR;
        venc_snap.u32Profile      = 0;
        venc_snap.bRcnRefShareBuf = TD_TRUE;
        venc_snap.enGopMode       = OT_VENC_GOP_MODE_NORMAL_P;
        venc_snap.u32FrameRate    = framerate;
        venc_snap.u32Gop          = framerate;
        venc_snap.u32BitRate      = bitrate;
        venc_snap.u32LowDelay     = TD_FALSE;
        break;

    case WK_VIDEO_CHANNEL_THUMBNAIL:
        venc_thumbnail.VencChn         = WK_VIDEO_CHANNEL_THUMBNAIL;
        venc_thumbnail.srcModId        = OT_ID_VPSS;
        venc_thumbnail.VpssGrp         = 0;
        venc_thumbnail.VpssChn         = WK_VIDEO_CHANNEL_RECORD;
        venc_thumbnail.enPayLoad       = OT_PT_JPEG;
        venc_thumbnail.enSize          = pic_size;
        venc_thumbnail.enRcMode        = SAMPLE_RC_CBR;
        venc_thumbnail.u32Profile      = 0;
        venc_thumbnail.bRcnRefShareBuf = TD_TRUE;
        venc_thumbnail.enGopMode       = OT_VENC_GOP_MODE_NORMAL_P;
        venc_thumbnail.u32FrameRate    = framerate;
        venc_thumbnail.u32Gop          = framerate;
        venc_thumbnail.u32BitRate      = bitrate;
        venc_thumbnail.u32LowDelay     = TD_FALSE;
        break;
    
    default:
        break;
    }

    return 1;
}

void wk_mpp_venc_set_payload(int payload_type)
{
    m_preview_payload = payload_type;
}

int wk_mpp_venc_start(wk_mpp_venc_t *venc)
{
    td_s32 s32Ret;
    ot_venc_gop_attr stGopAttr;
    ot_size in_size;

    sample_comm_sys_get_pic_size(venc->enSize, &in_size);

    sample_comm_venc_chn_param g_venc_chn_param;
    g_venc_chn_param.bitrate              = venc->u32BitRate;
    g_venc_chn_param.frame_rate           = venc->u32FrameRate;
    if(WK_VIDEO_CHANNEL_PREVIEW == venc->VencChn){
        g_venc_chn_param.stats_time           = 2;
    }
    else{
        g_venc_chn_param.stats_time           = 1;
    }
    g_venc_chn_param.gop                  = venc->u32Gop;
    g_venc_chn_param.venc_size.width      = in_size.width;
    g_venc_chn_param.venc_size.height     = in_size.height;
    g_venc_chn_param.size                 = venc->enSize;
    g_venc_chn_param.profile              = venc->u32Profile;
    g_venc_chn_param.is_rcn_ref_share_buf = venc->bRcnRefShareBuf;
    g_venc_chn_param.gop_attr.gop_mode    = venc->enGopMode;
    g_venc_chn_param.gop_attr.normal_p.ip_qp_delta    = 2;
    g_venc_chn_param.type                 = venc->enPayLoad;
    g_venc_chn_param.rc_mode              = venc->enRcMode;

    printf("venc start chn[%d] payload[%d] framerate[%d] bitrate[%d]\n", venc->VencChn, g_venc_chn_param.type, g_venc_chn_param.frame_rate, g_venc_chn_param.bitrate);
    printf("venc start width[%d] height[%d]\n", g_venc_chn_param.venc_size.width, g_venc_chn_param.venc_size.height);
    printf("venc start size[%d] profile[%d]\n",g_venc_chn_param.size, g_venc_chn_param.profile);
    
    if(OT_PT_JPEG == venc->enPayLoad) {    //抓拍通道创建
        s32Ret = WK_COMM_VENC_SnapStart(venc->VencChn, venc->enSize);
    }
    else{
        s32Ret = sample_comm_venc_start(venc->VencChn, &g_venc_chn_param);
    }

    if (s32Ret != TD_SUCCESS) {
        printf("sample_comm_venc_start ch[%d] failed.\n", venc->VencChn);
        goto EXIT_VI_VPSS_UNBIND;
    }

    sample_comm_vpss_bind_venc(venc->VpssGrp, venc->VpssChn, venc->VencChn);

    return s32Ret;

EXIT_VI_VPSS_UNBIND:
    return s32Ret;
}

int wk_mpp_venc_set_IntraRefresh(ot_venc_chn VencChn)
{
    ot_venc_intra_refresh  stIntraRefresh;
    ot_venc_intra_refresh_mode   enIntraRefreshMode;
    td_s32          s32Ret;

    s32Ret = ss_mpi_venc_get_intra_refresh(VencChn, &stIntraRefresh);
    if (TD_SUCCESS != s32Ret)
    {
        sample_print("Get Intra Refresh failed for %#x!\n", s32Ret);
        return s32Ret;
    }

    enIntraRefreshMode = OT_VENC_INTRA_REFRESH_ROW;
    stIntraRefresh.enable = TD_TRUE;
    stIntraRefresh.mode = enIntraRefreshMode;
    stIntraRefresh.refresh_num = (3000 + 15) >> 8;
    printf("===== u32RefreshNum[%d]\n", stIntraRefresh.refresh_num);
    stIntraRefresh.request_i_qp = 30;
    s32Ret = ss_mpi_venc_set_intra_refresh(VencChn, &stIntraRefresh);
    if (TD_SUCCESS != s32Ret)
    {
        sample_print("Set Intra Refresh failed for %#x!\n", s32Ret);
        return s32Ret;
    }

    sample_print("==ss_mpi_venc_set_intra_refresh [%d]\n ", s32Ret);

    return s32Ret;
}

void wk_mpp_venc_setRcParam(ot_venc_chn VencChn)
{
    td_s32 s32Ret;
    ot_venc_rc_param stRcParam;

    s32Ret = ss_mpi_venc_get_rc_param(VencChn, &stRcParam);
    if(m_preview_payload == 1){
        stRcParam.h265_cbr_param.min_i_qp = 20;
        stRcParam.h265_cbr_param.max_i_qp = 30;

        stRcParam.h265_cbr_param.min_qp = 20;
        stRcParam.h265_cbr_param.max_qp = 30;
    }
    else{
        stRcParam.h264_cbr_param.min_i_qp = 18;
        stRcParam.h264_cbr_param.max_i_qp = 40;

        stRcParam.h264_cbr_param.min_qp = 18;
        stRcParam.h264_cbr_param.max_qp = 40;
    }

    s32Ret = ss_mpi_venc_set_rc_param(VencChn, &stRcParam);
    if (TD_SUCCESS != s32Ret)
    {
        sample_print("ss_mpi_venc_set_rc_param failed for %#x!\n", s32Ret);
        return s32Ret;
    }

    sample_print("==ss_mpi_venc_set_rc_param [%d]\n ", s32Ret);
}


int wk_mpp_venc_stream_start(ot_venc_chn VencChn)
{
    td_s32 s32Ret;

    switch (VencChn)
    {
    case WK_VIDEO_CHANNEL_RECORD:
        wk_mpp_venc_start(&venc_record);

        s32Ret = WK_COMM_VENC_GetStreamStart(VencChn);
        if (TD_SUCCESS != s32Ret)
        {
            sample_print("Venc Get GopAttr failed for %#x!\n", s32Ret);
            sample_comm_venc_stop(VencChn);
        }
        break;

    case WK_VIDEO_CHANNEL_PREVIEW:
        wk_mpp_venc_start(&venc_preview);
        wk_mpp_venc_set_IntraRefresh(VencChn);
        wk_mpp_venc_setRcParam(VencChn);

        s32Ret = WK_COMM_VENC_GetStreamStart(VencChn);
        if (TD_SUCCESS != s32Ret)
        {
            sample_print("Venc Get GopAttr failed for %#x!\n", s32Ret);
            sample_comm_venc_stop(VencChn);
        }
        break;

    case WK_VIDEO_CHANNEL_SNAP:
        wk_mpp_venc_start(&venc_snap);
        break;
    
    default:
        break;
    }

    return s32Ret;
}

void wk_mpp_venc_stream_stop(ot_venc_chn VencChn)
{
    sample_comm_venc_stop(VencChn);
    sample_comm_vpss_un_bind_venc(0, 0, VencChn);
}

void wk_mpp_venc_preview_reset(void)
{
    //mpp开启后再执行相关配置，防止配置未开启的模块导致崩溃
    if(!wk_mpp_init_flag){
        return;
    }

    if(venc_record.VpssGrp >= 0){
        sample_comm_vpss_un_bind_venc(venc_preview.VpssGrp, venc_preview.VpssChn, venc_preview.VencChn);
    }
    WK_COMM_VENC_PreviewStop();
    usleep(500*1000);

    wk_mpp_venc_stream_start(WK_VIDEO_CHANNEL_PREVIEW);
}

int wk_mpp_venc_stop(void)
{
    td_s32 s32Ret;

    WK_COMM_VENC_StopCHN();

    if(venc_record.VpssGrp >= 0){
        sample_comm_vpss_un_bind_venc(venc_record.VpssGrp, venc_record.VpssChn, venc_record.VencChn);
        sample_comm_vpss_un_bind_venc(venc_preview.VpssGrp, venc_preview.VpssChn, venc_preview.VencChn);
        sample_comm_vpss_un_bind_venc(venc_snap.VpssGrp, venc_snap.VpssChn, venc_snap.VencChn);
    }

    return s32Ret;
}

//================= record/preview/snap operation =====================//
void wk_mpp_set_preview_callback(int (*callback)(unsigned char *pBuf, int length ,WK_FRAME_FLAG_E FrameFlag))
{
    WK_COMM_VENC_SetPreviewCallback(callback);
}

void wk_mpp_set_record_callback(int (*callback)(unsigned char *pBuf, int length))
{
    WK_COMM_VENC_SetRecordCallback(callback);
}

int wk_mpp_record_handle(int rec_type, int check_idr)
{
    td_s32 s32Ret;
    int frame_size = 0;

    if(rec_type == WK_MPP_VENC_REC_IDR){
        WK_COMM_VENC_GetIDR(WK_VIDEO_CHANNEL_RECORD);
    }

    s32Ret = WK_COMM_VENC_GetRecordStreamHandle(&frame_size, check_idr);
    if(TD_SUCCESS != s32Ret){
        ot_usleep(100*1000);
    }

    return frame_size;
}

int wk_mpp_snap_handle(int vencChn, char* snap_path)
{
    td_s32 s32Ret;

    s32Ret = WK_COMM_VENC_SnapJpegHandle((ot_venc_chn)vencChn, snap_path);
    if(TD_SUCCESS != s32Ret){
        ot_usleep(100*1000);
    }

    return s32Ret;
}

//=================== isp parameter  ======================//
int wk_mpp_scene_start(int scenemode)
{
    char *inipath;
    td_s32 s32ret = TD_SUCCESS;
    ot_scene_param stSceneParam;
    ot_scene_video_mode stVideoMode;

    wk_scence_mode = 0; //scenemode;
    printf("=========== wk_scence_mode[%d]\n", wk_scence_mode);

    inipath = "param/sensor_os04a10";
    s32ret = ot_scene_create_param(inipath, &stSceneParam, &stVideoMode);
    if (TD_SUCCESS != s32ret)
    {
        printf("SCENETOOL_CreateParam failed\n");
        return TD_FAILURE;
    }
    s32ret = ot_scene_init(&stSceneParam);
    if (TD_SUCCESS != s32ret)
    {
        printf("ot_scene_init failed\n");
        return TD_FAILURE;
    }

    s32ret = ot_scene_set_scene_mode(&(stVideoMode.video_mode[scenemode]));
    if (TD_SUCCESS != s32ret)
    {
        printf("HI_SRDK_SCENEAUTO_Start failed\n");
        return TD_FAILURE;
    }

    s32ret = ot_scene_pause(TD_FALSE);
    if (s32ret != TD_SUCCESS) {
        printf("OT_SCENE_Resume failed\n");
        return TD_FAILURE;
    }
    printf("The sceneauto is started.\n");

    return s32ret;
}

int wk_mpp_scene_stop()
{
    td_s32 s32ret = TD_SUCCESS;
    s32ret = ot_scene_deinit();
    if (TD_SUCCESS != s32ret)
    {
        printf("ot_scene_deinit failed\n");
        return TD_FAILURE;
    }

    return s32ret;
}


void wk_mpp_set_CSCAttr(unsigned char param,unsigned char value)
{
    td_s32 s32Ret;
    ot_vi_pipe ViPipe = 0;
    ot_isp_csc_attr nstCSCAttr;

    s32Ret = ss_mpi_isp_get_csc_attr(ViPipe, &nstCSCAttr);
    if(s32Ret != TD_SUCCESS){
        sample_print("ISP Get CSCAttr failed for %#x!\n", s32Ret);
    }

    //输入value范围:[0-255]  需要转换为[0-100]
    switch(param)
    {
    case WK_CSC_BRIGTHNESS:
        nstCSCAttr.luma = value * 100 / 255;
        break;

    case WK_CSC_CONTRAST:
        nstCSCAttr.contr = value * 100 / 255;
        break;

    case WK_CSC_SATURATION:
        nstCSCAttr.satu = value * 100 / 255;
        break;

    case WK_CSC_SHARPNESS:
        nstCSCAttr.hue = value * 100 / 255;
        break;

    default:
        break;
    }

    s32Ret = ss_mpi_isp_set_csc_attr(ViPipe, &nstCSCAttr);
    if(s32Ret != TD_SUCCESS){
        sample_print("ISP Set CSCAttr failed for %#x!\n", s32Ret);
    }
}

void wk_mpp_set_ExposureAttr(unsigned char ntype, unsigned int value)
{
    td_s32 s32Ret;
    ot_vi_pipe ViPipe = 0;
    ot_isp_exposure_attr stExposureAttr;

    s32Ret = ss_mpi_isp_get_exposure_attr(ViPipe, &stExposureAttr);
    if(s32Ret != TD_SUCCESS){
        sample_print("ISP Get ExposureAttr failed for %#x!\n", s32Ret);
    }

    switch(ntype)
    {
    case WK_AE_EXPOSURE_MODE:
        if(value == 1){
            stExposureAttr.op_type = OT_OP_MODE_MANUAL;
            stExposureAttr.manual_attr.exp_time_op_type = OT_OP_MODE_MANUAL;
            stExposureAttr.manual_attr.a_gain_op_type = OT_OP_MODE_MANUAL;
            stExposureAttr.manual_attr.d_gain_op_type = OT_OP_MODE_MANUAL;
            stExposureAttr.manual_attr.ispd_gain_op_type = OT_OP_MODE_MANUAL;
            stExposureAttr.manual_attr.isp_d_gain = 1024;
        }
        else{
            stExposureAttr.op_type = OT_OP_MODE_AUTO;
        }
        break;

    case WK_AE_EXPOSURE_ISO:
        if(OT_OP_MODE_MANUAL == stExposureAttr.op_type){
            stExposureAttr.manual_attr.a_gain = value * 1024;
        }
        break;

    case WK_AE_EXPOSURE_TIME:
        if(OT_OP_MODE_MANUAL == stExposureAttr.op_type){
            stExposureAttr.manual_attr.exp_time = value;
        }
        break;

    // case WK_AE_EXPOSURE_TARGETCOMP:
    //     if(OP_TYPE_AUTO == stExposureAttr.enOpType){ 
    //         stExposureAttr.stAuto.u8Compensation = value;
    //     }
    //     break;

    default:
        break;
    }

    s32Ret = ss_mpi_isp_set_exposure_attr(ViPipe, &stExposureAttr);
    if(s32Ret != TD_SUCCESS){
        sample_print("ISP Set ExposureAttr failed for %#x!\n", s32Ret);
    }
}

void wk_mpp_set_WBAttr(unsigned char awbmode)
{
    td_s32 s32Ret;
    ot_vi_pipe ViPipe = 0;
    ot_isp_wb_attr stWBAttr;
    ot_isp_awb_attr_ex stAWBEXAttr;

    s32Ret = ss_mpi_isp_get_wb_attr(ViPipe, &stWBAttr);
    if(s32Ret != TD_SUCCESS){
        sample_print("ISP Get WBAttr failed for %#x!\n", s32Ret);
        return;
    }

    s32Ret = ss_mpi_isp_get_awb_attr_ex(ViPipe, &stAWBEXAttr);
    if(s32Ret != TD_SUCCESS){
        sample_print("ISP Get AWBExAttr failed for %#x!\n", s32Ret);
        return;
    }

    stAWBEXAttr.tolerance = 4;
    stAWBEXAttr.in_or_out.out_thresh = 30000;
    stAWBEXAttr.in_or_out.high_start = 5500;
    stAWBEXAttr.in_or_out.high_stop = 6500;
    stAWBEXAttr.in_or_out.low_start = 4500;
    stAWBEXAttr.in_or_out.low_stop = 4000;

    OT_PRINT("[LIB] --> wk_mpp_set_WBAttr [%d]\n",awbmode);
    if(WK_WB_AUTO == awbmode){
        stWBAttr.op_type = OT_OP_MODE_AUTO;
        stWBAttr.auto_attr.speed = 128;
    }
    else{
        stWBAttr.op_type = OT_OP_MODE_MANUAL;
    }

    switch (awbmode)
    {
    case WK_WB_AUTO:
        stWBAttr.auto_attr.high_color_temp = 10000;
        stWBAttr.auto_attr.low_color_temp = 2000;
        OT_PRINT("ISP Set WBAttr Hight:10000 Low:2000 \n");
        break;
    
    case WK_WB_CANDELA:
        stWBAttr.manual_attr.r_gain = 569;
        stWBAttr.manual_attr.gr_gain = 283;
        stWBAttr.manual_attr.gb_gain = 283;
        stWBAttr.manual_attr.b_gain = 397;
        break;

    case WK_WB_TUNGSTEN:
        stWBAttr.manual_attr.r_gain = 526;
        stWBAttr.manual_attr.gr_gain = 283;
        stWBAttr.manual_attr.gb_gain = 283;
        stWBAttr.manual_attr.b_gain = 452;
        break;

    case WK_WB_FLUORESCENCE:
        stWBAttr.manual_attr.r_gain = 402;
        stWBAttr.manual_attr.gr_gain = 283;
        stWBAttr.manual_attr.gb_gain = 283;
        stWBAttr.manual_attr.b_gain = 488;
        break;

    case WK_WB_DAYLIGHT:
        stWBAttr.manual_attr.r_gain = 429;
        stWBAttr.manual_attr.gr_gain = 283;
        stWBAttr.manual_attr.gb_gain = 283;
        stWBAttr.manual_attr.b_gain = 501;
        break;

    case WK_WB_CLOUDY:
        stWBAttr.manual_attr.r_gain = 329;
        stWBAttr.manual_attr.gr_gain = 283;
        stWBAttr.manual_attr.gb_gain = 283;
        stWBAttr.manual_attr.b_gain = 789;
        break;
    
    default:
        break;
    }

    s32Ret = ss_mpi_isp_set_wb_attr(ViPipe, &stWBAttr);
    if(s32Ret != TD_SUCCESS){
        sample_print("ISP Set WBAttr failed for %#x!\n", s32Ret);
        return;
    }

    s32Ret = ss_mpi_isp_set_awb_attr_ex(ViPipe, &stAWBEXAttr);
    if(s32Ret != TD_SUCCESS){
        sample_print("ISP Set AWBExAttr failed for %#x!\n", s32Ret);
        return;
    }
}

void wk_mpp_get_ExpInfo(int *pshutter, int *piso)
{
    td_s32 s32Ret;
    ot_vi_pipe ViPipe = 0;
    ot_isp_exp_info stExpInfo;
    int iso;

    s32Ret = ss_mpi_isp_query_exposure_info(ViPipe, &stExpInfo);
    *pshutter = stExpInfo.exp_time;
    *piso = stExpInfo.iso;

    iso = stExpInfo.iso / 100 * 1024;
    wk_mpp_get_black_level(iso);
}

void wk_mpp_get_black_level(int iso)
{
    td_s32 s32Ret;
    ot_vi_pipe viPipe;
    ot_isp_black_level_attr mBlackLevel;

    viPipe = 0; 
    s32Ret = ss_mpi_isp_get_black_level_attr(viPipe, &mBlackLevel);

    mBlackLevel.black_level_mode = OT_ISP_BLACK_LEVEL_MODE_MANUAL;
    if(iso > 13312){
        mBlackLevel.manual_attr.black_level[0][0] = 1024;
        mBlackLevel.manual_attr.black_level[0][1] = 1024;
        mBlackLevel.manual_attr.black_level[0][2] = 1024;
        mBlackLevel.manual_attr.black_level[0][3] = 1024;
    }
    else{
        mBlackLevel.manual_attr.black_level[0][0] = 1008;
        mBlackLevel.manual_attr.black_level[0][1] = 1024;
        mBlackLevel.manual_attr.black_level[0][2] = 1024;
        mBlackLevel.manual_attr.black_level[0][3] = 1008;
    }
    
    s32Ret = ss_mpi_isp_set_black_level_attr(viPipe, &mBlackLevel);
}


