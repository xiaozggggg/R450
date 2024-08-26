/*
  Copyright (c), 2001-2022, Shenshu Tech. Co., Ltd.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/time.h>

#include "sample_comm.h"

#define VPSS_DEFAULT_WIDTH  3840
#define VPSS_DEFAULT_HEIGHT 2160

#define MAX_FRM_WIDTH 4096
#define SAMPLE_VGS_SAVE_PATH "/mnt/sdcard/"

typedef struct stVGS_FUNCTION_PARAM
{
    td_bool bScale;
    ot_vgs_scale_coef_mode *penVgsSclCoefMode;
    sample_vb_base_info *pstOutImgVbInfo;
    td_s32 s32SampleNum;
} SAMPLE_VGS_FUNC_PARAM;

static ot_vb_calc_cfg stOutImgVbCalConfig;
static sample_vgs_vb_info g_stOutImgVbInfo;

static FILE *prawfile;
td_void sample_comm_vpss_get_default_grp_attr(ot_vpss_grp_attr *grp_attr)
{
    grp_attr->ie_en                     = TD_FALSE;
    grp_attr->dci_en                    = TD_FALSE;
    grp_attr->buf_share_en              = TD_FALSE;
    grp_attr->mcf_en                    = TD_FALSE;
    grp_attr->max_width                 = VPSS_DEFAULT_WIDTH;
    grp_attr->max_height                = VPSS_DEFAULT_HEIGHT;
    grp_attr->max_dei_width             = 0;
    grp_attr->max_dei_height            = 0;
    grp_attr->dynamic_range             = OT_DYNAMIC_RANGE_SDR8;
    grp_attr->pixel_format              = OT_PIXEL_FORMAT_YVU_SEMIPLANAR_420;
    grp_attr->dei_mode                  = OT_VPSS_DEI_MODE_OFF;
    grp_attr->buf_share_chn             = OT_VPSS_CHN0;
    grp_attr->frame_rate.src_frame_rate = -1;
    grp_attr->frame_rate.dst_frame_rate = -1;
}

td_void sample_comm_vpss_get_default_chn_attr(ot_vpss_chn_attr *chn_attr)
{
    chn_attr->mirror_en                 = TD_FALSE;
    chn_attr->flip_en                   = TD_FALSE;
    chn_attr->border_en                 = TD_FALSE;
    chn_attr->width                     = VPSS_DEFAULT_WIDTH;
    chn_attr->height                    = VPSS_DEFAULT_HEIGHT;
    chn_attr->depth                     = 1;
    chn_attr->chn_mode                  = OT_VPSS_CHN_MODE_USER;
    chn_attr->video_format              = OT_VIDEO_FORMAT_LINEAR;
    chn_attr->dynamic_range             = OT_DYNAMIC_RANGE_SDR8;
    chn_attr->pixel_format              = OT_PIXEL_FORMAT_YVU_SEMIPLANAR_420;
    chn_attr->compress_mode             = OT_COMPRESS_MODE_SEG;
    chn_attr->aspect_ratio.mode         = OT_ASPECT_RATIO_NONE;
    chn_attr->frame_rate.src_frame_rate = -1;
    chn_attr->frame_rate.dst_frame_rate = -1;
}

td_void sample_comm_vpss_get_default_3dnr_attr(ot_3dnr_attr *nr_attr)
{
    nr_attr->enable         = TD_FALSE;
    nr_attr->nr_type        = OT_NR_TYPE_VIDEO_NORM;
    nr_attr->compress_mode  = OT_COMPRESS_MODE_FRAME;
    nr_attr->nr_motion_mode = OT_NR_MOTION_MODE_NORM;
}

td_void sample_comm_vpss_get_default_vpss_cfg(sample_vpss_cfg *vpss_cfg, ot_fmu_mode vpss_fmu)
{
    ot_vpss_chn chn;
    ot_size in_size;
#if 1   //modify by Kyrie
    sample_sns_type sns_type = SENSOR0_TYPE;  

    sample_comm_vi_get_size_by_sns_type(sns_type, &in_size);
    sample_comm_vpss_get_default_grp_attr(&vpss_cfg->grp_attr);
    sample_comm_vpss_get_default_3dnr_attr(&vpss_cfg->nr_attr);
    vpss_cfg->vpss_grp = 0;
    vpss_cfg->grp_attr.max_width  = in_size.width;
    vpss_cfg->grp_attr.max_height = in_size.height;

    for (chn = 0; chn < OT_VPSS_MAX_PHYS_CHN_NUM; chn++) {
        vpss_cfg->chn_en[chn] = TD_FALSE;
        sample_comm_vpss_get_default_chn_attr(&vpss_cfg->chn_attr[chn]);
        if (chn > OT_VPSS_CHN1) {
            vpss_cfg->chn_attr[chn].compress_mode = OT_COMPRESS_MODE_NONE;
        }
        vpss_cfg->chn_attr[chn].width  = in_size.width;
        vpss_cfg->chn_attr[chn].height = in_size.height;
#ifdef OT_FPGA
        vpss_cfg->chn_attr[chn].frame_rate.src_frame_rate = 30; /* 30: fpga src frame rate */
        vpss_cfg->chn_attr[chn].frame_rate.dst_frame_rate = 10; /* 10: fpga dst frame rate */
