#
# sensor lib Makefile
#
ifeq ($(PARAM_FILE), )
    PARAM_FILE:=../../../../../../../Makefile.param
    include $(PARAM_FILE)
endif


ifeq ($(CBB_PARAM_FILE), )
    CBB_PARAM_FILE:=../../../../../Makefile.param
    include $(CBB_PARAM_FILE)
endif

ISP_PATH := $(ISP_ROOT)
EXT_PATH := $(ISP_PATH)/ext_drv/$(OT_ARCH)
3A_PATH  := $(ISP_PATH)/user/3a
LIBPATH = ../../../lib
OBJPATH = $(TEMP_PATH)/$(subst $(SDK_PATH)/,,$(CURDIR))/obj

ARFLAGS = rcv
ARFLAGS_SO = $(LIBS_LD_CFLAGS)
ARFLAGS_SO += -shared -fPIC -o
CFLAGS  += -Wall -fPIC -D$(OT_FPGA)
CFLAGS  += -O2
CFLAGS  += $(LIBS_CFLAGS)

ifeq ($(ISP_INI_CONFIG), y)
CFLAGS += -D INIFILE_CONFIG_MODE
endif

ifeq ($(OT_GDB),OT_GDB)
CFLAGS += -g
endif

ifeq ($(CONFIG_JPEGEDCF), y)
     CFLAGS += -D ENABLE_JPEGEDCF
endif

ISP_INC := $(ISP_PATH)/include
CUR_INC := ./
3A_INC := $(3A_PATH)/include
INC := -I$(ISP_INC) -I$(CUR_INC) -I$(3A_INC) $(COMM_INC)
DEPEND_FILE := $(foreach file,$(subst -I, ,$(CUR_INC)), $(wildcard $(file)/*.h))

COMPILE = $(CC) $(CFLAGS) $(DFLAGS) -lm

$(OBJPATH)/%.o: ./%.c $(DEPEND_FILE)
	@[ -e $(LIBPATH) ] || mkdir -p $(LIBPATH)
	@[ -e $(OBJPATH) ] || mkdir -p $(OBJPATH)
	@$(COMPILE) -o $@ -c $< $(INC)

SRCS = $(wildcard ./*.c)
OBJS = $(SRCS:%.c=%.o)
OBJS := $(OBJS:./%=$(OBJPATH)/%)

LIB_NAME := libsns_ov7251
TARGETLIB := $(LIBPATH)/$(LIB_NAME).a
TARGETLIB_SO := $(LIBPATH)/$(LIB_NAME).so

all:$(TARGETLIB)
$(TARGETLIB):$(OBJS)
	@($(AR) $(ARFLAGS) $(TARGETLIB) $(OBJS))
	@($(CC) $(ARFLAGS_SO) $(TARGETLIB_SO) $(OBJS))
	@mkdir -p $(REL_LIB)
	@cp $(TARGETLIB_SO) $(REL_LIB)
	@cp $(TARGETLIB) $(REL_LIB)
clean:
	@$(RM) -rf $(TARGETLIB) $(OBJS)
	@$(RM) -rf $(LIBPATH) $(OBJPATH)
	@$(RM) -rf $(REL_LIB)/$(LIB_NAME).a
	@$(RM) -rf $(REL_LIB)/$(LIB_NAME).so
aa:
	echo "$(INC)"
