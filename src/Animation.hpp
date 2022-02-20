#pragma once

#ifndef ANIMATION_H
#define ANIMATION_H

#include <raylib-cpp.hpp>

#include "raylib.h"

#include "Game.hpp"

namespace Billy
{
     class Animation
     {
     public:
          Animation();
          ~Animation();

     public:
          void InitTexturePlayer();
          void WalkAnimation();
          void CheerAnimation();
          void UpdateAnimation();
          void UpdatePlayer();
          void UpdateCollision();
          void Draw();

     public:
          Texture2D *GetPlayerTexture();
          Vector2 *GetPlayerPosition();
          Rectangle *GetPlayerRectangle();

     private:
          Texture2D *_playerTexture;
          Vector2 *_playerPosition;
          Rectangle *_playerFrameRectangle;
          Font *_font;

     private:
          float _frameSpeed;
          float _currentFrame;
          float _frameCounter;

          int _FPSGame;

          bool _isWalk;
          bool _isCollision;

          float *_collision;
          float *_position;

          // Jump player
          float _jumpSpeed;
          bool _isJump;
     };
}

#endif // ANIMATION_H