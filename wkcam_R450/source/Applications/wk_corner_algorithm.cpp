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

	//middle->wk_frame_pionts_venc_debug(_info, prev_pionts_test->points, 0);

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
}


int middle_test()
{
	wk_st_lk_middle* middle = wk_st_lk_middle::wk_st_lk_get_instance();

	middle->wk_register_get_frame_cb(fun_wk_get_frame_cb);


	td_char data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	cv::Mat mat3(2, 2, CV_8UC3, data);
	middle->wk_log_mat(mat3);


	return 0;
}



