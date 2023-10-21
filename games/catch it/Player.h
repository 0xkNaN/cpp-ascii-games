/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-18 23:23:52
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-21 22:56:27
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
  virtual void update(float deltaFrame);
  virtual void draw();

  virtual Vector2D *getPosition() { return position; }

private:
  SDL_Color color;

  float speed;
  float acceleration;

  Vector2D *velocity;
  Vector2D *position;

  int radius;
  float rotate;

  SDL_FPoint pT;
  SDL_FPoint pR;
  SDL_FPoint pL;
};
