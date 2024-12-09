
PRINTF_READ 		:= @printf "\033[31;1m\t%s\033[0m\n"
PRINTF_GREEN 		:= @printf "\033[32;1m\t%s\033[0m\n"
PRINTF_BLUE 		:= @printf "\033[34;1m\t%s\033[0m\n"

ELFPATH=./bin
OBJPATH=./obj
MKDIR_DEPEND=mkdir_elf_obj

COMPILE_CC=aarch64-v01c01-linux-gnu-gcc
COMPILE_CPP=aarch64-v01c01-linux-gnu-g++
ELF=$(ELFPATH)/wkcam_r450

############ include ############
HI_SDK_INC += -I ../Hi3519_MPP/inc
HI_SDK_INC += -I ../Hi3519_MPP/inc/common
HI_SDK_INC += -I ../Hi3519_MPP/inc/hisisdk
HI_SDK_INC += -I ../Hi3519_MPP/inc/scene_auto

THIRD_INC += -I ../include/
THIRD_INC += -I ../include/ffmpeg/
#THIRD_INC += -I ../include/wkSlam/
THIRD_INC += -I ./Applications/vins_mono/camera_model/include/
THIRD_INC += -I ../include/ceres/internal/miniglog/

############ mavlink ############
MAVLINK_INC = -I../include/mavlink/ -I../include/mavlink/walkera 

############ hisisdk ############
HISI_SDK_LIB = -L ../Hi3519_MPP/lib -lwkmpp
HISI_SDK_LIB += -L ../Hi3519_MPP/lib/hisisdk -lss_mpi -lss_mpi_sysbind -lss_mpi_sysmem -laiisp -lss_mpi_ae -lss_mpi_isp -lot_mpi_isp -lss_mpi_awb\
				  -lss_mpi_aibnr -lss_mpi_aidrc -lsvp_acl -lsecurec -ldehaze -lextend_stats -ldrc -l ldci -lbnr -lcalcflicker -lir_auto -lacs\
				 -laac_comm -laac_enc -laac_dec -laac_sbr_enc -laac_sbr_dec -lprotobuf-c -lss_mpi_dpu_match -lss_mpi_dpu_rect -lss_mpi_mcf  -lss_mpi_ai3dnr\
				 -lheif -lfileformat -lot_mpi_km -lss_mpi_thermo -lss_mpi_ive

################# opencv lib #################
OPENCV_INC = -I ../include/opencv/
OPENCV_INC += -I ../include/opencv2/
OPENCV_LIB = -L ../lib/opencv 	-lopencv_dnn -lopencv_ml -lopencv_objdetect -lopencv_shape -lopencv_stitching -lopencv_superres \
								-lopencv_videostab -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs \
								-lopencv_video -lopencv_photo -lopencv_imgproc -lopencv_flann -lopencv_core

