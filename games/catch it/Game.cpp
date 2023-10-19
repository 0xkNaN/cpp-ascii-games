/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-18 23:07:35
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-18 23:33:02
 */

#include "Game.h"

#include <iostream>

Game::Game()
{
  wWidth = 1440;
  wHeight = 720;

  level = 0;
  running = false;
}

bool Game::init()
{
  if (!!SDL_Init(SDL_INIT_EVERYTHING))
    return false;

  if (!!SDL_CreateWindowAndRenderer(wWidth, wHeight, 0, &window, &renderer))
    return false;

  //?
  SDL_SetWindowTitle(window, "Catch It!");
  SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

  running = true;

  //?
  return true;
}

void Game::clean()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void Game::handleEvents()
{
  SDL_Event event;
  SDL_PollEvent(&event);
  keystates = SDL_GetKeyboardState(0);

  switch (event.type)
  {
  case SDL_QUIT:
    running = false;
    break;

  default:
    break;
  }
}

void Game::update()
{
  level = (int)(SDL_GetTicks() / 10000); //? Level every 10 seconds
  // std::cout << level << std::endl;
}

void Game::render()
{
}