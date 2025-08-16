#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <raylib.h>

enum Focus {
  Downfocus,
  Leftfocus,
  Rightfocus,
  Upfocus,
};

enum MovementState {
  isIdle,
  isWalk,
  isRun,
};

class Player {
private:
    float x, y;
    Texture2D imgs[3];
    Focus focus;
    unsigned int count;
    unsigned int moveState;

    void Walk(float dx, float dy, MovementState ms);
    void Input();

public:
    Player(float x, float y, Texture2D img[3]);
    void Update();
    void Draw();
};

#endif // !PLAYER_HPP