#endif
    }
    vpss_cfg->chn_en[OT_VPSS_CHN0] = TD_TRUE;

    if (vpss_fmu == OT_FMU_MODE_WRAP) {
        vpss_cfg->chn_en[1] = TD_TRUE; /* vpss_chn0->vnec & vpss_chn1->vo */
    }
#endif
}

static td_s32 sample_common_vpss_set_chn_fmu_mode(ot_vpss_grp grp, ot_vpss_chn chn, td_bool chn0_wrap)
{
    td_s32 ret = TD_SUCCESS;
    if (chn == OT_VPSS_CHN0 && chn0_wrap == TD_TRUE) {
        ret = ss_mpi_vpss_set_chn_fmu_mode(grp, OT_VPSS_CHN0, OT_FMU_MODE_WRAP);
    }
    return ret;
}

static td_s32 sample_common_vpss_start_chn(ot_vpss_grp grp, const td_bool *chn_enable,
    const ot_vpss_chn_attr *chn_attr, td_bool chn0_wrap, td_u32 chn_array_size)
{
    ot_vpss_chn vpss_chn;
    td_s32 ret, i;

    for (i = 0; i < (td_s32)chn_array_size; ++i) {
        if (chn_enable[i] == TD_TRUE) {
            vpss_chn = i;
            // printf("====== vpss_chn[%d] chn_attr width[%d] height[%d]\n", vpss_chn, chn_attr[vpss_chn].width, chn_attr[vpss_chn].height);
            // printf("====== chn_attr pixel_format[%d]\n", chn_attr[vpss_chn].pixel_format);
            ret = ss_mpi_vpss_set_chn_attr(grp, vpss_chn, &chn_attr[vpss_chn]);
            if (ret != TD_SUCCESS) {
                sample_print_err("ss_mpi_vpss_set_chn_attr failed with %#x\n", ret);
                goto disable_chn;
            }
            /* set chn0 wrap fmu mode first, then enable chn */
            ret = sample_common_vpss_set_chn_fmu_mode(grp, vpss_chn, chn0_wrap);
            if (ret != TD_SUCCESS) {
                sample_print_err("ss_mpi_vpss_set_chn_fmu_mode failed with %#x\n", ret);
                goto disable_chn;
            }
            ret = ss_mpi_vpss_enable_chn(grp, vpss_chn);
            if (ret != TD_SUCCESS) {
                sample_print_err("ss_mpi_vpss_enable_chn failed with %#x\n", ret);
                goto disable_chn;
            }
        }
    }
    return TD_SUCCESS;

disable_chn:
    for (i = i - 1; i >= 0; i--) {
        if (chn_enable[i] == TD_TRUE) {
            vpss_chn = i;
            ret = ss_mpi_vpss_disable_chn(grp, vpss_chn);
            if (ret != TD_SUCCESS) {
                sample_print_err("ss_mpi_vpss_disable_chn failed with %#x!\n", ret);
            }
        }
    }
    return TD_FAILURE;
}

