#include <iostream>
#include <raylib.h>
#include "game.hpp"

Game::Game() {
  player = std::make_unique<Player>();
  recgame = Rectangle{200, 200, 200, 300};
}

void Game::Update() {
  Rectangle oldPos = player->GetPlayer();

  player->Update();

  Rectangle newPos = player->GetPlayer();

  Rectangle recX = oldPos;
  recX.x = newPos.x;
  if (CheckCollisionRecs(recX, recgame)) {
    std::cout << "true ini x" << std::endl;
    newPos.x = oldPos.x;
  }

  Rectangle recY = oldPos;
  recY.y = newPos.y;
  if (CheckCollisionRecs(recY, recgame)) {
    std::cout << "true ini y" << std::endl;
    newPos.y = oldPos.y;
  }

  player->needpos(Vector2{newPos.x, newPos.y});

  if (IsKeyPressed(KEY_F4)) {
    ToggleFullscreen();
  }
}

void Game::Draw() {
  BeginDrawing();
  ClearBackground(RAYWHITE);
  DrawRectangleLinesEx(recgame, 3, BLACK);
  player->Draw();
  EndDrawing();
}
