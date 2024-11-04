

#include <mavlink_common.h>
#include <sys_utils.h>
#include <isp_setting.h>
#include <thread_comm.h>

mavlink_message_t wkmsg;
mavlink_status_t  wkstatus;
mavlink_wk_camera_state_t 		  wk_camera_state;
mavlink_wk_camera_status_report_t wk_camera_status_report;

CMD_PHOTO_T mPicCmd;
CMD_RECORD_T mRecCmd;
CAM_PHOTO_PARAM_T m_CapTag;

uint8_t app_utc_flag = 0;
int sync_systime;
unsigned char m_ZoomStep;       //数字变焦倍数

pthread_mutex_t mMavlinkRecvLock;

extern void CamSendHandle(char *buf, int size);
extern void comm_send_data(uint8_t *data, uint16_t length);
extern void setRtspStop(bool status);

#ifdef __cplusplus
extern "C" {
#endif
extern td_s32 wk_quaternion_push_data(td_float q0, td_float q1, td_float q2, td_float q3, td_u64 pts);
#ifdef __cplusplus
}
#endif


int takephotocount = 0;
int takephotomode = 0;

/*
 * deal with one command
 */
bool MavlinkCmdOnDealDate(int id ,char *MessageBuf)
{
    int time_tag;

	if((id<0) || (NULL==MessageBuf)){
		return false;
	}

	pthread_mutex_lock(&mMavlinkRecvLock);

	switch (id)
	{
    #if 1
		case MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL:{	//拍照录像
			mavlink_wk_camera_cmd_camera_control_t *p = (mavlink_wk_camera_cmd_camera_control_t *)MessageBuf;
			if((p->cam_ctrl_type == WKCAM_CAMERA_CONTROL_TYPE_CAPTURE) //单拍
				|| (p->cam_ctrl_type == WKCAM_CAMERA_CONTROL_TYPE_CAPTURE_CONTINUE) //连续拍
				|| (p->cam_ctrl_type == WKCAM_CAMERA_CONTROL_TYPE_CAPTURE_TIME_TOKEN) //定时拍 
                || (p->cam_ctrl_type == WKCAM_CAMERA_CONTROL_TYPE_PANORAMA_SHOT_START) //全景拍照开始
                || (p->cam_ctrl_type == WKCAM_CAMERA_CONTROL_TYPE_PANORAMA_SHOT_STOP)  //全景拍照结束
                || (p->cam_ctrl_type == WKCAM_CAMERA_CONTROL_TYPE_PANORAMA_INTURRUPT)) //全景拍照中断
			{	
				// 判断时间戳是不是和上次一致，是则忽略，并且回复上传一次的状态
                time_tag = (p->cam_ctrl_timestamps > wk_camera_state.takephoto_resp_timestamp) ?
                           (p->cam_ctrl_timestamps - wk_camera_state.takephoto_resp_timestamp) :
                           (wk_camera_state.takephoto_resp_timestamp - p->cam_ctrl_timestamps);
				if(time_tag < 200){
					WK_LOGD("wk_camera_state.takephoto_resp_timestamp == p->cam_ctrl_timestamps:%u\n" ,p->cam_ctrl_timestamps);
					break;
				}
				wk_camera_state.takephoto_resp_timestamp = p->cam_ctrl_timestamps;
                takephotocount += 1;

                OnSwitchCameraStatus(1);
                if(WKCAM_CAMERA_CONTROL_TYPE_PANORAMA_SHOT_START == p->cam_ctrl_type && takephotocount == 1){
                    takephotomode = m_CapTag.CapMode;
                    m_CapTag.CapMode = WKCAM_CAP_MODE_PANORAMA;
                }
                else if(WKCAM_CAMERA_CONTROL_TYPE_PANORAMA_SHOT_STOP == p->cam_ctrl_type){
                    takephotocount = 0;
                }
                else if(WKCAM_CAMERA_CONTROL_TYPE_PANORAMA_INTURRUPT == p->cam_ctrl_type){
                    takephotocount = 0;
                    m_CapTag.CapMode = takephotomode;
                }
                else{
                }
                WK_LOGD(" time_tag[%d] p->cam_ctrl_timestamps:%ld ctrl_type:%d sub_type:%d m_CapTag.CapMode:%d\n", 
                         time_tag, p->cam_ctrl_timestamps, p->cam_ctrl_type, p->cam_ctrl_sub_type, m_CapTag.CapMode);

                m_CapTag.CapContinue = p->cam_ctrl_value1;
				memset(&mPicCmd,0x00,sizeof(CMD_PHOTO_T));
				mPicCmd.cmd_recv = true;
                mPicCmd.cap_type = p->cam_ctrl_type;
                mPicCmd.cap_sub_type = p->cam_ctrl_sub_type+1;
				mPicCmd.cap_mode = m_CapTag.CapMode;
				mPicCmd.cap_continute = m_CapTag.CapContinue;
				mPicCmd.trig_timestamps = p->cam_ctrl_timestamps;
				mPicCmd.longitude = p->longitude;
				mPicCmd.latitude = p->latitude;
				mPicCmd.altitude = p->altitude;
				mPicCmd.roll = p->UavRoll;
				mPicCmd.pitch = p->UavPitch;
				mPicCmd.yaw = p->UavYaw;
				mPicCmd.gimbal_roll = p->GimbalRoll;
				mPicCmd.gimbal_pitch = p->GimbalPitch;
				mPicCmd.gimbal_yaw = p->GimbalYaw;
			} else if((p->cam_ctrl_type == WKCAM_CAMERA_CONTROL_TYPE_RECORD_START) //开始录像
				|| (p->cam_ctrl_type == WKCAM_CAMERA_CONTROL_TYPE_RECORD_STOP) //停止录像
				|| (p->cam_ctrl_type == WKCAM_CAMERA_CONTROL_TYPE_CAPTURE_TIME_LAPSE_START)	//开始延时摄影
				|| (p->cam_ctrl_type == WKCAM_CAMERA_CONTROL_TYPE_CAPTURE_TIME_LAPSE_STOP)) //停止延时摄影
			{
				// 判断时间戳是不是和上次一致，是则忽略，并且回复上传一次的状态
				if(p->cam_ctrl_timestamps - wk_camera_state.video_resp_timestamp < 2000){
					WK_LOGD("wk_camera_cmd_video_rec.trig_timestamps == p->cam_ctrl_timestamps:%d\n" ,p->cam_ctrl_timestamps);
					break;
				}

                OnSwitchCameraStatus(0);

				wk_camera_state.video_resp_timestamp = p->cam_ctrl_timestamps;

				memset(&mRecCmd, 0x00, sizeof(CMD_RECORD_T));
				mRecCmd.cmd_recv = true;
				mRecCmd.trig_timestamps = p->cam_ctrl_timestamps;
				mRecCmd.cmd = p->cam_ctrl_type;
				mRecCmd.sampling_time = p->cam_ctrl_value1;	//延时摄影间隔
				mRecCmd.frame_rate = p->cam_ctrl_value2;	//延时摄影帧率
				mRecCmd.sampling_total_time = p->cam_ctrl_value3;	//延时摄影总时长
				mRecCmd.sampling_sub_type = p->cam_ctrl_sub_type;
			}
			break;
		}
    #endif
    
		case MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO:{       // 拍照
			mavlink_wk_camera_cmd_takephoto_t *p = (mavlink_wk_camera_cmd_takephoto_t *)MessageBuf;
			// 判断时间戳是不是和上次一致，是则忽略，并且回复上传一次的状态
			if(wk_camera_state.takephoto_resp_timestamp == p->trig_timestamps){
				// printf("wk_camera_state.takephoto_resp_timestamp == p->trig_timestamps:%u\n" ,p->trig_timestamps);
                break;
			}

			wk_camera_state.takephoto_resp_timestamp = p->trig_timestamps;

            OnSwitchCameraStatus(1);

            memset(&mPicCmd,0x00,sizeof(CMD_PHOTO_T));
            mPicCmd.cmd_recv = true;
			mPicCmd.cap_mode = m_CapTag.CapMode;
			mPicCmd.cap_continute = m_CapTag.CapContinue;
            mPicCmd.trig_timestamps = p->trig_timestamps;
            mPicCmd.longitude = p->longitude;
            mPicCmd.latitude = p->latitude;
            mPicCmd.altitude = p->altitude;
            mPicCmd.roll = p->UavRoll;
            mPicCmd.pitch = p->UavPitch;
            mPicCmd.yaw = p->UavYaw;
            mPicCmd.gimbal_roll = p->GimbalRoll;
            mPicCmd.gimbal_pitch = p->GimbalPitch;
            mPicCmd.gimbal_yaw = p->GimbalYaw;

			break;}

		case MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC:{       // 录像
			mavlink_wk_camera_cmd_video_rec_t *p = (mavlink_wk_camera_cmd_video_rec_t *)MessageBuf;
			
			// 判断时间戳是不是和上次一致，是则忽略，并且回复上传一次的状态
            time_tag = (p->trig_timestamps > wk_camera_state.video_resp_timestamp) ?
                       (p->trig_timestamps - wk_camera_state.video_resp_timestamp) :
                       (wk_camera_state.video_resp_timestamp - p->trig_timestamps);
			if(time_tag < 2000){
				WK_LOGD("wk_camera_cmd_video_rec.trig_timestamps == p->trig_timestamps:%d\n", time_tag);
				break;
			}

            OnSwitchCameraStatus(0);

			// 判断录像状态标志是不是和上次一致，是则忽略，并且回复上传一次的状态
			// if(mRecCmd.cmd == p->cmd_type){
			// 	printf("mRecCmd.cmd == p->cmd_type:%d\n", p->cmd_type);
			// 	break;
			// }

			wk_camera_state.video_resp_timestamp = p->trig_timestamps;

			memset(&mRecCmd, 0x00, sizeof(CMD_RECORD_T));
			mRecCmd.cmd_recv = true;
            mRecCmd.trig_timestamps = p->trig_timestamps;
			mRecCmd.cmd = p->cmd_type;

			break;}

        case MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC:{   // 时间同步
			mavlink_wk_camera_cmd_utc_time_sync_t *p = (mavlink_wk_camera_cmd_utc_time_sync_t *)MessageBuf;
			char string[64] = {0};	
			CAM_TIME_T tm = {0};
			tm.year 	= p->year;
			tm.month 	= p->month;
			tm.date		= p->day;
			tm.hour		= p->hour;
			tm.minute	= p->min;
			tm.second	= p->sec;

			if(sync_systime >= 30){ //30秒同步一次时间
				sync_systime = 0;
				sprintf(string,"date -s %c%d-%d-%d %d:%d:%d%c",'"',tm.year,tm.month,tm.date,tm.hour,tm.minute,tm.second,'"');
				system(string);	
			}
			break;}

		case MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER:{   // 创建文件夹，便于用户自己设定拍照文件夹名字
			mavlink_wk_camera_cmd_create_folder_t *p = (mavlink_wk_camera_cmd_create_folder_t *)MessageBuf;
			
			// 设置的名字不为空
			if( 0 == strlen((char *)p->folder_name) ){
				char msg[64] = {0};
				sprintf(msg ,"folder name is null");
				memset(p->folder_name ,0 ,sizeof(p->folder_name));
				strncpy((char *)p->folder_name ,(char *)msg ,strlen((char *)p->folder_name));
				break;
			}

			// 查找是否已经存在同名文件夹
			DIR *dp = opendir("/mnt/sdcard");
			if(NULL == dp){
				char msg[64] = {0};
				sprintf(msg ,"not found /mnt/sdcard path");
				memset(p->folder_name ,0 ,sizeof(p->folder_name));
				strncpy((char *)p->folder_name ,(char *)msg ,strlen((char *)p->folder_name));
				break;
			}
			struct dirent *ptrDir = NULL;
			while( NULL != (ptrDir=readdir(dp)) )
			{
				if( 0 == strncmp((char *)ptrDir->d_name ,(char *)p->folder_name ,strlen((char *)p->folder_name)) ){
					char msg[64] = {0};
					sprintf(msg ,"%s is exist" ,p->folder_name);
					memset(p->folder_name ,0 ,sizeof(p->folder_name));
					strncpy((char *)p->folder_name ,(char *)msg ,strlen((char *)p->folder_name));
					break;		// 已经存在
				}
			}
			closedir(dp);
			dp = NULL;

			// 不存在
			char pathname[80] = {0};
			sprintf(pathname ,"/mnt/sdcard/%s" ,p->folder_name);
			if(0 != mkdir(pathname ,S_IRWXU) ){	// 文件所有者拥有读取、写入、执行权限
				char msg[64] = {0};
				sprintf(msg ,"create %s failed[reason%s]" ,p->folder_name ,strerror(errno));
				memset(p->folder_name ,0 ,sizeof(p->folder_name));
				strncpy((char *)p->folder_name ,(char *)msg ,strlen((char *)p->folder_name));
				break;
			}
			
			break;}

		case MAVLINK_MSG_ID_WK_CAMERA_CMD_PREVIEW_PARAM:{           // 设置预览通道参数
			mavlink_wk_camera_cmd_preview_param_t *p = (mavlink_wk_camera_cmd_preview_param_t *)MessageBuf;
			tagSetStreamInfoStru tag={0};
			tag.nEncodeMode = 1;		// h264
			tag.nframe_rate = 30;
			tag.nrate_speed = 0;
			tag.nIFrameInter = 30;
			if(WKCAM_PREVIEW_BITRATE_1M == p->preview_bitrate){
				tag.nBitrate = 1*1024;
			}else if(WKCAM_PREVIEW_BITRATE_2M == p->preview_bitrate){
				tag.nBitrate = 2*1024;
			}else{
				tag.nBitrate = 1*1024;    // default value
			}

			if(WKCAM_PREVIEW_RESOLUTION_1080P_30F == p->preview_resolution){
				tag.nWidth = 1280;
				tag.nHeigth = 720;
                tag.nBitrate = 2048;
			}else if(WKCAM_PREVIEW_RESOLUTION_720P_30F == p->preview_resolution){
				tag.nWidth = 1280;
				tag.nHeigth = 720;
                tag.nBitrate = 1024;
			}else{
				tag.nWidth = 1280;
				tag.nHeigth = 720;
                tag.nBitrate = 1024;
			}

            if(m_TagSecond.nBitrate == tag.nBitrate){
                break;
            }
			WK_LOGD("------------------------------------\n");
			WK_LOGD("tag.nEncodeMode:%d\n" ,tag.nEncodeMode);
			WK_LOGD("tag.nframe_rate:%d\n" ,tag.nframe_rate);
			WK_LOGD("tag.nrate_speed:%d\n" ,tag.nrate_speed);
			WK_LOGD("tag.nIFrameInter:%d\n" ,tag.nIFrameInter);
			WK_LOGD("tag.nBitrate:%d\n" ,tag.nBitrate);
			WK_LOGD("tag.nWidth:%d\n" ,tag.nWidth);
			WK_LOGD("tag.nHeigth:%d\n" ,tag.nHeigth);
			WK_LOGD("------------------------------------\n");
			if( SysSetConfig(SET_SYSTEM_RESET_SECONDSTREAM_COMM,0,(void*)&tag) ){
				WK_LOGD("set preview param successful!!!\n");
			}else{
				WK_LOGW("set preview param failed!!!\n");
			}
			memcpy(&m_TagSecond, (char *)&tag, sizeof(tagSetStreamInfoStru));
			OnWriteSecondStreamConfig((void*)&tag);

			break;}

		case MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER:{                 // 设置快门值
			mavlink_wk_camera_cmd_shutter_t *p = (mavlink_wk_camera_cmd_shutter_t *)MessageBuf;
			WK_LOGD("p->shutter:%d\n" ,p->shutter);
			if(OnSetAeExposureInfo(WK_AE_EXPOSURE_TIME,(unsigned int)p->shutter)){
				WK_LOGD("set shutter successful:%d!!!\n" ,p->shutter);
			}else{
				WK_LOGW("set shutter failed:%d!!!\n" ,p->shutter);
			}
			break;}

		case MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO:{                     // 设置 ISO
			mavlink_wk_camera_cmd_iso_t *p = (mavlink_wk_camera_cmd_iso_t *)MessageBuf;
			WK_LOGD("p->iso:%d\n" ,p->iso);
			if(OnSetAeExposureInfo(WK_AE_EXPOSURE_ISO,(unsigned int)((p->iso)/100))){
				WK_LOGD("set iso successful:%d!!!\n" ,p->iso);
			}else{
				WK_LOGW("set iso failed:%d!!!\n" ,p->iso);
			}
			break;}

		case MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE:{                 // 设置 EV_MODE
			mavlink_wk_camera_cmd_ev_mode_t *p = (mavlink_wk_camera_cmd_ev_mode_t *)MessageBuf;
			WK_LOGD("------------- p->ev_mode:%d\n");
			if(OnSetAeExposureInfo(WK_AE_EXPOSURE_MODE,(unsigned int)(p->ev_mode))){
				WK_LOGD("set exposure mode successful:%d!!!\n" ,p->ev_mode);
			}else{
				WK_LOGW("set exposure mode failed:%d!!!\n" ,p->ev_mode);
			}
			break;}

		case MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_VALUE:{                // 设置 EV_VALUE
			mavlink_wk_camera_cmd_ev_value_t *p = (mavlink_wk_camera_cmd_ev_value_t *)MessageBuf;
			WK_LOGD("p->ev_value:%d\n" ,p->ev_value);
            int tempEv = p->ev_value - 132 + DEFAULT_EV_VALUE;
            OnSetCSCAttr(WK_CSC_BRIGTHNESS, tempEv);
			// if(OnSetAeExposureInfo(WK_AE_EXPOSURE_TARGETCOMP,(unsigned int)p->ev_value)){
			// 	printf("set ev value successful:%d!!!\n" ,p->ev_value);
			// }else{
			// 	printf("set ev value failed!!!\n");
			// }
			break;}

		case MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC:{                    // 设置 CSC
			mavlink_wk_camera_cmd_csc_t *p = (mavlink_wk_camera_cmd_csc_t *)MessageBuf;
			WK_LOGD("set Brightness[%d] \n",p->csc_luma);
			if( !OnSetCSCAttr(WK_CSC_BRIGTHNESS,p->csc_luma) ){
				WK_LOGW("set brightness failed \n");
			}

			WK_LOGD("set Contrast[%d] \n",p->csc_contrast);
			if( !OnSetCSCAttr(WK_CSC_CONTRAST,p->csc_contrast) ){
				WK_LOGW("set Contrast failed \n");
			}

			WK_LOGD("set Saturation[%d] \n",p->csc_aturation);
			if( !OnSetCSCAttr(WK_CSC_SATURATION,p->csc_aturation) ){
				WK_LOGW("set Saturation failed \n");
			}

			WK_LOGD("set Sharpness[%d] \n",p->csc_hue);
			if( !OnSetCSCAttr(WK_CSC_SHARPNESS,p->csc_hue) ){
				WK_LOGW("set Sharpness failed \n");
			}
			break;}

		case MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM:{               // 设置 拍照参数
			mavlink_wk_camera_cmd_cap_param_t *p = (mavlink_wk_camera_cmd_cap_param_t *)MessageBuf;
			WK_LOGD("------------------------------------\n");
			WK_LOGD("m_CapTag.CapMode:%d\n" ,p->cap_mode);
			WK_LOGD("m_CapTag.CapContinue:%d\n" ,p->cap_continues);
			WK_LOGD("m_CapTag.CapRation:%d\n" ,p->cap_rotation);
			WK_LOGD("m_CapTag.CapResolution:%d\n" ,p->cap_resolution);
			WK_LOGD("m_CapTag.CapSave:%d\n" ,p->cap_save_format);
			WK_LOGD("------------------------------------\n");
			m_CapTag.CapMode = p->cap_mode;
			m_CapTag.CapContinue = p->cap_continues;
            m_CapTag.CapRation = p->cap_rotation;
            m_CapTag.CapResolution = p->cap_resolution;
            m_CapTag.CapSave = p->cap_save_format;
			WK_LOGD("set capture param successful!!! \n");
			break;}

		case MAVLINK_MSG_ID_WK_CAMERA_CMD_AWB_MODE:{     // 设置 白平衡模式
			mavlink_wk_camera_cmd_awb_mode_t *p = (mavlink_wk_camera_cmd_awb_mode_t *)MessageBuf;
			WK_LOGD("p->awb_mode:%d\n" ,p->awb_mode);
			if( OnSetAwbAttr(p->awb_mode) ){
				WK_LOGD("set awb successful!!!\n");
			}else{
				WK_LOGW("set awb failed!!!\n");
			}
			break;}
		case MAVLINK_MSG_ID_ODOMETRY:
		{
			mavlink_odometry_t* data = (mavlink_odometry_t *)MessageBuf;
			wk_quaternion_push_data(data->q[0], data->q[1], data->q[2], data->q[3], data->time_usec);
			break;
		}
		default:{
			return false;
			break;}
	}

	pthread_mutex_unlock(&mMavlinkRecvLock);

	return true;
}

