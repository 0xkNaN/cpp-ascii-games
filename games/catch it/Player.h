/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-18 23:23:52
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-19 23:24:37
 */

#pragma once

#include "GameObject.h"

class Player : public GameObject
{
public:
  Player();
  ~Player() {}

  virtual void load();
  virtual void update();
  virtual void draw();

private:
  SDL_Color color;

  int acceleration;

  SDL_Point velocity;
  SDL_Point position;
};
