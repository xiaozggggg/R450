/*
  Copyright (c), 2001-2022, Shenshu Tech. Co., Ltd.
 */

#ifndef GFBG_H
#define GFBG_H

#include <linux/fb.h>
#include "osal_ioctl.h"
#include "ot_type.h"
#include "ot_common.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#define IOC_TYPE_GFBG       'F'
/* To obtain the colorkey of an overlay layer */
#define FBIOGET_COLORKEY_GFBG       _IOR(IOC_TYPE_GFBG, 90, ot_fb_colorkey)
/* To set the colorkey of an overlay layer */
#define FBIOPUT_COLORKEY_GFBG       _IOW(IOC_TYPE_GFBG, 91, ot_fb_colorkey)
/* To get the alpha of an overlay layer */
#define FBIOGET_ALPHA_GFBG          _IOR(IOC_TYPE_GFBG, 92, ot_fb_alpha)
/* To set the alpha of an overlay layer */
#define FBIOPUT_ALPHA_GFBG          _IOW(IOC_TYPE_GFBG, 93, ot_fb_alpha)
/* To get the origin of an overlay layer on the screen */
#define FBIOGET_SCREEN_ORIGIN_GFBG  _IOR(IOC_TYPE_GFBG, 94, ot_fb_point)
/* To set the origin of an overlay layer on the screen */
#define FBIOPUT_SCREEN_ORIGIN_GFBG  _IOW(IOC_TYPE_GFBG, 95, ot_fb_point)
/* To wait for the vertical blanking region of an overlay layer */
#define FBIOGET_VER_BLANK_GFBG         _IO(IOC_TYPE_GFBG, 100)
/* To set the display state of an overlay layer */
#define FBIOPUT_SHOW_GFBG           _IOW(IOC_TYPE_GFBG, 101, td_bool)
/* To obtain the display state of an overlay layer */
#define FBIOGET_SHOW_GFBG           _IOR(IOC_TYPE_GFBG, 102, td_bool)
/* to obtain the capability of an overlay layer */
#define FBIOGET_CAPABILITY_GFBG    _IOR(IOC_TYPE_GFBG, 103, ot_fb_capability)
/* set the screen output size */
#define FBIOPUT_SCREEN_SIZE          _IOW(IOC_TYPE_GFBG, 130, ot_fb_size)
/* get the screen output size */
#define FBIOGET_SCREEN_SIZE          _IOR(IOC_TYPE_GFBG, 131, ot_fb_size)
/* To display multiple surfaces in turn and set the alpha and colorkey attributes */
#define FBIOFLIP_SURFACE            _IOW(IOC_TYPE_GFBG, 132, ot_fb_surfaceex)
/* To set the compression function status of an overlay layer */
#define FBIOPUT_COMPRESSION_GFBG    _IOW(IOC_TYPE_GFBG, 133, td_bool)
/* To obtain the compression function status of an overlay layer */
#define FBIOGET_COMPRESSION_GFBG    _IOR(IOC_TYPE_GFBG, 134, td_bool)
/* To create the layer */
#define FBIO_CREATE_LAYER           _IO(IOC_TYPE_GFBG, 149)
/* To destroy the layer */
#define FBIO_DESTROY_LAYER          _IO(IOC_TYPE_GFBG, 150)
/* To set the layer information */
#define FBIOPUT_LAYER_INFO                _IOW(IOC_TYPE_GFBG, 120, ot_fb_layer_info)
/* To get the layer information */
#define FBIOGET_LAYER_INFO                _IOR(IOC_TYPE_GFBG, 121, ot_fb_layer_info)
/* To get canvas buf */
#define FBIOGET_CANVAS_BUF             _IOR(IOC_TYPE_GFBG, 123, ot_fb_buf)
/* To refresh the displayed contents in extended mode */
#define FBIO_REFRESH                      _IOW(IOC_TYPE_GFBG, 124, ot_fb_buf)
/* sync refresh */
#define FBIO_WAITFOR_FREFRESH_DONE        _IO(IOC_TYPE_GFBG, 125)
/* To set the mirror mode */
#define FBIOPUT_MIRROR_MODE            _IOW(IOC_TYPE_GFBG, 126, ot_fb_mirror_mode)
/* To get the mirror mode */
#define FBIOGET_MIRROR_MODE            _IOW(IOC_TYPE_GFBG, 127, ot_fb_mirror_mode)
/* To set the rotate mode */
#define FBIOPUT_ROTATE_MODE            _IOW(IOC_TYPE_GFBG, 128, ot_fb_rotate_mode)
/* To get the rotate mode */
#define FBIOGET_ROTATE_MODE            _IOW(IOC_TYPE_GFBG, 129, ot_fb_rotate_mode)
/* To draw smart rect */
#define FBIO_DRAW_SMART_RECT    _IOW(IOC_TYPE_GFBG, 151, ot_fb_smart_rect_param)
/* To set graphic layer csc */
#define FBIOPUT_GRAPHIC_LAYER_CSC_GFBG    _IOW(IOC_TYPE_GFBG, 152, ot_fb_layer_csc)
/* To get graphic layer csc */
#define FBIOGET_GRAPHIC_LAYER_CSC_GFBG    _IOW(IOC_TYPE_GFBG, 153, ot_fb_layer_csc)


