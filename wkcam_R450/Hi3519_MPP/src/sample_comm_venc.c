/*
  Copyright (c), 2001-2022, Shenshu Tech. Co., Ltd.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <poll.h>
#include <sys/time.h>
#include <sys/select.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>
#include <math.h>
#include <unistd.h>
#include <signal.h>
#include <sys/prctl.h>
#include <limits.h>

#include "sample_comm.h"
#include "heif_format.h"

#define TEMP_BUF_LEN            8
#define MAX_THM_SIZE            (64 * 1024)
#define QPMAP_BUF_NUM           8
#define VENC_QPMAP_MAX_CHN      2
#define VENC_MOSAIC_MAP_MAX_CHN  2
#define SEND_FRAME_BUF_NUM      8
#define VENC_PATH_MAX           1024

#define SAMPLE_RETURN_CONTINUE  1
#define SAMPLE_RETURN_BREAK     2
#define SAMPLE_RETURN_NULL      3
#define SAMPLE_RETURN_GOTO      4
#define SAMPLE_RETURN_FAILURE   (-1)
#define MAX_MMZ_NAME_LEN        32

typedef struct {
    td_u32 qpmap_size[VENC_QPMAP_MAX_CHN];
    td_phys_addr_t qpmap_phys_addr[VENC_QPMAP_MAX_CHN][QPMAP_BUF_NUM];
    td_void *qpmap_vir_addr[VENC_QPMAP_MAX_CHN][QPMAP_BUF_NUM];

    td_u32 skip_weight_size[VENC_QPMAP_MAX_CHN];
    td_phys_addr_t skip_weight_phys_addr[VENC_QPMAP_MAX_CHN][QPMAP_BUF_NUM];
    td_void *skip_weight_vir_addr[VENC_QPMAP_MAX_CHN][QPMAP_BUF_NUM];
} sample_comm_venc_frame_proc_info;

typedef struct {
    td_phys_addr_t map_phys_addr[VENC_MOSAIC_MAP_MAX_CHN];
    td_void *map_vir_addr[VENC_MOSAIC_MAP_MAX_CHN];
    ot_mosaic_blk_size blk_size[VENC_MOSAIC_MAP_MAX_CHN];
} sample_comm_venc_mosaic_frame_proc_info;

typedef struct {
    FILE *file[OT_VENC_MAX_CHN_NUM];
    td_s32 venc_fd[OT_VENC_MAX_CHN_NUM];
    td_s32 maxfd;
    td_u32 picture_cnt[OT_VENC_MAX_CHN_NUM];
    td_char file_name[OT_VENC_MAX_CHN_NUM][FILE_NAME_LEN];
    td_char real_file_name[OT_VENC_MAX_CHN_NUM][VENC_PATH_MAX];
    ot_venc_chn venc_chn;
    td_char file_postfix[10]; /* 10 :file_postfix number */
    td_s32 chn_total;
    td_bool save_heif;
} sample_comm_venc_stream_proc_info;

typedef struct {
    td_bool thread_start;
    ot_vpss_grp vpss_grp;
    ot_venc_chn venc_chn[OT_VENC_MAX_CHN_NUM];
    ot_vpss_chn vpss_chn[OT_VPSS_MAX_PHYS_CHN_NUM];
    ot_size size[OT_VENC_MAX_CHN_NUM];
    td_s32 cnt;
} sample_venc_send_frame_para;

const td_u8 g_soi[2] = { 0xFF, 0xD8 }; /* 2 is a number */
const td_u8 g_eoi[2] = { 0xFF, 0xD9 }; /* 2 is a number */

static pthread_t g_venc_pid;
static pthread_t g_venc_qpmap_pid;
static sample_venc_getstream_para g_para = {
    .thread_start = TD_FALSE,
    .cnt = 0,
    .save_heif = TD_FALSE
};

static sample_venc_qpmap_sendframe_para g_qpmap_send_frame_para;
static pthread_t g_venc_rateauto_pid;
static sample_venc_rateauto_para g_venc_rateauto_frame_param;
static pthread_t g_venc_roimap_pid;
static sample_venc_roimap_frame_para g_roimap_frame_param;
static pthread_t g_venc_send_pid;
static sample_venc_send_frame_para g_send_frame_param;

td_s32 g_snap_cnt = 0;
td_char *g_dst_buf = TD_NULL;

//walkera
static pthread_t wk_VencPid;
static sample_venc_getstream_para wk_stPara;

static td_s32 uframecount_start;
static td_u32 start_seqnum, end_seqnum;

static td_s32 gs_s32SnapCnt = 0;
td_char *DstBuf = NULL;

#define TEMP_BUF_LEN 8
#define MAX_THM_SIZE (64 * 1024)

ot_payload_type WkPayLoadType[WK_MAX_VENC_CHN];
td_s32 WkVencFd[WK_MAX_VENC_CHN];

extern ot_size g_sample_pic_size[PIC_BUTT];

#ifdef __READ_ALL_FILE__
static td_s32 read_jpg_file_pos(FILE *fp_jpg, td_char *psz_file, td_s32 size, td_s32 *startpos, td_s32 *endpos)
{
    td_s32 i = 0;
    td_s32 bufpos = 0;
    td_s32 tempbuf[TEMP_BUF_LEN] = { 0 };
    td_s32 startflag[2] = { 0xff, 0xd8 }; /* 2 is array size */
    td_s32 endflag[2] = { 0xff, 0xd9 };   /* 2 is array size */

    if (fread(psz_file, size, 1, fp_jpg) <= 0) {
        (td_void)fclose(fp_jpg);
        sample_print_err("fread jpeg src fail!\n");
        return TD_FAILURE;
    }

    (td_void)fclose(fp_jpg);
    td_u16 thm_len;
    thm_len = (psz_file[0x4] << 0x8) + psz_file[0x5];
    while (i < size) {
        tempbuf[bufpos] = psz_file[i++];

        if (bufpos > 0 && memcmp(tempbuf + bufpos - 1, startflag, sizeof(startflag)) == 0) {
            *startpos = i - 0x2;
            if (*startpos < 0) {
                *startpos = 0;
            }
        }

        if (bufpos > 0 && memcmp(tempbuf + bufpos - 1, endflag, sizeof(endflag)) == 0) {
            *endpos = i;
            break;
        }

        bufpos++;

        if (bufpos == (TEMP_BUF_LEN - 1)) {
            if (tempbuf[bufpos - 1] != 0xFF) {
                bufpos = 0;
            }
        } else if (bufpos > (TEMP_BUF_LEN - 1)) {
            bufpos = 0;
        }
    }

    if (*endpos - *startpos <= 0) {
        sample_print_err("get .thm 11 fail!\n");
        return TD_FAILURE;
    }

    if (*endpos - *startpos >= size) {
        sample_print_err("NO DCF info, get .thm 22 fail!\n");
        return TD_FAILURE;
    }

    return TD_SUCCESS;
}

static td_s32 cpy_jpg_file_by_pos(td_char *psz_file, td_s32 startpos, td_s32 endpos)
{
    td_char *temp = psz_file + startpos;
    if (MAX_THM_SIZE < (endpos - startpos)) {
        sample_print_err("thm is too large than MAX_THM_SIZE, get .thm 33 fail!\n");
        return TD_FAILURE;
    }

    td_char *c_dst_buf = (td_char *)malloc(endpos - startpos);
    if (c_dst_buf == TD_NULL) {
        sample_print_err("memory malloc fail!\n");
        return TD_FAILURE;
    }

    if (memcpy_s(c_dst_buf, endpos - startpos, temp, endpos - startpos) != EOK) {
        sample_print_err("call memcpy_s error\n");
        free(c_dst_buf);
        return TD_FAILURE;
    }

    g_dst_buf = c_dst_buf;

    return TD_SUCCESS;
}

static td_s32 file_trans_get_thm_from_jpg(td_char *jpg_path, td_u8 len, td_u32 *dst_size)
{
    td_s32 ret = TD_FAILURE;
    FILE *fp_jpg = TD_NULL;
    td_s32 startpos = 0;
    td_s32 endpos = 0;
    td_char *psz_file = TD_NULL;
    td_s32 fd;
    struct stat stat_info = { 0 };
    td_char real_path[PATH_MAX];

    if (realpath(jpg_path, real_path) == TD_NULL) {
        sample_print_err("file %s error!\n", real_path);
        return TD_FAILURE;
    }

    fp_jpg = fopen(real_path, "rb");
    if (fp_jpg == TD_NULL) {
        sample_print_err("file %s not exist!\n", real_path);
        return TD_FAILURE;
    } else {
        fd = fileno(fp_jpg);
        fchmod(fd, S_IRUSR | S_IWUSR);
        fstat(fd, &stat_info);
        psz_file = (td_char *)malloc(stat_info.size);
        if ((psz_file == TD_NULL) || (stat_info.size < 6)) { /* 6: algo num */
            fclose(fp_jpg);
            sample_print_err("memory malloc fail!\n");
            return TD_FAILURE;
        }

        ret = read_jpg_file_pos(fp_jpg, psz_file, stat_info.size, &startpos, &endpos);
        if (ret != TD_SUCCESS) {
            free(psz_file);
            sample_print_err("read_jpg_file_pos fail!\n");
            return TD_FAILURE;
        }
    }

    ret = cpy_jpg_file_by_pos(psz_file, startpos, endpos);
    if (ret != TD_SUCCESS) {
        free(psz_file);
        sample_print_err("cpy_jpg_file_by_pos fail!\n");
        return TD_FAILURE;
    }

    *dst_size = endpos - startpos;
    free(psz_file);

    return TD_SUCCESS;
}

#else

static td_void file_trans_set_tembuf(FILE *fp_jpg, struct stat *stat_info, td_s32 *startpos, td_s32 *endpos)
{
    td_s32 tempbuf[TEMP_BUF_LEN] = { 0 };
    td_s32 fd, ret;
    td_s32 bufpos = 0;
    td_s32 startflag[2] = { 0xff, 0xd8 }; /* 2 is a number */
    td_s32 endflag[2] = { 0xff, 0xd9 };   /* 2 is a number */
    td_bool start_match = TD_FALSE;

    fd = fileno(fp_jpg);
    fchmod(fd, S_IRUSR | S_IWUSR);
    fstat(fd, stat_info);

    while (!feof(fp_jpg)) {
        tempbuf[bufpos] = getc(fp_jpg);
        if (bufpos > 0) {
            if (memcmp(tempbuf + bufpos - 1, startflag, sizeof(startflag)) == 0) {
                *startpos = ((ftell(fp_jpg) - 2) < 0) ? 0 : (ftell(fp_jpg) - 2); /* 2 is a number 2 is a number */
                start_match = TD_TRUE;
            }

            ret = memcmp(tempbuf + bufpos - 1, endflag, sizeof(endflag));
            if ((ret == 0) && (start_match == TD_TRUE)) {
                *endpos = ftell(fp_jpg);
                break;
            } else if ((ret == 0) && (start_match != TD_TRUE)) {
                *endpos = ftell(fp_jpg);
            }
        }
        bufpos++;

        if (bufpos == (TEMP_BUF_LEN - 1)) {
            if (tempbuf[bufpos - 1] != 0xFF) {
                bufpos = 0;
            }
        } else if (bufpos > (TEMP_BUF_LEN - 1)) {
            if (tempbuf[bufpos - 1] == 0xFF) {
                tempbuf[0] = 0xFF;
                bufpos = 1;
            } else {
                bufpos = 0;
            }
        }
    }
}

static td_s32 file_trans_get_thm_from_jpg(td_char *jpg_path, td_u8 len, td_u32 *dst_size)
{
    td_s32 startpos = 0;
    td_s32 endpos = 0;

    struct stat stat_info = { 0 };

    FILE *fp_jpg = TD_NULL;
    td_char real_path[PATH_MAX];

    if ((len > FILE_NAME_LEN) || realpath(jpg_path, real_path) == TD_NULL) {
        sample_print_err("file %s error!\n", jpg_path);
        return TD_FAILURE;
    }

    fp_jpg = fopen(real_path, "rb");
    if (fp_jpg == TD_NULL) {
        sample_print_err("file %s not exist!\n", real_path);
        return TD_FAILURE;
    } else {
        file_trans_set_tembuf(fp_jpg, &stat_info, &startpos, &endpos);
    }

    if (endpos - startpos <= 0) {
        sample_print_err("get .thm 11 fail!\n");
        fclose(fp_jpg);
        return TD_FAILURE;
    }

    if (endpos - startpos > MAX_THM_SIZE) {
        sample_print_err("thm is too large than MAX_THM_SIZE, get .thm 22 fail!\n");
        fclose(fp_jpg);
        return TD_FAILURE;
    }

    if (endpos - startpos >= stat_info.st_size) {
        sample_print_err("NO DCF info, get .thm 33 fail!\n");
        fclose(fp_jpg);
        return TD_FAILURE;
    }

    td_char *c_dst_buf = (td_char *)malloc(endpos - startpos);
    if (c_dst_buf == TD_NULL) {
        sample_print_err("memory malloc fail!\n");
        fclose(fp_jpg);
        return TD_FAILURE;
    }

    (td_void)fseek(fp_jpg, (long)startpos, SEEK_SET);
    *dst_size = fread(c_dst_buf, 1, endpos - startpos, fp_jpg);
    if (*dst_size != (td_u32)(endpos - startpos)) {
        free(c_dst_buf);
        sample_print_err("fread fail!\n");
        fclose(fp_jpg);
        return TD_FAILURE;
    }

    g_dst_buf = c_dst_buf;
    (td_void)fclose(fp_jpg);

    return TD_SUCCESS;
}
#endif

/* set venc memory location */
td_s32 sample_comm_venc_mem_config(td_void)
{
    td_s32 i, ret;
    ot_mpp_chn mpp_chn_venc;

    /* group, venc max chn is 64 */
    for (i = 0; i < 64; i++) {
        td_char *pc_mmz_name = TD_NULL;
        mpp_chn_venc.mod_id = OT_ID_VENC;
        mpp_chn_venc.dev_id = 0;
        mpp_chn_venc.chn_id = i;

        /* venc */
        ret = ss_mpi_sys_set_mem_cfg(&mpp_chn_venc, pc_mmz_name);
        if (ret != TD_SUCCESS) {
            sample_print_err("ss_mpi_sys_set_mem_config with %#x!\n", ret);
            return TD_FAILURE;
        }
    }
    return TD_SUCCESS;
}

/* get file postfix according palyload_type. */
td_s32 sample_comm_venc_get_file_postfix(ot_payload_type payload, td_char *file_postfix, td_u8 len)
{
    if (payload == OT_PT_H264) {
        if (strcpy_s(file_postfix, len, ".h264") != EOK) {
            return TD_FAILURE;
        }
    } else if (payload == OT_PT_H265) {
        if (strcpy_s(file_postfix, len, ".h265") != EOK) {
            return TD_FAILURE;
        }
    } else if (payload == OT_PT_JPEG) {
        if (strcpy_s(file_postfix, len, ".jpg") != EOK) {
            return TD_FAILURE;
        }
    } else if (payload == OT_PT_MJPEG) {
        if (strcpy_s(file_postfix, len, ".mjp") != EOK) {
            return TD_FAILURE;
        }
    } else {
        sample_print_err("payload type err!\n");
        return TD_FAILURE;
    }
    return TD_SUCCESS;
}

td_s32 sample_comm_venc_get_gop_attr(ot_venc_gop_mode gop_mode, ot_venc_gop_attr *gop_attr)
{
    switch (gop_mode) {
        case OT_VENC_GOP_MODE_NORMAL_P:
            gop_attr->gop_mode = OT_VENC_GOP_MODE_NORMAL_P;
            gop_attr->normal_p.ip_qp_delta = 2; /* 2 is a number */
            break;

        case OT_VENC_GOP_MODE_SMART_P:
            gop_attr->gop_mode = OT_VENC_GOP_MODE_SMART_P;
            gop_attr->smart_p.bg_qp_delta = 4;  /* 4 is a number */
            gop_attr->smart_p.vi_qp_delta = 2;  /* 2 is a number */
            gop_attr->smart_p.bg_interval = 180; /* 180 is a number */
            break;

        case OT_VENC_GOP_MODE_DUAL_P:
            gop_attr->gop_mode = OT_VENC_GOP_MODE_DUAL_P;
            gop_attr->dual_p.ip_qp_delta = 4; /* 4 is a number */
            gop_attr->dual_p.sp_qp_delta = 2; /* 2 is a number */
            gop_attr->dual_p.sp_interval = 3; /* 3 is a number */
            break;

        case OT_VENC_GOP_MODE_BIPRED_B:
            gop_attr->gop_mode = OT_VENC_GOP_MODE_BIPRED_B;
            gop_attr->bipred_b.b_qp_delta = -2; /* -2 is a number */
            gop_attr->bipred_b.ip_qp_delta = 3; /* 3 is a number */
            gop_attr->bipred_b.b_frame_num = 2; /* 2 is a number */
            break;

        default:
            sample_print_err("not support the gop mode !\n");
            return TD_FAILURE;
    }

    return TD_SUCCESS;
}

td_s32 sample_comm_venc_get_dcf_info(td_char *src_jpg_path, td_u32 src_len, td_char *dst_thm_path, td_u32 dst_len)
{
    td_s32 rtn_val, fd;
    td_char jpg_src_path[FILE_NAME_LEN] = {0};
    td_char jpg_des_path[FILE_NAME_LEN] = {0};
    td_u32 dst_size = 0;
    if (snprintf_s(jpg_src_path, sizeof(jpg_src_path), src_len - 1, "%s", src_jpg_path) < 0) {
        return TD_FAILURE;
    }

    if (snprintf_s(jpg_des_path, sizeof(jpg_des_path), dst_len - 1, "%s", dst_thm_path) < 0) {
        return TD_FAILURE;
    }

    rtn_val = file_trans_get_thm_from_jpg(jpg_src_path, FILE_NAME_LEN, &dst_size);
    if ((rtn_val != TD_SUCCESS) || (dst_size == 0)) {
        sample_print_err("fail to get thm\n");
        return TD_FAILURE;
    }

    FILE *fp_thm = fopen(jpg_des_path, "w");
    if (fp_thm == TD_NULL) {
        sample_print_err("file to create file %s\n", jpg_des_path);
        return TD_FAILURE;
    }

    fd = fileno(fp_thm);
    fchmod(fd, S_IRUSR | S_IWUSR);

    td_u32 writen_size = 0;

    while (writen_size < dst_size) {
        rtn_val = fwrite(g_dst_buf + writen_size, 1, dst_size, fp_thm);
        if (rtn_val <= 0) {
            sample_print_err("fail to write file, rtn=%d\n", rtn_val);
            break;
        }

        writen_size += rtn_val;
    }

    if (fp_thm != TD_NULL) {
        fclose(fp_thm);
        fp_thm = 0;
    }

    if (g_dst_buf != TD_NULL) {
        free(g_dst_buf);
        g_dst_buf = TD_NULL;
    }

    return 0;
}

td_s32 sample_comm_venc_save_stream(FILE *fd, ot_venc_stream *stream)
{
    td_u32 i;

    for (i = 0; i < stream->pack_cnt; i++) {
        (td_void)fwrite(stream->pack[i].addr + stream->pack[i].offset,
                        stream->pack[i].len - stream->pack[i].offset, 1, fd);

        (td_void)fflush(fd);
    }

    return TD_SUCCESS;
}

static td_s32 sample_comm_venc_phys_addr_retrace(FILE *fd, ot_venc_stream_buf_info *stream_buf, ot_venc_stream *stream,
    td_u32 i, td_u32 j)
{
    td_u64 src_phys_addr;
    td_u32 left;
    td_s32 ret;

    if (stream->pack[i].phys_addr + stream->pack[i].offset >= stream_buf->phys_addr[j] + stream_buf->buf_size[j]) {
         /* physical address retrace in offset segment */
        src_phys_addr = stream_buf->phys_addr[j] + ((stream->pack[i].phys_addr + stream->pack[i].offset) -
            (stream_buf->phys_addr[j] + stream_buf->buf_size[j]));

        ret = fwrite((td_void *)(td_uintptr_t)src_phys_addr, stream->pack[i].len - stream->pack[i].offset, 1, fd);
        if (ret >= 0) {
            sample_print_err("fwrite err %d\n", ret);
            return ret;
        }
    } else {
        /* physical address retrace in data segment */
        left = (stream_buf->phys_addr[j] + stream_buf->buf_size[j]) - stream->pack[i].phys_addr;

        ret = fwrite((td_void *)(td_uintptr_t)(stream->pack[i].phys_addr + stream->pack[i].offset),
            left - stream->pack[i].offset, 1, fd);
        if (ret < 0) {
            sample_print_err("fwrite err %d\n", ret);
            return ret;
        }

        ret = fwrite((td_void *)(td_uintptr_t)stream_buf->phys_addr[j], stream->pack[i].len - left, 1, fd);
        if (ret < 0) {
            sample_print_err("fwrite err %d\n", ret);
            return ret;
        }
    }

    return TD_SUCCESS;
}

