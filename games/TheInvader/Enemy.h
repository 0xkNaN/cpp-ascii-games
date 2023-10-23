/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-21 22:16:49
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-23 22:19:03
 */

#pragma once

#include "Vector2D.h"
#include "GameObject.h"

class Enemy : public GameObject
{
public:
  Enemy();
  ~Enemy() {}

  virtual void load(int posX, int posY);
  virtual void update();
  virtual void draw();

  virtual void onCollideWith(SDL_Rect *col, SDL_Rect *results);

private:
  float maxDistanceToPlayer;
};
