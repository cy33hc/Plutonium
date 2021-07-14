
#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <pu/sdl2/ttf_SDL_ttf.h>

#define CTRL_TRIANGLE   0
#define CTRL_CIRCLE     1
#define CTRL_CROSS      2
#define CTRL_SQUARE     3
#define CTRL_L1         4
#define CTRL_R1         5
#define CTRL_DOWN       6
#define CTRL_LEFT       7
#define CTRL_UP         8
#define CTRL_RIGHT      9
#define CTRL_SELECT     10
#define CTRL_START      11
#define CTRL_L2         12
#define CTRL_R2         13
#define CTRL_L3         14
#define CTRL_R3         15

namespace pu::sdl2
{
    using Texture = SDL_Texture*;
    using Window = SDL_Window*;
    using Renderer = SDL_Renderer*;
    using Font = TTF_Font*;
    using Surface = SDL_Surface*;
    using Controller = SDL_GameController*;
    using Joystick = SDL_Joystick*;
}