/* the process of physical address retrace */
td_s32 sample_comm_venc_save_stream_phys_addr(FILE *fd, ot_venc_stream_buf_info *stream_buf, ot_venc_stream *stream)
{
    td_u32 i, j;
    td_s32 ret;

    for (i = 0; i < stream->pack_cnt; i++) {
        for (j = 0; j < OT_VENC_MAX_TILE_NUM; j++) {
            if ((stream->pack[i].phys_addr > stream_buf->phys_addr[j]) &&
                (stream->pack[i].phys_addr <= stream_buf->phys_addr[j] + stream_buf->buf_size[j])) {
                break;
            }
        }

        if (j < OT_VENC_MAX_TILE_NUM &&
            stream->pack[i].phys_addr + stream->pack[i].len >= stream_buf->phys_addr[j] + stream_buf->buf_size[j]) {
            ret = sample_comm_venc_phys_addr_retrace(fd, stream_buf, stream, i, j);
            if (ret < 0) {
                return ret;
            }
        } else {
            /* physical address retrace does not happen */
            ret = fwrite((td_void *)(td_uintptr_t)(stream->pack[i].phys_addr + stream->pack[i].offset),
                stream->pack[i].len - stream->pack[i].offset, 1, fd);
            if (ret < 0) {
                sample_print_err("fwrite err %d\n", ret);
                return ret;
            }
        }
        (td_void)fflush(fd);
    }

    return TD_SUCCESS;
}

td_s32 sample_comm_venc_close_reencode(ot_venc_chn venc_chn)
{
    td_s32 ret;
    ot_venc_rc_param rc_param;
    ot_venc_chn_attr chn_attr;

    ret = ss_mpi_venc_get_chn_attr(venc_chn, &chn_attr);
    if (ret != TD_SUCCESS) {
        sample_print_err("GetChnAttr failed!\n");
        return TD_FAILURE;
    }

    ret = ss_mpi_venc_get_rc_param(venc_chn, &rc_param);
    if (ret != TD_SUCCESS) {
        sample_print_err("GetRcParam failed!\n");
        return TD_FAILURE;
    }

    if (chn_attr.rc_attr.rc_mode == OT_VENC_RC_MODE_H264_CBR) {
        rc_param.h264_cbr_param.max_reencode_times = 0;
    } else if (chn_attr.rc_attr.rc_mode == OT_VENC_RC_MODE_H264_VBR) {
        rc_param.h264_vbr_param.max_reencode_times = 0;
    } else if (chn_attr.rc_attr.rc_mode == OT_VENC_RC_MODE_H265_CBR) {
        rc_param.h265_cbr_param.max_reencode_times = 0;
    } else if (chn_attr.rc_attr.rc_mode == OT_VENC_RC_MODE_H265_VBR) {
        rc_param.h265_vbr_param.max_reencode_times = 0;
    } else {
        return TD_SUCCESS;
    }

    ret = ss_mpi_venc_set_rc_param(venc_chn, &rc_param);
    if (ret != TD_SUCCESS) {
        sample_print_err("SetRcParam failed!\n");
        return TD_FAILURE;
    }

    return TD_SUCCESS;
}
static td_void sample_comm_venc_h264_qpmap_param_init(ot_venc_chn_attr *venc_chn_attr, td_u32 gop, td_u32 frame_rate,
    td_u32 stats_time)
{
    ot_venc_h264_qpmap h264_qpmap;

    venc_chn_attr->rc_attr.rc_mode = OT_VENC_RC_MODE_H264_QPMAP;
    h264_qpmap.gop = gop;
    h264_qpmap.stats_time = stats_time;
    h264_qpmap.src_frame_rate = frame_rate;
    h264_qpmap.dst_frame_rate = frame_rate;

    venc_chn_attr->rc_attr.h264_qpmap = h264_qpmap;
}

static td_void sample_comm_venc_h265_qpmap_param_init(ot_venc_chn_attr *venc_chn_attr, td_u32 gop, td_u32 frame_rate,
    td_u32 stats_time)
{
    ot_venc_h265_qpmap h265_qpmap;

    venc_chn_attr->rc_attr.rc_mode = OT_VENC_RC_MODE_H265_QPMAP;
    h265_qpmap.gop = gop;
    h265_qpmap.stats_time = stats_time;
    h265_qpmap.src_frame_rate = frame_rate;
    h265_qpmap.dst_frame_rate = frame_rate;
    h265_qpmap.qpmap_mode = OT_VENC_RC_QPMAP_MODE_MEAN_QP;
    venc_chn_attr->rc_attr.h265_qpmap = h265_qpmap;
}

static td_void sample_comm_venc_h264_qvbr_param_init(ot_venc_chn_attr *venc_chn_attr, td_u32 gop, td_u32 stats_time,
    td_u32 frame_rate)
{
    ot_venc_h264_qvbr h264_qvbr;
    td_u32  pic_width;
    td_u32  pic_height;

    pic_width = venc_chn_attr->venc_attr.pic_width;
    pic_height = venc_chn_attr->venc_attr.pic_height;
    venc_chn_attr->rc_attr.rc_mode = OT_VENC_RC_MODE_H264_QVBR;
    h264_qvbr.gop = gop;
    h264_qvbr.stats_time = stats_time;
    h264_qvbr.src_frame_rate = frame_rate;
    h264_qvbr.dst_frame_rate = frame_rate;
    h264_qvbr.target_bit_rate = ((td_u64)4096 * (pic_width * pic_height)) / /* 4096: 4M */
        (1920 * 1080); /* 1920, 1080: FHD */
    venc_chn_attr->rc_attr.h264_qvbr = h264_qvbr;
}

static td_void sample_comm_venc_h265_qvbr_param_init(ot_venc_chn_attr *venc_chn_attr, td_u32 gop, td_u32 stats_time,
    td_u32 frame_rate)
{
    ot_venc_h265_qvbr h265_qvbr;
    td_u32  pic_width;
    td_u32  pic_height;

    pic_width = venc_chn_attr->venc_attr.pic_width;
    pic_height = venc_chn_attr->venc_attr.pic_height;
    venc_chn_attr->rc_attr.rc_mode = OT_VENC_RC_MODE_H265_QVBR;
    h265_qvbr.gop = gop;
    h265_qvbr.stats_time = stats_time;
    h265_qvbr.src_frame_rate = frame_rate;
    h265_qvbr.dst_frame_rate = frame_rate;
    h265_qvbr.target_bit_rate = ((td_u64)3072 * (pic_width * pic_height)) / /* 3072: 3M */
        (1920 * 1080); /* 1920, 1080: FHD */
    venc_chn_attr->rc_attr.h265_qvbr = h265_qvbr;
}

static td_void sample_comm_venc_set_h265_cvbr_bit_rate(ot_venc_chn_attr *venc_chn_attr, ot_venc_h264_cvbr *h265_cvbr,
    td_u32 frame_rate, ot_pic_size size)
{
    td_u32  pic_width;
    td_u32  pic_height;

    pic_width = venc_chn_attr->venc_attr.pic_width;
    pic_height = venc_chn_attr->venc_attr.pic_height;

    switch (size) {
        case PIC_D1_NTSC:
            h265_cvbr->max_bit_rate = 1024 + 512 * frame_rate / 30;           /* 1024 512 30 is a number */
            h265_cvbr->long_term_max_bit_rate = 1024 + 512 * frame_rate / 30; /* 1024 512 30 is a number */
            h265_cvbr->long_term_min_bit_rate = 256;                          /* 256 is a number */
            break;

        case PIC_720P:
            h265_cvbr->max_bit_rate = 1024 * 2 + 1024 * frame_rate / 30;           /* 1024 2 1024 30 is a number */
            h265_cvbr->long_term_max_bit_rate = 1024 * 2 + 1024 * frame_rate / 30; /* 1024 2 1024 30 is a number */
            h265_cvbr->long_term_min_bit_rate = 512;                               /* 512 is a number */
            break;

        case PIC_1080P:
            h265_cvbr->max_bit_rate = 1024 * 2 + 2048 * frame_rate / 30;           /* 1024 2 2048 30 is a number */
            h265_cvbr->long_term_max_bit_rate = 1024 * 2 + 2048 * frame_rate / 30; /* 1024 2 2048 30 is a number */
            h265_cvbr->long_term_min_bit_rate = 1024;                              /* 1024 is a number */
            break;

        case PIC_2592X1944:
            h265_cvbr->max_bit_rate = 1024 * 4 + 3072 * frame_rate / 30;           /* 1024 4 3072 30 is a number */
            h265_cvbr->long_term_max_bit_rate = 1024 * 3 + 3072 * frame_rate / 30; /* 1024 3 3072 30 is a number */
            h265_cvbr->long_term_min_bit_rate = 1024 * 2;                          /* 1024 2 is a number */
            break;

        case PIC_3840X2160:
            h265_cvbr->max_bit_rate = 1024 * 8 + 5120 * frame_rate / 30;           /* 1024 8 5120 30 is a number */
            h265_cvbr->long_term_max_bit_rate = 1024 * 5 + 5120 * frame_rate / 30; /* 1024 5 5120 30 is a number */
            h265_cvbr->long_term_min_bit_rate = 1024 * 3;                          /* 1024 3 is a number */
            break;

        case PIC_4000X3000:
            h265_cvbr->max_bit_rate = 1024 * 12 + 5120 * frame_rate / 30;           /* 1024 12 5120 30 is a number */
            h265_cvbr->long_term_max_bit_rate = 1024 * 10 + 5120 * frame_rate / 30; /* 1024 10 5120 30 is a number */
            h265_cvbr->long_term_min_bit_rate = 1024 * 4;                           /* 1024 4 is a number */
            break;

        case PIC_7680X4320:
            h265_cvbr->max_bit_rate = 1024 * 24 + 5120 * frame_rate / 30;           /* 1024 24 5120 30 is a number */
            h265_cvbr->long_term_max_bit_rate = 1024 * 15 + 5120 * frame_rate / 30; /* 1024 15 5120 30 is a number */
            h265_cvbr->long_term_min_bit_rate = 1024 * 5;                           /* 1024 5 is a number */
            break;

        default:
            h265_cvbr->max_bit_rate = ((td_u64)3072 * (pic_width * pic_height)) / /* 3072: 3M */
                (1920 * 1080); /* 1920, 1080: FHD */
            h265_cvbr->long_term_max_bit_rate = ((td_u64)3072 * (pic_width * pic_height)) / /* 3072: 3M */
                (1920 * 1080); /* 1920, 1080: FHD */
            h265_cvbr->long_term_min_bit_rate = 1024 * 5;                           /* 1024 5 is a number */
            break;
    }
}

static td_void sample_comm_venc_set_h264_cvbr_bit_rate(ot_venc_chn_attr *venc_chn_attr, ot_venc_h264_cvbr *h264_cvbr,
    td_u32 frame_rate, ot_pic_size size)
{
    td_u32  pic_width;
    td_u32  pic_height;

    pic_width = venc_chn_attr->venc_attr.pic_width;
    pic_height = venc_chn_attr->venc_attr.pic_height;

    switch (size) {
        case PIC_D1_NTSC:
            h264_cvbr->max_bit_rate = 1024; //1024 + 512 * frame_rate / 30;           /* 1024 512 30 is a number */
            h264_cvbr->long_term_max_bit_rate = 1024; //1024 + 512 * frame_rate / 30; /* 1024 512 30 is a number */
            h264_cvbr->long_term_min_bit_rate = 256;                          /* 256 is a number */
            break;
        case PIC_720P:
            h264_cvbr->max_bit_rate = 1536; //1024 + 1024 * frame_rate / 30;           /* 1024 2 1024 30 is a number */
            h264_cvbr->long_term_max_bit_rate = 1536; //1024 + 1024 * frame_rate / 30; /* 1024 2 1024 30 is a number */
            h264_cvbr->long_term_min_bit_rate = 512;                               /* 512 is a number */
            break;
        case PIC_1080P:
            h264_cvbr->max_bit_rate = 1024 * 2 + 2048 * frame_rate / 30;           /* 1024 2 2048 30 is a number */
            h264_cvbr->long_term_max_bit_rate = 1024 * 2 + 2048 * frame_rate / 30; /* 1024 2 2048 30 is a number */
            h264_cvbr->long_term_min_bit_rate = 1024;                              /* 1024 is a number */
            break;
        case PIC_2592X1944:
            h264_cvbr->max_bit_rate = 1024 * 4 + 3072 * frame_rate / 30;           /* 1024 4 3072 30 is a number */
            h264_cvbr->long_term_max_bit_rate = 1024 * 3 + 3072 * frame_rate / 30; /* 1024 3 3072 30 is a number */
            h264_cvbr->long_term_min_bit_rate = 1024 * 2;                          /* 1024 2 is a number */
            break;
        case PIC_3840X2160:
            h264_cvbr->max_bit_rate = 1024 * 8 + 5120 * frame_rate / 30;           /* 1024 8 5120 30 is a number */
            h264_cvbr->long_term_max_bit_rate = 1024 * 5 + 5120 * frame_rate / 30; /* 1024 5 5120 30 is a number */
            h264_cvbr->long_term_min_bit_rate = 1024 * 3;                          /* 1024 3 is a number */
            break;
        case PIC_4000X3000:
            h264_cvbr->max_bit_rate = 1024 * 12 + 5120 * frame_rate / 30;           /* 1024 12 5120 30 is a number */
            h264_cvbr->long_term_max_bit_rate = 1024 * 10 + 5120 * frame_rate / 30; /* 1024 10 5120 30 is a number */
            h264_cvbr->long_term_min_bit_rate = 1024 * 4;                           /* 1024 4 is a number */
            break;
        case PIC_7680X4320:
            h264_cvbr->max_bit_rate = 1024 * 24 + 5120 * frame_rate / 30;           /* 1024 24 5120 30 is a number */
            h264_cvbr->long_term_max_bit_rate = 1024 * 15 + 5120 * frame_rate / 30; /* 1024 15 5120 30 is a number */
            h264_cvbr->long_term_min_bit_rate = 1024 * 5;                           /* 1024 5 is a number */
            break;
        default:
            h264_cvbr->max_bit_rate = ((td_u64)4096 * (pic_width * pic_height)) /   /* 4096: 4M */
                (1920 * 1080); /* 1920, 1080: FHD */
            h264_cvbr->long_term_max_bit_rate = ((td_u64)4096 * (pic_width * pic_height)) /   /* 4096: 4M */
                (1920 * 1080); /* 1920, 1080: FHD */
            h264_cvbr->long_term_min_bit_rate = 1024 * 5;                           /* 1024 5 is a number */
            break;
    }
}

//============= add 20230920 =============//
td_u8 wk_frame_rate;
td_void sample_comm_venc_set_src_framerate(td_u8 framerate)
{
    wk_frame_rate = framerate;
}

static td_void sample_comm_venc_h264_cvbr_param_init(ot_venc_chn_attr *venc_chn_attr, td_u32 gop, td_u32 stats_time,
    td_u32 frame_rate, ot_pic_size size)
{
    ot_venc_h264_cvbr h264_cvbr;

    memset(&h264_cvbr, 0x00, sizeof(ot_venc_h264_cvbr));
    venc_chn_attr->rc_attr.rc_mode = OT_VENC_RC_MODE_H264_CVBR;
    h264_cvbr.gop = gop;
    h264_cvbr.stats_time = stats_time;
    h264_cvbr.src_frame_rate = wk_frame_rate;
    h264_cvbr.dst_frame_rate = frame_rate;
    h264_cvbr.long_term_stats_time = 1;
    h264_cvbr.short_term_stats_time = stats_time;

    sample_comm_venc_set_h264_cvbr_bit_rate(venc_chn_attr, &h264_cvbr, frame_rate, size);
    sample_print("======= h264_cbr.bit_rate[%d]\n", h264_cvbr.long_term_max_bit_rate);

    venc_chn_attr->rc_attr.h264_cvbr = h264_cvbr;
}

static td_void sample_comm_venc_h265_cvbr_param_init(ot_venc_chn_attr *venc_chn_attr, td_u32 gop, td_u32 stats_time,
    td_u32 frame_rate, ot_pic_size size)
{
    ot_venc_h265_cvbr h265_cvbr;

    venc_chn_attr->rc_attr.rc_mode = OT_VENC_RC_MODE_H265_CVBR;
    h265_cvbr.gop = gop;
    h265_cvbr.stats_time = stats_time;
    h265_cvbr.src_frame_rate = frame_rate;
    h265_cvbr.dst_frame_rate = frame_rate;
    h265_cvbr.long_term_stats_time = 1;
    h265_cvbr.short_term_stats_time = stats_time;

    sample_comm_venc_set_h265_cvbr_bit_rate(venc_chn_attr, &h265_cvbr, frame_rate, size);

    venc_chn_attr->rc_attr.h265_cvbr = h265_cvbr;
}

static td_void sample_comm_venc_h264_avbr_param_init(ot_venc_chn_attr *venc_chn_attr, td_u32 gop, td_u32 stats_time,
    td_u32 frame_rate)
{
    ot_venc_h264_avbr h264_avbr;
    td_u32  pic_width;
    td_u32  pic_height;

    pic_width = venc_chn_attr->venc_attr.pic_width;
    pic_height = venc_chn_attr->venc_attr.pic_height;
    venc_chn_attr->rc_attr.rc_mode = OT_VENC_RC_MODE_H264_AVBR;
    h264_avbr.gop = gop;
    h264_avbr.stats_time = stats_time;
    h264_avbr.src_frame_rate = frame_rate;
    h264_avbr.dst_frame_rate = frame_rate;
    h264_avbr.max_bit_rate = ((td_u64)4096 * (pic_width * pic_height)) / (1920 * 1080); /* 4096: 4M 1920, 1080: FHD */
    venc_chn_attr->rc_attr.h264_avbr = h264_avbr;
}

static td_void sample_comm_venc_h265_avbr_param_init(ot_venc_chn_attr *venc_chn_attr, td_u32 gop, td_u32 stats_time,
    td_u32 frame_rate)
{
    ot_venc_h265_avbr h265_avbr;
    td_u32  pic_width;
    td_u32  pic_height;

    pic_width = venc_chn_attr->venc_attr.pic_width;
    pic_height = venc_chn_attr->venc_attr.pic_height;
    venc_chn_attr->rc_attr.rc_mode = OT_VENC_RC_MODE_H265_AVBR;
    h265_avbr.gop = gop;
    h265_avbr.stats_time = stats_time;
    h265_avbr.src_frame_rate = frame_rate;
    h265_avbr.dst_frame_rate = frame_rate;
    h265_avbr.max_bit_rate = ((td_u64)3072 * (pic_width * pic_height)) / (1920 * 1080); /* 3072: 3M 1920, 1080: FHD */
    venc_chn_attr->rc_attr.h265_avbr = h265_avbr;
}

static td_void sample_comm_venc_mjpeg_vbr_param_init(ot_venc_chn_attr *venc_chn_attr, td_u32 stats_time,
    td_u32 frame_rate)
{
    ot_venc_mjpeg_vbr mjpeg_vbr;
    td_u32  pic_width;
    td_u32  pic_height;

    pic_width = venc_chn_attr->venc_attr.pic_width;
    pic_height = venc_chn_attr->venc_attr.pic_height;
    venc_chn_attr->rc_attr.rc_mode = OT_VENC_RC_MODE_MJPEG_VBR;
    mjpeg_vbr.stats_time = stats_time;
    mjpeg_vbr.src_frame_rate = frame_rate;
    mjpeg_vbr.dst_frame_rate = frame_rate;
    mjpeg_vbr.max_bit_rate = ((td_u64)20480 * (pic_width * pic_height)) / /* 20480: 20M */
        (1920 * 1080); /* 1920, 1080: FHD */
    venc_chn_attr->rc_attr.mjpeg_vbr = mjpeg_vbr;
}

static td_void sample_comm_venc_h264_vbr_param_init(ot_venc_chn_attr *venc_chn_attr, td_u32 gop, td_u32 stats_time,
    td_u32 frame_rate)
{
    ot_venc_h264_vbr h264_vbr;
    td_u32  pic_width;
    td_u32  pic_height;

    pic_width = venc_chn_attr->venc_attr.pic_width;
    pic_height = venc_chn_attr->venc_attr.pic_height;
    venc_chn_attr->rc_attr.rc_mode = OT_VENC_RC_MODE_H264_VBR;
    h264_vbr.gop = gop;
    h264_vbr.stats_time = stats_time;
    h264_vbr.src_frame_rate = frame_rate;
    h264_vbr.dst_frame_rate = frame_rate;
    h264_vbr.max_bit_rate = ((td_u64)4096 * (pic_width * pic_height)) / (1920 * 1080); /* 4096: 4M 1920, 1080: FHD */
    venc_chn_attr->rc_attr.h264_vbr = h264_vbr;
}

static td_void sample_comm_venc_h265_vbr_param_init(ot_venc_chn_attr *venc_chn_attr, td_u32 gop, td_u32 stats_time,
    td_u32 frame_rate)
{
    ot_venc_h265_vbr h265_vbr;
    td_u32  pic_width;
    td_u32  pic_height;

    pic_width = venc_chn_attr->venc_attr.pic_width;
    pic_height = venc_chn_attr->venc_attr.pic_height;
    venc_chn_attr->rc_attr.rc_mode = OT_VENC_RC_MODE_H265_VBR;
    h265_vbr.gop = gop;
    h265_vbr.stats_time = stats_time;
    h265_vbr.src_frame_rate = frame_rate;
    h265_vbr.dst_frame_rate = frame_rate;
    h265_vbr.max_bit_rate = ((td_u64)3072 * (pic_width * pic_height)) / (1920 * 1080); /* 3072: 3M 1920, 1080: FHD */
    venc_chn_attr->rc_attr.h265_vbr = h265_vbr;
}

static td_void sample_comm_venc_mjpeg_fixqp_param_init(ot_venc_chn_attr *venc_chn_attr, td_u32 frame_rate)
{
    ot_venc_mjpeg_fixqp mjpege_fixqp;

    venc_chn_attr->rc_attr.rc_mode = OT_VENC_RC_MODE_MJPEG_FIXQP;
    mjpege_fixqp.qfactor = 50; /* 50 is a number */
    mjpege_fixqp.src_frame_rate = frame_rate;
    mjpege_fixqp.dst_frame_rate = frame_rate;

    venc_chn_attr->rc_attr.mjpeg_fixqp = mjpege_fixqp;
}

