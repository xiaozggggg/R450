CONFIG_UCLIBC_BUILD=y

CROSS_COMPILE ?= mips-linux-gnu-

CC = $(CROSS_COMPILE)gcc
CPLUSPLUS = $(CROSS_COMPILE)g++
LD = $(CROSS_COMPILE)ld
AR = $(CROSS_COMPILE)ar cr
STRIP = $(CROSS_COMPILE)strip

CFLAGS = $(INCLUDES) -O2 -Wall -march=mips32r2

ifeq ($(CONFIG_UCLIBC_BUILD), y)
CFLAGS += -muclibc
LDFLAG += -muclibc
endif

ifeq ($(CONFIG_UCLIBC_BUILD), y)
SDK_LIB_DIR = ../lib/uclibc
else
SDK_LIB_DIR = ../lib/glibc
endif

# include paths
SDK_INC_DIR  = -I../inc/net
SDK_INC_DIR  = -I../inc/xop

# source objects
SOURCE_OBJS  = ./net/Acceptor.o
SOURCE_OBJS += ./net/BufferReader.o


INCLUDES = $(SDK_INC_DIR)

LIBS = $(SDK_LIB_DIR)/libimp.a $(SDK_LIB_DIR)/libalog.a

LDFLAG += -Wl,-gc-sections

SAMPLES = rtsp_srv.so \

all: 	$(SAMPLES)

mainApp: $(SDK_LIB_DIR)/libimp.a $(SDK_LIB_DIR)/libalog.a $(SOURCE_OBJS)
	$(CPLUSPLUS) $(LDFLAG) -shared -o $@ $^ $(LIBS) -lpthread -lm -lrt
	$(STRIP) $@

%.o:%.c imp_common_api.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f *.o *~ $(SAMPLES)
	rm -rf $(SOURCE_OBJS)

distclean: clean
	rm -f $(SAMPLES)
