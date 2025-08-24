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
    MovementState moveState;
    unsigned int count;

    void Walk(float dx, float dy, MovementState ms);
    void Input();

public:
    Player();
    ~Player();
    void Update();
    void Draw();
};

#endif // !PLAYER_HPP