typedef struct {
    td_u32  width;
    td_u32  height;
} ot_fb_size;

typedef struct {
    td_bool enable;         /* colorkey enable flag */
    td_u32 value;           /* colorkey value, maybe contains alpha */
} ot_fb_colorkey;

typedef struct {
    td_s32 x;
    td_s32 y;
    td_s32 width;
    td_s32 height;
} ot_fb_rect;

typedef struct {
    td_s32 x_pos;         /* <  horizontal position */
    td_s32 y_pos;         /* <  vertical position */
} ot_fb_point;

/* Alpha info */
typedef struct {
    td_bool pixel_alpha;   /*  pixel alpha enable flag */
    td_bool global_alpha_en;  /*  global alpha enable flag */
    td_u8 alpha0;         /*  alpha0 value, used in ARGB1555 */
    td_u8 alpha1;         /*  alpha1 value, used in ARGB1555 */
    td_u8 global_alpha;    /*  global alpha value */
} ot_fb_alpha;

typedef enum {
    OT_FB_FORMAT_RGB565 = 0,
    OT_FB_FORMAT_RGB888,              /*  RGB888 24bpp */

    OT_FB_FORMAT_KRGB444,       /*  RGB444 16bpp */
    OT_FB_FORMAT_KRGB555,       /*  RGB555 16bpp */
    OT_FB_FORMAT_KRGB888,       /*  RGB888 32bpp */

    OT_FB_FORMAT_ARGB4444,      /* ARGB4444 */
    OT_FB_FORMAT_ARGB1555,      /* ARGB1555 */
    OT_FB_FORMAT_ARGB8888,      /* ARGB8888 */
    OT_FB_FORMAT_ARGB8565,      /* ARGB8565 */

    OT_FB_FORMAT_RGBA4444,      /* ARGB4444 */
    OT_FB_FORMAT_RGBA5551,      /* RGBA5551 */
    OT_FB_FORMAT_RGBA5658,      /* RGBA5658 */
    OT_FB_FORMAT_RGBA8888,      /* RGBA8888 */

    OT_FB_FORMAT_BGR565,        /* BGR565 */
    OT_FB_FORMAT_BGR888,        /* BGR888 */
    OT_FB_FORMAT_ABGR4444,      /* ABGR4444 */
    OT_FB_FORMAT_ABGR1555,      /* ABGR1555 */
    OT_FB_FORMAT_ABGR8888,      /* ABGR8888 */
    OT_FB_FORMAT_ABGR8565,      /* ABGR8565 */
    OT_FB_FORMAT_KBGR444,       /* BGR444 16bpp */
    OT_FB_FORMAT_KBGR555,       /* BGR555 16bpp */
    OT_FB_FORMAT_KBGR888,       /* BGR888 32bpp */

    OT_FB_FORMAT_1BPP,          /* clut1 */
    OT_FB_FORMAT_2BPP,          /* clut2 */
    OT_FB_FORMAT_4BPP,          /* clut4 */
    OT_FB_FORMAT_8BPP,          /* clut8 */
    OT_FB_FORMAT_ACLUT44,       /* AClUT44 */
    OT_FB_FORMAT_ACLUT88,         /* ACLUT88 */
    OT_FB_FORMAT_PUYVY,         /* UYVY */
    OT_FB_FORMAT_PYUYV,         /* YUYV */
    OT_FB_FORMAT_PYVYU,         /* YVYU */
    OT_FB_FORMAT_YUV888,        /* YUV888 */
    OT_FB_FORMAT_AYUV8888,      /* AYUV8888 */
    OT_FB_FORMAT_YUVA8888,      /* YUVA8888 */
    OT_FB_FORMAT_BUTT
} ot_fb_color_format;

typedef struct {
    td_bool is_key_rgb;
    td_bool is_key_alpha;      /* whether support colorkey alpha */
    td_bool is_global_alpha;   /* whether support global alpha */
    td_bool is_cmap;          /* whether support color map */
    td_bool has_cmap_reg;    /* whether has color map register */
    td_bool is_color_format[OT_FB_FORMAT_BUTT]; /* support which color format */
    td_bool is_vo_scale;       /* support vo scale */
    /* whether support a certain layer */
    td_bool is_layer_support;
    td_u32  max_width;    /* the max pixels per line */
    td_u32  max_height;   /* the max lines */
    td_u32  min_width;    /* the min pixels per line */
    td_u32  min_height;   /* the min lines */
    td_u32  ver_deflicker_level;   /* vertical deflicker level, 0 means vertical deflicker is unsupporteded. */
    td_u32  hor_deflicker_level;   /* horizontal deflicker level, 0 means horizontal deflicker is unsupporteded. */
    td_bool  is_decompress;
    td_bool  is_premul;
    td_bool  is_ghdr;         /* new feature. is ghdr supported. */
    td_bool  is_osb;   /* new feature. is smart rect supported */
} ot_fb_capability;

/* refresh mode */
typedef enum {
    OT_FB_LAYER_BUF_DOUBLE = 0x0,       /* 2 display buf in fb */
    OT_FB_LAYER_BUF_ONE    = 0x1,       /* 1 display buf in fb */
    OT_FB_LAYER_BUF_NONE   = 0x2, /* no display buf in fb,the buf user refreshed will be directly set to VO */
    OT_FB_LAYER_BUF_DOUBLE_IMMEDIATE = 0x3, /* 2 display buf in fb, each refresh will be displayed */
    OT_FB_LAYER_BUF_BUTT
} ot_fb_layer_buf;

/* surface info */
typedef struct {
    td_phys_addr_t  phys_addr;     /* start physical address */
    td_u32  width;       /* width pixels */
    td_u32  height;      /* height pixels */
    td_u32  pitch;       /* line pixels */
    ot_fb_color_format format; /* color format */
} ot_fb_surface;

typedef struct {
    td_phys_addr_t phys_addr;
    ot_fb_alpha alpha;
    ot_fb_colorkey colorkey;
} ot_fb_surfaceex;

/* refresh surface info */
typedef struct {
    ot_fb_surface canvas;
    ot_fb_rect update_rect;       /* refresh region */
} ot_fb_buf;

/* cursor info */
typedef struct {
    ot_fb_surface cursor;
    ot_fb_point hot_pos;
} ot_fb_cursor;

/* antiflicker level */
/* Auto means fb will choose a appropriate antiflicker level automatically according to the color info of map */
typedef enum {
    OT_FB_LAYER_ANTIFLICKER_NONE = 0x0,  /* no antiflicker */
    OT_FB_LAYER_ANTIFLICKER_LOW = 0x1,   /* low level */
    OT_FB_LAYER_ANTIFLICKER_MID = 0x2, /* middle level */
    OT_FB_LAYER_ANTIFLICKER_HIGH = 0x3, /* high level */
    OT_FB_LAYER_ANTIFLICKER_AUTO = 0x4, /* auto */
    OT_FB_LAYER_ANTIFLICKER_BUTT
} ot_fb_layer_antiflicker_level;

