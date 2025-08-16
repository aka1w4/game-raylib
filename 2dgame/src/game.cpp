#include <raylib.h>
#include "game.hpp"

Game::Game(float x, float y, Texture2D img[3]) {
    player = std::make_unique<Player>(x, y, img);
}

void Game::Update() {
    player->Update();

    if (IsKeyPressed(KEY_F4)) {
      ToggleFullscreen();
    }
}

void Game::Draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    player->Draw();
    EndDrawing();
}
