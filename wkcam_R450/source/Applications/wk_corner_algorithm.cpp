#include "wk_corner_algorithm.h"

#include <core.hpp>
#include <highgui.hpp>
#include <opencv.hpp>

wk_corner_video_frame_s::wk_ptr prev_frame;
wk_st_points_s::wk_ptr prev_pionts_test(new wk_st_points_s);
bool falg;


void fun_wk_get_frame_cb(wk_corner_video_frame_s::wk_ptr _info)
{
	wk_st_lk_middle* middle = wk_st_lk_middle::wk_st_lk_get_instance();

#if 1
	//WK_LOGD("####### frame pts --- %ld\n", _info->pts);
	//middle->wk_frame_pionts_venc_debug(_info, prev_pionts_test->points, 0);
	return;
#else
	if(falg == false){
		falg = true;
		
		middle->wk_corner_recognize(_info, prev_pionts_test);
		middle->wk_frame_pionts_venc_debug(_info, prev_pionts_test->points, prev_pionts_test->points_cnt);

		cv::Mat test;
		middle->wk_frame_to_mat(_info, test);
		cv::imwrite("./outpu1111t.jpg", test);
		
		prev_frame = _info;
	}
	else{
		wk_lk_points_output_s::wk_ptr output(new wk_lk_points_output_s);
		wk_lk_points_input_s::wk_ptr intput(new wk_lk_points_input_s);

		intput->curr_frame = &_info->frame;
		intput->prev_frame = &prev_frame->frame;
		memcpy(intput->prev_points, prev_pionts_test->points, sizeof(prev_pionts_test->points));
		intput->points_cnt = prev_pionts_test->points_cnt;
		
		middle->wk_corner_track(intput, output);

		int rect_num = 0;
		for(int ifor =0; ifor < output->points_cnt; ifor++) {
			if(output->status[ifor] == 0) {
				continue;
			}
			prev_pionts_test->points[rect_num].x = output->curr_points[ifor].x;
			prev_pionts_test->points[rect_num].y = output->curr_points[ifor].y;
			rect_num++;
		}
		prev_pionts_test->points_cnt = rect_num;

		middle->wk_frame_pionts_venc_debug(_info, prev_pionts_test->points, prev_pionts_test->points_cnt);

		prev_frame = _info;

		wk_location_result_s::wk_ptr result(new wk_location_result_s);
		result->x = 12.3;
		result->y = 13.2;
		result->z = 3.12;
		result->q[0] = 2.2;
		result->q[1] = 3.3;
		result->q[2] = 4.4;
		result->q[3] = 5.5;
		result->corner_num = prev_pionts_test->points_cnt;
		result->frame = _info;
		middle->wk_result_export(result);
	
		if(prev_pionts_test->points_cnt == 0){
			falg = false;
		}
	}
	 
	return;
#endif	
}

void fun_wk_get_imu_cb(wk_imu_data_s::wk_ptr _info)
{
	static int cnt=0;

	if(cnt++>100){
		WK_LOGD("gyro -- %f\t%f\t%f\t accel ---- %f\t%f\t%f   ----	%ld\n", 
			_info->gyro_x, _info->gyro_y, _info->gyro_z, _info->accel_x, _info->accel_y, _info->accel_z, _info->u64pts);
		cnt=0;
	}
	return;
}

void fun_wk_get_quaternion_cb(wk_quaternion_data_s::wk_ptr _info)
{
	static int cnt=0;
	
	if(cnt++>100){
		WK_LOGD("quaternion -- %f\t%f\t%f\t%f\t ----  %ld\n", 
			_info->q[0], _info->q[1], _info->q[2], _info->q[3], _info->u64pts);
		cnt=0;
	}
	return;
}

int middle_test(char* argv)
{
	wk_st_lk_middle* middle = wk_st_lk_middle::wk_st_lk_get_instance();
	middle->wk_register_get_frame_cb(fun_wk_get_frame_cb);

	wk_quaternion_middle* p_middle = wk_quaternion_middle::wk_quaternion_get_instance();
	p_middle->wk_register_get_quaternion_cb(fun_wk_get_quaternion_cb);

	wk_imu_middle* imu_middle = wk_imu_middle::wk_imu_get_instance();
	imu_middle->wk_register_get_imu_cb(fun_wk_get_imu_cb);

	#ifdef DEBUG_SAVE_IMU_FRAME
	system("rm -rf /mnt/sdcard/frame/frame_all.yuv");
	system("rm -rf ./imu.csv");

	if(strcmp(argv, "1") == 0 || strcmp(argv, "3") == 0){
		middle->wk_frame_save_file_enable(TD_TRUE);
	}

	if(strcmp(argv, "2") == 0 || strcmp(argv, "3") == 0){
		imu_middle->wk_imu_save_file_enable(TD_TRUE);
	}	
	#endif

#if 0
	wk_mqtt_debug* mqtt_debug = wk_mqtt_debug::wk_mqtt_get_instance();
	wk_mqtt_debug_data_s::wk_ptr debug_data(new wk_mqtt_debug_data_s);
	memset(debug_data.get(), 0, sizeof(wk_mqtt_debug_data_s));
	debug_data->x = 12.3;
	debug_data->y = 13.2;
	debug_data->z = 3.12;
	debug_data->q[0] = 2.2;
	debug_data->q[1] = 3.3;
	debug_data->q[2] = 4.4;
	debug_data->q[3] = 5.5;
	debug_data->str = "hea~~";

	while(1){
		mqtt_debug->wk_mqtt_debug_data_push(debug_data);
		sleep(1);
	}
#endif 

	return 0;
}