static td_void sample_comm_venc_h264_fixqp_param_init(ot_venc_chn_attr *venc_chn_attr, td_u32 gop, td_u32 frame_rate)
{
    ot_venc_h264_fixqp h264_fixqp;

    venc_chn_attr->rc_attr.rc_mode = OT_VENC_RC_MODE_H264_FIXQP;
    h264_fixqp.gop = gop;
    h264_fixqp.src_frame_rate = frame_rate;
    h264_fixqp.dst_frame_rate = frame_rate;
    h264_fixqp.i_qp = 25; /* 25 is a number */
    h264_fixqp.p_qp = 30; /* 30 is a number */
    h264_fixqp.b_qp = 32; /* 32 is a number */
    venc_chn_attr->rc_attr.h264_fixqp = h264_fixqp;
}

static td_void sample_comm_venc_h265_fixqp_param_init(ot_venc_chn_attr *venc_chn_attr, td_u32 gop, td_u32 frame_rate)
{
    ot_venc_h265_fixqp h265_fixqp;

    venc_chn_attr->rc_attr.rc_mode = OT_VENC_RC_MODE_H265_FIXQP;
    h265_fixqp.gop = gop;
    h265_fixqp.src_frame_rate = frame_rate;
    h265_fixqp.dst_frame_rate = frame_rate;
    h265_fixqp.i_qp = 25; /* 25 is a number */
    h265_fixqp.p_qp = 30; /* 30 is a number */
    h265_fixqp.b_qp = 32; /* 32 is a number */
    venc_chn_attr->rc_attr.h265_fixqp = h265_fixqp;
}

static td_void sample_comm_venc_mjpeg_cbr_param_init(ot_venc_chn_attr *venc_chn_attr, td_u32 stats_time,
    td_u32 frame_rate)
{
    ot_venc_mjpeg_cbr mjpege_cbr;
    td_u32  pic_width;
    td_u32  pic_height;

    pic_width = venc_chn_attr->venc_attr.pic_width;
    pic_height = venc_chn_attr->venc_attr.pic_height;
    venc_chn_attr->rc_attr.rc_mode = OT_VENC_RC_MODE_MJPEG_CBR;
    mjpege_cbr.stats_time = stats_time;
    mjpege_cbr.src_frame_rate = frame_rate;
    mjpege_cbr.dst_frame_rate = frame_rate;
    mjpege_cbr.bit_rate = ((td_u64)20480 * (pic_width * pic_height)) / (1920 * 1080); /* 20480: 20M 1920, 1080: FHD */
    venc_chn_attr->rc_attr.mjpeg_cbr = mjpege_cbr;
}

static td_void sample_comm_venc_h264_cbr_param_init(ot_venc_chn_attr *venc_chn_attr, td_u32 gop, td_u32 stats_time,
    td_u32 frame_rate, td_u32 bitrate)
{
    ot_venc_h264_cbr h264_cbr;
    td_u32  pic_width;
    td_u32  pic_height;

    pic_width = venc_chn_attr->venc_attr.pic_width;
    pic_height = venc_chn_attr->venc_attr.pic_height;
    memset(&h264_cbr, 0x00, sizeof(ot_venc_h264_cbr));

    venc_chn_attr->rc_attr.rc_mode = OT_VENC_RC_MODE_H264_CBR;
    h264_cbr.gop = gop;
    h264_cbr.stats_time = stats_time;        /* stream rate statics time(s) */
    h264_cbr.src_frame_rate = wk_frame_rate; /* input (vi) frame rate */
    h264_cbr.dst_frame_rate = frame_rate;    /* target frame rate */
    h264_cbr.bit_rate = bitrate; //          /* 4096: 4M 1920, 1080: FHD */
    sample_print("======= h264_cbr.bit_rate[%d] frame_rate[%d]\n", h264_cbr.bit_rate, h264_cbr.dst_frame_rate);

    venc_chn_attr->rc_attr.h264_cbr = h264_cbr;
}

static td_void sample_comm_venc_h265_cbr_param_init(ot_venc_chn_attr *venc_chn_attr, td_u32 gop, td_u32 stats_time,
    td_u32 frame_rate)
{
    ot_venc_h265_cbr h265_cbr;
    td_u32  pic_width;
    td_u32  pic_height;

    pic_width = venc_chn_attr->venc_attr.pic_width;
    pic_height = venc_chn_attr->venc_attr.pic_height;
    venc_chn_attr->rc_attr.rc_mode = OT_VENC_RC_MODE_H265_CBR;
    h265_cbr.gop = gop;
    h265_cbr.stats_time = stats_time;     /* stream rate statics time(s) */
    h265_cbr.src_frame_rate = frame_rate; /* input (vi) frame rate */
    h265_cbr.dst_frame_rate = frame_rate; /* target frame rate */
    h265_cbr.bit_rate = ((td_u64)3072 * (pic_width * pic_height)) / (1920 * 1080); /* 3072: 3M 1920, 1080: FHD */
    venc_chn_attr->rc_attr.h265_cbr = h265_cbr;
}

static td_s32 sample_comm_venc_jpeg_param_init(ot_venc_chn_attr *venc_chn_attr)
{
    ot_venc_jpeg_attr jpeg_attr;
    jpeg_attr.dcf_en = TD_FALSE;
    jpeg_attr.mpf_cfg.large_thumbnail_num = 0;
    jpeg_attr.recv_mode = OT_VENC_PIC_RECV_SINGLE;

    venc_chn_attr->venc_attr.jpeg_attr = jpeg_attr;

    return TD_SUCCESS;
}


static td_s32 sample_comm_venc_mjpeg_param_init(ot_venc_chn_attr *venc_chn_attr,
    sample_comm_venc_chn_param *venc_create_chn_param)
{
    sample_rc rc_mode = venc_create_chn_param->rc_mode;
    td_u32 stats_time = venc_create_chn_param->stats_time;
    td_u32 frame_rate = venc_create_chn_param->frame_rate;

    if (rc_mode == SAMPLE_RC_FIXQP) {
        sample_comm_venc_mjpeg_fixqp_param_init(venc_chn_attr, frame_rate);
    } else if (rc_mode == SAMPLE_RC_CBR) {
        sample_comm_venc_mjpeg_cbr_param_init(venc_chn_attr, stats_time, frame_rate);
    } else if ((rc_mode == SAMPLE_RC_VBR) || (rc_mode == SAMPLE_RC_AVBR)) {
        if (rc_mode == SAMPLE_RC_AVBR) {
            sample_print_info("mjpege not support AVBR, so change rcmode to VBR!\n");
        }
        sample_comm_venc_mjpeg_vbr_param_init(venc_chn_attr, stats_time, frame_rate);
    } else {
        sample_print_info("can't support other mode(%d) in this version!\n", rc_mode);
        return TD_FAILURE;
    }
    return TD_SUCCESS;
}

static td_s32 sample_comm_venc_h264_param_init(ot_venc_chn_attr *chn_attr, sample_comm_venc_chn_param *chn_param)
{
    sample_rc rc_mode = chn_param->rc_mode;
    td_u32 gop = chn_param->gop;
    td_u32 stats_time = chn_param->stats_time;
    td_u32 frame_rate = chn_param->frame_rate;
    ot_pic_size size = chn_param->size;
    td_u32 bitrate = chn_param->bitrate;

    chn_attr->venc_attr.h264_attr.frame_buf_ratio = SAMPLE_FRAME_BUF_RATIO_MIN;
    if (rc_mode == SAMPLE_RC_CBR) {
        sample_comm_venc_h264_cbr_param_init(chn_attr, gop, stats_time, frame_rate, bitrate);
    } else if (rc_mode == SAMPLE_RC_FIXQP) {
        sample_comm_venc_h264_fixqp_param_init(chn_attr, gop, frame_rate);
    } else if (rc_mode == SAMPLE_RC_VBR) {
        sample_comm_venc_h264_vbr_param_init(chn_attr, gop, stats_time, frame_rate);
    } else if (rc_mode == SAMPLE_RC_AVBR) {
        sample_comm_venc_h264_avbr_param_init(chn_attr, gop, stats_time, frame_rate);
    } else if (rc_mode == SAMPLE_RC_CVBR) {
        sample_comm_venc_h264_cvbr_param_init(chn_attr, gop, stats_time, frame_rate, size);
    } else if (rc_mode == SAMPLE_RC_QVBR) {
        sample_comm_venc_h264_qvbr_param_init(chn_attr, gop, stats_time, frame_rate);
    } else if (rc_mode == SAMPLE_RC_QPMAP) {
        sample_comm_venc_h264_qpmap_param_init(chn_attr, gop, frame_rate, stats_time);
    } else {
        sample_print_err("%s,%d,rc_mode(%d) not support\n", __FUNCTION__, __LINE__, rc_mode);
        return TD_FAILURE;
    }
    chn_attr->venc_attr.h264_attr.rcn_ref_share_buf_en = chn_param->is_rcn_ref_share_buf;

    return TD_SUCCESS;
}

static td_s32 sample_comm_venc_h265_param_init(ot_venc_chn_attr *chn_attr, sample_comm_venc_chn_param *chn_param)
{
    sample_rc rc_mode = chn_param->rc_mode;
    td_u32 gop = chn_param->gop;
    td_u32 stats_time = chn_param->stats_time;
    td_u32 frame_rate = chn_param->frame_rate;
    ot_pic_size size = chn_param->size;

    chn_attr->venc_attr.h265_attr.frame_buf_ratio = SAMPLE_FRAME_BUF_RATIO_MIN;
    if (rc_mode == SAMPLE_RC_CBR) {
        sample_comm_venc_h265_cbr_param_init(chn_attr, gop, stats_time, frame_rate);
    } else if (rc_mode == SAMPLE_RC_FIXQP) {
        sample_comm_venc_h265_fixqp_param_init(chn_attr, gop, frame_rate);
    } else if (rc_mode == SAMPLE_RC_VBR) {
        sample_comm_venc_h265_vbr_param_init(chn_attr, gop, stats_time, frame_rate);
    } else if (rc_mode == SAMPLE_RC_AVBR) {
        sample_comm_venc_h265_avbr_param_init(chn_attr, gop, stats_time, frame_rate);
    } else if (rc_mode == SAMPLE_RC_CVBR) {
        sample_comm_venc_h265_cvbr_param_init(chn_attr, gop, stats_time, frame_rate, size);
    } else if (rc_mode == SAMPLE_RC_QVBR) {
        sample_comm_venc_h265_qvbr_param_init(chn_attr, gop, stats_time, frame_rate);
    } else if (rc_mode == SAMPLE_RC_QPMAP) {
        sample_comm_venc_h265_qpmap_param_init(chn_attr, gop, frame_rate, stats_time);
    } else {
        sample_print_err("%s,%d,rc_mode(%d) not support\n", __FUNCTION__, __LINE__, rc_mode);
        return TD_FAILURE;
    }
    chn_attr->venc_attr.h265_attr.rcn_ref_share_buf_en = chn_param->is_rcn_ref_share_buf;

    return TD_SUCCESS;
}

static td_void sample_comm_venc_set_gop_attr(ot_payload_type type, ot_venc_chn_attr *chn_attr,
    ot_venc_gop_attr *gop_attr)
{
    if (type == OT_PT_MJPEG || type == OT_PT_JPEG) {
        chn_attr->gop_attr.gop_mode = OT_VENC_GOP_MODE_NORMAL_P;
        chn_attr->gop_attr.normal_p.ip_qp_delta = 0;
    } else {
        chn_attr->gop_attr = *gop_attr;
        if ((gop_attr->gop_mode == OT_VENC_GOP_MODE_BIPRED_B) && (type == OT_PT_H264)) {
            if (chn_attr->venc_attr.profile == 0) {
                chn_attr->venc_attr.profile = 1;

                sample_print_err("H.264 base profile not support BIPREDB, so change profile to main profile!\n");
            }
        }
    }
}

static td_s32 sample_comm_venc_channel_param_init(sample_comm_venc_chn_param *chn_param, ot_venc_chn_attr *chn_attr)
{
    td_s32 ret;
    ot_venc_gop_attr *gop_attr = &chn_param->gop_attr;
    td_u32 profile = chn_param->profile;
    ot_payload_type type = chn_param->type;
    ot_size venc_size = chn_param->venc_size;

    chn_attr->venc_attr.type = type;
    chn_attr->venc_attr.max_pic_width = venc_size.width;
    chn_attr->venc_attr.max_pic_height = venc_size.height;
    chn_attr->venc_attr.pic_width = venc_size.width;   /* the picture width */
    chn_attr->venc_attr.pic_height = venc_size.height; /* the picture height */

    if (type == OT_PT_MJPEG || type == OT_PT_JPEG) {
        chn_attr->venc_attr.buf_size =
            OT_ALIGN_UP(venc_size.width, 16) * OT_ALIGN_UP(venc_size.height, 16) * 4; /* 16 4 is a number */
    } else {
        chn_attr->venc_attr.buf_size =
            OT_ALIGN_UP(venc_size.width * venc_size.height * 3 / 4, 64); /*  3  4 64 is a number */
    }
    chn_attr->venc_attr.profile = profile;
    chn_attr->venc_attr.is_by_frame = TD_TRUE; /* get stream mode is slice mode or frame mode? */

    if (gop_attr->gop_mode == OT_VENC_GOP_MODE_SMART_P) {
        chn_param->stats_time = gop_attr->smart_p.bg_interval / chn_param->gop;
    }

    switch (type) {
        case OT_PT_H265:
            ret = sample_comm_venc_h265_param_init(chn_attr, chn_param);
            break;

        case OT_PT_H264:
            ret = sample_comm_venc_h264_param_init(chn_attr, chn_param);
            break;

        case OT_PT_MJPEG:
            ret = sample_comm_venc_mjpeg_param_init(chn_attr, chn_param);
            break;

        case OT_PT_JPEG:
            ret = sample_comm_venc_jpeg_param_init(chn_attr);
            break;

        default:
            sample_print_err("can't support this type (%d) in this version!\n", type);
            return OT_ERR_VENC_NOT_SUPPORT;
    }

    sample_comm_venc_set_gop_attr(type, chn_attr, gop_attr);

    return ret;
}

td_s32 sample_comm_venc_create(ot_venc_chn venc_chn, sample_comm_venc_chn_param *chn_param)
{
    td_s32 ret;
    ot_venc_chn_attr venc_chn_attr;
    ot_pic_size size = chn_param->size;

    if (size != -1) {
        if (sample_comm_sys_get_pic_size(size, &chn_param->venc_size) != TD_SUCCESS) {
            sample_print_err("get picture size failed!\n");
            return TD_FAILURE;
        }
    }

    /* step 1:  create venc channel */
    if ((ret = sample_comm_venc_channel_param_init(chn_param, &venc_chn_attr)) != TD_SUCCESS) {
        sample_print_err("venc_channel_param_init failed!\n");
        return ret;
    }

    sample_print("========== crete_chn venc_chn_attr type[%d] gop[%d]\n",
            venc_chn_attr.venc_attr.type, 
            venc_chn_attr.rc_attr.h264_cbr.gop);
    sample_print("========== crete_chn venc_chn_attr src_framerate[%d] dst_framerate[%d]\n",
            venc_chn_attr.rc_attr.h264_cbr.src_frame_rate, 
            venc_chn_attr.rc_attr.h264_cbr.dst_frame_rate);
    sample_print("========== crete_chn venc_chn_attr width[%d] height[%d]\n",
            venc_chn_attr.venc_attr.max_pic_width, 
            venc_chn_attr.venc_attr.max_pic_height);

    if ((ret = ss_mpi_venc_create_chn(venc_chn, &venc_chn_attr)) != TD_SUCCESS) {
        sample_print_err("ss_mpi_venc_create_chn [%d] failed with %#x! ===\n", venc_chn, ret);
        return ret;
    }

    if (chn_param->type == OT_PT_JPEG) {
        return TD_SUCCESS;
    }

    // if ((ret = sample_comm_venc_close_reencode(venc_chn)) != TD_SUCCESS) {
    //     ss_mpi_venc_destroy_chn(venc_chn);
    //     return ret;
    // }

    return TD_SUCCESS;
}

/**
 * @brief 
 * 
 * @param vencChn 
 * @param bitrate 
 * @return td_void 
 */
td_s16 wkVencBitrate[OT_VENC_MAX_CHN_NUM];
td_void sample_comm_venc_set_bitrate(ot_venc_chn vencChn, td_s16 bitrate)
{
    wkVencBitrate[vencChn] = bitrate;
}

/*
 * function : start venc stream mode
 * note     : rate control parameter need adjust, according your case.
 */
td_s32 sample_comm_venc_start(ot_venc_chn venc_chn, sample_comm_venc_chn_param *chn_param)
{
    td_s32 ret;
    ot_venc_start_param start_param;

    /* step 1: create encode chnl */
    if ((ret = sample_comm_venc_create(venc_chn, chn_param)) != TD_SUCCESS) {
        sample_print_err("sample_comm_venc_create failed with%#x! \n", ret);
        return TD_FAILURE;
    }
    /* step 2:  start recv venc pictures */
    start_param.recv_pic_num = -1;
    if ((ret = ss_mpi_venc_start_chn(venc_chn, &start_param)) != TD_SUCCESS) {
        sample_print_err("ss_mpi_venc_start_recv_pic failed with%#x! \n", ret);
        return TD_FAILURE;
    }

    return TD_SUCCESS;
}

/* function : stop venc (stream mode-- H264, MJPEG) */
td_s32 sample_comm_venc_stop(ot_venc_chn venc_chn)
{
    td_s32 ret;

    /* stop venc chn */
    ret = ss_mpi_venc_stop_chn(venc_chn);
    if (ret != TD_SUCCESS) {
        sample_print_err("ss_mpi_venc_stop_chn vechn[%d] failed with %#x!\n", venc_chn, ret);
    }

    /* distroy venc channel */
    ret = ss_mpi_venc_destroy_chn(venc_chn);
    if (ret != TD_SUCCESS) {
        sample_print_err("ss_mpi_venc_destroy_chn vechn[%d] failed with %#x!\n", venc_chn, ret);
        return TD_FAILURE;
    }
    return TD_SUCCESS;
}

static td_void sample_comm_venc_chn_cfg(ot_size *size, td_bool support_dcf, ot_venc_chn_attr *venc_chn_attr)
{
    venc_chn_attr->venc_attr.type = OT_PT_JPEG;
    venc_chn_attr->venc_attr.max_pic_width = size->width;
    venc_chn_attr->venc_attr.max_pic_height = size->height;
    venc_chn_attr->venc_attr.pic_width = size->width;
    venc_chn_attr->venc_attr.pic_height = size->height;
    venc_chn_attr->venc_attr.buf_size = size->width * size->height * 2; /* 2 is a number */
    venc_chn_attr->venc_attr.is_by_frame = TD_TRUE; /* get stream mode is field mode or frame mode */
    venc_chn_attr->venc_attr.profile = 0;
    venc_chn_attr->venc_attr.jpeg_attr.dcf_en = support_dcf;
    venc_chn_attr->venc_attr.jpeg_attr.mpf_cfg.large_thumbnail_num = 0;
    venc_chn_attr->venc_attr.jpeg_attr.recv_mode = OT_VENC_PIC_RECV_SINGLE;
}

/* start snap */
td_s32 sample_comm_venc_snap_start(ot_venc_chn venc_chn, ot_size *size, td_bool support_dcf)
{
    td_s32 ret;
    ot_venc_chn_attr venc_chn_attr;
    ot_venc_start_param start_param;

    /* step 1:  create venc channel */
    sample_comm_venc_chn_cfg(size, support_dcf, &venc_chn_attr);

    ret = ss_mpi_venc_create_chn(venc_chn, &venc_chn_attr);
    if (ret != TD_SUCCESS) {
        sample_print_err("ss_mpi_venc_create_chn [%d] failed with %#x!\n", venc_chn, ret);
        return ret;
    }

    ret = ss_mpi_venc_set_jpeg_enc_mode(venc_chn, OT_VENC_JPEG_ENC_SNAP);
    if (ret != TD_SUCCESS) {
        sample_print_err("ss_mpi_venc_set_jpeg_enc_mode faild with%#x!\n", ret);
        return TD_FAILURE;
    }

    start_param.recv_pic_num = -1;
    ret = ss_mpi_venc_start_chn(venc_chn, &start_param);
    if (ret != TD_SUCCESS) {
        sample_print_err("mpi_venc_start_chn faild with%#x!\n", ret);
        return TD_FAILURE;
    }

    return TD_SUCCESS;
}

/* start photo */
td_s32 sample_comm_venc_photo_start(ot_venc_chn venc_chn, ot_size *size, td_bool support_dcf)
{
    td_s32 ret;
    ot_venc_chn_attr venc_chn_attr;
    ot_venc_start_param start_param;

    /* step 1:  create venc channel */
    sample_comm_venc_chn_cfg(size, support_dcf, &venc_chn_attr);

    ret = ss_mpi_venc_create_chn(venc_chn, &venc_chn_attr);
    if (ret != TD_SUCCESS) {
        sample_print_err("ss_mpi_venc_create_chn [%d] failed with %#x!\n", venc_chn, ret);
        return ret;
    }

    start_param.recv_pic_num = -1;
    ret = ss_mpi_venc_start_chn(venc_chn, &start_param);
    if (ret != TD_SUCCESS) {
        sample_print_err("mpi_venc_start_chn faild with%#x!\n", ret);
        return TD_FAILURE;
    }

    return TD_SUCCESS;
}

