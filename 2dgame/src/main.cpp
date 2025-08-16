#include <raylib.h>
#include "game.hpp"

int main() {
    InitWindow(800, 450, "Kepingan Yang Hilang");
    SetTargetFPS(60);

    Texture2D imgs[3];
    imgs[0] = LoadTexture("assets/female_idle.png");
    imgs[1] = LoadTexture("assets/female_walking.png");
    imgs[2] = LoadTexture("assets/female_runing.png");
    Game *game = new Game(0, 0, imgs);

    while (!WindowShouldClose()) {
      game->Update();
      game->Draw();
    }

    delete game;
    for (Texture2D &img : imgs) {
      UnloadTexture(img);
    } 
    CloseWindow();
    return 0;
}
