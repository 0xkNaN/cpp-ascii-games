/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-18 23:23:52
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-21 13:15:35
 */

#pragma once

#include "Vector2D.h"
#include "GameObject.h"

class Player : public GameObject
{
public:
  Player();
  ~Player() {}

  virtual void load();
  virtual void update(float deltaFrame);
  virtual void draw();

private:
  SDL_Color color;

  float speed;
  float acceleration;
  float friction;

  Vector2D *velocity;
  Vector2D *position;
};