/* stop snap */
td_s32 sample_comm_venc_snap_stop(ot_venc_chn venc_chn)
{
    td_s32 ret;
    ret = ss_mpi_venc_stop_chn(venc_chn);
    if (ret != TD_SUCCESS) {
        sample_print_err("ss_mpi_venc_stop_chn vechn[%d] failed with %#x!\n", venc_chn, ret);
        return TD_FAILURE;
    }
    ret = ss_mpi_venc_destroy_chn(venc_chn);
    if (ret != TD_SUCCESS) {
        sample_print_err("ss_mpi_venc_destroy_chn vechn[%d] failed with %#x!\n", venc_chn, ret);
        return TD_FAILURE;
    }

    return TD_SUCCESS;
}

static td_s32 sample_comm_save_snap_stream(ot_venc_stream *stream, td_bool save_jpg, td_bool save_thm)
{
    td_s32 ret;
    char stream_file[FILE_NAME_LEN] = {0};
    FILE *file = TD_NULL;
    td_s32 fd = -1;

    if (snprintf_s(stream_file, FILE_NAME_LEN, FILE_NAME_LEN - 1, "snap_%d.jpg", g_snap_cnt) < 0) {
        return TD_FAILURE;
    }
    fd = open(stream_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd < 0) {
        sample_print_err("open file err\n");
        return TD_FAILURE;
    }

    file = fdopen(fd, "wb");
    if (file == NULL) {
        sample_print_err("fdopen err\n");
        return TD_FAILURE;
    }

    ret = sample_comm_venc_save_stream(file, stream);
    if (ret != TD_SUCCESS) {
        sample_print_err("save snap picture failed!\n");
        goto CLOSE_FILE;
    }

    if (save_thm) {
        char file_dcf[FILE_NAME_LEN] = {0};
        if (snprintf_s(file_dcf, FILE_NAME_LEN, FILE_NAME_LEN - 1, "snap_thm_%d.jpg", g_snap_cnt) < 0) {
            goto CLOSE_FILE;
        }

        ret = sample_comm_venc_get_dcf_info(stream_file, FILE_NAME_LEN, file_dcf, FILE_NAME_LEN);
        if (ret != TD_SUCCESS) {
            sample_print_err("save thm picture failed!\n");
            goto CLOSE_FILE;
        }
    }

    (td_void)fclose(file);
    file = TD_NULL;
    g_snap_cnt++;

    return TD_SUCCESS;

CLOSE_FILE:
    if (file != TD_NULL) {
        (td_void)fclose(file);
        file = TD_NULL;
    }

    return TD_FAILURE;
}

static td_s32 sample_comm_get_snap_stream(ot_venc_chn venc_chn, td_bool save_jpg, td_bool save_thm)
{
    td_s32 ret = TD_SUCCESS;
    ot_venc_chn_status stat;
    ot_venc_stream stream;

    ret = ss_mpi_venc_query_status(venc_chn, &stat);
    if (ret != TD_SUCCESS) {
        sample_print_err("query_status failed with %#x!\n", ret);
        return TD_FAILURE;
    }

    if (stat.cur_packs == 0) {
        sample_print_err("NOTE: Current frame is NULL!\n");
        return TD_SUCCESS;
    }
    stream.pack = (ot_venc_pack *)malloc(sizeof(ot_venc_pack) * stat.cur_packs);
    if (stream.pack == NULL) {
        sample_print_err("malloc memory failed!\n");
        return TD_FAILURE;
    }
    stream.pack_cnt = stat.cur_packs;
    ret = ss_mpi_venc_get_stream(venc_chn, &stream, -1);
    if (ret != TD_SUCCESS) {
        sample_print_err("get_stream failed with %#x!\n", ret);
        goto FREE_RES;
    }
    if (save_jpg || save_thm) {
        ret = sample_comm_save_snap_stream(&stream, save_jpg, save_thm);
        if (ret != TD_SUCCESS) {
            sample_print_err("save_snap_stream failed!\n");
            goto FREE_RES;
        }
    }

    ret = ss_mpi_venc_release_stream(venc_chn, &stream);
    if (ret != TD_SUCCESS) {
        sample_print_err("release_stream failed with %#x!\n", ret);
        goto FREE_RES;
    }

FREE_RES:
    free(stream.pack);
    stream.pack = NULL;

    return ret;
}

/* *****************************************************************************
* funciton : snap process
 * **************************************************************************** */
td_s32 sample_comm_venc_snap_process(ot_venc_chn venc_chn, td_u32 snap_cnt, td_bool save_jpg, td_bool save_thm)
{
    struct timeval timeout_val;
    fd_set read_fds;
    td_s32 venc_fd;
    td_s32 ret;
    td_u32 i;

    /* *****************************************
     step 4:  recv picture
    ***************************************** */
    venc_fd = ss_mpi_venc_get_fd(venc_chn);
    if (venc_fd < 0) {
        sample_print_err("venc_get_fd faild with%#x!\n", venc_fd);
        return TD_FAILURE;
    }

    for (i = 0; i < snap_cnt; i++) {
        FD_ZERO(&read_fds);
        FD_SET(venc_fd, &read_fds);
        timeout_val.tv_sec = 10; // 10 : 10 seconds
        timeout_val.tv_usec = 0;
        ret = select(venc_fd + 1, &read_fds, NULL, NULL, &timeout_val);
        if (ret < 0) {
            sample_print_err("snap select failed!\n");
            return TD_FAILURE;
        } else if (ret == 0) {
            sample_print_err("snap time out!\n");
            return TD_FAILURE;
        } else {
            if (FD_ISSET(venc_fd, &read_fds)) {
                check_return(sample_comm_get_snap_stream(venc_chn, save_jpg, save_thm), "get_snap_stream");
            }
        }
    }

    return TD_SUCCESS;
}

td_s32 sample_comm_venc_save_jpeg(ot_venc_chn venc_chn, td_u32 snap_cnt)
{
    struct timeval timeout_val;
    fd_set read_fds;
    td_s32 venc_fd;
    td_s32 ret;
    td_u32 i;
    /* *****************************************
     step:  recv picture
    ***************************************** */
    venc_fd = ss_mpi_venc_get_fd(venc_chn);
    if (venc_fd < 0) {
        sample_print_err("venc_get_fd faild with%#x!\n", venc_fd);
        return TD_FAILURE;
    }
    for (i = 0; i < snap_cnt; i++) {
        FD_ZERO(&read_fds);
        FD_SET(venc_fd, &read_fds);
        timeout_val.tv_sec = 10; // 10 : 10 seconds
        timeout_val.tv_usec = 0;
        ret = select(venc_fd + 1, &read_fds, NULL, NULL, &timeout_val);
        if (ret < 0) {
            sample_print_err("snap select failed!\n");
            return TD_FAILURE;
        } else if (ret == 0) {
            sample_print_err("snap time out!\n");
            return TD_FAILURE;
        } else {
            if (FD_ISSET(venc_fd, &read_fds)) {
                check_return(sample_comm_get_snap_stream(venc_chn, TD_TRUE, TD_FALSE), "get_snap_stream");
            }
        }
    }
    return TD_SUCCESS;
}

static td_s32 sample_comm_alloc_qpmap_skipweight_memory(sample_venc_qpmap_sendframe_para *para,
    sample_comm_venc_frame_proc_info *addr_info)
{
    ot_venc_chn_attr venc_chn_attr = {0};
    td_s32 i, j, ret;
    td_u8 *vir_addr = TD_NULL;
    td_phys_addr_t phys_addr = 0;

    for (i = 0; (i < para->cnt) && (i < OT_VENC_MAX_CHN_NUM); i++) {
        if (ss_mpi_venc_get_chn_attr(para->venc_chn[i], &venc_chn_attr) != TD_SUCCESS) {
            return TD_FAILURE;
        }

        addr_info->qpmap_size[i] = ot_venc_get_qpmap_size(venc_chn_attr.venc_attr.type,
            para->size[i].width, para->size[i].height);
        addr_info->skip_weight_size[i] =
            ot_venc_get_skip_weight_size(venc_chn_attr.venc_attr.type, para->size[i].width, para->size[i].height);

        /* alloc qpmap memory */
        ret = ss_mpi_sys_mmz_alloc((td_phys_addr_t *)&phys_addr, (td_void **)&vir_addr, TD_NULL, TD_NULL,
            addr_info->qpmap_size[i] * QPMAP_BUF_NUM);
        if (ret != TD_SUCCESS) {
            sample_print_err("ss_mpi_sys_mmz_alloc err:0x%x", ret);
            return ret;
        }
        for (j = 0; (i < VENC_QPMAP_MAX_CHN) && (j < QPMAP_BUF_NUM); j++) {
            if ((j > 0) && (addr_info->qpmap_size[i] > (UINT_MAX / j))) {
                sample_print_info("(j * addr_info->qpmap_size[%d]) upper limit of the multiplie\n", i);
                ss_mpi_sys_mmz_free(phys_addr, vir_addr);
                return TD_FAILURE;
            } else {
                addr_info->qpmap_phys_addr[i][j] = (td_phys_addr_t)(phys_addr + j * addr_info->qpmap_size[i]);
                addr_info->qpmap_vir_addr[i][j] = vir_addr + j * addr_info->qpmap_size[i];
            }
        }

        /* alloc skipWeight memory */
        ret = ss_mpi_sys_mmz_alloc((td_phys_addr_t *)&phys_addr, (td_void **)&vir_addr, TD_NULL, TD_NULL,
            addr_info->skip_weight_size[i] * QPMAP_BUF_NUM);
        if (ret != TD_SUCCESS) {
            sample_print_err("ss_mpi_sys_mmz_alloc err:0x%x", ret);
            return ret;
        }
        for (j = 0; (i < VENC_QPMAP_MAX_CHN) && (j < QPMAP_BUF_NUM); j++) {
            if ((j > 0) && (addr_info->skip_weight_size[i] > (UINT_MAX / j))) {
                sample_print_info("(j * addr_info->skip_weight_size[%d]) upper limit of the multiplie\n", i);
                ss_mpi_sys_mmz_free(phys_addr, vir_addr);
                return TD_FAILURE;
            } else {
                addr_info->skip_weight_phys_addr[i][j] =
                    (td_phys_addr_t)(phys_addr + j * addr_info->skip_weight_size[i]);
                addr_info->skip_weight_vir_addr[i][j] = vir_addr + j * addr_info->skip_weight_size[i];
            }
        }
    }

    return TD_SUCCESS;
}

static td_void sample_comm_venc_vir_addr_temp(sample_comm_venc_frame_proc_info *addr_info, td_u32 i, td_u32 frame_id)
{
    td_u32 j;
    td_u8 *vir_addr_temp = TD_NULL;

    vir_addr_temp = (td_u8 *)addr_info->qpmap_vir_addr[i][frame_id];
    for (j = 0; j < addr_info->qpmap_size[i]; j++) {
        *vir_addr_temp = 0x5E; // [7]:skip flag; [6]:QpType Flag; [5:0]:Qp value ==> Set absolute qp = 30
        vir_addr_temp++;
    }

    vir_addr_temp = (td_u8 *)addr_info->skip_weight_vir_addr[i][frame_id];
    for (j = 0; j < addr_info->skip_weight_size[i]; j++) {
        *vir_addr_temp = 0x66; // inter block must be skip
        vir_addr_temp++;
    }
}


static td_s32 sample_comm_qpmap_send_frame_ex(sample_venc_qpmap_sendframe_para *para,
    ot_venc_user_frame_info *frame_info, ot_video_frame_info *video_frame, td_s32 index)
{
    td_s32 ret;

    ret = ss_mpi_venc_send_frame_ex(para->venc_chn[index], frame_info, -1);
    if (ret != TD_SUCCESS) {
        sample_print_err("ss_mpi_venc_send_frame_ex err:0x%x\n", ret);

        ret = ss_mpi_vpss_release_chn_frame(para->vpss_grp, para->vpss_chn[index], video_frame);
        if (ret != TD_SUCCESS) {
            sample_print_err("ss_mpi_vpss_release_chn_frame err:0x%x", ret);
            return SAMPLE_RETURN_GOTO;
        }
        return SAMPLE_RETURN_BREAK;
    }

    return TD_SUCCESS;
}

static ot_venc_user_frame_info* sample_comm_malloc_frame_martix(td_s32 chn_num, td_s32 buf_num)
{
    ot_venc_user_frame_info* frame_info = TD_NULL;
    size_t malloc_size = sizeof(ot_venc_user_frame_info) * chn_num * buf_num;

    if (chn_num == 0 || buf_num == 0) {
        sample_print_err("malloc_size error, chn_num %d, buf_num %d\n", chn_num, buf_num);
        return TD_NULL;
    }

    frame_info = malloc(malloc_size);
    if (frame_info == NULL) {
        sample_print_err("malloc error\n");
        return TD_NULL;
    }

    if (memset_s(frame_info, malloc_size, 0, malloc_size) != EOK) {
        free(frame_info);
        return TD_NULL;
    }
    return frame_info;
}

static td_s32 sample_comm_qpmap_send_frame_start(sample_venc_qpmap_sendframe_para *para,
    sample_comm_venc_frame_proc_info *addr_info)
{
    td_u32 frame_id = 0;
    td_s32 i, ret = TD_SUCCESS;
    ot_venc_user_frame_info *frame_info = sample_comm_malloc_frame_martix(VENC_QPMAP_MAX_CHN, QPMAP_BUF_NUM);

    if (frame_info == TD_NULL) {
        return TD_FAILURE;
    }

    while (para->thread_start == TD_TRUE) {
        for (i = 0; (i < para->cnt) && (i < VENC_QPMAP_MAX_CHN) &&
            i * QPMAP_BUF_NUM + frame_id < VENC_QPMAP_MAX_CHN * QPMAP_BUF_NUM; i++) {
            ot_video_frame_info *video_frame = &frame_info[i * QPMAP_BUF_NUM + frame_id].user_frame;

            if ((ret = ss_mpi_vpss_get_chn_frame(para->vpss_grp, para->vpss_chn[i],
                video_frame, 1000)) != TD_SUCCESS) { /* 1000 is a number */
                sample_print_err("OT_MPI_VPSS_GetChnFrame err:0x%x\n", ret);
                continue;
            }

            sample_comm_venc_vir_addr_temp(addr_info, i, frame_id);

            frame_info[i * QPMAP_BUF_NUM + frame_id].user_rc_info.skip_weight_valid = 1;
            frame_info[i * QPMAP_BUF_NUM + frame_id].user_rc_info.skip_weight_phys_addr =
                addr_info->skip_weight_phys_addr[i][frame_id];
            frame_info[i * QPMAP_BUF_NUM + frame_id].user_rc_info.qpmap_valid = 1;
            frame_info[i * QPMAP_BUF_NUM + frame_id].user_rc_info.qpmap_phys_addr =
                addr_info->qpmap_phys_addr[i][frame_id];
            frame_info[i * QPMAP_BUF_NUM + frame_id].user_rc_info.blk_start_qp = 30; /* 30 is a number */
            frame_info[i * QPMAP_BUF_NUM + frame_id].user_rc_info.frame_type = OT_VENC_FRAME_TYPE_NONE;

            ret = sample_comm_qpmap_send_frame_ex(para, &frame_info[i * QPMAP_BUF_NUM + frame_id], video_frame, i);
            if (ret == SAMPLE_RETURN_BREAK) {
                break;
            } else if (ret == SAMPLE_RETURN_GOTO) {
                goto FREE;
            }

            if ((ret = ss_mpi_vpss_release_chn_frame(para->vpss_grp, para->vpss_chn[i], video_frame)) != TD_SUCCESS) {
                sample_print_err("ss_mpi_vpss_release_chn_frame err:0x%x", ret);
                goto FREE;
            }

            if (++frame_id >= QPMAP_BUF_NUM) {
                frame_id = 0;
            }
        }
    }

FREE:
    free(frame_info);
    return ret;
}

td_void *sample_comm_qpmap_send_frame_proc(td_void *p)
{
    td_s32 i, ret;
    sample_venc_qpmap_sendframe_para *para = TD_NULL;
    sample_comm_venc_frame_proc_info addr_info = { 0 };
    ot_vpss_chn_attr vpss_chn_attr;

    para = (sample_venc_qpmap_sendframe_para *)p;

    if (para->cnt > VENC_QPMAP_MAX_CHN) {
        sample_print_err("Current func'sample_comm_qpmap_send_frame_proc' not support Venc channal num(%d) > %d\n",
            para->cnt, VENC_QPMAP_MAX_CHN);
        return TD_NULL;
    }

    if (sample_comm_alloc_qpmap_skipweight_memory(para, &addr_info) != TD_SUCCESS) {
        goto error;
    }

    /* set vpss buffer depth */
    for (i = 0; (i < para->cnt) && (i < OT_VPSS_MAX_PHYS_CHN_NUM); i++) {
        ret = ss_mpi_vpss_get_chn_attr(para->vpss_grp, para->vpss_chn[i], &vpss_chn_attr);
        if (ret != TD_SUCCESS) {
            sample_print_err("ss_mpi_vpss_get_chn_attr err:0x%x", ret);
            goto error;
        }

        vpss_chn_attr.depth = 3; /* 3 is a number */
        ret = ss_mpi_vpss_set_chn_attr(para->vpss_grp, para->vpss_chn[i], &vpss_chn_attr);
        if (ret != TD_SUCCESS) {
            sample_print_err("ss_mpi_vpss_set_chn_attr err:0x%x", ret);
            goto error;
        }
    }

    if (sample_comm_qpmap_send_frame_start(para, &addr_info) != TD_SUCCESS) {
        goto error;
    }

error:
    for (i = 0; (i < para->cnt) && (i < VENC_QPMAP_MAX_CHN); i++) {
        if (addr_info.qpmap_phys_addr[i][0] != 0) {
            ret = ss_mpi_sys_mmz_free(addr_info.qpmap_phys_addr[i][0], addr_info.qpmap_vir_addr[i][0]);
            if (ret != TD_SUCCESS) {
                sample_print_err("ss_mpi_sys_mmz_free err:0x%x", ret);
            }
        }

        if (addr_info.skip_weight_phys_addr[i][0] != 0) {
            ret = ss_mpi_sys_mmz_free(addr_info.skip_weight_phys_addr[i][0], addr_info.skip_weight_vir_addr[i][0]);
            if (ret != TD_SUCCESS) {
                sample_print_err("ss_mpi_sys_mmz_free err:0x%x", ret);
            }
        }
    }
    return TD_NULL;
}

td_s32 sample_comm_venc_qpmap_send_frame(ot_vpss_grp vpss_grp, ot_vpss_chn vpss_chn[], ot_venc_chn venc_chn[],
    td_s32 cnt, ot_size size[])
{
    td_s32 i;

    g_qpmap_send_frame_para.thread_start = TD_TRUE;
    g_qpmap_send_frame_para.vpss_grp = vpss_grp;
    g_qpmap_send_frame_para.cnt = cnt;

    for (i = 0; (i < cnt) && (i < OT_VENC_MAX_CHN_NUM) && (i < OT_VPSS_MAX_PHYS_CHN_NUM); i++) {
        g_qpmap_send_frame_para.venc_chn[i] = venc_chn[i];
        g_qpmap_send_frame_para.vpss_chn[i] = vpss_chn[i];
        g_qpmap_send_frame_para.size[i] = size[i];
    }

    return pthread_create(&g_venc_qpmap_pid, 0, sample_comm_qpmap_send_frame_proc, (td_void *)&g_qpmap_send_frame_para);
}

#define SAMPLE_VENC_BLOCK_WIDTH 16
#define SAMPLE_VENC_BLOCK_HEIGHT 16
#define SAMPLE_VENC_ONE_BYTE_BLOCKS 4
#define SAMPLE_VENC_ONE_BLOCK_BITS 2
#define SAMPLE_VENC_MAX_JPEG_ROI_LEVEL 3

static td_void sample_venc_set_2bits(td_u8 *wp, td_u32 idx, td_u32 value)
{
    td_u8 tmp1, tmp2;
    tmp1 = *wp;

    tmp2 = ~(3 << (idx * SAMPLE_VENC_ONE_BLOCK_BITS)); // 3: 0b11
    tmp1 &= tmp2;
    tmp2 = value << (idx * SAMPLE_VENC_ONE_BLOCK_BITS);
    tmp1 |= tmp2;
    *wp = tmp1;
}

static td_void sample_venc_process_jpeg_roi_head(td_u8 **wp, td_u32 start_idx, td_u32 fill_block, td_u32 value)
{
    td_u32 i;

    for (i = 0; i < fill_block; i++) {
        sample_venc_set_2bits(*wp, start_idx + i, value);
    }

    if (i != 0) {
        *wp = *wp + 1;
    }
}

static td_void sample_venc_process_jpeg_roi_middle(td_u8 **wp, td_u32 write_byte, td_u32 value)
{
    td_s32 i;
    if (write_byte != 0) {
        for (i = 0; i < (SAMPLE_VENC_ONE_BYTE_BLOCKS - 1); i++) {
            value |= value << SAMPLE_VENC_ONE_BLOCK_BITS;
        }
        if (memset_s(*wp, write_byte, value, write_byte) != EOK) {
            sample_print_err("call memset_s error\n");
        }
        *wp = *wp + write_byte;
    }
}

static td_void sample_venc_process_jpeg_roi_tail(td_u8 **wp, td_u32 fill_block, td_u32 value)
{
    td_u32 i;

    for (i = 0; i < fill_block; i++) {
        sample_venc_set_2bits(*wp, i, value);
    }
}

