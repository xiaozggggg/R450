#ifndef _VIDEI_LIST_H_
#define _VIDEI_LIST_H_

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>


#define LINK_LIST_LENGTH	8
#define SIZE_OF_FRAME 		(500*1024) 
#define MAX_IDR_FRAME_SIZE  (3*1024*1024)
// #define MAX_IDR_FRAME_SIZE  (5*1024*1024)

#define VIDEO_FULL_VALUE_THRESHOLD ((1<<18))//buf leave 1/4

#define STACK_MEMORY_CH1	0
#define STACK_MEMORY_CH2	0
#define STACK_MEMORY_CH3    0


#define ENABLE_QUEUE_CH1	0
#define ENABLE_QUEUE_CH2	1
#define ENABLE_QUEUE_CH3    0

typedef enum{
    WK_FRAME_START = 0 ,       // 数据帧的开始标志
    WK_FRAME_CENTER ,          // 数据帧的中间标志
    WK_FRAME_END,              // 数据帧的结束标志
    WK_FRAME_APPEND,
} WK_FRAME_FLAG_E;


struct NodeContentDef
{
    int             seqNUm;
    int             length;                 // 帧长度
    int             timeStamp;
    unsigned char   buf[SIZE_OF_FRAME];     // 存储图像帧数据
    int             appendPtr;              // 偏移量
};

struct Node
{
    struct 	NodeContentDef 	nodeContent;
    bool                    frameError;
    struct	Node            *next;
};


int     VideoList_Init1(void);
int     VideoList_AppendWriteNode1(unsigned char *pBuf, int length ,WK_FRAME_FLAG_E FrameFlag);
int     VideoList_ReadOneFrame1(unsigned char *pBuf, int *pLen);
void    VideoLink_Reset1(void);

int     VideoList_Init2(void);
int     VideoList_AppendWriteNode2(unsigned char *pBuf, int length ,WK_FRAME_FLAG_E FrameFlag);
int     VideoList_ReadOneFrame2(unsigned char *pBuf, int *pLen);
void    VideoLink_Reset2(void);


int     VideoList_Init3(void);
int     VideoList_AppendWriteNode3(unsigned char *pBuf, int length ,WK_FRAME_FLAG_E FrameFlag);
int     VideoList_ReadOneFrame3(unsigned char *pBuf, int *pLen);
void    VideoLink_Reset3(void);

struct buf_medunit{
	char* p;
	int size;
	char frmaetype;
	unsigned long long pts;
	struct buf_medunit* next;
};

struct mem_medqueue_unit{
	struct buf_medunit lists[400];
  	struct buf_medunit *pwrite;
  	struct buf_medunit *pread;
 	char* pMemBegin, *pMemEnd, *pMemFree;
};

void OnVideoListInit(void);
int  OnAddVideoDataToList(unsigned char *pViBuf,int nSize);
int  OnReadVideoData(unsigned char *pBuf,int nSize,char &frametype);
void OnVideoListReset(void);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif
