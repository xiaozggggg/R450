#include "VideoList.h"
#include "wk_log.h"

extern void write_frame_to_file(unsigned char *videobuf, int nsize);

#if ENABLE_QUEUE_CH1
	// video channel1
	static struct Node* nodeWdPtr1;          // 用于写
	static struct Node* nodeHDMIPtr1;        // 用于读
	static pthread_rwlock_t rwlock1;
	static pthread_rwlockattr_t attr1;
	//struct Node videoLink1[LINK_LIST_LENGTH]; 

#if STACK_MEMORY_CH1
		struct Node videoLink1[LINK_LIST_LENGTH];
#else
		struct Node *videoLink1[LINK_LIST_LENGTH] = {0};
#endif 
#endif 

#if ENABLE_QUEUE_CH2
	// video channel2
	static struct Node* nodeWdPtr2;          // 用于写
	static struct Node* nodeHDMIPtr2;        // 用于读
	static pthread_rwlock_t rwlock2;
	static pthread_rwlockattr_t attr2;

	#if STACK_MEMORY_CH2
		struct Node videoLink2[LINK_LIST_LENGTH];
	#else  
		struct Node *videoLink2[LINK_LIST_LENGTH] = {0};
	#endif 

#endif

#if ENABLE_QUEUE_CH3
	// video channel3
	static struct Node* nodeWdPtr3;          // 用于写
	static struct Node* nodeHDMIPtr3;        // 用于读
	static pthread_rwlock_t rwlock3;
	static pthread_rwlockattr_t attr3;

	#if STACK_MEMORY_CH3
		struct Node videoLink3[LINK_LIST_LENGTH]; 
	#else 
		struct Node *videoLink3[LINK_LIST_LENGTH] = {0}; 
	#endif 

#endif 

#if ENABLE_QUEUE_CH1
////////////////////////////////////////////////// video channel1 //////////////////////////////////////////////////
/*
 * 功  能： 初始化 VideoList
 * 参  数： 无
 * 返回值：
 *      成功      ---》0
 *      失败      ---》-1
 */
int VideoList_Init1(void)
{
	int i;
	struct Node *head , *next;

#if STACK_MEMORY_CH1
	head = &videoLink1[0];
	head->next = head;

    // 形成 单向循环链
	for(i = 1; i < LINK_LIST_LENGTH; i++)
	{
		next = &videoLink1[i];
		next->next = head->next;
		head->next = next;
	}
#else 
	videoLink1[0] = (struct Node *)malloc(sizeof(struct Node));
	if(videoLink1[0]){
		head = videoLink1[0];
		head->next = head;
	}else{
		return -1;
	}

	for(i = 1; i < LINK_LIST_LENGTH; i++)
	{
		videoLink1[i] = (struct Node *)malloc(sizeof(struct Node));
		if(videoLink1[i]){
			next = videoLink1[i];
			next->next = head->next;
			head->next = next;
		}else{
			for(i=i-1 ;i >= 0; i--){  
				free(videoLink1[i]);
				videoLink1[i] = NULL;
			}
			return -1;
		}
	}
#endif 

    nodeWdPtr1 = head;
	nodeHDMIPtr1 = head;

	if(pthread_rwlockattr_init(&attr1) != 0)
		return -1;

    if(pthread_rwlockattr_setkind_np (&attr1, PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP) != 0)
    	return -1;

    if(pthread_rwlock_init(&rwlock1, &attr1) != 0)
    	return -1;

    WK_LOGD("%s successful\n" ,__FUNCTION__);

	return 0;
}

/*
 * 功  能： 读取一帧数据
 * 参  数：
 *      pBuf    ---》保存读取一帧数据的缓冲区首地址
 *      pLen    ---》保存读取一帧数据的长度的地址
 * 返回值：
 *      成功      ---》0
 *      失败      ---》-1
 */
int VideoList_ReadOneFrame1(unsigned char *pBuf, int *pLen)
{
    // Param Check
    if( (!pBuf) || (!pLen) ){
        WK_LOGE("Input Param Error!\n");
        return -1;
    }

	int err = 0;

	if(pthread_rwlock_tryrdlock(&rwlock1) != 0)
	{
		return -1;
	}

	if(nodeHDMIPtr1 != nodeWdPtr1)
	{
		memcpy(pBuf, nodeHDMIPtr1->nodeContent.buf, nodeHDMIPtr1->nodeContent.length);
		memcpy(pLen, &nodeHDMIPtr1->nodeContent.length, sizeof(int));

		nodeHDMIPtr1 = nodeHDMIPtr1->next;
	}else{
		err = -1;
	}	

	pthread_rwlock_unlock(&rwlock1);

	return err;
}


/*
 * 功  能： 追加写入（一帧数据有可能是分开多次传输，那么需要组帧）
 * 参  数：
 *      pBuf        ---》写入数据缓冲区首地址
 *      length      ---》写入数据的长度
 *      FrameFlag   ---》数据帧标志
 *                      FRAME_START         写入一帧数据的开始部分
 *                      FRAME_CENTER        写入一帧数据的中间部分
 *                      FRAME_END           写入一帧数据的结束部分
 * 返回值：
 *      成功          ---》0
 *      失败          ---》-1
 */
int VideoList_AppendWriteNode1(unsigned char *pBuf, int length ,WK_FRAME_FLAG_E FrameFlag)
{
    // Param Check
    if( (!pBuf) || (length<=0) || (FrameFlag<0) ){
        WK_LOGE("Input Param Error!\n");
        return -1;
    }

	pthread_rwlock_wrlock(&rwlock1);

    if( (FrameFlag==WK_FRAME_START) || (FrameFlag == WK_FRAME_CENTER)  || (FrameFlag==WK_FRAME_APPEND) ){
        // 写入数据
        nodeWdPtr1->nodeContent.length += length;
        memcpy(nodeWdPtr1->nodeContent.buf + nodeWdPtr1->nodeContent.appendPtr, pBuf, length);
        nodeWdPtr1->nodeContent.appendPtr += length;

    }else if(FrameFlag == WK_FRAME_END){
        // 写入最后一点数据
        nodeWdPtr1->nodeContent.length += length;
        memcpy(nodeWdPtr1->nodeContent.buf + nodeWdPtr1->nodeContent.appendPtr, pBuf, length);
        nodeWdPtr1->nodeContent.appendPtr += length;

        // 指向下一个节点，并且将其清零
		nodeWdPtr1 = nodeWdPtr1->next;
		memset(nodeWdPtr1->nodeContent.buf, 0, nodeWdPtr1->nodeContent.length);
		nodeWdPtr1->nodeContent.length = 0;
		nodeWdPtr1->nodeContent.appendPtr = 0;
		nodeWdPtr1->frameError = false;
	}

	pthread_rwlock_unlock(&rwlock1);

	return 0;
}

void VideoLink_Reset1(void)
{
	pthread_rwlock_wrlock(&rwlock1);

#if STACK_MEMORY_CH1
    nodeWdPtr1 = nodeHDMIPtr1 = &videoLink1[0];
#else 
	nodeWdPtr1 = nodeHDMIPtr1 = videoLink1[0];
#endif 

	memset(nodeWdPtr1->nodeContent.buf, 0, nodeWdPtr1->nodeContent.length);
	nodeWdPtr1->nodeContent.length = 0;
	nodeWdPtr1->nodeContent.appendPtr = 0;
	nodeWdPtr1->frameError = false;

	pthread_rwlock_unlock(&rwlock1);
}

#endif 

#if ENABLE_QUEUE_CH2
////////////////////////////////////////////////// video channel2 //////////////////////////////////////////////////
/*
 * 功  能： 初始化 VideoList
 * 参  数： 无
 * 返回值：
 *      成功      ---》0
 *      失败      ---》-1
 */
int VideoList_Init2(void)
{
	int i;
	struct Node *head , *next;

#if STACK_MEMORY_CH2
	 head = &videoLink2[0];
	 head->next = head;

    // 形成 单向循环链
	for(i = 1; i < LINK_LIST_LENGTH; i++)
	{
		next = &videoLink2[i];
		next->next = head->next;
		head->next = next;
	}
#else 
	videoLink2[0] = (struct Node *)malloc(sizeof(struct Node));
	if(videoLink2[0]){
		head = videoLink2[0];
		head->next = head;
	}else{
		return -1;
	}

	for(i = 1; i < LINK_LIST_LENGTH; i++)
	{
		videoLink2[i] = (struct Node *)malloc(sizeof(struct Node));
		if(videoLink2[i]){
			next = videoLink2[i];
			next->next = head->next;
			head->next = next;
		}else{
			for(i=i-1 ;i >= 0; i--){  
				free(videoLink2[i]);
				videoLink2[i] = NULL;
			}
			return -1;
		}
	}
#endif 

    nodeWdPtr2 = head;
	nodeHDMIPtr2 = head;

	if(pthread_rwlockattr_init(&attr2) != 0)
		return -1;

    if(pthread_rwlockattr_setkind_np (&attr2, PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP) != 0)
    	return -1;

    if(pthread_rwlock_init(&rwlock2, &attr2) != 0)
    	return -1;

    WK_LOGD("%s successful\n" ,__FUNCTION__);

	return 0;
}

/*
 * 功  能： 读取一帧数据
 * 参  数：
 *      pBuf    ---》保存读取一帧数据的缓冲区首地址
 *      pLen    ---》保存读取一帧数据的长度的地址
 * 返回值：
 *      成功      ---》0
 *      失败      ---》-1
 */
int VideoList_ReadOneFrame2(unsigned char *pBuf, int *pLen)
{
    // Param Check
    if( (!pBuf) || (!pLen) ){
        WK_LOGE("Input Param Error!\n");
        return -1;
    }

	int err = 0;

	if(pthread_rwlock_tryrdlock(&rwlock2) != 0)
	{
		return -1;
	}

	if(nodeHDMIPtr2 != nodeWdPtr2)
	{
		memcpy(pBuf, nodeHDMIPtr2->nodeContent.buf, nodeHDMIPtr2->nodeContent.length);
		memcpy(pLen, &nodeHDMIPtr2->nodeContent.length, sizeof(int));

		nodeHDMIPtr2 = nodeHDMIPtr2->next;
	}else{
		err = -1;
	}	

	pthread_rwlock_unlock(&rwlock2);

	return err;
}


/*
 * 功  能： 追加写入（一帧数据有可能是分开多次传输，那么需要组帧）
 * 参  数：
 *      pBuf        ---》写入数据缓冲区首地址
 *      length      ---》写入数据的长度
 *      FrameFlag   ---》数据帧标志
 *                      FRAME_START         写入一帧数据的开始部分
 *                      FRAME_CENTER        写入一帧数据的中间部分
 *                      FRAME_END           写入一帧数据的结束部分
 * 返回值：
 *      成功          ---》0
 *      失败          ---》-1
 */
int VideoList_AppendWriteNode2(unsigned char *pBuf, int length ,WK_FRAME_FLAG_E FrameFlag)
{
    // Param Check
    if( (!pBuf) || (length<=0) || (FrameFlag<0) ){
        WK_LOGE("Input Param Error!\n");
        return -1;
    }

	pthread_rwlock_wrlock(&rwlock2);

    if( (FrameFlag==WK_FRAME_START) || (FrameFlag == WK_FRAME_CENTER) || (FrameFlag==WK_FRAME_APPEND) ){
        // 写入数据
        nodeWdPtr2->nodeContent.length += length;
        memcpy(nodeWdPtr2->nodeContent.buf + nodeWdPtr2->nodeContent.appendPtr, pBuf, length);
        nodeWdPtr2->nodeContent.appendPtr += length;

    }else if(FrameFlag == WK_FRAME_END){
        // 写入最后一点数据
        nodeWdPtr2->nodeContent.length += length;
        memcpy(nodeWdPtr2->nodeContent.buf + nodeWdPtr2->nodeContent.appendPtr, pBuf, length);
        nodeWdPtr2->nodeContent.appendPtr += length;

        // 指向下一个节点，并且将其清零
		nodeWdPtr2 = nodeWdPtr2->next;
		memset(nodeWdPtr2->nodeContent.buf, 0, nodeWdPtr2->nodeContent.length);
		nodeWdPtr2->nodeContent.length = 0;
		nodeWdPtr2->nodeContent.appendPtr = 0;
		nodeWdPtr2->frameError = false;
	}

	pthread_rwlock_unlock(&rwlock2);

	return 0;
}

void VideoLink_Reset2(void)
{
	pthread_rwlock_wrlock(&rwlock2);

#if STACK_MEMORY_CH2
    nodeWdPtr2 = nodeHDMIPtr2 = &videoLink2[0];
#else 
	nodeWdPtr2 = nodeHDMIPtr2 = videoLink2[0];
#endif 
	memset(nodeWdPtr2->nodeContent.buf, 0, nodeWdPtr2->nodeContent.length);
	nodeWdPtr2->nodeContent.length = 0;
	nodeWdPtr2->nodeContent.appendPtr = 0;
	nodeWdPtr2->frameError = false;

	pthread_rwlock_unlock(&rwlock2);
}

#endif 

#if ENABLE_QUEUE_CH3

////////////////////////////////////////////////// video channel2 //////////////////////////////////////////////////
/*
 * 功  能： 初始化 VideoList
 * 参  数： 无
 * 返回值：
 *      成功      ---》0
 *      失败      ---》-1
 */
int VideoList_Init3(void)
{
	int i;
	struct Node *head , *next;

#if STACK_MEMORY_CH3
	head = &videoLink3[0];
	head->next = head;

    // 形成 单向循环链
	for(i = 1; i < LINK_LIST_LENGTH; i++)
	{
		next = &videoLink3[i];
		next->next = head->next;
		head->next = next;
	}

#else 
	videoLink3[0] = (struct Node *)malloc(sizeof(struct Node));
	if(videoLink3[0]){
		head = videoLink3[0];
		head->next = head;
	}else{
		return -1;
	}

	for(i = 1; i < LINK_LIST_LENGTH; i++)
	{
		videoLink3[i] = (struct Node *)malloc(sizeof(struct Node));
		if(videoLink3[i]){
			next = videoLink3[i];
			next->next = head->next;
			head->next = next;
		}else{
			for(i=i-1 ;i >= 0; i--){  
				free(videoLink3[i]);
				videoLink3[i] = NULL;
			}
			return -1;
		}
	}
#endif 

    nodeWdPtr3 = head;
	nodeHDMIPtr3 = head;

	if(pthread_rwlockattr_init(&attr3) != 0)
		return -1;

    if(pthread_rwlockattr_setkind_np (&attr3, PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP) != 0)
    	return -1;

    if(pthread_rwlock_init(&rwlock3, &attr3) != 0)
    	return -1;

    WK_LOGD("%s successful\n" ,__FUNCTION__);

	return 0;
}

/*
 * 功  能： 读取一帧数据
 * 参  数：
 *      pBuf    ---》保存读取一帧数据的缓冲区首地址
 *      pLen    ---》保存读取一帧数据的长度的地址
 * 返回值：
 *      成功      ---》0
 *      失败      ---》-1
 */
int VideoList_ReadOneFrame3(unsigned char *pBuf, int *pLen)
{
    // Param Check
    if( (!pBuf) || (!pLen) ){
        WK_LOGE("Input Param Error!\n");
        return -1;
    }

	int err = 0;

	if(pthread_rwlock_tryrdlock(&rwlock3) != 0)
	{
		return -1;
	}

	if(nodeHDMIPtr3 != nodeWdPtr3)
	{
		memcpy(pBuf, nodeHDMIPtr3->nodeContent.buf, nodeHDMIPtr3->nodeContent.length);
		memcpy(pLen, &nodeHDMIPtr3->nodeContent.length, sizeof(int));

		nodeHDMIPtr3 = nodeHDMIPtr3->next;
	}else{
		err = -1;
	}	

	pthread_rwlock_unlock(&rwlock3);

	return err;
}


/*
 * 功  能： 追加写入（一帧数据有可能是分开多次传输，那么需要组帧）
 * 参  数：
 *      pBuf        ---》写入数据缓冲区首地址
 *      length      ---》写入数据的长度
 *      FrameFlag   ---》数据帧标志
 *                      FRAME_START         写入一帧数据的开始部分
 *                      FRAME_CENTER        写入一帧数据的中间部分
 *                      FRAME_END           写入一帧数据的结束部分
 * 返回值：
 *      成功          ---》0
 *      失败          ---》-1
 */
int VideoList_AppendWriteNode3(unsigned char *pBuf, int length ,WK_FRAME_FLAG_E FrameFlag)
{
    // Param Check
    if( (!pBuf) || (length<=0) || (FrameFlag<0) ){
        WK_LOGE("Input Param Error!\n");
        return -1;
    }

	pthread_rwlock_wrlock(&rwlock3);

    if( (FrameFlag==WK_FRAME_START) || (FrameFlag == WK_FRAME_CENTER) || (FrameFlag==WK_FRAME_APPEND) ){
        // 写入数据
        nodeWdPtr3->nodeContent.length += length;
        memcpy(nodeWdPtr3->nodeContent.buf + nodeWdPtr3->nodeContent.appendPtr, pBuf, length);
        nodeWdPtr3->nodeContent.appendPtr += length;

    }else if(FrameFlag == WK_FRAME_END){
        // 写入最后一点数据
        nodeWdPtr3->nodeContent.length += length;
        memcpy(nodeWdPtr3->nodeContent.buf + nodeWdPtr3->nodeContent.appendPtr, pBuf, length);
        nodeWdPtr3->nodeContent.appendPtr += length;

        // 指向下一个节点，并且将其清零
		nodeWdPtr3 = nodeWdPtr3->next;
		memset(nodeWdPtr3->nodeContent.buf, 0, nodeWdPtr3->nodeContent.length);
		nodeWdPtr3->nodeContent.length = 0;
		nodeWdPtr3->nodeContent.appendPtr = 0;
		nodeWdPtr3->frameError = false;
	}

	pthread_rwlock_unlock(&rwlock3);

	return 0;
}

