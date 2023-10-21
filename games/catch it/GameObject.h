/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-18 23:25:11
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-21 13:46:02
 */

#pragma once

#include <SDL2/SDL.h>

class GameObject
{
public:
  GameObject() {}
  ~GameObject() {}

  virtual void load() = 0;
  virtual void update(float deltaFrame) = 0;
  virtual void draw() = 0;
};
