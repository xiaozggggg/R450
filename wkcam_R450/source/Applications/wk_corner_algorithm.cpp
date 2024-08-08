#include "wk_corner_algorithm.h"


wk_corner_video_frame_s::wk_ptr prev_frame;
wk_st_points_s prev_pionts_test;
bool falg;




void fun_wk_get_frame_cb(wk_corner_video_frame_s::wk_ptr _info)
{
	wk_st_lk_middle* middle = wk_st_lk_middle::wk_st_lk_get_instance();
	
	if(falg == false){
		falg = true;
		
		middle->wk_corner_recognize(_info->frame, &prev_pionts_test);
		middle->wk_frame_pionts_venc_debug(_info->frame, &prev_pionts_test.points[0], prev_pionts_test.points_cnt);
		
		prev_frame = _info;
	}
	else{
		wk_lk_points_output_s output;
		wk_lk_points_input_s intput;

		memset(&output, 0, sizeof(wk_lk_points_output_s));
		memset(&intput, 0, sizeof(wk_lk_points_input_s));
		
		intput.curr_frame = _info->frame;
		intput.prev_frame = prev_frame->frame;
		memcpy(intput.prev_points, prev_pionts_test.points, sizeof(prev_pionts_test.points));
		intput.points_cnt = prev_pionts_test.points_cnt;
		
		middle->wk_corner_track(&intput, &output);

		int rect_num = 0;
		for(int ifor =0; ifor < output.points_cnt; ifor++) {
			if(output.status[ifor] == 0) {
				continue;
			}
			prev_pionts_test.points[rect_num].x = output.curr_points[ifor].x;
			prev_pionts_test.points[rect_num].y = output.curr_points[ifor].y;
			rect_num++;
		}
		prev_pionts_test.points_cnt = rect_num;

		middle->wk_frame_pionts_venc_debug(_info->frame, &prev_pionts_test.points[0], prev_pionts_test.points_cnt);

		prev_frame = _info;
	}
	
	return;
}





int middle_test()
{
	wk_st_lk_middle* middle = wk_st_lk_middle::wk_st_lk_get_instance();

	middle->wk_register_get_frame_cb(fun_wk_get_frame_cb);

	return 0;
}