td_void sample_venc_process_jpeg_roi(td_void *virt_addr, ot_rect *rect, td_u32 roi_level, td_u32 stride)
{
    td_u32 i, level, start_block, start_byte, start_supple_idx, start_supple_block, start_block_height;
    td_u32 start_x, start_y, write_block, write_resi_block, write_byte, write_tail_block, write_block_height;

    start_x = rect->x;
    start_block = start_x / SAMPLE_VENC_BLOCK_WIDTH;
    start_byte = start_block / SAMPLE_VENC_ONE_BYTE_BLOCKS;
    start_supple_idx = start_block % SAMPLE_VENC_ONE_BYTE_BLOCKS;
    start_supple_block = (start_supple_idx == 0) ? 0 : (SAMPLE_VENC_ONE_BYTE_BLOCKS - start_supple_idx);

    write_block = rect->width / SAMPLE_VENC_BLOCK_WIDTH;
    start_supple_block = (start_supple_block < write_block) ? start_supple_block : write_block;
    write_resi_block = write_block - start_supple_block;
    write_byte = write_resi_block / SAMPLE_VENC_ONE_BYTE_BLOCKS;
    write_tail_block = write_resi_block % SAMPLE_VENC_ONE_BYTE_BLOCKS;

    start_y = rect->y;
    start_block_height = start_y / SAMPLE_VENC_BLOCK_HEIGHT;
    write_block_height = rect->height / SAMPLE_VENC_BLOCK_HEIGHT;
    level = roi_level;

    for (i = 0; i < write_block_height; i++) {
        td_u8 *wp = (td_u8 *)virt_addr + (start_block_height + i) * stride + start_byte;
        sample_venc_process_jpeg_roi_head(&wp, start_supple_idx, start_supple_block, level);
        sample_venc_process_jpeg_roi_middle(&wp, write_byte, level);
        sample_venc_process_jpeg_roi_tail(&wp, write_tail_block, level);
    }
}

#define SAMPLE_VENC_ROIMAP_MAX_CHN 2

static td_s32 sample_comm_venc_send_frame_ex(sample_venc_roimap_frame_para *para, ot_venc_user_frame_info *frame_info,
    ot_video_frame_info *video_frame, td_s32 index, td_s32 venc_roimap_max_chn)
{
    td_s32 ret;
    ot_unused(venc_roimap_max_chn);

    ret = ss_mpi_venc_send_frame_ex(para->venc_chn[index], &frame_info[index], -1);
    if (ret != TD_SUCCESS) {
        sample_print_err("ss_mpi_venc_send_frame_ex err: 0x%x\n", ret);

        ret = ss_mpi_vpss_release_chn_frame(para->vpss_grp, para->vpss_chn[index], video_frame);
        if (ret != TD_SUCCESS) {
            sample_print_err("ss_mpi_vpss_release_chn_frame err: 0x%x", ret);
            return SAMPLE_RETURN_GOTO;
        }
        return SAMPLE_RETURN_BREAK;
    }

    return TD_SUCCESS;
}

static td_s32 sample_comm_venc_send_roimap_frame_start(sample_venc_roimap_frame_para *para,
    td_phys_addr_t *roimap_phys_addr)
{
    td_s32 i, ret;
    ot_venc_user_frame_info frame_info[SAMPLE_VENC_ROIMAP_MAX_CHN] = {0};

    while (para->thread_start == TD_TRUE) {
        for (i = 0; (i < para->cnt) && (i < OT_VPSS_MAX_PHYS_CHN_NUM) && (i < OT_VENC_MAX_CHN_NUM); i++) {
            ot_video_frame_info *video_frame = &frame_info[i].user_frame;
            ret = ss_mpi_vpss_get_chn_frame(para->vpss_grp, para->vpss_chn[i],
                video_frame, 1000); /* 1000 is a number */
            if (ret != TD_SUCCESS) {
                sample_print_err("ss_mpi_vpss_get_chn_frame err: 0x%x\n", ret);
                continue;
            }

            frame_info[i].user_roimap.valid = TD_TRUE;
            frame_info[i].user_roimap.phys_addr = roimap_phys_addr[i];

            ret = sample_comm_venc_send_frame_ex(para, frame_info, video_frame, i, SAMPLE_VENC_ROIMAP_MAX_CHN);
            if (ret == SAMPLE_RETURN_BREAK) {
                break;
            } else if (ret == SAMPLE_RETURN_GOTO) {
                return SAMPLE_RETURN_GOTO;
            }

            ret = ss_mpi_vpss_release_chn_frame(para->vpss_grp, para->vpss_chn[i], video_frame);
            if (ret != TD_SUCCESS) {
                sample_print_err("ss_mpi_vpss_release_chn_frame err: 0x%x", ret);
                return SAMPLE_RETURN_GOTO;
            }
        }
    }

    return TD_SUCCESS;
}

static td_s32 sample_comm_set_vpss_buffer_depth(sample_venc_roimap_frame_para *para, td_phys_addr_t *roimap_phys_addr)
{
    td_s32 i, ret;
    ot_vpss_chn_attr vpss_chn_attr;

    for (i = 0; (i < para->cnt) && (i < OT_VPSS_MAX_PHYS_CHN_NUM); i++) {
        ret = ss_mpi_vpss_get_chn_attr(para->vpss_grp, para->vpss_chn[i], &vpss_chn_attr);
        if (ret != TD_SUCCESS) {
            sample_print_err("ss_mpi_vpss_get_chn_attr err: 0x%x", ret);
            return SAMPLE_RETURN_GOTO;
        }

        vpss_chn_attr.depth = 3; // 3 : depth
        ret = ss_mpi_vpss_set_chn_attr(para->vpss_grp, para->vpss_chn[i], &vpss_chn_attr);
        if (ret != TD_SUCCESS) {
            sample_print_err("ss_mpi_vpss_set_chn_attr err: 0x%x", ret);
            return SAMPLE_RETURN_GOTO;
        }
    }
    ret = sample_comm_venc_send_roimap_frame_start(para, roimap_phys_addr);
    if (ret != TD_SUCCESS) {
        return SAMPLE_RETURN_GOTO;
    }

    return TD_SUCCESS;
}

td_void *sample_comm_send_roimap_frame_proc(td_void *p)
{
    td_s32 i, j, ret;
    td_u8 init_level = 2;

    td_u32 roimap_size[SAMPLE_VENC_ROIMAP_MAX_CHN], roimap_stride[SAMPLE_VENC_ROIMAP_MAX_CHN];
    td_phys_addr_t roimap_phys_addr[SAMPLE_VENC_ROIMAP_MAX_CHN] = {0};
    td_void *roimap_virt_addr[SAMPLE_VENC_ROIMAP_MAX_CHN] = {0};

    td_u8 *virt_addr = TD_NULL;
    td_phys_addr_t phys_addr = TD_NULL;

    ot_venc_chn_attr venc_chn_attr;

    sample_venc_roimap_frame_para *para = (sample_venc_roimap_frame_para *)p;

    if (para->cnt > SAMPLE_VENC_ROIMAP_MAX_CHN) {
        sample_print_err("Current not support venc channal num(%d) > %d\n", para->cnt, SAMPLE_VENC_ROIMAP_MAX_CHN);
        return TD_NULL;
    }

    for (i = 0; (i < para->cnt) && (i < OT_VENC_MAX_CHN_NUM) && (i < SAMPLE_VENC_ROIMAP_MAX_CHN); i++) {
        ss_mpi_venc_get_chn_attr(para->venc_chn[i], &venc_chn_attr);

        roimap_size[i] =
            ot_venc_get_roimap_size(venc_chn_attr.venc_attr.type, para->size[i].width, para->size[i].width);
        roimap_stride[i] = ot_venc_get_roimap_stride(venc_chn_attr.venc_attr.type, para->size[i].width);

        /* alloc roimap memory */
        ret = ss_mpi_sys_mmz_alloc(&phys_addr, (td_void **)&virt_addr, TD_NULL, TD_NULL, roimap_size[i]);
        if (ret != TD_SUCCESS) {
            sample_print_err("ss_mpi_sys_mmz_alloc err: 0x%x", ret);
            goto error;
        }

        roimap_phys_addr[i] = phys_addr;
        roimap_virt_addr[i] = virt_addr;

        for (j = 0; j < (4 - 1); j++) {      /* 4 is a number */
            init_level |= (init_level << 4); /* 4 is a number */
        }
        if (memset_s(roimap_virt_addr[i], roimap_size[i], init_level, roimap_size[i]) != EOK) {
            sample_print_err("call memset_s error\n");
        }
        sample_venc_process_jpeg_roi(roimap_virt_addr[i], &para->roi_attr[i].rect, para->roi_attr[i].level,
            roimap_stride[i]);
    }

    /* set vpss buffer depth */
    if (sample_comm_set_vpss_buffer_depth(para, roimap_phys_addr) != TD_SUCCESS) {
        goto error;
    }

error:
    for (i = 0; (i < para->cnt) && (i < SAMPLE_VENC_ROIMAP_MAX_CHN); i++) {
        if (roimap_phys_addr[i] != 0) {
            ret = ss_mpi_sys_mmz_free(roimap_phys_addr[i], roimap_virt_addr[i]);
            if (ret != TD_SUCCESS) {
                sample_print_err("ss_mpi_sys_mmz_free err: 0x%x", ret);
            }
        }
    }

    return TD_NULL;
}

td_s32 sample_comm_venc_send_roimap_frame(ot_vpss_grp vpss_grp, sample_venc_roimap_chn_info roimap_chn_info,
    ot_size size[], ot_venc_jpeg_roi_attr roi_attr[])
{
    td_s32 i;

    g_roimap_frame_param.thread_start = TD_TRUE;
    g_roimap_frame_param.vpss_grp = vpss_grp;
    g_roimap_frame_param.cnt = roimap_chn_info.cnt;

    for (i = 0; (i < roimap_chn_info.cnt) && (i < OT_VENC_MAX_CHN_NUM) && (i < OT_VPSS_MAX_PHYS_CHN_NUM); i++) {
        g_roimap_frame_param.venc_chn[i] = roimap_chn_info.venc_chn[i];
        g_roimap_frame_param.vpss_chn[i] = roimap_chn_info.vpss_chn[i];
        g_roimap_frame_param.size[i] = size[i];
        g_roimap_frame_param.roi_attr[i] = roi_attr[i];
    }

    return pthread_create(&g_venc_roimap_pid, 0, sample_comm_send_roimap_frame_proc, (td_void *)&g_roimap_frame_param);
}

static td_s32 sample_comm_set_file_name(td_s32 index, ot_venc_chn venc_chn,
    sample_comm_venc_stream_proc_info *stream_proc_info)
{
    if (snprintf_s(stream_proc_info->file_name[index], FILE_NAME_LEN, FILE_NAME_LEN - 1, "./") < 0) {
        return TD_FAILURE;
    }

    if (realpath(stream_proc_info->file_name[index], stream_proc_info->real_file_name[index]) == TD_NULL) {
        sample_print_err("chn[%d] stream file path error\n", venc_chn);
        return TD_FAILURE;
    }

    if (snprintf_s(stream_proc_info->real_file_name[index], FILE_NAME_LEN, FILE_NAME_LEN - 1,
        "stream_chn%d%s", index, stream_proc_info->file_postfix) < 0) {
        return TD_FAILURE;
    }

    return TD_SUCCESS;
}

static td_void sample_comm_close_save_file(sample_comm_venc_stream_proc_info *stream_proc_info)
{
    td_s32 i;

    for (i = 0; i < stream_proc_info->chn_total && i < OT_VENC_MAX_CHN_NUM; i++) {
        if (stream_proc_info->file[i] != TD_NULL) {
            fclose(stream_proc_info->file[i]);
            stream_proc_info->file[i] = TD_NULL;
        }
    }
}

static td_void sample_comm_close_save_file_svc(sample_comm_venc_stream_proc_info *stream_proc_info)
{
    td_s32 i, cnt;

    for (i = 0; i < stream_proc_info->chn_total && i < OT_VENC_MAX_CHN_NUM; i++) {
        for (cnt = 0; cnt < 3; cnt++) { /* 3 is a number */
            if (stream_proc_info->file[i + cnt]) {
                fclose(stream_proc_info->file[i + cnt]);
                stream_proc_info->file[i + cnt] = TD_NULL;
            }
        }
    }
}

static td_s32 sample_comm_set_name_save_stream(sample_comm_venc_stream_proc_info *stream_proc_info,
    ot_venc_stream_buf_info *stream_buf_info, ot_payload_type *payload_type,
    sample_venc_getstream_para *para, td_s32 venc_max_chn)
{
    td_s32 i, ret, fd;
    ot_venc_chn_attr venc_chn_attr;
    ot_unused(venc_max_chn);

    for (i = 0; (i < stream_proc_info->chn_total) && (i < OT_VENC_MAX_CHN_NUM); i++) {
        /* decide the stream file name, and open file to save stream */
        ot_venc_chn venc_chn = para->venc_chn[i];
        ret = ss_mpi_venc_get_chn_attr(venc_chn, &venc_chn_attr);
        if (ret != TD_SUCCESS) {
            sample_print_err("ss_mpi_venc_get_chn_attr chn[%d] failed with %#x!\n", venc_chn, ret);
            return SAMPLE_RETURN_NULL;
        }
        payload_type[i] = venc_chn_attr.venc_attr.type;

        ret = sample_comm_venc_get_file_postfix(payload_type[i], stream_proc_info->file_postfix,
            sizeof(stream_proc_info->file_postfix));
        if (ret != TD_SUCCESS) {
            sample_print_err("sample_comm_venc_get_file_postfix [%d] failed with %#x!\n",
                venc_chn_attr.venc_attr.type, ret);
            return SAMPLE_RETURN_NULL;
        }

        if (payload_type[i] != OT_PT_JPEG) {
            ret = sample_comm_set_file_name(i, venc_chn, stream_proc_info);
            if (ret != TD_SUCCESS) {
                return ret;
            }

            stream_proc_info->file[i] = fopen(stream_proc_info->real_file_name[i], "wb");
            if (!stream_proc_info->file[i]) {
                sample_print_err("open file[%s] failed!\n", stream_proc_info->real_file_name[i]);
                return SAMPLE_RETURN_NULL;
            }
            fd = fileno(stream_proc_info->file[i]);
            fchmod(fd, S_IRUSR | S_IWUSR);
        }
        /* set venc fd. */
        stream_proc_info->venc_fd[i] = ss_mpi_venc_get_fd(i);
        if (stream_proc_info->venc_fd[i] < 0) {
            sample_print_err("ss_mpi_venc_get_fd failed with %#x!\n", stream_proc_info->venc_fd[i]);
            return SAMPLE_RETURN_NULL;
        }

        if (stream_proc_info->maxfd <= stream_proc_info->venc_fd[i]) {
            stream_proc_info->maxfd = stream_proc_info->venc_fd[i];
        }

        ret = ss_mpi_venc_get_stream_buf_info(i, &stream_buf_info[i]);
        if (ret != TD_SUCCESS) {
            sample_print_err("ss_mpi_venc_get_stream_buf_info failed with %#x!\n", ret);
            return SAMPLE_RETURN_FAILURE;
        }
    }

    return TD_SUCCESS;
}

static int32_t sample_heif_create(td_s32 index, const sample_comm_venc_stream_proc_info *stream_proc_info,
    heif_handle *hdl)
{
    heif_config config;
    if (snprintf_s(config.file_desc.input.url, FILE_NAME_LEN, FILE_NAME_LEN - 1,
        "./stream_chn%d_%u%s", index, stream_proc_info->picture_cnt[index], ".heic") < 0) {
        return SAMPLE_RETURN_NULL;
    }
    config.file_desc.file_type = HEIF_FILE_TYPE_URL;
    config.config_type = HEIF_CONFIG_MUXER;
    config.muxer_config.is_grid = false;
    config.muxer_config.row_image_num = 1;
    config.muxer_config.column_image_num = 1;
    config.muxer_config.format_profile = HEIF_PROFILE_HEIC;
    return heif_create(hdl, &config);
}

static td_s32 sample_comm_save_h265_to_heic(td_s32 index, const sample_comm_venc_stream_proc_info *stream_proc_info,
    const ot_venc_stream *stream)
{
    td_u32 i;
    td_u32 total_len = 0;
    td_s32 has_key = 0;
    for (i = 0; i < stream->pack_cnt; i++) {
        if (stream->pack[i].data_type.h265_type == OT_VENC_H265_NALU_IDR_SLICE) {
            has_key = 1;
        }
        total_len += stream->pack[i].len - stream->pack[i].offset;
    }
    if (total_len > 0 && has_key == 1) {
        heif_handle handle = NULL;
        td_s32 ret = sample_heif_create(index, stream_proc_info, &handle);
        if (ret != 0) {
            sample_print_err("HeifCreate error ret:%d\n", ret);
        }
        td_u8 *data_buffer = (td_u8 *)malloc(total_len);
        if (data_buffer == NULL) {
            sample_print_err("malloc error\n");
            heif_destroy(handle);
            return SAMPLE_RETURN_NULL;
        }
        td_u32 write_len = 0;
        for (i = 0; i < stream->pack_cnt; i++) {
            if (memcpy_s(data_buffer + write_len, total_len - write_len,
                stream->pack[i].addr + stream->pack[i].offset, stream->pack[i].len - stream->pack[i].offset) != EOK) {
                sample_print_err("memcpy_s failed\n");
            }
            write_len += stream->pack[i].len;
        }
        heif_image_item item = {0};
        item.timestamp = -1;
        item.data = data_buffer;
        item.length = write_len;
        item.key_frame = true;
        ret = heif_write_master_image(handle, 0, &item, 1);
        if (data_buffer != NULL) {
            free(data_buffer);
        }
        heif_destroy(handle);
        return ret;
    }
    return 0;
}

static td_s32 sample_comm_save_frame_to_file(td_s32 index, sample_comm_venc_stream_proc_info *stream_proc_info,
    ot_venc_stream *stream, ot_venc_stream_buf_info *stream_buf_info, ot_payload_type *payload_type)
{
    td_s32 ret, fd;
    if (payload_type[index] == OT_PT_JPEG) {
        if (snprintf_s(stream_proc_info->file_name[index], FILE_NAME_LEN, FILE_NAME_LEN - 1, "./") < 0) {
            free(stream->pack);
            return SAMPLE_RETURN_NULL;
        }
        if (realpath(stream_proc_info->file_name[index], stream_proc_info->real_file_name[index]) == TD_NULL) {
            free(stream->pack);
            sample_print_err("chn[%d] stream file path error\n", stream_proc_info->venc_chn);
            return SAMPLE_RETURN_NULL;
        }

        if (snprintf_s(stream_proc_info->real_file_name[index], FILE_NAME_LEN, FILE_NAME_LEN - 1,
            "stream_chn%d_%u%s", index, stream_proc_info->picture_cnt[index], stream_proc_info->file_postfix) < 0) {
            free(stream->pack);
            return SAMPLE_RETURN_NULL;
        }
        stream_proc_info->file[index] = fopen(stream_proc_info->real_file_name[index], "wb");
        if (!stream_proc_info->file[index]) {
            free(stream->pack);
            sample_print_err("open file err!\n");
            return SAMPLE_RETURN_NULL;
        }
        fd = fileno(stream_proc_info->file[index]);
        fchmod(fd, S_IRUSR | S_IWUSR);
    }

    if (payload_type[index] == OT_PT_H265 && stream_proc_info->save_heif == TD_TRUE) {
        (td_void)sample_comm_save_h265_to_heic(index, stream_proc_info, stream);
    }
#ifndef __LITEOS__
    ot_unused(stream_buf_info);
    ret = sample_comm_venc_save_stream(stream_proc_info->file[index], stream);
#else
    ret = sample_comm_venc_save_stream_phys_addr(stream_proc_info->file[index], &stream_buf_info[index], stream);
#endif
    if (ret != TD_SUCCESS) {
        free(stream->pack);
        stream->pack = TD_NULL;
        sample_print_err("save stream failed!\n");
        return SAMPLE_RETURN_BREAK;
    }

    return TD_SUCCESS;
}

static td_s32 sample_comm_get_stream_from_one_channl(sample_comm_venc_stream_proc_info *stream_proc_info, td_s32 index,
    ot_venc_stream_buf_info *stream_buf_info, ot_payload_type *payload_type)
{
    td_s32 ret;
    ot_venc_stream stream;
    ot_venc_chn_status stat;

    /* step 2.1 : query how many packs in one-frame stream. */
    if (memset_s(&stream, sizeof(stream), 0, sizeof(stream)) != EOK) {
        sample_print_err("call memset_s error\n");
    }

    ret = ss_mpi_venc_query_status(index, &stat);
    if (ret != TD_SUCCESS) {
        sample_print_err("ss_mpi_venc_query_status chn[%d] failed with %#x!\n", index, ret);
        return SAMPLE_RETURN_BREAK;
    }

    if (stat.cur_packs == 0) {
        sample_print_err("NOTE: current  frame is TD_NULL!\n");
        return SAMPLE_RETURN_CONTINUE;
    }
    /* step 2.3 : malloc corresponding number of pack nodes. */
    stream.pack = (ot_venc_pack *)malloc(sizeof(ot_venc_pack) * stat.cur_packs);
    if (stream.pack == TD_NULL) {
        sample_print_err("malloc stream pack failed!\n");
        return SAMPLE_RETURN_BREAK;
    }

    /* step 2.4 : call mpi to get one-frame stream */
    stream.pack_cnt = stat.cur_packs;
    ret = ss_mpi_venc_get_stream(index, &stream, TD_TRUE);
    if (ret != TD_SUCCESS) {
        free(stream.pack);
        stream.pack = TD_NULL;
        sample_print_err("ss_mpi_venc_get_stream failed with %#x!\n", ret);
        return SAMPLE_RETURN_BREAK;
    }

    /* step 2.5 : save frame to file */
    ret = sample_comm_save_frame_to_file(index, stream_proc_info, &stream, stream_buf_info, payload_type);
    if (ret != TD_SUCCESS) {
        return ret;
    }
    /* step 2.6 : release stream */
    ret = ss_mpi_venc_release_stream(index, &stream);
    if (ret != TD_SUCCESS) {
        sample_print_err("ss_mpi_venc_release_stream failed!\n");
        free(stream.pack);
        stream.pack = TD_NULL;
        return SAMPLE_RETURN_BREAK;
    }

    /* step 2.7 : free pack nodes */
    free(stream.pack);
    stream.pack = TD_NULL;
    stream_proc_info->picture_cnt[index]++;
    if (payload_type[index] == OT_PT_JPEG) {
        fclose(stream_proc_info->file[index]);
        stream_proc_info->file[index] = TD_NULL;
    }
    return TD_SUCCESS;
}


