

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <pthread.h>
#include <mavlink.h>

#include <RtspServer.h>
#include <RtspPusher.h>
#include <VideoList.h>
#include <sys_utils.h>
#include <thread_video_preview.h>
#include <isp_setting.h>

// #include "wk_srt_server.h"
#include "lb_queue.h"

#define SAVE_VIDEO_FILE 0
#define SRT_SERVER 0

typedef struct _frame_data_s {
    int             length;
    unsigned char   buf[SIZE_OF_FRAME];
} _frame_data_t;

struct blocking_queue_t *lbqueue = NULL;

static char framebuf[SIZE_OF_FRAME] = {0};
char Local_IpAddress[16] = {0};

static FILE* pVideoFile;
char mp4path[60];
int frame_count = 0;
static int rtsp_h264_h265;
static bool stop_preview;

#if SRT_SERVER
SrtLiveServer *pSrtServer;
#endif

int addFrameToQueue(unsigned char *databuf, int datalen, WK_FRAME_FLAG_E FrameFlag)
{
    int i;
    int r;

    if (!lbqueue)
        return -1;

    if (stop_preview){
        return -1;
    }

    // printf("put one frame to queue start datalen[%d] \n",datalen);

    _frame_data_t *pdat = (_frame_data_t*)malloc(sizeof(_frame_data_t));

    pdat->length = datalen;
    memcpy(pdat->buf, databuf, datalen);

    r = lbqueue->put(lbqueue, pdat);
    if (r == false)
    {
        fprintf(stderr, "Block Queue Push element <%d> failed!\n", i);
        free(pdat);
    }

    // printf("start code [%x] [%x] [%x] [%x] [%x] -- frame length[%d]\n",databuf[0],databuf[1],databuf[2],databuf[3],databuf[4],datalen);

    return -1;
}

// get & send video stream frame to rtspserver
#if SRT_SERVER
void* sendFrameThread(void* parg)
{
    int framelen = 0;
    _frame_data_t *pdat;

    // struct timeval timeout;
	// unsigned long long start_timoout=0;
    // unsigned long long end_timoout=0;
    // unsigned long long temp_timoout=0;
	// gettimeofday(&timeout, NULL);
	// start_timoout=timeout.tv_sec*1000000 + timeout.tv_usec;

    while(1)
    {
        pdat = (_frame_data_t *)lbqueue->take(lbqueue);
        if (pdat) 
        {
            // gettimeofday(&timeout, NULL);
            // end_timoout=timeout.tv_sec*1000000 + timeout.tv_usec;
            // temp_timoout = (end_timoout - start_timoout) / 1000;
            // start_timoout = end_timoout;

            // if(temp_timoout < 20 || temp_timoout > 45){
            //     printf("***********");
            // }
            // printf("===== get one frame time[%lld]\n",temp_timoout);

        #if SAVE_VIDEO_FILE
            // printf("============ sendFrameThread [%d]\n",pdat->length);
            if(pVideoFile != NULL){
                fwrite(pdat->buf, pdat->length, 1, pVideoFile);
                frame_count++;
                if(frame_count > 9000){
                    WK_LOGD("============ write h265 finish\n");
                    fclose(pVideoFile);
                    pVideoFile = NULL;
                }
            }
        #endif

            if(pSrtServer != NULL){
                if(rtsp_h264_h265 == 0){ //h264
                    pSrtServer->SendData((char *)pdat->buf, pdat->length);  
                }
                else{
                    pSrtServer->SendData((char *)pdat->buf, pdat->length);
                }
            }

            // fprintf(stderr, "Block Queue Poll element : [%d]-%s\n", pdat->num, pdat->dat);
            free(pdat);
            pdat = NULL;
        }
        else{
            usleep(5*1000);
        }
    }
}
#else
void sendFrameThread(xop::RtspServer* rtspServer, xop::MediaSessionId sessionId)
{
    int framelen = 0;
    _frame_data_t *pdat;

    // struct timeval timeout;
	// unsigned long long start_timoout=0;
    // unsigned long long end_timoout=0;
    // unsigned long long temp_timoout=0;
	// gettimeofday(&timeout, NULL);
	// start_timoout=timeout.tv_sec*1000000 + timeout.tv_usec;

    while(1)
    {
        pdat = (_frame_data_t *)lbqueue->take(lbqueue);
        if (pdat) 
        {
            // gettimeofday(&timeout, NULL);
            // end_timoout=timeout.tv_sec*1000000 + timeout.tv_usec;
            // temp_timoout = (end_timoout - start_timoout) / 1000;
            // start_timoout = end_timoout;

            // if(temp_timoout < 20 || temp_timoout > 45){
            //     printf("===========");
            // }
            // printf("====== get one frame time[%lld]\n",temp_timoout);

        #if SAVE_VIDEO_FILE
            // printf("============ sendFrameThread [%d]\n",pdat->length);
            if(pVideoFile != NULL){
                fwrite(pdat->buf, pdat->length, 1, pVideoFile);
                frame_count++;
                if(frame_count > 9000){
                    WK_LOGD("============ write h265 finish\n");
                    fclose(pVideoFile);
                    pVideoFile = NULL;
                }
            }
        #else
            xop::AVFrame videoFrame = {0};
            videoFrame.type = 0; 
            videoFrame.size = pdat->length; 

            if(rtsp_h264_h265 == 0){
                videoFrame.timestamp = xop::H264Source::getTimeStamp();
                videoFrame.buffer.reset(new uint8_t[videoFrame.size]);    
                memcpy(videoFrame.buffer.get(), pdat->buf, videoFrame.size);
                rtspServer->pushFrame(sessionId, xop::channel_0, videoFrame);
            }
            else{
                videoFrame.timestamp = xop::H265Source::getTimeStamp(); 
                videoFrame.buffer.reset(new uint8_t[videoFrame.size]);    
                memcpy(videoFrame.buffer.get(), pdat->buf+4, videoFrame.size-4);
                rtspServer->pushFrame(sessionId, xop::channel_0, videoFrame);
            }

            // printf("============ sendFrameThread [%d]\n",pdat->length);
            //xop::Timer::sleep(40); 
        #endif

            free(pdat);
            pdat = NULL;
        }
        else{
            usleep(5*1000);
        }
    }
}
#endif

