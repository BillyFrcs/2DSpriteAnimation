#pragma once

#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <raylib-cpp.hpp>
#include <raylib.h>

#include <iostream>

#include "Game.hpp"

namespace Billy
{
     class Animation
     {
     public:
          Animation();
          ~Animation();

     public:
          void InitPlayerAnimation();
          void WalkAnimation();
          void CheerAnimation();
          void *PlayerMovement();
          void *PlayerJump();
          void *PlayerController();
          void Collision();
          void DrawSprite();
          void DrawRectangleFrame();
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