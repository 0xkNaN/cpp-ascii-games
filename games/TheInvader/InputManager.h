/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-23 22:19:52
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-23 22:51:51
 */

#pragma once

#include <iostream>
#include <SDL2/SDL.h>

class InputManager
{

public:
  ~InputManager() {}
  static InputManager *Instance()
  {
    if (instance == 0)
      instance = new InputManager();
    return instance;
  }

  void handle();

  bool isKeyPressed(SDL_Scancode key) const;

private:
  InputManager() {}
  static InputManager *instance;

  //? Keyboard
  const Uint8 *keystates;
  void onKeyDown();
  void onKeyUp();
};

typedef InputManager TheInputManager;