/* mirror mode  */
typedef enum {
    OT_FB_MIRROR_NONE = 0x0,
    OT_FB_MIRROR_HOR = 0x1,
    OT_FB_MIRROR_VER = 0x2,
    OT_FB_MIRROR_BOTH = 0x3,
    OT_FB_MIRROR_BUTT
} ot_fb_mirror_mode;

/* rotate mode */
typedef enum {
    OT_FB_ROTATE_NONE = 0x0,
    OT_FB_ROTATE_90 = 0x1,
    OT_FB_ROTATE_180 = 0x2,
    OT_FB_ROTATE_270 = 0x3,
    OT_FB_ROTATE_BUTT
} ot_fb_rotate_mode;

/* layer info maskbit */
typedef enum {
    OT_FB_LAYER_MASK_BUF_MODE = 0x1,           /* buf mode bitmask */
    OT_FB_LAYER_MASK_ANTIFLICKER_MODE = 0x2,  /* antiflicker mode bitmask */
    OT_FB_LAYER_MASK_POS = 0x4,               /* the position bitmask */
    OT_FB_LAYER_MASK_CANVAS_SIZE = 0x8,      /* canvassize bitmask */
    OT_FB_LAYER_MASK_DISPLAY_SIZE = 0x10,       /* displaysize bitmask */
    OT_FB_LAYER_MASK_SCREEN_SIZE = 0x20,     /* screensize bitmask */
    OT_FB_LAYER_MASK_MUL = 0x40,           /* pre-mult bitmask */
    OT_FB_LAYER_MASK_BUTT
} ot_fb_layer_info_maskbit;

/* layer info */
typedef struct {
    ot_fb_layer_buf buf_mode;
    ot_fb_layer_antiflicker_level antiflicker_level;
    td_s32 x_pos;           /*  the x pos of origin point in screen */
    td_s32 y_pos;           /*  the y pos of origin point in screen */
    td_u32 canvas_width;    /*  the width of canvas buffer */
    td_u32 canvas_height;   /*  the height of canvas buffer */
    /* the width of display buf in fb.for 0 buf, there is no display buf in fb, so it's effectless */
    td_u32 display_width;
    td_u32 display_height;  /*  the height of display buf in fb. */
    td_u32 screen_width;    /*  the width of screen */
    td_u32 screen_height;   /*  the height of screen */
    td_bool is_premul;      /*  The data drawn in buf is premul data or not */
    td_u32 mask;           /*  param modify mask bit */
} ot_fb_layer_info;

/* smart rect mode  */
typedef enum {
    OT_FB_SMART_RECT_NONE = 0x0, /* disable smart rect */
    OT_FB_SMART_RECT_SOLID = 0x1,
    OT_FB_SMART_RECT_FILLED = 0x2,
    OT_FB_SMART_RECT_CORNER = 0x3,
    OT_FB_SMART_RECT_BUTT
} ot_fb_smart_rect_mode;

/* smart rect */
typedef struct {
    ot_fb_smart_rect_mode mode;
    ot_fb_rect rect;
    td_u32 corner_length; /* max 255 only use for OT_FB_SMART_RECT_CORNER mode */
    td_u32 thick; /* max 32 */
    td_u32 color_value;
} ot_fb_smart_rect;

typedef struct {
    td_u32 num; /* max 128 */
    ot_fb_smart_rect *rect_start;
} ot_fb_smart_rect_param;

