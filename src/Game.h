#pragma once

#ifndef GAME_H
#define GAME_H

#include <raylib-cpp.hpp>

#include "raylib.h"

#include "Animation.h"

class Animation;

typedef enum Screen
{
     SCREEN_WIDTH = 800,
     SCREEN_HEIGHT = 500,
} Screen;

namespace Billy
{
     class Game
     {
     public:
          Game();
          ~Game();

     public:
          void GameLoop();
          void RunGameAnimation();

     private:
          raylib::Window *_window;

          Animation *Animation_Object;

     private:
          int *_FPSGame;
     };
}

#endif // GAME_H