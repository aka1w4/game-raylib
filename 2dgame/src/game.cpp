#include <raylib.h>
#include "game.hpp"

Game::Game() {
    player = std::make_unique<Player>();
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