td_s32 sample_common_vpss_start(ot_vpss_grp grp, const ot_vpss_grp_attr *grp_attr,
    const sample_vpss_chn_attr *vpss_chn_attr)
{
    td_s32 ret;

    if (vpss_chn_attr->chn_array_size < OT_VPSS_MAX_PHYS_CHN_NUM) {
        sample_print_err("array size(%u) of chn_enable and chn_attr need >= %u!\n",
            vpss_chn_attr->chn_array_size, OT_VPSS_MAX_PHYS_CHN_NUM);
        return TD_FAILURE;
    }

    ret = ss_mpi_vpss_create_grp(grp, grp_attr);
    if (ret != TD_SUCCESS) {
        sample_print_err("ss_mpi_vpss_create_grp(grp:%d) failed with %#x!\n", grp, ret);
        return TD_FAILURE;
    }

    ret = ss_mpi_vpss_start_grp(grp);
    if (ret != TD_SUCCESS) {
        sample_print_err("ss_mpi_vpss_start_grp failed with %#x\n", ret);
        goto destroy_grp;
    }

    ret = sample_common_vpss_start_chn(grp, vpss_chn_attr->chn_enable, &vpss_chn_attr->chn_attr[0],
        vpss_chn_attr->chn0_wrap, OT_VPSS_MAX_PHYS_CHN_NUM);
    if (ret != TD_SUCCESS) {
        goto stop_grp;
    }

    return TD_SUCCESS;

stop_grp:
    ret = ss_mpi_vpss_stop_grp(grp);
    if (ret != TD_SUCCESS) {
        sample_print_err("ss_mpi_vpss_stop_grp failed with %#x!\n", ret);
    }
destroy_grp:
    ret = ss_mpi_vpss_destroy_grp(grp);
    if (ret != TD_SUCCESS) {
        sample_print_err("ss_mpi_vpss_destroy_grp failed with %#x!\n", ret);
    }
    return TD_FAILURE;
}

td_s32 sample_common_vpss_stop(ot_vpss_grp grp, const td_bool *chn_enable, td_u32 chn_array_size)
{
    td_s32 i;
    td_s32 ret;
    ot_vpss_chn vpss_chn;

    if (chn_array_size < OT_VPSS_MAX_PHYS_CHN_NUM) {
        sample_print_err("array size(%u) of chn_enable need > %u!\n", chn_array_size, OT_VPSS_MAX_PHYS_CHN_NUM);
        return TD_FAILURE;
    }

    for (i = 0; i < OT_VPSS_MAX_PHYS_CHN_NUM; ++i) {
        if (chn_enable[i] == TD_TRUE) {
            vpss_chn = i;
            ret = ss_mpi_vpss_disable_chn(grp, vpss_chn);
            if (ret != TD_SUCCESS) {
                sample_print_err("ss_mpi_vpss_disable_chn failed with %#x!\n", ret);
            }
        }
    }

    ret = ss_mpi_vpss_stop_grp(grp);
    if (ret != TD_SUCCESS) {
        sample_print_err("ss_mpi_vpss_stop_grp failed with %#x!\n", ret);
    }

    ret = ss_mpi_vpss_destroy_grp(grp);
    if (ret != TD_SUCCESS) {
        sample_print_err("ss_mpi_vpss_destroy_grp failed with %#x!\n", ret);
    }

    return TD_SUCCESS;
}

/*****************************************************************************
* function : get one frame(YUV) form vpss
*****************************************************************************/
td_s32 SAMPLE_COMM_VPSS_SetRawFilename(char *filename)
{
    td_s32 sRet = 0;

    if(prawfile != TD_NULL){
        fclose(prawfile);
        prawfile = TD_NULL;
    }

    prawfile = fopen(filename, "ab");
    if (NULL == prawfile){
        sample_print_err("open file %s fail !\n", filename);
        sRet = -1;
    }

    return sRet;
}

