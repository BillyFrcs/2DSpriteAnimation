#include "Animation.hpp"

#include <iostream>

constexpr auto PLAYER_SHEET = "Assets/Character/FemaleAdventure/Tilesheet/character_femaleAdventurer_sheetHD.png";
constexpr auto FONT = "Assets/Fonts/cocogoose.ttf";

static constexpr auto MAX_FRAME_SPEED = 20;
static constexpr auto MIN_FRAME_SPEED = 1;
static constexpr auto PLAYER_JUMP_SPEED = 200.0f;

Billy::Animation::Animation() : _playerTexture(),
                                _playerPosition(),
                                _playerFrameRectangle(),
                                _font(),
                                _frameSpeed(),
                                _currentFrame(),
                                _frameCounter(),
                                _FPSGame(),
                                _isWalk(),
                                _isCollision(),
                                _collision(),
                                _position()
{
     // Animation frames
     this->_frameSpeed = 8.0f;
     this->_currentFrame = 0.0f;
     this->_frameCounter = 0.0f;

     this->_FPSGame = 60; // FPS game animations

     this->_isWalk = true;
     this->_isCollision = false;

     // Collision
     this->_collision = new float(0.0f);
     this->_position = new float(0.0f);

     // Jump player
     this->_jumpSpeed = 5.0f;
     this->_isJump = false;

     // Raylib constructor classes
     this->_playerTexture = new Texture2D();
     this->_playerPosition = new Vector2();
     this->_playerFrameRectangle = new Rectangle();
     this->_font = new Font();
}

Billy::Animation::~Animation()
{
}

void Billy::Animation::InitTexturePlayer()
{
     // Load texture
     *this->_playerTexture = LoadTexture(PLAYER_SHEET);

     static float xPosition = 300.0f;
     static float yPosition = 100.0f;

     *this->_playerPosition = {xPosition, yPosition};

     // Player walk frames animation
     *this->_playerFrameRectangle = {0.0f, 1025, static_cast<float>(this->_playerTexture->width) / 9, static_cast<float>(this->_playerTexture->height) / 4.7f};

     // Load font
     *this->_font = LoadFont(FONT);
}

void Billy::Animation::CheerAnimation()
{
     this->_frameCounter++;

     if (this->_frameCounter >= (this->_FPSGame / this->_frameSpeed))
     {
          this->_frameCounter = 0;

          this->_currentFrame++;

          if (this->_currentFrame > 7)
          {
               this->_currentFrame = 0;
          }

          this->GetPlayerRectangle()->x = (this->_currentFrame * this->GetPlayerTexture()->width) / 9;
     }

     if (IsKeyPressed(KEY_RIGHT))
     {
          this->_frameSpeed++;
     }
     else if (IsKeyPressed(KEY_LEFT))
     {
          this->_frameSpeed--;
     }

     if (this->_frameSpeed > MAX_FRAME_SPEED)
     {
          this->_frameSpeed = MAX_FRAME_SPEED;
     }
     else if (this->_frameSpeed < MIN_FRAME_SPEED)
     {
          this->_frameSpeed = MIN_FRAME_SPEED;
     }
}

void Billy::Animation::WalkAnimation()
{
     this->_frameCounter++;

     if (this->_frameCounter >= (this->_FPSGame / this->_frameSpeed))
     {
          this->_frameCounter = 0;

          this->_currentFrame++;

          if (this->_currentFrame > 7)
          {
               this->_currentFrame = 0;
          }

          this->GetPlayerRectangle()->x = (this->_currentFrame * this->GetPlayerTexture()->width) / 9;
     }

     if (IsKeyPressed(KEY_RIGHT))
     {
          this->_frameSpeed++;
     }
     else if (IsKeyPressed(KEY_LEFT))
     {
          this->_frameSpeed--;
     }

     if (this->_frameSpeed > MAX_FRAME_SPEED)
     {
          this->_frameSpeed = MAX_FRAME_SPEED;
     }
     else if (this->_frameSpeed < MIN_FRAME_SPEED)
     {
          this->_frameSpeed = MIN_FRAME_SPEED;
     }
}

