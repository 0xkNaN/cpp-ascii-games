/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-22 23:52:27
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-23 00:19:30
 */

#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "Game.h"

class CollisionManager
{
public:
  ~CollisionManager() {}
  static CollisionManager *Instance()
  {
    if (instance == 0)
      instance = new CollisionManager();
    return instance;
  }

  void checkCollision();

private:
  CollisionManager() {}

  static CollisionManager *instance;
};

typedef CollisionManager TheCollisionManager;