td_void SAMPLE_COMM_VPSS_GetOneFrame(unsigned char *getbuf, ot_vpss_grp VpssGrp, ot_vpss_chn VpssChn)
{
    td_s32 s32ret;
    ot_video_frame_info stVideoFrame;
    td_u32 phy_addr, size;
    td_u32 mHeight, mWidth, u32UvHeight;
    td_char *pUserPageAddr[2] = {TD_NULL, TD_NULL, TD_NULL};

    unsigned int w, h, offset;
    char* pVBufVirt_Y;
    char* pVBufVirt_C;
	char* pMemContent;
    char TotalPart;
	unsigned char TmpBuff[MAX_FRM_WIDTH]; //If this value is too small and the image is big, this memory may not be enough

	size = 0;
	u32UvHeight = 0;

    //Get one frame from vpss channel1
    s32ret = ss_mpi_vpss_get_chn_frame(VpssGrp, VpssChn, &stVideoFrame, 0);
    if(s32ret == TD_SUCCESS){
        if (OT_PIXEL_FORMAT_YVU_SEMIPLANAR_420 == stVideoFrame.video_frame.pixel_format)
        {
            size = (stVideoFrame.video_frame.stride[0]) * (stVideoFrame.video_frame.height) * 3 / 2;
            u32UvHeight = stVideoFrame.video_frame.height/2;
        }
        mWidth = stVideoFrame.video_frame.width;
        mHeight = stVideoFrame.video_frame.height;

        phy_addr = stVideoFrame.video_frame.phys_addr[0];

        // printf("YUV Frame Info -->Stride:[%d] Width:[%d] Height:[%d] Compress:[%d] Size[%d] UVHeight[%d]\n",
        // 	stVideoFrame.video_frame.stride[0], mWidth, mHeight,
        //     stVideoFrame.video_frame.stride, size, u32UvHeight);

        pUserPageAddr[0] = (td_char *)ss_mpi_sys_mmap(phy_addr, size);
        if(TD_NULL == pUserPageAddr[0]){
            return;
        }

        pVBufVirt_Y = pUserPageAddr[0];
        pVBufVirt_C = pVBufVirt_Y + (stVideoFrame.video_frame.stride[0]) * mHeight;
        offset = 0;

        //YVU420SP    --->   YUV420P
        /* save Y --------*/
        if(OT_VPSS_CHN0 == VpssChn){
            for (h = 0; h < mHeight; h++)
            {
                fwrite(pVBufVirt_Y, mWidth, 1, prawfile);
                pVBufVirt_Y += mWidth;
            }
        }
        else{
            memcpy(getbuf, pVBufVirt_Y, mWidth*mHeight);
            offset += mWidth*mHeight;
        }

        /* save U -------*/
        for(h = 0; h < u32UvHeight; h++)
        {
            pMemContent = pVBufVirt_C + h * stVideoFrame.video_frame.stride[1];

            pMemContent += 1;

            for(w = 0; w < mWidth/2; w++)
            {
                TmpBuff[w] = *pMemContent;
                pMemContent += 2;
            }

            if(OT_VPSS_CHN0 == VpssChn){
                fwrite(TmpBuff, mWidth/2, 1, prawfile);
            }
            else{
                memcpy(getbuf+offset, TmpBuff, mWidth/2);
                offset += mWidth/2;
            }
        }

        /* save V -------*/
        for(h = 0; h < u32UvHeight; h++)
        {
            pMemContent = pVBufVirt_C + h * stVideoFrame.video_frame.stride[1];

            for(w = 0; w < mWidth/2; w++)
            {
                TmpBuff[w] = *pMemContent;
                pMemContent += 2;
            }
            
            if(OT_VPSS_CHN0 == VpssChn){
                fwrite(TmpBuff, mWidth/2, 1, prawfile);
            }
            else{
                memcpy(getbuf+offset, TmpBuff, mWidth/2);
                offset += mWidth/2;
            }
        }

        if(prawfile != TD_NULL){
            fclose(prawfile);
            prawfile = TD_NULL;
        }

        ss_mpi_sys_munmap(pUserPageAddr[0], size);
        pUserPageAddr[0] = TD_NULL;

        ss_mpi_vpss_release_chn_frame(VpssGrp, VpssChn, &stVideoFrame);
    }
}

