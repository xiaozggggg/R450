#ifndef __WRITE_EXIF_H__
#define __WRITE_EXIF_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include "exif-data.h"
#include "ot_common_isp.h"
#include "ss_mpi_sys.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif /* __cplusplus */

/* start of JPEG image data section */
#define IMAGE_DATA_OFFSET 20

/* raw EXIF header data */
static const unsigned char exif_header[] = {
  0xff, 0xd8, 0xff, 0xe1
};
/* length of data in exif_header */
static const unsigned int exif_header_len = sizeof(exif_header);

/* byte order to use in the EXIF block */
#define FILE_BYTE_ORDER EXIF_BYTE_ORDER_INTEL

/* comment to write into the EXIF block */
#define FILE_COMMENT "libexif test"

/* special header required for EXIF_TAG_USER_COMMENT */
#define ASCII_COMMENT "ASCII\0\0\0"

int wk_write_exif(ot_gps_info *gps_info, ot_isp_exp_info *exp_info, FILE *pfd);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif