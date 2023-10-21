/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-21 22:16:49
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-21 22:56:39
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
  virtual void update(float deltaFrame);
  virtual void draw();

  virtual Vector2D *getPosition() { return position; }

private:
  SDL_Color color;

  float speed;
  float acceleration;

  Vector2D *velocity;
  Vector2D *position;
};