//=============================== VGS =================================//
td_void SAMPLE_VGS_SetVbConfig(ot_vb_calc_cfg *pstVbCalConfig)
{
    memcpy(&stOutImgVbCalConfig, pstVbCalConfig, sizeof(ot_vb_calc_cfg));
}

static td_s32 SAMPLE_VGS_GetFrameVb(const sample_vb_base_info *pstVbInfo, const ot_vb_calc_cfg *pstVbCalConfig,
                                    ot_video_frame_info *pstFrameInfo, sample_vgs_vb_info *pstVgsVbInfo)
{
    td_phys_addr_t phys_addr = 0;

    pstVgsVbInfo->vb_handle = ss_mpi_vb_get_blk(OT_VB_INVALID_POOL_ID, pstVbCalConfig->vb_size, TD_NULL);
    pstVgsVbInfo->vb_size = pstVbCalConfig->vb_size;
    sample_print_info("ss_mpi_vb_get_blk BlkId=[%d] BlkSize[%d] \n", pstVgsVbInfo->vb_handle, pstVgsVbInfo->vb_size);
    if (OT_VB_INVALID_POOL_ID == pstVgsVbInfo->vb_handle){
        sample_print_err("ss_mpi_vb_get_blk failed!\n");
        return TD_FAILURE;
    }
    pstVgsVbInfo->vb_used = TD_TRUE;

    phys_addr = ss_mpi_vb_handle_to_phys_addr(pstVgsVbInfo->vb_handle);
    if (0 == phys_addr){
        sample_print_err("ss_mpi_vb_phys_addr_to_handle failed!.\n");
        ss_mpi_vb_release_blk(pstVgsVbInfo->vb_handle);
        return TD_FAILURE;
    }

    pstVgsVbInfo->virt_addr = (td_u8 *)ss_mpi_sys_mmap(phys_addr, pstVbCalConfig->vb_size);
    if (TD_NULL == pstVgsVbInfo->virt_addr)
    {
        sample_print_err("HI_MPI_SYS_Mmap failed!.\n");
        ss_mpi_vb_release_blk(pstVgsVbInfo->vb_handle);
        return TD_FAILURE;
    }

    pstFrameInfo->mod_id = OT_ID_VGS;
    pstFrameInfo->pool_id = ss_mpi_vb_handle_to_pool_id(pstVgsVbInfo->vb_handle);

    pstFrameInfo->video_frame.width       = pstVbInfo->width;
    pstFrameInfo->video_frame.height      = pstVbInfo->height;
    pstFrameInfo->video_frame.field        = OT_VIDEO_FIELD_FRAME;
    pstFrameInfo->video_frame.pixel_format  = pstVbInfo->pixel_format;
    pstFrameInfo->video_frame.video_format  = pstVbInfo->video_format;
    pstFrameInfo->video_frame.compress_mode = pstVbInfo->compress_mode;
    pstFrameInfo->video_frame.dynamic_range = OT_DYNAMIC_RANGE_SDR8;
    pstFrameInfo->video_frame.color_gamut   = OT_COLOR_GAMUT_BT601;

    pstFrameInfo->video_frame.header_stride[0]  = pstVbCalConfig->head_stride;
    pstFrameInfo->video_frame.header_stride[1]  = pstVbCalConfig->head_stride;
    pstFrameInfo->video_frame.header_phys_addr[0] = phys_addr;
    pstFrameInfo->video_frame.header_phys_addr[1] = pstFrameInfo->video_frame.header_phys_addr[0] + pstVbCalConfig->head_y_size;
    pstFrameInfo->video_frame.header_virt_addr[0] = pstVgsVbInfo->virt_addr;
    pstFrameInfo->video_frame.header_virt_addr[1] = pstFrameInfo->video_frame.header_virt_addr[0] + pstVbCalConfig->head_y_size;

    pstFrameInfo->video_frame.stride[0]  = pstVbCalConfig->main_stride;
    pstFrameInfo->video_frame.stride[1]  = pstVbCalConfig->main_stride;
    pstFrameInfo->video_frame.phys_addr[0] = pstFrameInfo->video_frame.header_phys_addr[0] + pstVbCalConfig->head_size;
    pstFrameInfo->video_frame.phys_addr[1] = pstFrameInfo->video_frame.phys_addr[0] + pstVbCalConfig->main_y_size;
    pstFrameInfo->video_frame.virt_addr[0] = pstFrameInfo->video_frame.header_virt_addr[0] + pstVbCalConfig->head_size;
    pstFrameInfo->video_frame.virt_addr[1] = pstFrameInfo->video_frame.virt_addr[0] + pstVbCalConfig->main_y_size;

    return TD_SUCCESS;
}

