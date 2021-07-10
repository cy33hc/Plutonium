TARGET		:= libpu

LIBS = -lvita2d -lc -lSceCommonDialog_stub -lSceLibKernel_stub \
	-lSceDisplay_stub -lSceGxm_stub -lSceSysmodule_stub -lSceCtrl_stub \
	-lSceTouch_stub -lm -lSceAppMgr_stub -lSceAppUtil_stub  -lSceShaccCg_stub

CPPSOURCES	:= Source Source/pu Source/pu/audio Source/pu/ui Source/pu/ttf Source/pu/ui/elm Source/pu/ui/extras Source/pu/ui/render Source/pu/web
CSOURCES := Source/pu/sdl2
ASMSOURCES := .
INCLUDES        := Include
ASMFILES	:= $(foreach dir,$(ASMSOURCES), $(wildcard $(dir)/*.S))
CPPFILES   := $(foreach dir,$(CPPSOURCES), $(wildcard $(dir)/*.cpp))
CFILES := $(foreach dir,$(CSOURCES), $(wildcard $(dir)/*.c))
BINFILES := $(foreach dir,$(DATA), $(wildcard $(dir)/*.bin))
OBJS     := $(addsuffix .o,$(BINFILES)) $(ASMFILES:.S=.o) $(CFILES:.c=.o) $(CPPFILES:.cpp=.o)

PREFIX  = arm-vita-eabi
CC      = $(PREFIX)-gcc
CXX      = $(PREFIX)-g++
CFLAGS  = -IInclude -I/usr/local/vitasdk/arm-vita-eabi/include/freetype2 -Wl,-q -O2 -g -mtune=cortex-a9 -mfpu=neon -ftree-vectorize
CXXFLAGS  = $(CFLAGS) -fno-exceptions -std=gnu++17
ASFLAGS = $(CFLAGS)
AR      = $(PREFIX)-gcc-ar

all: $(TARGET).a

$(TARGET).a: $(OBJS)
	$(AR) -rc $@ $^

install: $(TARGET).a
	@mkdir -p $(VITASDK)/$(PREFIX)/lib/
	cp $(TARGET).a $(VITASDK)/$(PREFIX)/lib/
	@mkdir -p $(VITASDK)/$(PREFIX)/include
	cp -R Include/* $(VITASDK)/$(PREFIX)/include

clean:
	@rm -rf $(TARGET).a $(TARGET).elf $(OBJS)
