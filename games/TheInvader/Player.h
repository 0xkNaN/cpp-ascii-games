/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-18 23:23:52
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-22 01:04:17
 */

#pragma once

#include "Vector2D.h"
#include "GameObject.h"

class Player : public GameObject
{
public:
  Player();
  ~Player() {}

  virtual void load(int posX, int posY);
  virtual void update();
  virtual void draw();

  virtual void onCollideWith(SDL_Rect *col, SDL_Rect *results) {}

private:
  int radius;
  float rotate;
};