#DBoW2_LIB = -L ../lib/DBoW2 -lDBoW2
#g2o_LIB = -L ../lib/g2o -lg2o
ceres_LIB = -L ../lib/ceres -lceres
BOOST_LIB = -L ../lib/boost -lboost_filesystem -lboost_program_options -lboost_system
################# rtsp src #################
RTSP_INC_PATH1 = ./Libraries/rtsp_srv/inc/net
RTSP_INC_PATH2 = ./Libraries/rtsp_srv/inc/xop
RTSP_SRC_PATH1 = ./Libraries/rtsp_srv/src/net
RTSP_SRC_PATH2 = ./Libraries/rtsp_srv/src/xop
RTSP_SRC1  = $(notdir $(wildcard $(RTSP_SRC_PATH1)/*.cpp))
RTSP_OBJS1 = $(patsubst %.cpp,$(OBJPATH)/%.o,$(RTSP_SRC1))
RTSP_SRC2  = $(notdir $(wildcard $(RTSP_SRC_PATH2)/*.cpp))
RTSP_OBJS2 = $(patsubst %.cpp,$(OBJPATH)/%.o,$(RTSP_SRC2))

RTSP_INC_PATH = -I$(RTSP_INC_PATH1) -I$(RTSP_INC_PATH2)
#RTSP_LIBS = -std=c++11 -std=gnu++11 
RTSP_LIBS = -std=c++11
RTSP_OBJS = $(RTSP_OBJS1) $(RTSP_OBJS2)

################# mosquitto lib #################
MOSQU_INC = -I ../include/mosquitto/
MOSQU_LIB = -L ../lib/mosquitto -lmosquitto -lssl -lcrypto

################# applications src #################
APPLICATIONS_PATH = ./Applications
APPLICATIONS_SRC  = $(notdir $(wildcard $(APPLICATIONS_PATH)/*.cpp))
APPLICATIONS_OBJS = $(patsubst %.cpp,$(OBJPATH)/%.o,$(APPLICATIONS_SRC))
APPLICATIONS_INC_PATH = -I$(APPLICATIONS_PATH)

IMU_PATH = ./Applications/imu_rev
IMU_SRC  = $(notdir $(wildcard $(IMU_PATH)/*.cpp))
IMU_OBJS = $(patsubst %.cpp,$(OBJPATH)/%.o,$(IMU_SRC))
IMU_INC_PATH = -I$(IMU_PATH)

ST_LK_PATH = ./Applications/st_lk
ST_LK_SRC  = $(notdir $(wildcard $(ST_LK_PATH)/*.cpp))
ST_LK_OBJS = $(patsubst %.cpp,$(OBJPATH)/%.o,$(ST_LK_SRC))
ST_LK_INC_PATH = -I$(ST_LK_PATH)

P_PATH = ./Applications/quaternion
P_SRC  = $(notdir $(wildcard $(P_PATH)/*.cpp))
P_OBJS = $(patsubst %.cpp,$(OBJPATH)/%.o,$(P_SRC))
P_INC_PATH = -I$(P_PATH)

#VO_MONO_PATH = ./Applications/vo_mono
#VO_MONO_SRC  = $(notdir $(wildcard $(VO_MONO_PATH)/*.cpp))
#VO_MONO_OBJS = $(patsubst %.cpp,$(OBJPATH)/%.o,$(VO_MONO_SRC))
#VO_MONO_INC_PATH = -I$(VO_MONO_PATH)

#WK_SLAM_PATH = ./Applications/wk_slam
#WK_SLAM_SRC  = $(notdir $(wildcard $(WK_SLAM_PATH)/*.cpp))
#WK_SLAM_OBJS = $(patsubst %.cpp,$(OBJPATH)/%.o,$(WK_SLAM_SRC))
#WK_SLAM_INC_PATH = -I$(WK_SLAM_PATH)

VINS_CMS_PATH = ./Applications/vins_mono/camera_model/src
VINS_CMS_SRC  = $(notdir $(wildcard $(VINS_CMS_PATH)/*.cpp))
VINS_CMS_OBJS = $(patsubst %.cpp,$(OBJPATH)/%.o,$(VINS_CMS_SRC))
VINS_CMS_INC_PATH = -I$(VINS_CMS_PATH)

VINS_CALIB_PATH = ./Applications/vins_mono/camera_model/src/calib
VINS_CALIB_SRC  = $(notdir $(wildcard $(VINS_CALIB_PATH)/*.cpp))
VINS_CALIB_OBJS = $(patsubst %.cpp,$(OBJPATH)/%.o,$(VINS_CALIB_SRC))
VINS_CALIB_INC_PATH = -I$(VINS_CALIB_PATH)

VINS_CM_PATH = ./Applications/vins_mono/camera_model/src/camera_models
VINS_CM_SRC  = $(notdir $(wildcard $(VINS_CM_PATH)/*.cpp))
VINS_CM_OBJS = $(patsubst %.cpp,$(OBJPATH)/%.o,$(VINS_CM_SRC))
VINS_CM_INC_PATH = -I$(VINS_CM_PATH)

VINS_CB_PATH = ./Applications/vins_mono/camera_model/src/chessboard
VINS_CB_SRC  = $(notdir $(wildcard $(VINS_CB_PATH)/*.cpp))
VINS_CB_OBJS = $(patsubst %.cpp,$(OBJPATH)/%.o,$(VINS_CB_SRC))
VINS_CB_INC_PATH = -I$(VINS_CB_PATH)

VINS_GPL_PATH = ./Applications/vins_mono/camera_model/src/gpl
VINS_GPL_SRC  = $(notdir $(wildcard $(VINS_GPL_PATH)/*.cpp))
VINS_GPL_OBJS = $(patsubst %.cpp,$(OBJPATH)/%.o,$(VINS_GPL_SRC))
VINS_GPL_INC_PATH = -I$(VINS_GPL_PATH)

VINS_SG_PATH = ./Applications/vins_mono/camera_model/src/sparse_graph
VINS_SG_SRC  = $(notdir $(wildcard $(VINS_SG_PATH)/*.cpp))
VINS_SG_OBJS = $(patsubst %.cpp,$(OBJPATH)/%.o,$(VINS_SG_SRC))
VINS_SG_INC_PATH = -I$(VINS_SG_PATH)

VINS_VES_PATH = ./Applications/vins_mono/vins_estimator/src
VINS_VES_SRC  = $(notdir $(wildcard $(VINS_VES_PATH)/*.cpp))
VINS_VES_OBJS = $(patsubst %.cpp,$(OBJPATH)/%.o,$(VINS_VES_SRC))
VINS_VES_INC_PATH = -I$(VINS_VES_PATH)

VINS_VESF_PATH = ./Applications/vins_mono/vins_estimator/src/factor
VINS_VESF_SRC  = $(notdir $(wildcard $(VINS_VESF_PATH)/*.cpp))
VINS_VESF_OBJS = $(patsubst %.cpp,$(OBJPATH)/%.o,$(VINS_VESF_SRC))
VINS_VESF_INC_PATH = -I$(VINS_VESF_PATH)

VINS_VESFT_PATH = ./Applications/vins_mono/vins_estimator/src/feature_tracker
VINS_VESFT_SRC  = $(notdir $(wildcard $(VINS_VESFT_PATH)/*.cpp))
VINS_VESFT_OBJS = $(patsubst %.cpp,$(OBJPATH)/%.o,$(VINS_VESFT_SRC))
VINS_VESFT_INC_PATH = -I$(VINS_VESFT_PATH)

VINS_VESI_PATH = ./Applications/vins_mono/vins_estimator/src/initial
VINS_VESI_SRC  = $(notdir $(wildcard $(VINS_VESI_PATH)/*.cpp))
VINS_VESI_OBJS = $(patsubst %.cpp,$(OBJPATH)/%.o,$(VINS_VESI_SRC))
VINS_VESI_INC_PATH = -I$(VINS_VESI_PATH)

VINS_VESLC_PATH = ./Applications/vins_mono/vins_estimator/src/loop-closure
VINS_VESLC_SRC  = $(notdir $(wildcard $(VINS_VESLC_PATH)/*.cpp))
VINS_VESLC_OBJS = $(patsubst %.cpp,$(OBJPATH)/%.o,$(VINS_VESLC_SRC))
VINS_VESLC_INC_PATH = -I$(VINS_VESLC_PATH)

VINS_VESLCT_PATH = ./Applications/vins_mono/vins_estimator/src/loop-closure/ThirdParty
VINS_VESLCT_SRC  = $(notdir $(wildcard $(VINS_VESLCT_PATH)/*.cpp))
VINS_VESLCT_OBJS = $(patsubst %.cpp,$(OBJPATH)/%.o,$(VINS_VESLCT_SRC))
VINS_VESLCT_INC_PATH = -I$(VINS_VESLCT_PATH)

VINS_VESLCTD_PATH = ./Applications/vins_mono/vins_estimator/src/loop-closure/ThirdParty/DBoW
VINS_VESLCTD_SRC  = $(notdir $(wildcard $(VINS_VESLCTD_PATH)/*.cpp))
VINS_VESLCTD_OBJS = $(patsubst %.cpp,$(OBJPATH)/%.o,$(VINS_VESLCTD_SRC))
VINS_VESLCTD_INC_PATH = -I$(VINS_VESLCTD_PATH)

VINS_VESLCTU_PATH = ./Applications/vins_mono/vins_estimator/src/loop-closure/ThirdParty/DUtils
VINS_VESLCTU_SRC  = $(notdir $(wildcard $(VINS_VESLCTU_PATH)/*.cpp))
VINS_VESLCTU_OBJS = $(patsubst %.cpp,$(OBJPATH)/%.o,$(VINS_VESLCTU_SRC))
VINS_VESLCTU_INC_PATH = -I$(VINS_VESLCTU_PATH)

VINS_VESLCTV_PATH = ./Applications/vins_mono/vins_estimator/src/loop-closure/ThirdParty/DVision
VINS_VESLCTV_SRC  = $(notdir $(wildcard $(VINS_VESLCTV_PATH)/*.cpp))
VINS_VESLCTV_OBJS = $(patsubst %.cpp,$(OBJPATH)/%.o,$(VINS_VESLCTV_SRC))
VINS_VESLCTV_INC_PATH = -I$(VINS_VESLCTV_PATH)

VINS_VESU_PATH = ./Applications/vins_mono/vins_estimator/src/utility
VINS_VESU_SRC  = $(notdir $(wildcard $(VINS_VESU_PATH)/*.cpp))
VINS_VESU_OBJS = $(patsubst %.cpp,$(OBJPATH)/%.o,$(VINS_VESU_SRC))
VINS_VESU_INC_PATH = -I$(VINS_VESU_PATH)

################# drivers src #################
DRIVERS_PATH = ./Drivers
DRIVERS_SRC  = $(notdir $(wildcard $(DRIVERS_PATH)/*.cpp))
DRIVERS_OBJS = $(patsubst %.cpp,$(OBJPATH)/%.o,$(DRIVERS_SRC))
DRIVERS_INC_PATH = -I$(DRIVERS_PATH)

################# utils src #################
UTILS_PATH = ./Utils
UTILS_SRC  = $(notdir $(wildcard $(UTILS_PATH)/*.cpp))
UTILS_OBJS = $(patsubst %.cpp,$(OBJPATH)/%.o,$(UTILS_SRC))
UTILS_INC_PATH = -I$(UTILS_PATH)

UTILS_C_PATH = ./Utils_C
UTILS_SRC_C  = $(notdir $(wildcard $(UTILS_C_PATH)/*.c))
UTILS_OBJS_C = $(patsubst %.c,$(OBJPATH)/%.o,$(UTILS_SRC_C))
UTILS_C_INC_PATH = -I$(UTILS_C_PATH)

################# git info shell #################
GIT_INFO_PATH = ./Applications/git_info
GIT_INFO_SHELL_PATH = $(GIT_INFO_PATH)/git_info.sh
GIT_INFO_INC_PATH = $(GIT_INFO_PATH)/git_info.h
GIT_INFO_DEPEND = gitinfo

CUR_INC_PATH = -I./
########################################################################
CONFIG = $(APPLICATIONS_INC_PATH) $(DRIVERS_INC_PATH) $(RTSP_INC_PATH) $(UTILS_INC_PATH) $(UTILS_C_INC_PATH) $(ST_LK_INC_PATH) $(IMU_INC_PATH) $(P_INC_PATH) $(VINS_CMS_INC_PATH) $(VINS_CALIB_INC_PATH) $(VINS_CM_INC_PATH) $(VINS_CB_INC_PATH) $(VINS_GPL_INC_PATH) $(VINS_SG_INC_PATH) $(VINS_VES_INC_PATH) $(VINS_VESF_INC_PATH) $(VINS_VESFT_INC_PATH) $(VINS_VESI_INC_PATH) $(VINS_VESLC_INC_PATH) $(VINS_VESLCTV_INC_PATH) $(VINS_VESLCTU_INC_PATH) $(VINS_VESLCTD_INC_PATH) $(VINS_VESLCT_INC_PATH) $(VINS_VESU_INC_PATH)
CONFIG += $(MAVLINK_INC) $(HI_SDK_INC) $(THIRD_INC) $(OPENCV_INC) $(MOSQU_INC)
LIBS  = $(RTSP_LIBS) $(SQLITE_LIB) $(HISI_SDK_LIB) $(OPENCV_LIB) $(ceres_LIB) $(BOOST_LIB) $(MOSQU_LIB)
LIBS  += -fno-aggressive-loop-optimizations -Wall -W -fPIC -lm -pthread -ldl -std=c++11 -lrt

################# debug src #################
CONFIG += -DDEBUG_ST_LK_POINTS_PREVIEW     # 关闭：光流图像直接送流；打开：则需要调用wk_frame_pionts_venc_debug接口送流
#CONFIG += -DDEBUG_SAVE_IMU_FRAME          # 关闭：关闭imu和图像保存功能；打开：打开imu和图像保存功能

all: $(MKDIR_DEPEND) $(GIT_INFO_DEPEND) $(ELF)
	$(PRINTF_GREEN) "Compile $(ELF) complete"

$(MKDIR_DEPEND):
	mkdir -p $(ELFPATH)
	mkdir -p $(OBJPATH)

$(GIT_INFO_DEPEND):
	chmod a+x $(GIT_INFO_SHELL_PATH)
	$(GIT_INFO_SHELL_PATH)
	$(PRINTF_GREEN) "Generate $(GIT_INFO_INC_PATH)"

$(ELF):$(APPLICATIONS_OBJS) $(DRIVERS_OBJS) $(UTILS_OBJS) $(RTSP_OBJS) $(UTILS_OBJS_C) $(ST_LK_OBJS) $(IMU_OBJS) $(P_OBJS) $(VINS_CMS_OBJS) $(VINS_CALIB_OBJS) $(VINS_CM_OBJS) $(VINS_CB_OBJS) $(VINS_GPL_OBJS) $(VINS_SG_OBJS) $(VINS_VES_OBJS) $(VINS_VESF_OBJS) $(VINS_VESFT_OBJS) $(VINS_VESI_OBJS) $(VINS_VESLC_OBJS) $(VINS_VESLCTV_OBJS) $(VINS_VESLCTU_OBJS) $(VINS_VESLCTD_OBJS) $(VINS_VESLCT_OBJS) $(VINS_VESU_OBJS)
	$(COMPILE_CPP) -o $@ $^ $(LIBS)


################# .cpp ---> .o #################
$(OBJPATH)/%.o:$(APPLICATIONS_PATH)/%.cpp
	$(COMPILE_CPP) -c $< -o $@ $(CONFIG) -Os

$(OBJPATH)/%.o:$(IMU_PATH)/%.cpp
	$(COMPILE_CPP) -c $< -o $@ $(CONFIG) -Os

$(OBJPATH)/%.o:$(ST_LK_PATH)/%.cpp
	$(COMPILE_CPP) -c $< -o $@ $(CONFIG) -Os

$(OBJPATH)/%.o:$(P_PATH)/%.cpp
	$(COMPILE_CPP) -c $< -o $@ $(CONFIG) -Os
	
#$(OBJPATH)/%.o:$(VO_MONO_PATH)/%.cpp
#	$(COMPILE_CPP) -c $< -o $@ $(CONFIG) -Os

#$(OBJPATH)/%.o:$(WK_SLAM_PATH)/%.cpp
#	$(COMPILE_CPP) -c $< -o $@ $(CONFIG) -Os

$(OBJPATH)/%.o:$(VINS_CMS_PATH)/%.cpp
	$(COMPILE_CPP) -c $< -o $@ $(CONFIG) -Os
	
$(OBJPATH)/%.o:$(VINS_CALIB_PATH)/%.cpp
	$(COMPILE_CPP) -c $< -o $@ $(CONFIG) -Os

$(OBJPATH)/%.o:$(VINS_CM_PATH)/%.cpp
	$(COMPILE_CPP) -c $< -o $@ $(CONFIG) -Os

$(OBJPATH)/%.o:$(VINS_CB_PATH)/%.cpp
	$(COMPILE_CPP) -c $< -o $@ $(CONFIG) -Os

$(OBJPATH)/%.o:$(VINS_GPL_PATH)/%.cpp
	$(COMPILE_CPP) -c $< -o $@ $(CONFIG) -Os

$(OBJPATH)/%.o:$(VINS_SG_PATH)/%.cpp
	$(COMPILE_CPP) -c $< -o $@ $(CONFIG) -Os

$(OBJPATH)/%.o:$(VINS_VES_PATH)/%.cpp
	$(COMPILE_CPP) -c $< -o $@ $(CONFIG) -Os

$(OBJPATH)/%.o:$(VINS_VESF_PATH)/%.cpp
	$(COMPILE_CPP) -c $< -o $@ $(CONFIG) -Os

$(OBJPATH)/%.o:$(VINS_VESFT_PATH)/%.cpp
	$(COMPILE_CPP) -c $< -o $@ $(CONFIG) -Os

$(OBJPATH)/%.o:$(VINS_VESI_PATH)/%.cpp
	$(COMPILE_CPP) -c $< -o $@ $(CONFIG) -Os

$(OBJPATH)/%.o:$(VINS_VESLC_PATH)/%.cpp
	$(COMPILE_CPP) -c $< -o $@ $(CONFIG) -Os

$(OBJPATH)/%.o:$(VINS_VESLCT_PATH)/%.cpp
	$(COMPILE_CPP) -c $< -o $@ $(CONFIG) -Os

$(OBJPATH)/%.o:$(VINS_VESLCTD_PATH)/%.cpp
	$(COMPILE_CPP) -c $< -o $@ $(CONFIG) -Os

$(OBJPATH)/%.o:$(VINS_VESLCTU_PATH)/%.cpp
	$(COMPILE_CPP) -c $< -o $@ $(CONFIG) -Os

$(OBJPATH)/%.o:$(VINS_VESLCTV_PATH)/%.cpp
	$(COMPILE_CPP) -c $< -o $@ $(CONFIG) -Os

$(OBJPATH)/%.o:$(VINS_VESU_PATH)/%.cpp
	$(COMPILE_CPP) -c $< -o $@ $(CONFIG) -Os											

$(OBJPATH)/%.o:$(UTILS_C_PATH)/%.c
	$(COMPILE_CC) -c $< -o $@ $(CONFIG) -Os

$(OBJPATH)/%.o:$(DRIVERS_PATH)/%.cpp
	$(COMPILE_CPP) -c $< -o $@ $(CONFIG) -Os

$(OBJPATH)/%.o:$(UTILS_PATH)/%.cpp
	$(COMPILE_CPP) -c $< -o $@ $(CONFIG) -Os

$(OBJPATH)/%.o:$(RTSP_SRC_PATH1)/%.cpp
	$(COMPILE_CPP) -c $< -o $@ $(RTSP_INC_PATH) -Os

$(OBJPATH)/%.o:$(RTSP_SRC_PATH2)/%.cpp
	$(COMPILE_CPP) -c $< -o $@ $(RTSP_INC_PATH) -Os

clean:
	rm $(OBJPATH)/*.o $(ELF) $(GIT_INFO_INC_PATH)