static td_s32 SAMPLE_VGS_COMMON_FUNCTION(SAMPLE_VGS_FUNC_PARAM *pParam)
{
    td_s32 s32Ret = TD_FAILURE;
    FILE *pFileWrite = TD_NULL;
    td_char szOutFileName[128];

    ot_vgs_handle hHandle = -1;
    ot_vgs_task_attr stVgsTaskAttr;

    ot_vb_pool_cfg stVbPoolCfg;
    ot_vb_pool hPool = OT_VB_INVALID_POOL_ID;

    if (TD_NULL == pParam){
        return s32Ret;
    }

    /************************************************
    step2:  Get frame
    *************************************************/
    s32Ret = ss_mpi_vpss_get_chn_frame(0, OT_VPSS_CHN0, &stVgsTaskAttr.img_in, 50);
    if(s32Ret != TD_SUCCESS){
        sample_print_err("ss_mpi_vpss_get_chn_frame failed, s32Ret:0x%x\n", s32Ret);
        goto EXIT2;
    }

    //不进行缩放，直接发送到VENC进行编码
    if(pParam->bScale == TD_FALSE){
        sample_print_err("VGS no scale send to venc start \n");
        s32Ret = ss_mpi_venc_send_frame(WK_VIDEO_CHANNEL_SNAP, &stVgsTaskAttr.img_in, 10000);
        if (s32Ret != TD_SUCCESS){
            sample_print_err("ss_mpi_venc_send_frame failed, s32Ret:0x%x", s32Ret);
        }

        ss_mpi_vpss_release_chn_frame(0, OT_VPSS_CHN0, &stVgsTaskAttr.img_in);

        return TD_SUCCESS;
    }

    memset(&stVgsTaskAttr.img_out.video_frame, 0, sizeof(ot_video_frame));
    memcpy(&stVgsTaskAttr.img_out.video_frame, &stVgsTaskAttr.img_in.video_frame, sizeof(ot_video_frame));
    s32Ret = SAMPLE_VGS_GetFrameVb(pParam->pstOutImgVbInfo, &stOutImgVbCalConfig, &stVgsTaskAttr.img_out, &g_stOutImgVbInfo);
    if (s32Ret != TD_SUCCESS)
    {
        goto EXIT2;
    }

    /************************************************
    step3:  Create VGS job
    *************************************************/
    sample_print_info("VGS scale task start \n");
    s32Ret = ss_mpi_vgs_begin_job(&hHandle);
    if (s32Ret != TD_SUCCESS){
        sample_print_err("ss_mpi_vgs_begin_job failed, s32Ret:0x%x", s32Ret);
        goto EXIT3;
    }

    /************************************************
    step4:  Add VGS task
    *************************************************/
    s32Ret = ss_mpi_vgs_add_scale_task(hHandle, &stVgsTaskAttr, OT_VGS_SCALE_COEF_NORM);
    if (s32Ret != TD_SUCCESS)
    {
        ss_mpi_vgs_cancel_job(hHandle);
        sample_print_err("ss_mpi_vgs_add_scale_task failed, s32Ret:0x%x\n", s32Ret);
        goto EXIT3;
    }

    /************************************************
    step5:  Start VGS work
    *************************************************/
    s32Ret = ss_mpi_vgs_end_job(hHandle);
    if (s32Ret != TD_SUCCESS)
    {
        ss_mpi_vgs_cancel_job(hHandle);
        sample_print_err("ss_mpi_vgs_cancel_job failed, s32Ret:0x%x\n", s32Ret);
        goto EXIT3;
    }

    /************************************************
    step6:  Send Frame to Venc(encode to JPEG)
    *************************************************/
    sample_print_info("VGS no scale send to venc start \n");
    s32Ret = ss_mpi_venc_send_frame(WK_VIDEO_CHANNEL_SNAP, &stVgsTaskAttr.img_out, 10000);
    if (s32Ret != TD_SUCCESS){
        sample_print_err("ss_mpi_venc_send_frame failed, s32Ret:0x%x", s32Ret);
    }

    /************************************************
    step7:  Release and Exit
    *************************************************/
    ss_mpi_vb_release_blk(g_stOutImgVbInfo.vb_handle);

    if (TD_NULL != g_stOutImgVbInfo.virt_addr){
        ss_mpi_sys_munmap((td_void *)g_stOutImgVbInfo.virt_addr, g_stOutImgVbInfo.vb_size);
        g_stOutImgVbInfo.virt_addr = TD_NULL;
    }

    if(-1 != hHandle){
        ss_mpi_vgs_cancel_job(hHandle);
        hHandle = -1;
    }

    s32Ret = ss_mpi_vpss_release_chn_frame(0, OT_VPSS_CHN0, &stVgsTaskAttr.img_in);
    return s32Ret;

EXIT3:
    ss_mpi_vb_release_blk(g_stOutImgVbInfo.vb_handle);

    if (TD_NULL != g_stOutImgVbInfo.virt_addr){
        ss_mpi_sys_munmap((td_void *)g_stOutImgVbInfo.virt_addr, g_stOutImgVbInfo.vb_size);
        g_stOutImgVbInfo.virt_addr = TD_NULL;
    }
EXIT2:
    ss_mpi_vpss_release_chn_frame(0, 0, &stVgsTaskAttr.img_in);

    return s32Ret;
}

