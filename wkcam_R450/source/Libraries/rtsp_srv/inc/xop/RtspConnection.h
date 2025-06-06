﻿// PHZ
// 2018-6-8

#ifndef _RTSP_CONNECTION_H
#define _RTSP_CONNECTION_H

#include "EventLoop.h"
#include "TcpConnection.h"
#include "RtpConnection.h"
#include "RtspMessage.h"
#include "rtsp.h"
#include <iostream>
#include <functional>
#include <memory>
#include <vector>
#include <cstdint>

namespace xop
{

class RtspServer;
class MediaSession;

class RtspConnection : public TcpConnection
{
public:
    typedef std::function<void (SOCKET sockfd)> CloseCallback;

    enum ConnectionMode
    {
        RTSP_SERVER, // RTSP服务器
        RTSP_PUSHER, // RTSP推流器
        //RTSP_CLIENT, // RTSP客户端
    };

    RtspConnection() = delete;
    RtspConnection(Rtsp *rtspServer, TaskScheduler *taskScheduler, int sockfd);
    ~RtspConnection();

    MediaSessionId getMediaSessionId()
    { return _sessionId; }

    TaskScheduler *getTaskScheduler() const 
    { return _pTaskScheduler; }

    void keepAlive()
    { _aliveCount++; }

    bool isAlive() const
    {
        if (isClosed())
        {
            return false;
        }

        if(_rtpConnPtr != nullptr)
        {
            // 组播暂时不加入心跳检测
            if(_rtpConnPtr->isMulticast())
                return true;
        }

        return (_aliveCount > 0);
    }

    void resetAliveCount()
    { _aliveCount = 0; }

    int getId() const
    { return _pTaskScheduler->getId(); }

private:
    friend class RtpConnection;
    friend class MediaSession;
    friend class RtspServer;
    friend class RtspPusher;

    bool onRead(BufferReader& buffer);
    void onClose();
    void handleRtcp(SOCKET sockfd);

    void sendMessage(std::shared_ptr<char> buf, uint32_t size);
    bool handleRtspRequest(BufferReader& buffer);
    bool handleRtspResponse(BufferReader& buffer);

    void handleCmdOption();
    void handleCmdDescribe();
    void handleCmdSetup();
    void handleCmdPlay();
    void handleCmdTeardown();
    void handleCmdGetParamter();

    void sendOptions(ConnectionMode mode= RTSP_SERVER);
    void sendDescribe();
    void sendAnnounce();
    void sendSetup();
    void handleRecord();

    std::atomic_int _aliveCount;

    Rtsp* _pRtsp = nullptr;
    xop::TaskScheduler *_pTaskScheduler = nullptr;
    enum ConnectionMode _connMode = RTSP_SERVER;
    MediaSessionId _sessionId = 0;

    std::shared_ptr<xop::Channel> _rtpChannelPtr;
    std::shared_ptr<RtspRequest> _rtspRequestPtr;
    std::shared_ptr<RtspResponse> _rtspResponsePtr;
    std::shared_ptr<RtpConnection> _rtpConnPtr;
    std::shared_ptr<xop::Channel> _rtcpChannels[MAX_MEDIA_CHANNEL];
};

}

#endif