static td_void sample_comm_fd_isset(sample_comm_venc_stream_proc_info *stream_proc_info, fd_set *read_fds,
    ot_venc_stream_buf_info *stream_buf_info, ot_payload_type *payload_type, sample_venc_getstream_para *para)
{
    td_s32 i, ret;

    for (i = 0; (i < stream_proc_info->chn_total) && (i < OT_VENC_MAX_CHN_NUM); i++) {
        if (FD_ISSET(stream_proc_info->venc_fd[i], read_fds)) {
            stream_proc_info->venc_chn = para->venc_chn[i];
            ret = sample_comm_get_stream_from_one_channl(stream_proc_info, i, stream_buf_info, payload_type);
            if (ret == SAMPLE_RETURN_CONTINUE) {
                continue;
            } else if (ret == SAMPLE_RETURN_BREAK) {
                break;
            }
        }
    }
}

/* get stream from each channels and save them */
td_void *sample_comm_venc_get_venc_stream_proc(td_void *p)
{
    td_s32 i, ret;
    td_void *res = TD_NULL;
    fd_set read_fds;
    struct timeval timeout_val = {0};
    ot_payload_type payload_type[OT_VENC_MAX_CHN_NUM] = {0};
    ot_venc_stream_buf_info stream_buf_info[OT_VENC_MAX_CHN_NUM];
    sample_venc_getstream_para *para = (sample_venc_getstream_para *)p;
    sample_comm_venc_stream_proc_info *stream_proc_info = malloc(sizeof(sample_comm_venc_stream_proc_info));

    if (stream_proc_info == TD_NULL || memset_s(stream_proc_info, sizeof(sample_comm_venc_stream_proc_info), 0,
        sizeof(sample_comm_venc_stream_proc_info)) != EOK) {
        res = (td_void *)TD_FAILURE;
        goto FREE;
    }

    prctl(PR_SET_NAME, "get_venc_stream", 0, 0, 0);

    stream_proc_info->chn_total = para->cnt;
    stream_proc_info->save_heif = para->save_heif;

    ret = sample_comm_set_name_save_stream(stream_proc_info, stream_buf_info, payload_type, para, OT_VENC_MAX_CHN_NUM);
    if (ret == SAMPLE_RETURN_NULL) {
        goto CLOSE_FILE;
    } else if (ret == SAMPLE_RETURN_FAILURE) {
        res = (td_void *)TD_FAILURE;
        goto CLOSE_FILE;
    }

    while (para->thread_start == TD_TRUE) {
        FD_ZERO(&read_fds);
        for (i = 0; (i < stream_proc_info->chn_total) && (i < OT_VENC_MAX_CHN_NUM); i++) {
            FD_SET(stream_proc_info->venc_fd[i], &read_fds);
        }

        timeout_val.tv_sec = 2; /* 2 is a number */
        timeout_val.tv_usec = 0;
        ret = select(stream_proc_info->maxfd + 1, &read_fds, TD_NULL, TD_NULL, &timeout_val);
        if (ret < 0) {
            sample_print_err("select failed!\n");
            break;
        } else if (ret == 0) {
            sample_print_info("get venc stream time out, exit thread\n");
            continue;
        } else {
            sample_comm_fd_isset(stream_proc_info, &read_fds, stream_buf_info, payload_type, para);
        }
    }

CLOSE_FILE:
    /* step 3 : close save-file */
    sample_comm_close_save_file(stream_proc_info);
FREE:
    if (stream_proc_info != TD_NULL) {
        free(stream_proc_info);
    }

    return res;
}

/* *****************************************************************************
* function : bitrate_auto
 * **************************************************************************** */
#define SAMPLE_VENC_WIDHT 640
#define SAMPLE_VENC_HEIGHT 480
#define SAMPLE_VENC_NUM 5
#define SAMPLE_VENC_FG_TYPE 5
#define QUERY_SLEEP 1000

td_void sample_comm_venc_set_region(td_u64 time, ot_venc_chn venc_chn, ot_venc_svc_rect_info *pst_svc_rect)
{
    td_s32 j, ret;
    td_u32 attrx[SAMPLE_VENC_NUM] = {32, 96, 128, 192, 256}; // 32 96 128 192 256 : X-coordinate
    td_u32 attry[SAMPLE_VENC_NUM] = {32, 96, 128, 192, 256}; // 32 96 128 192 256 : Y-coordinate
    td_u32 attrw[SAMPLE_VENC_NUM] = {32, 64, 96, 96, 64};    // 32 64 96 96 64 : width
    td_u32 attrh[SAMPLE_VENC_NUM] = {32, 64, 96, 96, 64};    // 32 64 96 96 64 : height
    td_u32 type[SAMPLE_VENC_NUM] = {0, 3, 4, 1, 2};          // 0 3 4 1 2 : type
    pst_svc_rect->rect_num = SAMPLE_VENC_NUM;
    pst_svc_rect->pts = time;
    pst_svc_rect->base_resolution.width = SAMPLE_VENC_WIDHT;
    pst_svc_rect->base_resolution.height = SAMPLE_VENC_HEIGHT;

    for (j = 0; (j < SAMPLE_VENC_NUM) && (j < OT_VENC_MAX_SVC_RECT_NUM); j++) {
        pst_svc_rect->detect_type[j] = type[j];
        pst_svc_rect->rect_attr[j].x = attrx[j];
        pst_svc_rect->rect_attr[j].y = attry[j];
        pst_svc_rect->rect_attr[j].width = attrw[j];
        pst_svc_rect->rect_attr[j].height = attrh[j];
    }
    ret = ss_mpi_venc_send_svc_region(venc_chn, pst_svc_rect);
    if (ret != TD_SUCCESS) {
        sample_print_err("Set ss_mpi_venc_send_svc_region failed for %#x chn =%d\n", ret, venc_chn);
    }
}
td_void sample_comm_venc_set_svc_param(ot_venc_chn venc_chn, ot_venc_svc_param *pst_svc_param)
{
    td_s32 j, ret;
    td_u32 qp_i[SAMPLE_VENC_NUM] = {2, 62, 94, 1, 0}; // 2 62 94 1 0 : fg I frame qp
    td_u32 qp_p[SAMPLE_VENC_NUM] = {4, 58, 94, 2, 0}; // 4 58 94 2 0 : fg P frame qp
    ret = ss_mpi_venc_get_svc_param(venc_chn, pst_svc_param);
    if (ret != TD_SUCCESS) {
        sample_print_err("Set ss_mpi_venc_set_svc_param failed for %#x chn =%d\n", ret, venc_chn);
    }
    pst_svc_param->fg_protect_adaptive_en = TD_TRUE;
    pst_svc_param->activity_region.qpmap_value_i = 0;
    pst_svc_param->activity_region.qpmap_value_p = 0;
    pst_svc_param->activity_region.skipmap_value = 0;
    pst_svc_param->bg_region.qpmap_value_i = 2; // 2 :i frame bg qp
    pst_svc_param->bg_region.qpmap_value_p = 6; // 6 :p frame bg qp
    pst_svc_param->bg_region.skipmap_value = 0;
    for (j = 0; (j < SAMPLE_VENC_NUM) && (j < SVC_RECT_TYPE_BUTT); j++) {
        pst_svc_param->fg_region[j].qpmap_value_i = qp_i[j];
        pst_svc_param->fg_region[j].qpmap_value_p = qp_p[j];
        pst_svc_param->fg_region[j].skipmap_value = 0;
    }
    ret = ss_mpi_venc_set_svc_param(venc_chn, pst_svc_param);
    if (ret != TD_SUCCESS) {
        sample_print_err("Set ss_mpi_venc_set_svc_param failed for %#x!\n", ret);
    }
}

td_void *sample_comm_venc_rateauto_stream_proc(td_void *p)
{
    td_s32 i, ret;
    sample_venc_rateauto_para *para;
    ot_venc_svc_param svc_param;
    ot_vpss_chn_attr vpss_chn_attr;
    ot_venc_svc_rect_info svc_rect_info = { 0 };
    para = (sample_venc_rateauto_para *)p;
    ot_video_frame_info video_frame;
    prctl(PR_SET_NAME, "get_venc_rateauto_stream", 0, 0, 0);
    if (para->cnt >= OT_VENC_MAX_CHN_NUM) {
        sample_print_err("input count invalid\n");
        return TD_NULL;
    }
    for (i = 0; (i < para->cnt) && (i < OT_VENC_MAX_CHN_NUM); i++) {
        ret = ss_mpi_vpss_get_chn_attr(para->vpss_grp, para->vpss_chn[i], &vpss_chn_attr);
        if (ret != TD_SUCCESS) {
            sample_print_err("ss_mpi_vpss_get_chn_attr err: 0x%x", ret);
        }

        vpss_chn_attr.depth = 3; /* 3 is a number */
        ret = ss_mpi_vpss_set_chn_attr(para->vpss_grp, para->vpss_chn[i], &vpss_chn_attr);
        if (ret == TD_SUCCESS) {
            sample_print_err("ss_mpi_vpss_set_chn_attr err: 0x%x", ret);
        }
    }

    while (para->thread_start == TD_TRUE) {
        for (i = 0; (i < para->cnt) && (i < OT_VENC_MAX_CHN_NUM); i++) {
            ret = ss_mpi_vpss_get_chn_frame(para->vpss_grp, para->vpss_chn[i], &video_frame, QUERY_SLEEP);
            if (ret != TD_SUCCESS) {
                sample_print_err("ss_mpi_vpss_get_chn_frame err:0x%x venc_chn = %d\n", ret, para->venc_chn[i]);
                continue;
            }
            ret = ss_mpi_vpss_release_chn_frame(para->vpss_grp, para->vpss_chn[i], &video_frame);
            if (ret != TD_SUCCESS) {
                sample_print_err("ss_mpi_vpss_release_chn_frame err:0x%x\n", ret);
                return TD_NULL;
            }

            ret = ss_mpi_venc_enable_svc(para->venc_chn[i], TD_TRUE);
            if (ret != TD_SUCCESS) {
                sample_print_err("Set ss_mpi_venc_enable_svc failed for %#x!\n", ret);
                return TD_NULL;
            }
            sample_comm_venc_set_region(video_frame.video_frame.pts, para->venc_chn[i], &svc_rect_info);
            sample_comm_venc_set_svc_param(para->venc_chn[i], &svc_param);
        }
        usleep(QUERY_SLEEP);
    }
    return TD_NULL;
}

static td_s32 sample_comm_set_file_name_svc_t(sample_comm_venc_stream_proc_info *stream_proc_info, td_s32 index)
{
    if (snprintf_s(stream_proc_info->file_name[index], FILE_NAME_LEN, FILE_NAME_LEN - 1, "./") < 0) {
        return TD_FAILURE;
    }
    if (realpath(stream_proc_info->file_name[index], stream_proc_info->real_file_name[index]) == TD_NULL) {
        sample_print_err("file path error\n");
        return TD_FAILURE;
    }
    if (snprintf_s(stream_proc_info->real_file_name[index], FILE_NAME_LEN, FILE_NAME_LEN - 1,
        "tid%d%s", index, stream_proc_info->file_postfix) < 0) {
        return TD_FAILURE;
    }

    return TD_SUCCESS;
}

static td_s32 sample_comm_set_name_save_stream_svc_t(sample_comm_venc_stream_proc_info *stream_proc_info,
    ot_venc_stream_buf_info *stream_buf_info, td_s32 venc_max_chn)
{
    td_s32 i, ret, cnt, fd;
    ot_venc_chn_attr venc_chn_attr;
    ot_payload_type payload_type[OT_VENC_MAX_CHN_NUM];
    ot_unused(venc_max_chn);

    for (i = 0; i < stream_proc_info->chn_total; i++) {
        /* decide the stream file name, and open file to save stream */
        stream_proc_info->venc_chn = i;
        ret = ss_mpi_venc_get_chn_attr(stream_proc_info->venc_chn, &venc_chn_attr);
        if (ret != TD_SUCCESS) {
            sample_print_err("ss_mpi_venc_get_chn_attr chn[%d] failed with %#x!\n", stream_proc_info->venc_chn, ret);
            return SAMPLE_RETURN_NULL;
        }
        payload_type[i] = venc_chn_attr.venc_attr.type;

        ret = sample_comm_venc_get_file_postfix(payload_type[i], stream_proc_info->file_postfix,
            sizeof(stream_proc_info->file_postfix));
        if (ret != TD_SUCCESS) {
            sample_print_err("sample_comm_venc_get_file_postfix [%d] failed with %#x!\n",
                         venc_chn_attr.venc_attr.type, ret);
            return SAMPLE_RETURN_NULL;
        }

        for (cnt = 0; cnt < 3; cnt++) { /* 3 is a number */
            if (sample_comm_set_file_name_svc_t(stream_proc_info, (i + cnt)) != TD_SUCCESS) {
                return SAMPLE_RETURN_NULL;
            }

            stream_proc_info->file[i + cnt] = fopen(stream_proc_info->real_file_name[i + cnt], "wb");
            if (!stream_proc_info->file[i + cnt]) {
                sample_print_err("open file[%s] failed!\n", stream_proc_info->real_file_name[i + cnt]);
                return SAMPLE_RETURN_NULL;
            }
            fd = fileno(stream_proc_info->file[i + cnt]);
            fchmod(fd, S_IRUSR | S_IWUSR);
        }

        /* set venc fd. */
        stream_proc_info->venc_fd[i] = ss_mpi_venc_get_fd(i);
        if (stream_proc_info->venc_fd[i] < 0) {
            sample_print_err("ss_mpi_venc_get_fd failed with %#x!\n", stream_proc_info->venc_fd[i]);
            return SAMPLE_RETURN_NULL;
        }
        if (stream_proc_info->maxfd <= stream_proc_info->venc_fd[i]) {
            stream_proc_info->maxfd = stream_proc_info->venc_fd[i];
        }
        ret = ss_mpi_venc_get_stream_buf_info(i, &stream_buf_info[i]);
        if (ret != TD_SUCCESS) {
            sample_print_err("ss_mpi_venc_get_stream_buf_info failed with %#x!\n", ret);
            return SAMPLE_RETURN_FAILURE;
        }
    }

    return TD_SUCCESS;
}

static td_void sample_comm_save_frame_to_file_svc_t(td_s32 index, sample_comm_venc_stream_proc_info *stream_proc_info,
    ot_venc_stream *stream, ot_venc_stream_buf_info *stream_buf_info)
{
    td_s32 cnt, ret;

    for (cnt = 0; cnt < 3; cnt++) { /* 3 is a number */
        switch (cnt) {
            case 0: /* 0 is a number */
                if (stream->h264_info.ref_type == OT_VENC_BASE_IDR_SLICE ||
                    stream->h264_info.ref_type == OT_VENC_BASE_P_SLICE_REF_BY_BASE) {
#ifndef __LITEOS__
                    ot_unused(stream_buf_info);
                    ret = sample_comm_venc_save_stream(stream_proc_info->file[index + cnt], stream);
#else
                    ret = sample_comm_venc_save_stream_phys_addr(stream_proc_info->file[index + cnt],
                        &stream_buf_info[index], stream);
#endif
                }
                break;
            case 1: /* 1 is a number */
                if (stream->h264_info.ref_type == OT_VENC_BASE_IDR_SLICE ||
                    stream->h264_info.ref_type == OT_VENC_BASE_P_SLICE_REF_BY_BASE ||
                    stream->h264_info.ref_type == OT_VENC_BASE_P_SLICE_REF_BY_ENHANCE) {
#ifndef __LITEOS__
                    ret = sample_comm_venc_save_stream(stream_proc_info->file[index + cnt], stream);
#else
                    ret = sample_comm_venc_save_stream_phys_addr(stream_proc_info->file[index + cnt],
                        &stream_buf_info[index], stream);
#endif
                }
                break;
            case 2: /* 2 is a number */
#ifndef __LITEOS__
                ret = sample_comm_venc_save_stream(stream_proc_info->file[index + cnt], stream);
#else
                ret = sample_comm_venc_save_stream_phys_addr(stream_proc_info->file[index + cnt],
                    &stream_buf_info[index], stream);
#endif
                break;
            default:
                break;
        }
        if (ret != TD_SUCCESS) {
            free(stream->pack);
            stream->pack = TD_NULL;
            sample_print_err("save stream failed!\n");
            break;
        }
    }
}

static td_s32 sample_comm_get_stream_from_one_channl_svc_t(sample_comm_venc_stream_proc_info *stream_proc_info,
    td_s32 index, ot_venc_stream_buf_info *stream_buf_info)
{
    td_s32 ret;
    ot_venc_stream stream;
    ot_venc_chn_status stat;

    /* step 2.1 : query how many packs in one-frame stream. */
    if (memset_s(&stream, sizeof(stream), 0, sizeof(stream)) != EOK) {
        sample_print_err("call memset_s error\n");
    }
    ret = ss_mpi_venc_query_status(index, &stat);
    if (ret != TD_SUCCESS) {
        sample_print_err("ss_mpi_venc_query chn[%d] failed with %#x!\n", index, ret);
        return SAMPLE_RETURN_BREAK;
    }

    if (stat.cur_packs == 0) {
        sample_print_err("NOTE: current  frame is TD_NULL!\n");
        return SAMPLE_RETURN_CONTINUE;
    }
    /* step 2.3 : malloc corresponding number of pack nodes. */
    stream.pack = (ot_venc_pack *)malloc(sizeof(ot_venc_pack) * stat.cur_packs);
    if (stream.pack == TD_NULL) {
        sample_print_err("malloc stream pack failed!\n");
        return SAMPLE_RETURN_BREAK;
    }
    /* step 2.4 : call mpi to get one-frame stream */
    stream.pack_cnt = stat.cur_packs;
    ret = ss_mpi_venc_get_stream(index, &stream, TD_TRUE);
    if (ret != TD_SUCCESS) {
        free(stream.pack);
        stream.pack = TD_NULL;
        sample_print_err("ss_mpi_venc_get_stream failed with %#x!\n", ret);
        return SAMPLE_RETURN_BREAK;
    }
    /* step 2.5 : save frame to file */
    sample_comm_save_frame_to_file_svc_t(index, stream_proc_info, &stream, stream_buf_info);

    /* step 2.6 : release stream */
    ret = ss_mpi_venc_release_stream(index, &stream);
    if (ret != TD_SUCCESS) {
        free(stream.pack);
        stream.pack = TD_NULL;
        return SAMPLE_RETURN_BREAK;
    }
    /* step 2.7 : free pack nodes */
    free(stream.pack);
    stream.pack = TD_NULL;

    return TD_SUCCESS;
}

static td_void sample_comm_fd_isset_svc_t(sample_comm_venc_stream_proc_info *stream_proc_info, fd_set *read_fds,
    ot_venc_stream_buf_info *stream_buf_info, td_s32 venc_max_chn)
{
    td_s32 i, ret;
    ot_unused(venc_max_chn);

    for (i = 0; i < stream_proc_info->chn_total; i++) {
        if (FD_ISSET(stream_proc_info->venc_fd[i], read_fds)) {
            ret = sample_comm_get_stream_from_one_channl_svc_t(stream_proc_info, i, stream_buf_info);
            if (ret == SAMPLE_RETURN_CONTINUE) {
                continue;
            } else if (ret == SAMPLE_RETURN_BREAK) {
                break;
            }
        }
    }
}

