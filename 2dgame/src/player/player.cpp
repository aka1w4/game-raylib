#include <raylib.h>
#include "player.hpp"

const int width = 64;
const int height = 128;
const int frameCount = 8;
const float walkSpeed = 2.5f;
const float runSpeed = 6.0f;

Player::Player() : focus(Rightfocus) {
  pos = Vector2{100.0f, 100.0f};
  this->imgs[0] = LoadTexture("assets/female_idle.png");
  this->imgs[1] = LoadTexture("assets/female_walking.png");
  this->imgs[2] = LoadTexture("assets/female_runing.png");
}

Player::~Player() {
  for (Texture2D &img : imgs) {
    UnloadTexture(img);
  } 
}

void Player::Update() {
  count++;
  Input();
 }

void Player::Draw() {
  int x0 = (count / 6) % frameCount * width;
  Rectangle sourceRec = {(float)x0, height*(float)focus, width, height};

  DrawTextureRec(imgs[moveState], sourceRec, pos, WHITE);
}

void Player::Input() {
  MovementState ms = isIdle;
  float speed;
  if (IsKeyDown(KEY_W)) {
    speed = IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT) ? runSpeed : walkSpeed;
    ms = IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT) ? isRun : isWalk;
    Walk(0, -speed, ms);
    focus = Upfocus;
  } else if (IsKeyDown(KEY_S)) {
    speed = IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT) ? runSpeed : walkSpeed;
    ms = IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT) ? isRun : isWalk;
    Walk(0, +speed, ms);
    focus = Downfocus;
  } else if (IsKeyDown(KEY_A)) {
    speed = IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT) ? runSpeed : walkSpeed;
    ms = IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT) ? isRun : isWalk;
    Walk(-speed, 0, ms);
    focus = Leftfocus;
  } else if (IsKeyDown(KEY_D)) {
    speed = IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT) ? runSpeed : walkSpeed;
    ms = IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT) ? isRun : isWalk;
    Walk(+speed, 0, ms);
    focus = Rightfocus;
  } else {
    moveState = ms;
  }
}

void Player::Walk(float dx, float dy, MovementState ms) {
  if (dx != 0 || dy != 0) {
    switch (ms) {
    case isRun:
      moveState = isRun;
      break;
    case isWalk:
      moveState = isWalk;
      break;
    case isIdle:
    default:
      moveState = isIdle;
      break;
    }

    pos.x += dx;
    pos.y += dy;
  } else {
    moveState = isIdle;
  }
}

Rectangle Player::GetPlayer() {
  return Rectangle{
    pos.x,
    pos.y,
    width,
    height,
  };
}

void Player::needpos(Vector2 v) {
  pos = v;
}
