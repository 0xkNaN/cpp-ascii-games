/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-18 23:23:52
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-18 23:29:49
 */

#pragma once

#include "GameObject.h"

class Player : public GameObject
{
public:
  Player() : GameObject() {}
  ~Player() {}

  void load();
  void render();
  void draw();
};