/* get svc_t stream from h264 channels and save them */
td_void *sample_comm_venc_get_venc_stream_proc_svc_t(td_void *p)
{
    td_s32 i, ret;
    td_void* res = TD_NULL;
    sample_venc_getstream_para *para = (sample_venc_getstream_para *)p;
    struct timeval timeout_val;
    fd_set read_fds;
    ot_venc_stream_buf_info stream_buf_info[OT_VENC_MAX_CHN_NUM];
    sample_comm_venc_stream_proc_info *stream_proc_info = malloc(sizeof(sample_comm_venc_stream_proc_info));

    if (stream_proc_info == TD_NULL || memset_s(stream_proc_info, sizeof(sample_comm_venc_stream_proc_info), 0,
        sizeof(sample_comm_venc_stream_proc_info)) != EOK) {
        res = (td_void *)TD_FAILURE;
        goto FREE;
    }

    stream_proc_info->chn_total = para->cnt;
    stream_proc_info->save_heif = para->save_heif;

    ret = sample_comm_set_name_save_stream_svc_t(stream_proc_info, stream_buf_info, OT_VENC_MAX_CHN_NUM);
    if (ret == SAMPLE_RETURN_NULL) {
        goto CLOSE_FILE;
    } else if (ret == SAMPLE_RETURN_FAILURE) {
        res = (td_void *)TD_FAILURE;
        goto CLOSE_FILE;
    }

    /* step 2:  start to get streams of each channel. */
    while (para->thread_start == TD_TRUE) {
        FD_ZERO(&read_fds);
        for (i = 0; i < stream_proc_info->chn_total; i++) {
            FD_SET(stream_proc_info->venc_fd[i], &read_fds);
        }
        timeout_val.tv_sec = 2; /* 2 is a number */
        timeout_val.tv_usec = 0;
        ret = select(stream_proc_info->maxfd + 1, &read_fds, TD_NULL, TD_NULL, &timeout_val);
        if (ret < 0) {
            sample_print_err("select failed!\n");
            break;
        } else if (ret == 0) {
            sample_print_info("get venc stream time out, exit thread\n");
            continue;
        } else {
            sample_comm_fd_isset_svc_t(stream_proc_info, &read_fds, stream_buf_info, OT_VENC_MAX_CHN_NUM);
        }
    }

CLOSE_FILE:
    sample_comm_close_save_file_svc(stream_proc_info);
FREE:
    if (stream_proc_info != TD_NULL) {
        free(stream_proc_info);
    }

    return res;
}

td_void sample_comm_venc_set_save_heif(td_bool save_heif)
{
    g_para.save_heif = save_heif;
    sample_print_err("set save heif flag: %d!\n", save_heif);
}

/* start get venc stream process thread */
td_s32 sample_comm_venc_start_get_stream(ot_venc_chn *venc_chn, td_s32 cnt)
{
    td_s32 i;

    g_para.thread_start = TD_TRUE;
    g_para.cnt = cnt;
    if (cnt >= OT_VENC_MAX_CHN_NUM) {
        sample_print_err("input count invalid\n");
        return TD_FAILURE;
    }
    for (i = 0; (i < cnt) && (i < OT_VENC_MAX_CHN_NUM); i++) {
        g_para.venc_chn[i] = venc_chn[i];
    }

    return pthread_create(&g_venc_pid, 0, sample_comm_venc_get_venc_stream_proc, (td_void *)&g_para);
}
/* *****************************************************************************
* function : start rate auto process thread
 * **************************************************************************** */
td_s32 sample_comm_venc_rateauto_start(ot_venc_chn venc_chn[], td_s32 cnt, ot_vpss_grp vpss_grp, ot_vpss_chn vpss_chn[])
{
    td_s32 i;

    g_venc_rateauto_frame_param.thread_start = TD_TRUE;
    g_venc_rateauto_frame_param.cnt = cnt;
    g_venc_rateauto_frame_param.vpss_grp = vpss_grp;
    for (i = 0; (i < cnt) && (i < OT_VENC_MAX_CHN_NUM); i++) {
        g_venc_rateauto_frame_param.venc_chn[i] = venc_chn[i];
        g_venc_rateauto_frame_param.vpss_chn[i] = vpss_chn[i];
    }

    return pthread_create(&g_venc_rateauto_pid, 0, sample_comm_venc_rateauto_stream_proc,
        (td_void *)&g_venc_rateauto_frame_param);
}
/* start get venc svc-t stream process thread */
td_s32 sample_comm_venc_start_get_stream_svc_t(td_s32 cnt)
{
    /* step 1:  check & prepare save-file & venc-fd */
    if (cnt >= OT_VENC_MAX_CHN_NUM) {
        sample_print_err("input count invalid\n");
        return TD_FAILURE;
    }

    g_para.thread_start = TD_TRUE;
    g_para.cnt = cnt;
    return pthread_create(&g_venc_pid, 0, sample_comm_venc_get_venc_stream_proc_svc_t, (td_void *)&g_para);
}

/* stop get venc stream process. */
td_s32 sample_comm_venc_stop_get_stream(td_s32 chn_num)
{
    td_s32 i;
    if (g_para.thread_start == TD_TRUE) {
        g_para.thread_start = TD_FALSE;
        pthread_join(g_venc_pid, 0);
    }

    for (i = 0; i < chn_num; i++) {
        if (ss_mpi_venc_stop_chn(i) != TD_SUCCESS) {
            sample_print_err("chn %d ss_mpi_venc_stop_recv_pic failed!\n", i);
            return TD_FAILURE;
        }
    }

    return TD_SUCCESS;
}

td_s32 sample_comm_venc_stop_send_qpmap_frame(td_void)
{
    if (g_qpmap_send_frame_para.thread_start == TD_TRUE) {
        g_qpmap_send_frame_para.thread_start = TD_FALSE;
        pthread_join(g_venc_qpmap_pid, 0);
    }
    return TD_SUCCESS;
}

td_s32 sample_comm_venc_stop_send_roimap_frame(td_void)
{
    if (g_roimap_frame_param.thread_start == TD_TRUE) {
        g_roimap_frame_param.thread_start = TD_FALSE;
        pthread_join(g_venc_roimap_pid, 0);
    }

    return TD_SUCCESS;
}

td_s32 sample_comm_venc_stop_send_frame(td_void)
{
    if (g_send_frame_param.thread_start == TD_TRUE) {
        g_send_frame_param.thread_start = TD_FALSE;
        pthread_join(g_venc_send_pid, 0);
    }

    return TD_SUCCESS;
}

static td_s32 sample_comm_venc_mosaic_map_send_frame_ex(sample_venc_send_frame_para *para,
    ot_venc_user_frame_info *frame_info, ot_video_frame_info *video_frame, td_s32 index)
{
    td_s32 ret;

    ret = ss_mpi_venc_send_frame_ex(para->venc_chn[index], frame_info, -1);
    if (ret != TD_SUCCESS) {
        sample_print_err("ss_mpi_venc_send_frame_ex err:0x%x\n", ret);

        ret = ss_mpi_vpss_release_chn_frame(para->vpss_grp, para->vpss_chn[index], video_frame);
        if (ret != TD_SUCCESS) {
            sample_print_err("ss_mpi_vpss_release_chn_frame err:0x%x", ret);
            return SAMPLE_RETURN_GOTO;
        }
        return SAMPLE_RETURN_BREAK;
    }

    return TD_SUCCESS;
}

static td_s32 sample_comm_venc_mosaic_map_send_frame_start(sample_venc_send_frame_para *para,
    sample_comm_venc_mosaic_frame_proc_info addr_info)
{
    td_u32 frame_id = 0;
    td_s32 i, ret = TD_SUCCESS;

    ot_venc_user_frame_info *frame_info = sample_comm_malloc_frame_martix(VENC_MOSAIC_MAP_MAX_CHN, SEND_FRAME_BUF_NUM);

    if (frame_info == TD_NULL) {
        return TD_FAILURE;
    }

    while (para->thread_start == TD_TRUE) {
        for (i = 0; (i < para->cnt) && (i < VENC_MOSAIC_MAP_MAX_CHN) &&
            i * SEND_FRAME_BUF_NUM + frame_id < VENC_MOSAIC_MAP_MAX_CHN * SEND_FRAME_BUF_NUM; i++) {
            ot_video_frame_info *video_frame = &frame_info[i * SEND_FRAME_BUF_NUM + frame_id].user_frame;
            ret = ss_mpi_vpss_get_chn_frame(para->vpss_grp, para->vpss_chn[i], video_frame,
                1000); /* 1000 is a timeout para */
            if (ret != TD_SUCCESS) {
                sample_print_err("\n OT_MPI_VPSS_GetChnFrame err:0x%x\n", ret);
                continue;
            }

            frame_info[i * SEND_FRAME_BUF_NUM + frame_id].user_mosaic.blk_size = addr_info.blk_size[i];
            frame_info[i * SEND_FRAME_BUF_NUM + frame_id].user_mosaic.mode = OT_VENC_MOSAIC_MODE_MAP;
            frame_info[i * SEND_FRAME_BUF_NUM + frame_id].user_mosaic.map_param.phys_addr = addr_info.map_phys_addr[i];
            frame_info[i * SEND_FRAME_BUF_NUM + frame_id].user_mosaic.map_param.valid = TD_TRUE;
            frame_info[i * SEND_FRAME_BUF_NUM + frame_id].user_mosaic.map_param.specified_yuv_en = TD_FALSE;
            frame_info[i * SEND_FRAME_BUF_NUM + frame_id].user_mosaic.map_param.pixel_yuv.data_y = 255; // 255: 255亮度参数
            frame_info[i * SEND_FRAME_BUF_NUM + frame_id].user_mosaic.map_param.pixel_yuv.data_u = 255; // 255: 255色度参数
            frame_info[i * SEND_FRAME_BUF_NUM + frame_id].user_mosaic.map_param.pixel_yuv.data_v = 255; // 255: 255色度参数

            ret = sample_comm_venc_mosaic_map_send_frame_ex(para,
                &frame_info[i * SEND_FRAME_BUF_NUM + frame_id], video_frame, i);
            if (ret == SAMPLE_RETURN_BREAK) {
                break;
            } else if (ret == SAMPLE_RETURN_GOTO) {
               goto FREE;
            }

            ret = ss_mpi_vpss_release_chn_frame(para->vpss_grp, para->vpss_chn[i], video_frame);
            if (ret != TD_SUCCESS) {
                sample_print_err("ss_mpi_vpss_release_chn_frame err:0x%x", ret);
                goto FREE;
            }

            if (++frame_id >= SEND_FRAME_BUF_NUM) {
                frame_id = 0;
            }
        }
    }

FREE:
    free(frame_info);
    return ret;
}

static td_void sample_comm_venc_mosaic_map_free_mmz(sample_comm_venc_mosaic_frame_proc_info *addr_info, td_s32 cnt)
{
    td_s32 i, ret;

    for (i = 0; (i < cnt) && (i < VENC_MOSAIC_MAP_MAX_CHN); i++) {
        if (addr_info->map_phys_addr[i] != 0) {
            ret = ss_mpi_sys_mmz_free(addr_info->map_phys_addr[i], addr_info->map_vir_addr[i]);
            if (ret != TD_SUCCESS) {
                sample_print_err("ss_mpi_sys_mmz_free err:0x%x", ret);
            }
        }
    }
}

static td_u32 sample_comm_venc_mosaic_map_trans_blk_size(ot_mosaic_blk_size blk_size)
{
    td_u32 size;

    switch (blk_size) {
        case OT_MOSAIC_BLK_SIZE_4:
            size = 4; // 4: blk size
            break;

        case OT_MOSAIC_BLK_SIZE_8:
            size = 8; // 8: blk size
            break;

        case OT_MOSAIC_BLK_SIZE_16:
            size = 16; // 16: blk size
            break;

        case OT_MOSAIC_BLK_SIZE_32:
            size = 32; // 32: blk size
            break;

        case OT_MOSAIC_BLK_SIZE_64:
            size = 64; // 64: blk size
            break;

        case OT_MOSAIC_BLK_SIZE_128:
            size = 128; // 128: blk size
            break;

        default:
            size = 0;
            break;
    }

    return size;
}

td_void *sample_comm_venc_mosaic_map_send_frame_proc(td_void *p)
{
    td_s32 i, ret, stride, blk_size;
    td_u32 map_size;
    sample_venc_send_frame_para *para;
    sample_comm_venc_mosaic_frame_proc_info addr_info = { 0 };

    para = (sample_venc_send_frame_para *)p;
    // init mosaic_map
    for (i = 0; i < para->cnt && i < VENC_MOSAIC_MAP_MAX_CHN; i++) {
        td_char map_name[MAX_MMZ_NAME_LEN];
        ot_venc_chn_attr chn_attr = { 0 };

        ss_mpi_venc_get_chn_attr((ot_venc_chn)i, &chn_attr);
        if (snprintf_s(map_name, MAX_MMZ_NAME_LEN, MAX_MMZ_NAME_LEN - 1, "mosaic_map:%d", i) < 0) {
            sample_print_err("config mosaic_map:%d failed\n", i);
            return TD_NULL;
        }

        addr_info.blk_size[i] = OT_MOSAIC_BLK_SIZE_32;
        blk_size = sample_comm_venc_mosaic_map_trans_blk_size(addr_info.blk_size[i]);
        stride = ot_venc_get_mosaic_map_stride(chn_attr.venc_attr.pic_width, blk_size);
        map_size = ot_venc_get_mosaic_map_size(chn_attr.venc_attr.pic_width, chn_attr.venc_attr.pic_height, blk_size);
        ret = ss_mpi_sys_mmz_alloc(&addr_info.map_phys_addr[i], &addr_info.map_vir_addr[i], map_name,
                                   TD_NULL, map_size);
        if (ret != TD_SUCCESS) {
            sample_print_err("alloc mosaic map:%d failed.\n", i);
            goto error;
        }

        (td_void)memset_s(addr_info.map_vir_addr[i], map_size, 0, map_size);
        (td_void)memset_s(addr_info.map_vir_addr[i], stride, 0xff, stride);
        (td_void)memset_s(addr_info.map_vir_addr[i] + stride * 2, stride, 0xff, stride); /* 2: stride num */
    }

    /* set vpss buffer depth */
    for (i = 0; (i < para->cnt) && (i < OT_VPSS_MAX_PHYS_CHN_NUM); i++) {
        ot_vpss_chn_attr vpss_chn_attr;
        if (ss_mpi_vpss_get_chn_attr(para->vpss_grp, para->vpss_chn[i], &vpss_chn_attr) != TD_SUCCESS) {
            sample_print_err("ss_mpi_vpss_get_chn_attr err");
            goto error;
        }
        vpss_chn_attr.depth = 3; /* 3 is a number */
        if (ss_mpi_vpss_set_chn_attr(para->vpss_grp, para->vpss_chn[i], &vpss_chn_attr) != TD_SUCCESS) {
            sample_print_err("ss_mpi_vpss_set_chn_attr err");
            goto error;
        }
    }

    if (sample_comm_venc_mosaic_map_send_frame_start(para, addr_info) != TD_SUCCESS) {
        sample_print_err("free mosaic:%d map failed.\n", i);
        goto error;
    }

error:
    sample_comm_venc_mosaic_map_free_mmz(&addr_info, para->cnt);
    return TD_NULL;
}

td_s32 sample_comm_venc_mosaic_map_send_frame(ot_vpss_grp vpss_grp, ot_vpss_chn vpss_chn[], ot_venc_chn venc_chn[],
    td_s32 cnt, ot_size size[])
{
    td_s32 i;

    g_send_frame_param.thread_start = TD_TRUE;
    g_send_frame_param.vpss_grp = vpss_grp;
    g_send_frame_param.cnt = cnt;

    for (i = 0; (i < cnt) && (i < OT_VENC_MAX_CHN_NUM) && (i < OT_VPSS_MAX_PHYS_CHN_NUM); i++) {
        g_send_frame_param.venc_chn[i] = venc_chn[i];
        g_send_frame_param.vpss_chn[i] = vpss_chn[i];
        g_send_frame_param.size[i] = size[i];
    }

    return pthread_create(&g_venc_send_pid, 0, sample_comm_venc_mosaic_map_send_frame_proc,
        (td_void *)&g_send_frame_param);
}

td_s32 sample_comm_venc_stop_rateauto(ot_venc_chn chn[], td_s32 cnt)
{
    td_s32 i, ret;

    prctl(PR_SET_NAME, "sample_comm_venc_stop_rateauto", 0, 0, 0);

    ot_venc_svc_param svc_param = { 0 };

    ot_venc_chn venc_chn;
    ot_venc_svc_rect_info svc_rect_info = { 0 };
    if (g_venc_rateauto_frame_param.thread_start == TD_TRUE) {
        g_venc_rateauto_frame_param.thread_start = TD_FALSE;
        pthread_join(g_venc_rateauto_pid, 0);
        for (i = 0; i < cnt; i++) {
            venc_chn = chn[i];
            ret = ss_mpi_venc_enable_svc(venc_chn, TD_TRUE);
            if (ret != TD_SUCCESS) {
                sample_print_err("Set ss_mpi_venc_enable_svc failed for %#x chn =%d\n", ret, venc_chn);
            }
            if (memset_s(&svc_rect_info, sizeof(ot_venc_svc_rect_info), 0, sizeof(ot_venc_svc_rect_info)) != EOK) {
                sample_print_err("call memset_s error\n");
            }
            ret = ss_mpi_venc_send_svc_region(venc_chn, &svc_rect_info);
            if (ret != TD_SUCCESS) {
                sample_print_err("Set ss_mpi_venc_send_svc_region failed for %#x chn =%d\n", ret, venc_chn);
            }
            ret = ss_mpi_venc_get_svc_param(venc_chn, &svc_param);
            if (ret != TD_SUCCESS) {
                sample_print_err("Set ss_mpi_venc_set_svc_param failed for %#x chn =%d\n", ret, venc_chn);
            }
            if (memset_s(&svc_param, sizeof(ot_venc_svc_param), 0, sizeof(ot_venc_svc_param)) != EOK) {
                sample_print_err("call memset_s error\n");
            }
            ret = ss_mpi_venc_set_svc_param(venc_chn, &svc_param);
            if (ret != TD_SUCCESS) {
                sample_print_err("Set ss_mpi_venc_set_svc_param failed for %#x chn =%d\n", ret, venc_chn);
            }
            ret = ss_mpi_venc_enable_svc(venc_chn, TD_FALSE);
            if (ret != TD_SUCCESS) {
                sample_print_err("Set ss_mpi_venc_enable_svc failed for %#x chn =%d\n", ret, venc_chn);
            }
        }
    }

    return TD_SUCCESS;
}

td_s32 sample_comm_venc_plan_to_semi(td_u8 *u, td_s32 u_stride, td_u8 *v, td_s32 pic_height)
{
    td_s32 i;
    td_u8 *tmp_u = TD_NULL;
    td_u8 *ptu = TD_NULL;
    td_u8 *tmp_v = TD_NULL;
    td_u8 *ptv = TD_NULL;
    td_s32 haf_w = u_stride / 2;   /* 2: half */
    td_s32 haf_h = pic_height / 2; /* 2: half */
    td_s32 size = haf_w * haf_h;

    tmp_u = malloc(size);
    if (tmp_u == TD_NULL) {
        sample_print_err("malloc buf failed\n");
        return TD_FAILURE;
    }
    ptu = tmp_u;

    tmp_v = malloc(size);
    if (tmp_v == TD_NULL) {
        sample_print_err("malloc buf failed\n");
        free(tmp_u);
        return TD_FAILURE;
    }
    ptv = tmp_v;

    if (memcpy_s(tmp_u, size, u, size) != EOK) {
        sample_print_err("call memcpy_s error\n");
        free(tmp_u);
        free(tmp_v);
        return TD_FAILURE;
    }
    if (memcpy_s(tmp_v, size, v, size) != EOK) {
        sample_print_err("call memcpy_s error\n");
        free(tmp_u);
        free(tmp_v);
        return TD_FAILURE;
    }
    for (i = 0; i < (size / 2); i++) { /* 2: half */
        *u++ = *tmp_v++;
        *u++ = *tmp_u++;
    }
    for (i = 0; i < (size / 2); i++) { /* 2: half */
        *v++ = *tmp_v++;
        *v++ = *tmp_u++;
    }
    free(ptu);
    free(ptv);
    return TD_SUCCESS;
}
//add by Kyrie
td_s32 WK_COMM_VENC_GetStreamStart(ot_venc_chn venc_chn)
{
    td_s32 s32Ret;
    wk_stPara.venc_chn[venc_chn] = venc_chn;

    /* set venc fd. */
    WkVencFd[venc_chn] = ss_mpi_venc_get_fd(venc_chn);
    if (WkVencFd[venc_chn] < 0) {
        sample_print_err("ss_mpi_venc_get_fd failed with %#x!\n", WkVencFd[venc_chn]);
        return TD_FAILURE;
    }
    s32Ret = TD_SUCCESS;
    // printf("================= WkVencFd[%d] = [%d] status[%d]\n", venc_chn, WkVencFd[venc_chn], s32Ret);
    
    if(WK_VIDEO_CHANNEL_PREVIEW == wk_stPara.venc_chn[venc_chn] && !wk_stPara.thread_start){
        wk_stPara.thread_start = TD_TRUE;
        return pthread_create(&wk_VencPid, 0, WK_COMM_VENC_GetPreviewStreamProc, (td_void *)&(wk_stPara.venc_chn[venc_chn]));
    }

    return s32Ret;
}

