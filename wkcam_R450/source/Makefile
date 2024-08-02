
ELFPATH=./bin
OBJPATH=./obj

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

############ mavlink ############
MAVLINK_INC = -I../include/mavlink/ -I../include/mavlink/walkera 

############ hisisdk ############
HISI_SDK_LIB = -L ../Hi3519_MPP/lib -lwkmpp
HISI_SDK_LIB += -L ../Hi3519_MPP/lib/hisisdk -lss_mpi -lss_mpi_sysbind -lss_mpi_sysmem -laiisp -lss_mpi_ae -lss_mpi_isp -lot_mpi_isp -lss_mpi_awb\
				  -lss_mpi_aibnr -lss_mpi_aidrc -lsvp_acl -lsecurec -ldehaze -lextend_stats -ldrc -l ldci -lbnr -lcalcflicker -lir_auto -lacs\
				 -laac_comm -laac_enc -laac_dec -laac_sbr_enc -laac_sbr_dec -lprotobuf-c -lss_mpi_dpu_match -lss_mpi_dpu_rect -lss_mpi_mcf  -lss_mpi_ai3dnr\
				 -lheif -lfileformat -lot_mpi_km -lss_mpi_thermo -lss_mpi_ive

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

################# applications src #################
APPLICATIONS_PATH = ./Applications
APPLICATIONS_SRC  = $(notdir $(wildcard $(APPLICATIONS_PATH)/*.cpp))
APPLICATIONS_OBJS = $(patsubst %.cpp,$(OBJPATH)/%.o,$(APPLICATIONS_SRC))
APPLICATIONS_INC_PATH = -I$(APPLICATIONS_PATH)

ST_LK_PATH = ./Applications/st_lk
ST_LK_SRC  = $(notdir $(wildcard $(ST_LK_PATH)/*.cpp))
ST_LK_OBJS = $(patsubst %.cpp,$(OBJPATH)/%.o,$(ST_LK_SRC))
ST_LK_INC_PATH = -I$(ST_LK_PATH)

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

CUR_INC_PATH = -I./
########################################################################
CONFIG = $(APPLICATIONS_INC_PATH) $(DRIVERS_INC_PATH) $(RTSP_INC_PATH) $(UTILS_INC_PATH) $(UTILS_C_INC_PATH)
CONFIG += $(MAVLINK_INC) $(HI_SDK_INC) $(THIRD_INC)
LIBS  = $(RTSP_LIBS) $(SQLITE_LIB) $(HISI_SDK_LIB)
LIBS  += -fno-aggressive-loop-optimizations -Wall -W -fPIC -lm -pthread -ldl -std=c++11 -lrt

################# debug src #################
CONFIG += -DDEBUG_ST_LK_POINTS_PREVIEW

$(ELF):$(APPLICATIONS_OBJS) $(DRIVERS_OBJS) $(UTILS_OBJS) $(RTSP_OBJS) $(UTILS_OBJS_C) $(ST_LK_OBJS)
	$(COMPILE_CPP) -o $@ $^ $(LIBS)


################# .cpp ---> .o #################
$(OBJPATH)/%.o:$(APPLICATIONS_PATH)/%.cpp
	$(COMPILE_CPP) -c $< -o $@ $(CONFIG) -Os

$(OBJPATH)/%.o:$(ST_LK_PATH)/%.cpp
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
	rm $(OBJPATH)/*.o $(ELF)

