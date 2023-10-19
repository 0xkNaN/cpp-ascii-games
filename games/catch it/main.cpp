/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-16 21:26:36
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-19 23:03:29
 */

#include <iostream>
#include <algorithm>
#include <time.h>
#include <math.h>
#include <SDL2/SDL.h>

#include "Game.h"

#define SCREEN_WIDTH 1440
#define SCREEN_HEIGH 720
#define FPS 60
#define FRAME_RATE 1000.0f / FPS

int main(int argc, char const *argv[])
{

  bool i = TheGame::Instance()->init();
  if (!i)
  {
    std::cout << SDL_GetError() << std::endl;
    return EXIT_FAILURE;
  }

  while (TheGame::Instance()->isRunning())
  {
    int startFrame = SDL_GetTicks();

    TheGame::Instance()->handleEvents();
    TheGame::Instance()->update();
    TheGame::Instance()->render();

    if ((SDL_GetTicks() - startFrame) < FRAME_RATE)
      SDL_Delay(FRAME_RATE - (SDL_GetTicks() - startFrame));
  }

  TheGame::Instance()->clean();
  return 0;
}
