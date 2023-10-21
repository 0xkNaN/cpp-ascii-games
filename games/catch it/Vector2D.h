/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-21 13:06:37
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-21 17:31:57
 */

#pragma once

#include <iostream>
#include <cmath>

class Vector2D
{

public:
  Vector2D()
  {
    x = 0.0f;
    y = 0.0f;
  }

  Vector2D(float x, float y) : x(x), y(y)
  {
  }

  float getX() { return x; }
  float getY() { return y; }
  void setX(float x) { this->x = x; }
  void setY(float y) { this->y = y; }
  float length() { return sqrt(x * x + y * y); }
  void normalize(int n = 1)
  {
    float l = this->length();
    if (l > 0)
    {
      // (*this) *= 1 / l;
      this->setX(this->getX() * (n / l));
      this->setY(this->getY() * (n / l));
    }
  }

  //! Add Vector2D operators support

private:
  float x;
  float y;
};
