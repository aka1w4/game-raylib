#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <raylib.h>
#include "player/player.hpp"

class Game {
private:
    std::unique_ptr<Player> player;

public:
    Game(float x, float y, Texture2D img[3]);
    void Update();
    void Draw();
};

#endif // GAME_HPP