/*
 *  mavlink protocol decode one byte
 */
void mavlink_decode(unsigned char byte)
{
	if (mavlink_parse_char(0, byte, &wkmsg, &wkstatus)) {
        //WK_LOGI("============ wkcam_f210 recv wkmsg.msgid[%d]\n",wkmsg.msgid);
		switch (wkmsg.msgid) 
        {
        #if 1
			case MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL:{
				mavlink_wk_camera_cmd_camera_control_t wk_camera_cmd_camera_control;
				mavlink_msg_wk_camera_cmd_camera_control_decode(&wkmsg, &wk_camera_cmd_camera_control);
				MavlinkCmdOnDealDate((int)MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL, (char *)&wk_camera_cmd_camera_control);

				//printf("------------------- recv mavlink take photo or video rec!!!\n");
				break;}
        #endif
            case MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO:{       // 拍照
				mavlink_wk_camera_cmd_takephoto_t wk_camera_cmd_takephoto;
                mavlink_msg_wk_camera_cmd_takephoto_decode(&wkmsg, &wk_camera_cmd_takephoto);
                MavlinkCmdOnDealDate((int)MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO ,(char *)&wk_camera_cmd_takephoto);

                //printf("------------------- recv mavlink take photo!!!\n");
                break;}
    
            case MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC:{   // 时间同步
                mavlink_wk_camera_cmd_utc_time_sync_t wk_camera_cmd_utc_time_sync;
                mavlink_msg_wk_camera_cmd_utc_time_sync_decode(&wkmsg, &wk_camera_cmd_utc_time_sync);
				if (wkmsg.compid == MAV_COMP_ID_MISSIONPLANNER) {
					app_utc_flag = 1;
					MavlinkCmdOnDealDate((int)MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC, (char *)&wk_camera_cmd_utc_time_sync);
				}

				if(app_utc_flag == 0)	//fc
					MavlinkCmdOnDealDate((int)MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC, (char *)&wk_camera_cmd_utc_time_sync);
				// printf("------------------- recv mavlink utc time sync!!!\n");
                break;}

            case MAVLINK_MSG_ID_WK_CAMERA_CMD_PREVIEW_PARAM:{   // 设置预览通道参数
                mavlink_wk_camera_cmd_preview_param_t wk_camera_cmd_preview_param;
                mavlink_msg_wk_camera_cmd_preview_param_decode(&wkmsg, &wk_camera_cmd_preview_param);
                MavlinkCmdOnDealDate((int)MAVLINK_MSG_ID_WK_CAMERA_CMD_PREVIEW_PARAM ,(char *)&wk_camera_cmd_preview_param);
                //printf("------------------- recv mavlink preview param!!!\n");
                break;}

            case MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM:{    // 设置录像通道参数
                mavlink_wk_camera_cmd_record_param_t wk_camera_cmd_record_param;
                mavlink_msg_wk_camera_cmd_record_param_decode(&wkmsg, &wk_camera_cmd_record_param);
                MavlinkCmdOnDealDate((int)MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM ,(char *)&wk_camera_cmd_record_param);
                //printf("------------------- recv mavlink record param!!!\n");
                break;}

            case MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER:{        // 设置快门值
                mavlink_wk_camera_cmd_shutter_t wk_camera_cmd_shutter;
                mavlink_msg_wk_camera_cmd_shutter_decode(&wkmsg, &wk_camera_cmd_shutter);
                MavlinkCmdOnDealDate((int)MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER ,(char *)&wk_camera_cmd_shutter);
                //printf("------------------- recv mavlink shutter!!!\n");
                break;}

            case MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO:{            // 设置 ISO
                mavlink_wk_camera_cmd_iso_t wk_camera_cmd_iso;
                mavlink_msg_wk_camera_cmd_iso_decode(&wkmsg, &wk_camera_cmd_iso);
                MavlinkCmdOnDealDate((int)MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO ,(char *)&wk_camera_cmd_iso);
                //printf("------------------- recv mavlink iso!!!\n");
                break;}

            case MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE:{        // 设置 EV_MODE
                mavlink_wk_camera_cmd_ev_mode_t wk_camera_cmd_ev_mode;
                mavlink_msg_wk_camera_cmd_ev_mode_decode(&wkmsg, &wk_camera_cmd_ev_mode);
                MavlinkCmdOnDealDate((int)MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE ,(char *)&wk_camera_cmd_ev_mode);
                //printf("------------------- recv mavlink ev mode!!!\n");
                break;}  

            case MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_VALUE:{      // 设置 EV_VALUE
                mavlink_wk_camera_cmd_ev_value_t wk_camera_cmd_ev_value;
                mavlink_msg_wk_camera_cmd_ev_value_decode(&wkmsg, &wk_camera_cmd_ev_value);
                MavlinkCmdOnDealDate((int)MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_VALUE ,(char *)&wk_camera_cmd_ev_value);
                //printf("------------------- recv mavlink ev value!!!\n");
                break;}

            case MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC:{           // 设置 CSC
                mavlink_wk_camera_cmd_csc_t wk_camera_cmd_csc;
                mavlink_msg_wk_camera_cmd_csc_decode(&wkmsg, &wk_camera_cmd_csc);
                MavlinkCmdOnDealDate((int)MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC ,(char *)&wk_camera_cmd_csc);
                WK_LOGD("------------------- recv mavlink csc!!!\n");
                break;}

            case MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM:{     // 设置 拍照参数
                mavlink_wk_camera_cmd_cap_param_t wk_camera_cmd_cap_param;
                mavlink_msg_wk_camera_cmd_cap_param_decode(&wkmsg, &wk_camera_cmd_cap_param);
                MavlinkCmdOnDealDate((int)MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM ,(char *)&wk_camera_cmd_cap_param);
                WK_LOGD("------------------- recv mavlink cap param!!!\n");
                break;}

            case MAVLINK_MSG_ID_WK_CAMERA_CMD_AWB_MODE:{     // 设置 白平衡模式
                mavlink_wk_camera_cmd_awb_mode_t wk_camera_cmd_awb_mode;
                mavlink_msg_wk_camera_cmd_awb_mode_decode(&wkmsg, &wk_camera_cmd_awb_mode);
                MavlinkCmdOnDealDate((int)MAVLINK_MSG_ID_WK_CAMERA_CMD_AWB_MODE ,(char *)&wk_camera_cmd_awb_mode);
                WK_LOGD("------------------- recv mavlink awb mode!!!\n");
                break;}
			case MAVLINK_MSG_ID_ODOMETRY:
			{	  // 获取飞控四元数
				mavlink_odometry_t wk_odometry;
				mavlink_msg_odometry_decode(&wkmsg, &wk_odometry);
				MavlinkCmdOnDealDate((int)MAVLINK_MSG_ID_ODOMETRY ,(char *)&wk_odometry);
				//WK_LOGD("------------------- recv mavlink odometry data!!!\n");
				break;
			}
            default:{
                //printf("-------------------- not found wkmsg.msgid:%d\n" ,wkmsg.msgid);
                break;}
        }
    }
}