td_s32 SAMPLE_VGS_Scale(td_u8 stScaleOpt)
{
    td_s32 s32Ret = TD_FAILURE;
    SAMPLE_VGS_FUNC_PARAM stVgsFuncParam;
    sample_vb_base_info stOutImgVbInfo;
    ot_vgs_scale_coef_mode enVgsSclCoefMode = OT_VGS_SCALE_COEF_NORM;

    stOutImgVbInfo.video_format = OT_VIDEO_FORMAT_LINEAR;
    stOutImgVbInfo.pixel_format = OT_PIXEL_FORMAT_YVU_SEMIPLANAR_420;
    stOutImgVbInfo.width = 9600; //8192;
    stOutImgVbInfo.height = 5400; //4608;
    stOutImgVbInfo.align = 2;
    stOutImgVbInfo.compress_mode = OT_COMPRESS_MODE_NONE;

    memset(&stVgsFuncParam, 0, sizeof(SAMPLE_VGS_FUNC_PARAM));
    if(stScaleOpt == 2){ //48MP --> 8192*4608
        stVgsFuncParam.bScale = TD_TRUE;
        stVgsFuncParam.penVgsSclCoefMode = &enVgsSclCoefMode;
        stVgsFuncParam.pstOutImgVbInfo = &stOutImgVbInfo;
        stVgsFuncParam.s32SampleNum = 0;      
    }
    else if(stScaleOpt == 3){ //1080P --> 4K
        stOutImgVbInfo.width = 3840;
        stOutImgVbInfo.height = 2160;

        stVgsFuncParam.bScale = TD_TRUE;
        stVgsFuncParam.penVgsSclCoefMode = &enVgsSclCoefMode;
        stVgsFuncParam.pstOutImgVbInfo = &stOutImgVbInfo;
        stVgsFuncParam.s32SampleNum = 0;      
    }
    else{               //4K --> 3840*2160
        stVgsFuncParam.bScale = TD_FALSE;
        stVgsFuncParam.penVgsSclCoefMode = &enVgsSclCoefMode;
        stVgsFuncParam.pstOutImgVbInfo = &stOutImgVbInfo;
        stVgsFuncParam.s32SampleNum = 0;
    }

    s32Ret = SAMPLE_VGS_COMMON_FUNCTION(&stVgsFuncParam);
    if (s32Ret != TD_SUCCESS){
        sample_print_err("VGS Sample %d failed, s32Ret:0x%x\n", stVgsFuncParam.s32SampleNum, s32Ret);
    }

    return s32Ret;
}