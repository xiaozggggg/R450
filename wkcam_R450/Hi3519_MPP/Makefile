RM := rm
CP := cp
HOME := 'pwd'
CC := aarch64-v01c01-linux-gnu-gcc -fPIC
AR := aarch64-v01c01-linux-gnu-ar
CFLAGS := -g -fstack-protector -fPIC 
CFLAGS := -fPIC -g  -fsigned-char -mcpu=cortex-a53 -fno-aggressive-loop-optimizations -ldl -ffunction-sections -fdata-sections  -fstack-protector-strong -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -DUSER_BIT_64 -DKERNEL_BIT_64 -Wno-date-time
LDFLAGS := -shared -g -fno-common -mcpu=cortex-a53 -fno-aggressive-loop-optimizations -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -ldl -rdynamic -shared -fPIC -DUSER_BIT_64 -DKERNEL_BIT_64 -Wno-date-time
TARG := lib/libwkmpp.so

#CFLAGS += -DHNR_SCENE_AUTO_USED
#============================================================= 

INCS := -Isrc -Isrc -Iinc -Iinc/hisisdk -Iinc/common -Iinc/scene_auto -Iinc/libexif

#SRCS := $(shell ls src/*.c)
SUBDIRS=$(shell find ./src -maxdepth 7 -type d)
SRCS:=$(foreach dir,$(SUBDIRS),$(wildcard $(dir)/*.c))

#mppex;
#SUBDIRS_EX=$(shell find ./mppex/ -maxdepth 7 -type d)
#SRCS_EX:=$(foreach dir,$(SUBDIRS_EX),$(wildcard $(dir)/*.c))
#OBJS_EX:= $(patsubst %.c, %.o, $(SRCS_EX))
#TARG_EX:= lib/libmppex.a

OBJS := $(patsubst %.c, %.o, $(SRCS))
LIBS += 
DEP_OBJS := OBJS
DEP_LIBS += libexif.a
#DEP_LIBS += libmppex.a
#DEP_LIBS += libguide.a

$(TARG): $(OBJS) $(TARG_EX)
	$(RM) lib/$(DEP_OBJS) -rf
	$(foreach a, $(DEP_LIBS), cd lib; $(AR) -t $(a) | sed 's/^/lib\//' >> $(DEP_OBJS); $(AR) x $(a); cd ..;)
	${CC} ${LDFLAGS} -o $@ ${OBJS} 
# 	`cat lib/$(DEP_OBJS)` ${LIBS}
# 	rm -rf `cat lib/$(DEP_OBJS)`; 
# 	rm -rf lib/$(DEP_OBJS);
#	cp $(TARG) ../../../tftp_file

#$(TARG_EX): $(OBJS_EX)
#	${AR} -rcs $@ ${OBJS_EX}

.c.o:
	$(CC) $(CFLAGS) -c $< $(INCS) -o $@

.Phony: clean
clean:
	-rm $(TARG) $(OBJS) $(OBJS_EX) -rf