void setRtspStop(bool status)
{
    stop_preview = status;
}

// secondary stream - video preview srt srv thread
#if SRT_SERVER
void * thread_video_rtsp_srv_entry(void * parg)
{	
    WK_LOGI(" ############################## start srt server ############################## \n");

    // pSrtServer = new SrtLiveServer("192.168.4.80", 9600);
    pSrtServer = new SrtLiveServer("192.168.1.235", 8600);
    if(pSrtServer == NULL){
        return NULL;
    }

    pSrtServer->Startup();
}
#else
void * thread_video_rtsp_srv_entry(void * parg)
{	
    WK_LOGI(" ############################## start rtsp server ############################## \n");

    //////////////////////////////////////////////
    std::string ip;
    char IpAddress[16] = {0};
	if( getLocalIpAddress((char *)"wlan0" ,(char *)IpAddress) ){ //wireless wlan0 有线：eth0
		WK_LOGD("getLocalIpAddress successful!\n");
        ip = IpAddress;
	}else{
		WK_LOGE("getLocalIpAddress failed!\n");
        ip = "192.168.1.235";
	}

	// std::string ip = "192.168.1.235";
    std::string rtspUrl;

    std::shared_ptr<xop::EventLoop> eventLoop(new xop::EventLoop());  
    xop::RtspServer server(eventLoop.get(), ip, 554);  

    xop::MediaSession *session = xop::MediaSession::createNew("live"); 
    rtspUrl = "rtsp://" + ip +":"+std::string("554")+ "/" + session->getRtspUrlSuffix();   // "rtsp://192.168.1.152:554/live"

    if(rtsp_h264_h265 == 0){
        session->addMediaSource(xop::channel_0, xop::H264Source::createNew()); 
    }
    else{
        session->addMediaSource(xop::channel_0, xop::H265Source::createNew()); 
    }
    //session->startMulticast();  
    xop::MediaSessionId sessionId = server.addMeidaSession(session); 
         
    std::thread t1(sendFrameThread, &server, sessionId); 
    t1.detach(); 

	WK_LOGI("URL: %s\n", rtspUrl.c_str());
    //std::cout << "URL: " <<rtspUrl << std::endl;

    eventLoop->loop(); //主线程运行 RtspServer 
}
#endif

bool thread_video_preview_init(void)
{
    lbqueue = lb_queue(128);
    rtsp_h264_h265 = 0; //0:h264 1:h265
    stop_preview = false;

    // initial video-list vars
    // VideoList_Init2();
    // wk_mpp_set_preview_callback(VideoList_AppendWriteNode2);
    wk_mpp_set_preview_callback(addFrameToQueue);
    wk_mpp_venc_stream_start(WK_VIDEO_CHANNEL_PREVIEW);

#if SAVE_VIDEO_FILE
    sprintf(mp4path, "/mnt/sdcard/VID_test.h265");
    WK_LOGD("create h265 file %s \r\n", mp4path);
    pVideoFile = fopen(mp4path, "wb");
    if (!pVideoFile){
        WK_LOGW("open file[%s] failed!\n",mp4path);
        return -1;
    }
#endif

    // create rtsp server thread
    pthread_t tid_rtsp;
    if (pthread_create(&tid_rtsp,NULL,thread_video_rtsp_srv_entry,NULL) != 0)
    {
        WK_LOGE("err:initial video priview rtsp server thread error\r\n");
        return false;
    }

#if SRT_SERVER
    pthread_t tid_srt_server;
    if (pthread_create(&tid_srt_server,NULL,sendFrameThread,NULL) != 0)
    {
        WK_LOGE("err:initial sendFrameThread error\r\n");
        return false;
    }
#endif

    return true;
}

