/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-18 23:25:11
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-22 01:05:19
 */

#pragma once

#include <SDL2/SDL.h>

#include "Vector2D.h"

class GameObject
{
public:
  GameObject()
  {
    color = {253, 2, 249, 255};

    velocity = new Vector2D();
    position = new Vector2D();
  }
  ~GameObject() {}

  virtual void load(int posX, int posY) = 0;
  virtual void update() = 0;
  virtual void draw() = 0;

  virtual Vector2D *getPosition() = 0;

protected:
  SDL_Color color;

  float speed;
  float acceleration;

  Vector2D *velocity;
  Vector2D *position;
};
