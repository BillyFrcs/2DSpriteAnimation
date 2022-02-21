#include "Game.hpp"

Billy::Game::Game() : _window(),
                      Animation_Object(),
                      _FPSGame()
{
     this->_FPSGame = new int(60);

     // Initialize
     this->_window = new raylib::Window(Screen::SCREEN_WIDTH, Screen::SCREEN_HEIGHT, "2D Sprite Animation", false);

     // Target FPS
     SetTargetFPS(*this->_FPSGame);

     // Constructor classes
     this->Animation_Object = new Animation();
}

Billy::Game::~Game()
{
     delete (_window);
     delete (Animation_Object);

     free(GameLoop());
     free(Run());
}

void *Billy::Game::GameLoop()
{
     // Initialize
     this->Animation_Object->InitPlayerAnimation();

     // Game loop
     while (!this->_window->ShouldClose()) // Press ESC to exit
     {
          // Update
          this->Animation_Object->PlayerController();

          this->Animation_Object->Collision();

          // Draw
          BeginDrawing();

          ClearBackground(RAYWHITE);

          this->Animation_Object->Draw();

          EndDrawing();
     }
}

void *Billy::Game::Run()
{
     this->GameLoop();
}