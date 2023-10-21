/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-18 23:07:35
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-21 13:45:57
 */

#include "Game.h"

Game *Game::instance = 0;

Game::Game()
{
  level = 0;
  running = false;
}

bool Game::init(const char *title, int width, int height)
{
  wWidth = width;
  wHeight = height;

  if (!!SDL_Init(SDL_INIT_EVERYTHING))
    return false;

  if (!!SDL_CreateWindowAndRenderer(wWidth, wHeight, 0, &window, &renderer))
    return false;

  //?
  SDL_SetWindowTitle(window, title);
  SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

  //? Player
  player = new Player();
  player->load();
  gameObjects.push_back(player);

  //?
  running = true;
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

void Game::update(float deltaFrame)
{
  level = (int)(SDL_GetTicks() / 10000); //? Level every 10 seconds

  //? Update GameObjects
  for (unsigned int i = 0; i < gameObjects.size(); i++)
  {
    gameObjects[i]->update(deltaFrame);
  }
}

void Game::render()
{
  //? Clear
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  //? Render GameObjects
  for (unsigned int i = 0; i < gameObjects.size(); i++)
  {
    gameObjects[i]->draw();
  }

  //? Swipe
  SDL_RenderPresent(renderer);
}