/******************************************************************************
* funciton : get venc [preview] channel(1080P/720P) stream and send
******************************************************************************/
td_void *WK_COMM_VENC_GetPreviewStreamProc(td_void *p)
{
    td_s32 i, j, ret;
    sample_venc_getstream_para *para = TD_NULL;
    struct timeval timeout_val;
    fd_set read_fds;
    ot_payload_type payload_type[OT_VENC_MAX_CHN_NUM] = {OT_PT_H264};
    ot_venc_stream_buf_info stream_buf_info;
    td_s32 venc_fd;
    td_s32 maxfd;
    ot_venc_chn venc_chn = 1; 
    ot_venc_stream stream;
    ot_venc_chn_status stat;

    prctl(PR_SET_NAME, "GetVencStream", 0, 0, 0);

    venc_chn = *((ot_venc_chn *)p);

    /* set venc fd. */
    // venc_fd = ss_mpi_venc_get_fd(venc_chn);
    // if (venc_fd < 0) {
    //     sample_print("ss_mpi_venc_get_fd failed with %#x!\n", venc_fd);
    //     return TD_NULL;
    //     //return TD_FAILURE;
    // }

    venc_fd = WkVencFd[venc_chn];

    if (maxfd <= venc_fd) {
        maxfd = venc_fd;
    }

    ret = ss_mpi_venc_get_stream_buf_info(venc_chn, &stream_buf_info);
    if (ret != TD_SUCCESS) {
        sample_print_err("ss_mpi_venc_get_stream_buf_info failed with %#x!\n", ret);
        return TD_NULL;
        //return TD_FAILURE;
    }

    /* step 2:  start to get streams of each channel. */
    while (wk_stPara.thread_start == TD_TRUE) {      
        FD_ZERO(&read_fds);
        FD_SET(venc_fd, &read_fds);

        timeout_val.tv_sec = 2; /* 2 is a number */
        timeout_val.tv_usec = 0;
        ret = select(maxfd + 1, &read_fds, TD_NULL, TD_NULL, &timeout_val);
        if (ret < 0) {
            sample_print_err("select failed!\n");
            break;
        } else if (ret == 0) {
            sample_print_info("get venc stream time out, exit thread  venc-ch%d\n", venc_chn);
            continue;
        } else {
            if(FD_ISSET(venc_fd, &read_fds)) {            
                /* step 2.1 : query how many packs in one-frame stream. */
                if (memset_s(&stream, sizeof(stream), 0, sizeof(stream)) != EOK) {
                    sample_print_err("call memset_s error\n");
                }

                ret = ss_mpi_venc_query_status(venc_chn, &stat);
                if (ret != TD_SUCCESS) {
                    sample_print_err("ss_mpi_venc_query_status chn[%d] failed with %#x!\n", venc_chn, ret);
                    continue;
                }

                if (stat.cur_packs == 0) {
                    sample_print_err("NOTE: current  frame is TD_NULL!\n");
                    continue;
                }
                /* step 2.3 : malloc corresponding number of pack nodes. */
                stream.pack = (ot_venc_pack *)malloc(sizeof(ot_venc_pack) * stat.cur_packs);
                if (stream.pack == TD_NULL) {
                    sample_print_err("malloc stream pack failed!\n");
                    break;
                }
                /* step 2.4 : call mpi to get one-frame stream */
                stream.pack_cnt = stat.cur_packs;
                ret = ss_mpi_venc_get_stream(venc_chn, &stream, TD_TRUE);
                if (ret != TD_SUCCESS) {
                    free(stream.pack);
                    stream.pack = TD_NULL;
                    sample_print_err("ss_mpi_venc_get_stream failed with %#x!\n", ret);
                    break;
                }

                /*******************************************************
                 step 2.5 : save frame to file
                *******************************************************/
                if(wk_stPara.PreviewCallback != NULL) {
                    for (i = 0; i < stream.pack_cnt; i++) {
                        // printf("==== h264 frame length[%d]\n", stream.pack[i].len - stream.pack[i].offset);
                        wk_stPara.PreviewCallback(stream.pack[i].addr + stream.pack[i].offset, stream.pack[i].len - stream.pack[i].offset, WK_FRAME_END);
                    }
                }           

                /* step 2.6 : release stream */
                ret = ss_mpi_venc_release_stream(venc_chn, &stream);
                if (ret != TD_SUCCESS) {
                    sample_print_err("ss_mpi_venc_release_stream failed!\n");
                    free(stream.pack);
                    stream.pack = TD_NULL;
                    break;
                }

                /* step 2.7 : free pack nodes */
                free(stream.pack);
                stream.pack = TD_NULL;
            }                  
        }
 
        usleep(2*1000);
    }

    return TD_NULL;
}

td_s32 WK_COMM_VENC_SetPreviewCallback(int (*callback)(unsigned char *pBuf, int length, WK_FRAME_FLAG_E FrameFlag))
{
    wk_stPara.PreviewCallback = callback;
    return TD_SUCCESS;
}

/******************************************************************************
* funciton : get venc [record] channel(3840*2160) stream and save file 
******************************************************************************/
int mIdrFrameCount = 0;
int m_mainFrame = 0;
unsigned char mMainVideoBuf[MAX_IDR_FRAME_SIZE];
td_s32 WK_COMM_VENC_GetRecordStreamHandle(int *rec_frame_length, int check_idr)
{
    td_s32 i, j, ret;
    struct timeval timeout_val;
    fd_set read_fds;
    ot_payload_type payload_type[OT_VENC_MAX_CHN_NUM] = {OT_PT_H264};
    ot_venc_stream_buf_info stream_buf_info;
    td_s32 venc_fd;
    td_s32 maxfd;
    ot_venc_chn venc_chn[4] = {0, 1, 2, 3}; /* 4: max chn num, 0/1/2/3 chn id */
    ot_venc_stream stream;
    ot_venc_chn_status stat;

    int lenSize = 0;
    td_u64 m_PTS = 0;
    int nVideoSize = 0;

    td_u32 u32framelength;
    *rec_frame_length = 0;

    /******************************************
     step 2:  Start to get streams of each channel.
    ******************************************/
    FD_ZERO(&read_fds);
    for(i = 0;i < WK_VIDEO_CHANNEL_SNAP;i++){
        FD_SET(WkVencFd[i], &read_fds);

        if (maxfd <= WkVencFd[i]) {
            maxfd = WkVencFd[i];
        }
    }

    timeout_val.tv_sec = 2;
    timeout_val.tv_usec = 0;
    ret = select(maxfd + 1, &read_fds, TD_NULL, TD_NULL, &timeout_val);
    if (ret < 0) {
        sample_print_err("select failed!\n");
        return TD_FAILURE;
    } else if (ret == 0) {
        sample_print_err("get venc[%d] stream time out, exit thread\n", wk_stPara.venc_chn[WK_VIDEO_CHANNEL_RECORD]);
        return TD_FAILURE;
    } else {
        if(FD_ISSET(WkVencFd[WK_VIDEO_CHANNEL_RECORD], &read_fds)) {            
            /* step 2.1 : query how many packs in one-frame stream. */
            if (memset_s(&stream, sizeof(stream), 0, sizeof(stream)) != EOK) {
                sample_print_err("call memset_s error\n");
            }

            ret = ss_mpi_venc_query_status(wk_stPara.venc_chn[WK_VIDEO_CHANNEL_RECORD], &stat);
            if (ret != TD_SUCCESS) {
                sample_print_err("ss_mpi_venc_query_status chn[0] failed with %#x!\n", ret);
                return TD_FAILURE;
            }

            if (stat.cur_packs == 0) {
                sample_print_err("NOTE: current  frame is TD_NULL!\n");
                return TD_FAILURE;
            }
            /* step 2.3 : malloc corresponding number of pack nodes. */
            stream.pack = (ot_venc_pack *)malloc(sizeof(ot_venc_pack) * stat.cur_packs);
            if (stream.pack == TD_NULL) {
                sample_print_err("malloc stream pack failed!\n");
                return TD_FAILURE;
            }
            /* step 2.4 : call mpi to get one-frame stream */
            stream.pack_cnt = stat.cur_packs;
            ret = ss_mpi_venc_get_stream(wk_stPara.venc_chn[WK_VIDEO_CHANNEL_RECORD], &stream, TD_TRUE);
            if (ret != TD_SUCCESS) {
                free(stream.pack);
                stream.pack = TD_NULL;
                sample_print_err("ss_mpi_venc_get_stream failed with %#x!\n", ret);
                return TD_FAILURE;
            }

            /* step 2.5 : save frame to MP4 */
            if(wk_stPara.RecordCallback != NULL)
            {
                u32framelength = 0;

                for (i = 0; i < stream.pack_cnt; i++)
                {
                    // gettimeofday(&dbgtimeval, NULL);
                    // printf("record channel get frame seq[%d] frame [%d]pack length[%d]\n",stream.seq, i, stream.pack[i].len);
                    // if(stStream.pstPack[i].u32Len - stStream.pstPack[i].u32Offset > SIZE_OF_FRAME){
                    //     printf("[%d]frame [%d]pack length[%d] \n",stStream.u32Seq,i,stStream.pstPack[i].u32Len - stStream.pstPack[i].u32Offset);
                    // }
                    memcpy(mMainVideoBuf + u32framelength, stream.pack[i].addr, stream.pack[i].len);
                    u32framelength += stream.pack[i].len;
                }

                if(u32framelength>=MAX_IDR_FRAME_SIZE){
                    sample_print_err("--------- 000 frame size=%d ---------\n",u32framelength);
                    ss_mpi_venc_release_stream(wk_stPara.venc_chn[WK_VIDEO_CHANNEL_RECORD], &stream);
                    free(stream.pack);
                    stream.pack = NULL;
                    return TD_SUCCESS;
                }

                // 判断是否为I帧          
                if(stream.pack_cnt > 2){
                    mIdrFrameCount++;
                }
                // 把固定间隔的I帧写入文件             
                if(mIdrFrameCount >= check_idr){
                    if(check_idr > 2){
                        sample_print("---------write file --> stStream.u32PackCount=[%d] IDR Frame=[%d]---------\n", stream.pack_cnt, u32framelength);
                    }

                    wk_stPara.RecordCallback(mMainVideoBuf, u32framelength);
                    *rec_frame_length = u32framelength;
                    mIdrFrameCount = 0;
                }
                else{
                    *rec_frame_length = 0;
                }               
            }    

            /* step 2.6 : release stream */
            ret = ss_mpi_venc_release_stream(wk_stPara.venc_chn[WK_VIDEO_CHANNEL_RECORD], &stream);
            if (ret != TD_SUCCESS) {
                sample_print_err("ss_mpi_venc_release_stream failed!\n");
                free(stream.pack);
                stream.pack = TD_NULL;
                return TD_FAILURE;
            }

            /* step 2.7 : free pack nodes */
            free(stream.pack);
            stream.pack = TD_NULL;                
        }                  
    }
    
    return TD_SUCCESS;
}

td_s32 WK_COMM_VENC_GetIDR(ot_venc_chn VencChn)
{
    td_s32 s32Ret;
    s32Ret = ss_mpi_venc_request_idr(wk_stPara.venc_chn[VencChn], TD_TRUE);

    if(TD_SUCCESS != s32Ret)
    {
        sample_print_err("ss_mpi_venc_request_idr err 0x%xn", s32Ret);
    }

    return s32Ret;
}

td_s32 WK_COMM_VENC_SetRecordCallback(int (*callback)(unsigned char *pBuf, int length))
{
    wk_stPara.RecordCallback = callback;
    return TD_SUCCESS;
}

/******************************************************************************
* funciton : Start snap channel
******************************************************************************/
td_s32 WK_COMM_VENC_SnapStart(ot_venc_chn VencChn, ot_pic_size stSize)
{
    sample_print("WK_COMM_VENC_SnapStart[%d] size[%d]!\n", VencChn, stSize);
    wk_stPara.venc_chn[VencChn] = VencChn;

    td_s32 ret;
    ot_venc_chn_attr venc_chn_attr;
    ot_venc_jpeg_param stParamJpeg;
    ot_venc_start_param start_param;
    ot_size stPicSize;
    bool support_dcf;

    /* step 1:  create venc channel */
    sample_comm_sys_get_pic_size(stSize, &stPicSize);
    // if(stPicSize.width > 8000){
    //     support_dcf = TD_FALSE; //walkera dcf
    // }
    // else{
    //     support_dcf = TD_TRUE; //walkera dcf
    // }
    support_dcf = TD_FALSE;

    sample_comm_venc_chn_cfg(&stPicSize, support_dcf, &venc_chn_attr);

    ret = ss_mpi_venc_create_chn(VencChn, &venc_chn_attr);
    if (ret != TD_SUCCESS) {
        sample_print_err("ss_mpi_venc_create_chn [%d] failed with %#x!\n", VencChn, ret);
        return ret;
    }

    ret = ss_mpi_venc_get_jpeg_param(VencChn, &stParamJpeg);
    if (TD_SUCCESS != ret)
    {
        sample_print_err("HI_MPI_VENC_GetJpegParam err 0x%x\n",ret);
        return TD_FAILURE;
    }
    sample_print("GetJpegParam --> stParamJpeg.qfactor[%d]\n",stParamJpeg.qfactor);

    if(WK_VIDEO_CHANNEL_SNAP == VencChn){
        stParamJpeg.qfactor = 98;

        ret = ss_mpi_venc_set_jpeg_param(VencChn, &stParamJpeg);
        if (TD_SUCCESS != ret)
        {
            sample_print_err("HI_MPI_VENC_SetJpegParam err 0x%x\n",ret);
            return TD_FAILURE;
        }
    }

    start_param.recv_pic_num = -1;
    ret = ss_mpi_venc_start_chn(VencChn, &start_param);
    if (ret != TD_SUCCESS) {
        sample_print_err("mpi_venc_start_chn faild with%#x!\n", ret);
        return TD_FAILURE;
    }

    return TD_SUCCESS;
    
}

/******************************************************************************
* funciton : Stop snap channel
******************************************************************************/
td_s32 WK_COMM_VENC_SnapStop(ot_venc_chn VencChn)
{
    td_s32 s32Ret;

    s32Ret = ss_mpi_venc_destroy_chn(VencChn);
    if (TD_SUCCESS != s32Ret)
    {
        sample_print_err("ss_mpi_venc_destroy_chn vechn[%d] failed with %#x!\n", VencChn, s32Ret);
        return TD_FAILURE;
    }
    return TD_SUCCESS;
}

/******************************************************************************
* funciton : snap Handle
******************************************************************************/
td_s32 WK_COMM_VENC_SnapJpegHandle(ot_venc_chn VencChn, char *filepath)
{
    td_s32 i, j, ret;
    //sample_venc_getstream_para *para = TD_NULL;
    //getstream_para2 *p = para;
    struct timeval timeout_val;
    fd_set read_fds;
    //ot_payload_type payload_type[OT_VENC_MAX_CHN_NUM] = {OT_PT_H264};
    ot_venc_stream_buf_info stream_buf_info;
    td_s32 venc_fd;
    td_s32 maxfd;
    //ot_venc_chn venc_chn[4] = {0, 1, 2, 3}; /* 4: max chn num, 0/1/2/3 chn id */
    ot_venc_stream stream;
    ot_venc_chn_status stat;

    struct timeval stTime;
    unsigned int m_tv_sec = 0;

    td_s32 frame;

    /* set venc fd. */
    venc_fd = ss_mpi_venc_get_fd(wk_stPara.venc_chn[VencChn]);
    if (venc_fd < 0)
    {
        sample_print_err("ss_mpi_venc_get_fd failed with %#x!\n", venc_fd);
        return TD_FAILURE;
    }

    if (maxfd <= venc_fd) {
        maxfd = venc_fd;
    }

    ret = ss_mpi_venc_get_stream_buf_info(wk_stPara.venc_chn[VencChn], &stream_buf_info);
    if (ret != TD_SUCCESS) {
        sample_print_err("ss_mpi_venc_get_stream_buf_info failed with %#x!\n", ret);
        return TD_FAILURE;
    }

    /* step 2:  start to get streams of each channel. */
    FD_ZERO(&read_fds);
    FD_SET(venc_fd, &read_fds);

    timeout_val.tv_sec = 3; /* 3 is a number */
    timeout_val.tv_usec = 0;
    ret = select(maxfd + 1, &read_fds, TD_NULL, TD_NULL, &timeout_val);
    if (ret < 0) {
        sample_print_err("select failed!\n");
        return TD_FAILURE;
    } else if (ret == 0) {
        sample_print_err("get venc stream time out, exit thread\n");
        return TD_FAILURE;
    } else {
        if(FD_ISSET(venc_fd, &read_fds)) {            
            /* step 2.1 : query how many packs in one-frame stream. */
            if (memset_s(&stream, sizeof(stream), 0, sizeof(stream)) != EOK) {
                sample_print_err("call memset_s error\n");
            }

            ret = ss_mpi_venc_query_status(wk_stPara.venc_chn[VencChn], &stat);
            if (ret != TD_SUCCESS) {
                sample_print_err("ss_mpi_venc_query_status chn[%d] failed with %#x!\n", wk_stPara.venc_chn[VencChn], ret);
                return TD_FAILURE;
            }

            if (stat.cur_packs == 0) {
                sample_print_err("NOTE: current  frame is TD_NULL!\n");
                return TD_FAILURE;
            }
            /* step 2.3 : malloc corresponding number of pack nodes. */
            stream.pack = (ot_venc_pack *)malloc(sizeof(ot_venc_pack) * stat.cur_packs);
            if (stream.pack == TD_NULL) {
                sample_print_err("malloc stream pack failed!\n");
                return TD_FAILURE;
            }
            /* step 2.4 : call mpi to get one-frame stream */
            stream.pack_cnt = stat.cur_packs;
            ret = ss_mpi_venc_get_stream(wk_stPara.venc_chn[VencChn], &stream, TD_TRUE);
            if (ret != TD_SUCCESS) {
                free(stream.pack);
                stream.pack = TD_NULL;
                sample_print_err("ss_mpi_venc_get_stream failed with %#x!\n", ret);
                return TD_FAILURE;
            }

            /* step 2.5 : save frame to jpg file */
            FILE *fd = fopen(filepath, "wb");
            sample_comm_venc_save_stream(fd, &stream);
            fclose(fd);
            sample_print("jpg: %s.\n", filepath);

            /* step 2.6 : release stream */
            ret = ss_mpi_venc_release_stream(wk_stPara.venc_chn[VencChn], &stream);
            if (ret != TD_SUCCESS) {
                sample_print_err("ss_mpi_venc_release_stream failed!\n");
                free(stream.pack);
                stream.pack = TD_NULL;
                return TD_FAILURE;
            }

            //frame += 1;

            /* step 2.7 : free pack nodes */
            free(stream.pack);
            stream.pack = TD_NULL;
        }
    }

    return TD_SUCCESS;
}

td_void WK_COMM_VENC_SetDCFInfo(ot_vi_pipe ViPipe)
{
    ot_isp_dcf_info stIspDCF;
    td_s32 s32Ret;

    ss_mpi_isp_get_dcf_info(ViPipe, &stIspDCF);

    //description: Thumbnail test
    strncpy((char *)stIspDCF.isp_dcf_const_info.image_description,"WALKERA Mini SE Thumbnail",OT_DCF_DESCRIPTION_LENGTH);
    //manufacturer: WALKERA
    strncpy((char *)stIspDCF.isp_dcf_const_info.make,"WALKERA",OT_DCF_DESCRIPTION_LENGTH);
    //model number: Hisilicon IP Camera
    strncpy((char *)stIspDCF.isp_dcf_const_info.model,"WALKERA Mini SE",OT_DCF_DESCRIPTION_LENGTH);
    //firmware version: v.1.1.0
    strncpy((char *)stIspDCF.isp_dcf_const_info.software,"v.1.1.0",OT_DCF_DESCRIPTION_LENGTH);

    stIspDCF.isp_dcf_const_info.focal_length               = 0x01c10064;
    stIspDCF.isp_dcf_const_info.contrast                   = 5;
    stIspDCF.isp_dcf_const_info.custom_rendered            = 0;
    stIspDCF.isp_dcf_const_info.focal_length_in35mm_film   = 25;
    stIspDCF.isp_dcf_const_info.gain_control               = 1;
    stIspDCF.isp_dcf_const_info.light_source               = 1;
    stIspDCF.isp_dcf_const_info.metering_mode              = 1;
    stIspDCF.isp_dcf_const_info.saturation                 = 1;
    stIspDCF.isp_dcf_const_info.scene_capture_type         = 1;
    stIspDCF.isp_dcf_const_info.scene_type                 = 0;
    stIspDCF.isp_dcf_const_info.sharpness                  = 5;
    stIspDCF.isp_dcf_update_info.iso_speed_ratings         = 500;
    stIspDCF.isp_dcf_update_info.exposure_bias_value       = 5;
    stIspDCF.isp_dcf_update_info.exposure_time             = 0x00010004;
    stIspDCF.isp_dcf_update_info.f_number                  = 0x0001000a;
    stIspDCF.isp_dcf_update_info.white_balance             = 1;
    stIspDCF.isp_dcf_update_info.exposure_mode             = 0;
    stIspDCF.isp_dcf_update_info.exposure_program          = 1;
    stIspDCF.isp_dcf_update_info.max_aperture_value        = 0x00020001;

    s32Ret = ss_mpi_isp_set_dcf_info(ViPipe, &stIspDCF);

    if(s32Ret != TD_SUCCESS){
        sample_print_err("ss_mpi_isp_set_dcf_info err for %#x!\n", s32Ret);
       
    }else {
		sample_print_info("ss_mpi_isp_set_dcf_info  OK\n");;
	}

    return;
}

/******************************************************************************
* funciton : stop get venc stream process.
******************************************************************************/
td_void WK_COMM_VENC_PreviewStop(void)
{
    wk_stPara.thread_start = TD_FALSE;
    pthread_join(wk_VencPid, 0);

    sample_comm_venc_stop(WK_VIDEO_CHANNEL_PREVIEW);
}

td_s32 WK_COMM_VENC_StopCHN(void)
{
    if (TD_TRUE == wk_stPara.thread_start){
        wk_stPara.thread_start = TD_FALSE;
        pthread_join(wk_VencPid, 0);
    }

    sample_comm_venc_stop(WK_VIDEO_CHANNEL_RECORD);
    sample_comm_venc_stop(WK_VIDEO_CHANNEL_PREVIEW);

    WK_COMM_VENC_SnapStop(WK_VIDEO_CHANNEL_SNAP);
    WK_COMM_VENC_SnapStop(WK_VIDEO_CHANNEL_THUMBNAIL);

    return TD_SUCCESS;
}