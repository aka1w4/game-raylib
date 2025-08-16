#include <raylib.h>
#include "player.hpp"

const int width = 64;
const int height = 128;
const int frameCount = 8;
const float walkSpeed = 2.5f;
const float runSpeed = 6.0f;

Player::Player(float x, float y, Texture2D img[3]) : x(x), y(y) {
  this->imgs[0] = img[0];
  this->imgs[1] = img[1];
  this->imgs[2] = img[2];
}

void Player::Update() {
  count++;
  Input();
 }

void Player::Draw() {
  Vector2 position = {x, y};
  int x0 = (count / 5) % frameCount * width;
  Rectangle sourceRec = {(float)x0, height*(float)focus, width, height};

  DrawTextureRec(imgs[moveState], sourceRec, position, WHITE);
}

void Player::Input() {
  MovementState ms = isIdle;
  float speed;
  if (IsKeyDown(KEY_W)) {
    speed = IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT) ? runSpeed : walkSpeed;
    ms = IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT) ? isRun : isWalk;
    Walk(0, -speed, ms);
    focus = Bawah;
  } else if (IsKeyDown(KEY_S)) {
    speed = IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT) ? runSpeed : walkSpeed;
    ms = IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT) ? isRun : isWalk;
    Walk(0, +speed, ms);
    focus = Atas;
  } else if (IsKeyDown(KEY_A)) {
    speed = IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT) ? runSpeed : walkSpeed;
    ms = IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT) ? isRun : isWalk;
    Walk(-speed, 0, ms);
    focus = Kiri;
  } else if (IsKeyDown(KEY_D)) {
    speed = IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT) ? runSpeed : walkSpeed;
    ms = IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT) ? isRun : isWalk;
    Walk(+speed, 0, ms);
    focus = Kanan;
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

    x += dx;
    y += dy;
  } else {
    moveState = isIdle;
  }
}
