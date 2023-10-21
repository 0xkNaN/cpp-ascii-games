/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-18 23:25:11
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-21 22:55:36
 */

#pragma once

#include <SDL2/SDL.h>

#include "Vector2D.h"

class GameObject
{
public:
  GameObject() {}
  ~GameObject() {}

  virtual void load(int posX, int posY) = 0;
  virtual void update(float deltaFrame) = 0;
  virtual void draw() = 0;

  virtual Vector2D *getPosition() = 0;
};
