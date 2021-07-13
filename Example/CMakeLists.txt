cmake_minimum_required(VERSION 2.8)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()

project(plutonium_example)
include("${VITASDK}/share/vita.cmake" REQUIRED)

set(VITA_APP_NAME "Plutonium Example")
set(VITA_TITLEID  "SMLA00003")
set(VITA_VERSION  "01.00")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu11")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-psabi -Wunused-variable -Wwrite-strings -fpermissive -std=c++17 -Wimplicit-fallthrough")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fpermissive")

include_directories(
  Include
)

add_executable(${PROJECT_NAME}
  Source/Main.cpp
  Source/MainApplication.cpp
)

target_link_libraries(${PROJECT_NAME}
  pu
  SDL2
  SDL2_mixer
  SDL2_gfx
  SDL2_ttf
  SDL2_image
  SDL2_net
  freetype
  mikmod
  mpg123
  FLAC
  vorbisfile
  vorbis
  ogg
  webp
  png
  jpeg
  stdc++
  pthread
  c
  z
  SceCommonDialog_stub
  SceLibKernel_stub
  SceDisplay_stub
  SceGxm_stub
  SceSysmodule_stub
  SceCtrl_stub
  SceTouch_stub
  SceMotion_stub
  SceAudio_stub
  SceHid_stub
  SceNet_stub
  SceNetCtl_stub
  SceHttp_stub
  SceSsl_stub
  ScePspnetAdhoc_stub
  ScePromoterUtil_stub
  SceShellSvc_stub
  m
  SceAppMgr_stub
  SceAppUtil_stub
  SceShaccCg_stub
)

vita_create_self(eboot.bin ${PROJECT_NAME} UNSAFE)
vita_create_vpk(${PROJECT_NAME}.vpk ${VITA_TITLEID} eboot.bin
  VERSION ${VITA_VERSION}
  NAME ${VITA_APP_NAME}
  FILE DejaVuSans.ttf DejaVuSans.ttf
)