typedef enum {
    OT_FB_CSC_MATRIX_BT601LIMIT_TO_BT601LIMIT = 0, /* BT601LIMIT to BT601LIMIT */
    OT_FB_CSC_MATRIX_BT601FULL_TO_BT601LIMIT,  /* BT601FULL to BT601LIMIT */
    OT_FB_CSC_MATRIX_BT709LIMIT_TO_BT601LIMIT, /* BT709LIMIT to BT601LIMIT */
    OT_FB_CSC_MATRIX_BT709FULL_TO_BT601LIMIT,  /* BT709FULL to BT601LIMIT */

    OT_FB_CSC_MATRIX_BT601LIMIT_TO_BT709LIMIT, /* BT601LIMIT to BT709LIMIT */
    OT_FB_CSC_MATRIX_BT601FULL_TO_BT709LIMIT,  /* BT601FULL to BT709LIMIT */
    OT_FB_CSC_MATRIX_BT709LIMIT_TO_BT709LIMIT, /* BT709LIMIT to BT709LIMIT */
    OT_FB_CSC_MATRIX_BT709FULL_TO_BT709LIMIT,  /* BT709FULL to BT709LIMIT */

    OT_FB_CSC_MATRIX_BT601LIMIT_TO_BT601FULL,  /* BT601LIMIT to BT601FULL */
    OT_FB_CSC_MATRIX_BT601FULL_TO_BT601FULL,   /* BT601FULL to BT601FULL */
    OT_FB_CSC_MATRIX_BT709LIMIT_TO_BT601FULL,  /* BT709LIMIT to BT601FULL */
    OT_FB_CSC_MATRIX_BT709FULL_TO_BT601FULL,   /* BT709FULL to BT601FULL */

    OT_FB_CSC_MATRIX_BT601LIMIT_TO_BT709FULL,  /* BT601LIMIT to BT709FULL */
    OT_FB_CSC_MATRIX_BT601FULL_TO_BT709FULL,   /* BT601FULL to BT709FULL */
    OT_FB_CSC_MATRIX_BT709LIMIT_TO_BT709FULL,  /* BT709LIMIT to BT709FULL */
    OT_FB_CSC_MATRIX_BT709FULL_TO_BT709FULL,   /* BT709FULL to BT709FULL */

    OT_FB_CSC_MATRIX_BT601LIMIT_TO_RGBFULL,   /* BT601LIMIT to RGBFULL */
    OT_FB_CSC_MATRIX_BT601FULL_TO_RGBFULL,    /* BT601FULL to RGBFULL */
    OT_FB_CSC_MATRIX_BT709LIMIT_TO_RGBFULL,   /* BT709LIMIT to RGBFULL */
    OT_FB_CSC_MATRIX_BT709FULL_TO_RGBFULL,    /* BT709FULL to RGBFULL */

    OT_FB_CSC_MATRIX_BT601LIMIT_TO_RGBLIMIT,  /* BT601LIMIT to RGBLIMIT */
    OT_FB_CSC_MATRIX_BT601FULL_TO_RGBLIMIT,   /* BT601FULL to RGBLIMIT */
    OT_FB_CSC_MATRIX_BT709LIMIT_TO_RGBLIMIT,  /* BT709LIMIT to RGBLIMIT */
    OT_FB_CSC_MATRIX_BT709FULL_TO_RGBLIMIT,   /* BT709FULL to RGBLIMIT */

    OT_FB_CSC_MATRIX_RGBFULL_TO_BT601LIMIT,    /* RGBFULL to BT601LIMIT */
    OT_FB_CSC_MATRIX_RGBFULL_TO_BT601FULL,     /* RGBFULL to BT601FULL */
    OT_FB_CSC_MATRIX_RGBFULL_TO_BT709LIMIT,    /* RGBFULL to BT709LIMIT */
    OT_FB_CSC_MATRIX_RGBFULL_TO_BT709FULL,     /* RGBFULL to BT709FULL */

    OT_FB_CSC_MATRIX_BUTT
} ot_fb_layer_csc_matrix;

typedef struct {
    ot_fb_layer_csc_matrix csc_matrix; /* CSC matrix */
    td_u32 luma; /* RW Range:    [0, 100] luminance, default: 50 */
    td_u32 contrast; /* RW Range:    [0, 100] contrast, default: 50 */
    td_u32 hue; /* RW Range:    [0, 100] hue, default: 50 */
    td_u32 saturation; /* RW Range:    [0, 100] saturation, default: 50 */
    td_bool ex_csc_en; /* RW; range: [0, 1]; extended csc switch for luminance, default: 0 */
} ot_fb_layer_csc;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* GFBG_H */