void Billy::Animation::UpdateAnimation()
{
     this->CheerAnimation();

     // Movement with keyboard input
     if (this->_isWalk)
     {
          if (IsKeyDown(KEY_W))
          {
               this->_playerPosition->y -= this->_frameSpeed;

               this->WalkAnimation();
          }

          if (IsKeyDown(KEY_S))
          {
               this->_playerPosition->y += this->_frameSpeed;

               this->WalkAnimation();
          }

          if (IsKeyDown(KEY_A))
          {
               this->_playerPosition->x -= this->_frameSpeed;

               this->WalkAnimation();
          }

          if (IsKeyDown(KEY_D))
          {
               this->_playerPosition->x += this->_frameSpeed;

               this->WalkAnimation();
          }
     }

     // Movement with mouse gesture
     /*
     if (this->_isWalk)
     {
          *this->_playerPosition = GetMousePosition();

          this->WalkAnimation();
     }
     */
}

void Billy::Animation::UpdatePlayer()
{
     // Player jump
     if (IsKeyDown(KEY_SPACE))
     {
          this->_isJump = true;
     }

     if (this->_isJump)
     {
          this->_jumpSpeed += 1.0f;

          if (this->_jumpSpeed < 80.0f)
          {
               this->_playerPosition->y -= 3.0f;
          }
          else
          {
               this->_playerPosition->y += 3.0f;
          }
     }

     if (this->_jumpSpeed >= 150)
     {
          this->_jumpSpeed = 0.0f;

          this->_isJump = false;
     }
}

void Billy::Animation::UpdateCollision()
{
     // Left window collision
     if (this->GetPlayerPosition()->x < *this->_collision)
     {
          this->_isCollision = true;

          if (this->_isCollision)
          {
               this->GetPlayerPosition()->x = *this->_position;
          }
     }

     // Window right screen collision
     if (this->GetPlayerPosition()->x > Screen::SCREEN_WIDTH)
     {
          this->_isCollision = true;

          if (this->_isCollision)
          {
               this->GetPlayerPosition()->x = *this->_position;
          }
     }

     // Top window collision
     if (this->GetPlayerPosition()->y < *this->_collision)
     {
          this->_isCollision = true;

          if (this->_isCollision)
          {
               this->GetPlayerPosition()->y = *this->_position;
          }
     }

     // Window bottom screen collision
     if (this->GetPlayerPosition()->y > Screen::SCREEN_HEIGHT)
     {
          this->_isCollision = true;

          if (this->_isCollision)
          {
               this->GetPlayerPosition()->y = *this->_position;
          }
     }
}

void Billy::Animation::Draw()
{
     DrawTextEx(*this->_font, "FRAME SPEED:", {5, 5}, 25, 1, DARKGRAY);

     DrawText("PRESS RIGHT/LEFT KEYS to CHANGE SPEED!", 230, 40, 10, DARKGRAY);

     for (uint32_t animation = 0; animation < MAX_FRAME_SPEED; animation++)
     {
          if (animation < this->_frameSpeed)
          {
               DrawRectangle(160 + 21 * animation, 5, 20, 20, BLUE);
          }

          DrawRectangleLines(160 + 21 * animation, 5, 20, 20, BLUE);
     }

     DrawTextureRec(*this->GetPlayerTexture(), *this->GetPlayerRectangle(), *this->GetPlayerPosition(), WHITE);
}

Texture2D *Billy::Animation::GetPlayerTexture()
{
     return this->_playerTexture;
}

Vector2 *Billy::Animation::GetPlayerPosition()
{
     return this->_playerPosition;
}

Rectangle *Billy::Animation::GetPlayerRectangle()
{
     return this->_playerFrameRectangle;
}