void VideoLink_Reset3(void)
{
	pthread_rwlock_wrlock(&rwlock3);

#if STACK_MEMORY_CH3
    nodeWdPtr3 = nodeHDMIPtr3 = &videoLink3[0];
#else 
	nodeWdPtr3 = nodeHDMIPtr3 = videoLink3[0];
#endif 
	memset(nodeWdPtr3->nodeContent.buf, 0, nodeWdPtr3->nodeContent.length);
	nodeWdPtr3->nodeContent.length = 0;
	nodeWdPtr3->nodeContent.appendPtr = 0;
	nodeWdPtr3->frameError = false;

	pthread_rwlock_unlock(&rwlock3);
}

#endif 


static char *pVideoBufEx=NULL;
struct mem_medqueue_unit pListQueue;
pthread_mutex_t m_lock;

void OnVideoListInit(void)
{
    pVideoBufEx = NULL;

    WK_LOGD("----------OnVideoListInit------------------\n");
	if(pVideoBufEx == NULL){
		pVideoBufEx = (char*)malloc(LINK_LIST_LENGTH*MAX_IDR_FRAME_SIZE);
	}

	for(int j=0;j<400;j++){
		pListQueue.lists[j].next = &pListQueue.lists[j+1];
		pListQueue.lists[j].p = NULL;
		pListQueue.lists[j].frmaetype = 0;
		pListQueue.lists[j].size = 0;
	}

	pListQueue.lists[399].next = &pListQueue.lists[0];
	pListQueue.pread = pListQueue.pwrite = &pListQueue.lists[0];
	pListQueue.pMemBegin = pVideoBufEx;
	pListQueue.pMemEnd = pListQueue.pMemBegin+LINK_LIST_LENGTH*MAX_IDR_FRAME_SIZE;
	pListQueue.pMemFree = pListQueue.pMemBegin;
}

int OnAddVideoDataToList(unsigned char *pViBuf,int nSize)
{
	pthread_mutex_lock(&m_lock);

	int datamark = 0xaabbccdd;
    int listfree = pListQueue.pMemEnd - pListQueue.pMemFree;
	if((nSize+10) < listfree){
        // printf("------------ write append [%d] [%d]--------------\n", nSize, listfree);
		memmove(pListQueue.pMemFree ,&datamark, 4);
		memmove(pListQueue.pMemFree+4, pViBuf, nSize);
		pListQueue.pwrite->p = pListQueue.pMemFree;
		pListQueue.pwrite->size = nSize+4;
		pListQueue.pMemFree += nSize+4;
		pListQueue.pwrite = pListQueue.pwrite->next;
	}else{
        // printf("------------ write full [%d] [%d]--------------\n", nSize, listfree);
		memmove(pListQueue.pMemBegin, &datamark, 4);
		memmove(pListQueue.pMemBegin+4, pViBuf, nSize);
		pListQueue.pwrite->p = pListQueue.pMemBegin;
		pListQueue.pwrite->size = nSize+4;
		pListQueue.pMemFree = pListQueue.pMemBegin+nSize+4;
		pListQueue.pwrite = pListQueue.pwrite->next;
	}

	pthread_mutex_unlock(&m_lock);

    return 0;
}

int OnReadVideoData(unsigned char *pBuf,int nSize,char &frametype)
{
	int size=0;

	pthread_mutex_lock(&m_lock);
	if(pListQueue.pwrite!=pListQueue.pread){//INVS_FRAME_BP INVS_FRAME_I
		if(pListQueue.pread->size<MAX_IDR_FRAME_SIZE){
			int nmark=0;
			memcpy(&nmark,pListQueue.pread->p,4);
			if(nmark==0xaabbccdd){
				memcpy(pBuf,pListQueue.pread->p+4,pListQueue.pread->size-4);
				size=pListQueue.pread->size-4;
				pListQueue.pread=pListQueue.pread->next;
			}else{
				pListQueue.pread=pListQueue.pread->next;
			}
		}else{
			pListQueue.pread=pListQueue.pread->next;
		}
	}
	pthread_mutex_unlock(&m_lock);

	return size;
}

void OnVideoListReset(void)
{
	pListQueue.pread = pListQueue.pwrite = &pListQueue.lists[0];
    pListQueue.lists[399].next = &pListQueue.lists[0];

    WK_LOGI("============= OnVideoListReset ============\n");
}