void mavlink_set_camera_status_result(CAM_STATUS_T camStatus)
{	
	if(FILESYSTEM_TYPE_FAT == camStatus.fs_type){
		wk_camera_status_report.sdcard_filesystem = WKCAM_SDCARD_FILESYSTEM_FAT32; /*<  see enum WKCAM_SDCARD_FILESYSTEM*/
		wk_camera_status_report.sdcard_status = WKCAM_SDCARD_STATUS_MOUNT;
	}else if(FILESYSTEM_TYPE_EXT == camStatus.fs_type){
		wk_camera_status_report.sdcard_filesystem = WKCAM_SDCARD_FILESYSTEM_EXFAT; /*<  see enum WKCAM_SDCARD_FILESYSTEM*/
		wk_camera_status_report.sdcard_status = WKCAM_SDCARD_STATUS_MOUNT;
	}else{
		wk_camera_status_report.sdcard_filesystem = WKCAM_SDCARD_FILESYSTEM_OTHER; /*<  see enum WKCAM_SDCARD_FILESYSTEM*/
		wk_camera_status_report.sdcard_status = WKCAM_SDCARD_STATUS_NO_MOUNT;
	}

	wk_camera_status_report.video_record_time = camStatus.record_time;
	wk_camera_status_report.sdcard_capacity_total_bytes = camStatus.totalsize;
	wk_camera_status_report.sdcard_capacity_free_bytes = camStatus.freeDisk;
	wk_camera_status_report.capability_flags = WKCAM_CAP_ENC_H264;
}

void mavlink_send_wkcam_params(void)
{
    uint16_t length;
    uint8_t msgbuff[MAVLINK_MAX_PACKET_LEN];
	unsigned char value;
	CameraIspParams m_config;
    mavlink_message_t msg;
    mavlink_wk_camera_params_rpt_t wk_camera_params_rpt;

	memset(&wk_camera_params_rpt ,0 ,sizeof(wk_camera_params_rpt));

	//software version
	wk_camera_params_rpt.serial_number 		= 666666;
	wk_camera_params_rpt.focal_length  		= 9;
	wk_camera_params_rpt.focal_length_35mm 	= 9;
	wk_camera_params_rpt.major_ver 			= 1;
	wk_camera_params_rpt.minor_ver 			= 0;

	//photo params
	//wk_camera_params_rpt.cap_mode = WKCAM_CAP_MODE_SINGLE;
	wk_camera_params_rpt.cap_mode = m_CapTag.CapMode;
	wk_camera_params_rpt.cap_continues = m_CapTag.CapContinue;
	wk_camera_params_rpt.cap_save_format = m_CapTag.CapSave;
	wk_camera_params_rpt.cap_resolution = m_CapTag.CapResolution;
	wk_camera_params_rpt.cap_rotation = WKCAM_CAP_ROTATION_16_9;
	wk_camera_params_rpt.stream_enc_type = WKCAM_ENC_TYPE_H264;

	//preview channel params
	if(1280 == m_TagSecond.nWidth && 720 == m_TagSecond.nHeigth && 2048 == m_TagSecond.nBitrate){
		wk_camera_params_rpt.preview_resolution = WKCAM_PREVIEW_RESOLUTION_1080P_30F; //1280 2M
	}
	else if(1280 == m_TagSecond.nWidth && 720 == m_TagSecond.nHeigth && 1024 == m_TagSecond.nBitrate){
		wk_camera_params_rpt.preview_resolution = WKCAM_PREVIEW_RESOLUTION_1080P_1M;  //1280 1M
	}
    else{
        wk_camera_params_rpt.preview_resolution = WKCAM_PREVIEW_RESOLUTION_720P_30F;  //720 1M
    }

	//record channel params
	if(1920 == m_TagMain.nWidth && 1080 == m_TagMain.nHeigth && 60 == m_TagMain.nframe_rate){
		wk_camera_params_rpt.record_resolution = WKCAM_RECORD_RESOLUTION_6K25; //1080@60FPS
	}
	else{
		wk_camera_params_rpt.record_resolution = WKCAM_RECORD_RESOLUTION_4K30; //4K@30FPS
	}

    if(50*1024 < m_TagMain.nBitrate){
        wk_camera_params_rpt.record_bitrate = WKCAM_RECORD_BITRATE_100M;
    }
    else{
        wk_camera_params_rpt.record_bitrate = WKCAM_RECORD_BITRATE_50M;
    }

	OnGetCamParams(&m_config);
	wk_camera_params_rpt.ev_mode = m_config.aemode;
	wk_camera_params_rpt.iso = m_config.iso_value;
	wk_camera_params_rpt.shutter = m_config.shutter_value;
	wk_camera_params_rpt.ev_value = m_config.ev_value;
	wk_camera_params_rpt.awb_mode = m_config.awbmode;
	wk_camera_params_rpt.csc_luma = m_config.brightness;
	wk_camera_params_rpt.csc_contrast = m_config.contrast;
	wk_camera_params_rpt.csc_aturation = m_config.saturation;
	wk_camera_params_rpt.csc_hue = m_config.sharpness;

    mavlink_msg_wk_camera_params_rpt_encode(MAVLINK_SYS_ID,WK_MODULE_TYPE_CAMERA,&msg,&wk_camera_params_rpt);

    length = mavlink_msg_to_send_buffer(msgbuff,&msg);
    comm_send_data(msgbuff,length);
}

