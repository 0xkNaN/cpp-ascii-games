/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-23 22:20:09
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-23 22:56:57
 */

#include "InputManager.h"

#include "Game.h"

InputManager *InputManager::instance = 0;

void InputManager::handle()
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
    case SDL_QUIT:
      TheGame::Instance()->quit();
      break;

    case SDL_KEYDOWN:
      onKeyDown();
      break;

    case SDL_KEYUP:
      onKeyUp();
      break;

    default:
      break;
    }
  }
}

bool InputManager::isKeyPressed(SDL_Scancode key) const
{
  if (keystates != 0)
  {
    return keystates[key] == 1;
  }

  return false;
}

void InputManager::onKeyDown()
{
  keystates = SDL_GetKeyboardState(0);
}

void InputManager::onKeyUp()
{
  keystates = SDL_GetKeyboardState(0);
}