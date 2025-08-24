#include <raylib.h>
#include "game.hpp"

int main() {
    //SetTraceLogLevel(LOG_NONE);
    InitWindow(800, 450, "Kepingan Yang Hilang");
    InitAudioDevice();
    SetTargetFPS(60);

    Game *game = new Game();

    while (!WindowShouldClose()) {
      game->Update();
      game->Draw();
    }

    delete game;
    CloseAudioDevice();
    CloseWindow();
    return 0;
}