void mavlink_send_wkcam_status(void)
{
	uint16_t length;
    uint8_t msgbuff[MAVLINK_MAX_PACKET_LEN];
    mavlink_message_t msg;
    
	mavlink_msg_wk_camera_status_report_encode(MAVLINK_SYS_ID, WK_MODULE_TYPE_CAMERA, &msg, &wk_camera_status_report);

	length = mavlink_msg_to_send_buffer(msgbuff,&msg);
    comm_send_data(msgbuff,length);
}

void mavlink_send_wkcam_version(void)
{
	uint16_t length;
    uint8_t msgbuff[MAVLINK_MAX_PACKET_LEN];
    mavlink_message_t msg;
	mavlink_wk_module_version_t wk_camera_version;

	wk_camera_version.sw_ver = 1024;
	wk_camera_version.dev_type = WK_MODULE_TYPE_CAMERA;

	mavlink_msg_wk_module_version_encode(MAVLINK_SYS_ID, WK_MODULE_TYPE_CAMERA, &msg, &wk_camera_version);

    length = mavlink_msg_to_send_buffer(msgbuff,&msg);
    comm_send_data(msgbuff,length);	
}

void mavlink_camera_prodic_task(void)
{
    uint32_t now_ms = system_time_ms_get();
    static uint32_t last_camera_params_send_ms;
	static int count, cammode;

#if 1
	static uint32_t last_camera_time_lapse_state_send_ms;
	if (get_delta_time(now_ms,last_camera_time_lapse_state_send_ms) >= 500) //500ms
	{
		last_camera_time_lapse_state_send_ms = now_ms;
	}
#endif

    if (get_delta_time(now_ms,last_camera_params_send_ms) >= 1000) //1000ms
    {
        mavlink_send_wkcam_params();
        usleep(10*1000);

		mavlink_send_wkcam_status();
        usleep(10*1000);

		mavlink_send_wkcam_version();
        usleep(10*1000);

        // count++;
		// if(count >= 100){
		// 	mRecCmd.cmd = WACAM_VIDEO_REC_CMD_STOP;
		// 	mRecCmd.cmd_recv = true;
		// 	count = 0;
		// }
		// else if(count == 3){
		// 	mRecCmd.cmd = WACAM_VIDEO_REC_CMD_START;
		// 	mRecCmd.cmd_recv = true;
		// }
		// else{
        //     mRecCmd.cmd_recv = false;
		// }

		// count++;
		// if(count >= 3){
		// 	// mPicCmd.cap_mode = WKCAM_CAP_MODE_SINGLE;
		// 	// mPicCmd.cmd_recv = true;
		// 	count = 0;
		// }

		last_camera_params_send_ms = now_ms;

		sync_systime++;
    }	
}

void mavlink_prodic_tasks(void)
{
    pthread_mutex_lock(&mMavlinkRecvLock);

    // camera communication prodic tasks
    mavlink_camera_prodic_task();

	pthread_mutex_unlock(&mMavlinkRecvLock);
}

void mavlink_init(void)
{
    // set mavlink version
    mavlink_set_proto_version(0,2);
    mavlink_set_proto_version(1,2);

	memset(&wk_camera_status_report ,0 ,sizeof(wk_camera_status_report));

	sync_systime = 28;
    m_ZoomStep = 0;

    m_CapTag.CapMode = WKCAM_CAP_MODE_SINGLE;
    m_CapTag.CapSave = WKCAM_CAP_SAVE_FORMAT_JPG;
    m_CapTag.CapResolution = WKCAM_CAP_RESOLUTION_8M;
    m_CapTag.CapContinue = 1;
}


