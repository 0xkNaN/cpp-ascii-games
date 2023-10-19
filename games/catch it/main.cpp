/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-16 21:26:36
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-18 23:33:41
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

const Uint8 *keystates;

//? Player
SDL_Color pColor = {0, 255, 0, 255};
SDL_Point pPosition = {(int)(SCREEN_WIDTH / 2), (int)(SCREEN_HEIGH / 2)};
SDL_Point pDirection = {0, 0};
float pVelocity = 0.0f;
float pAcceleration = 0.5f;
const float maxPSpeed = 20.0f;

//! Player AngVel

void update()
{

  if (keystates != 0)
  {

    if (keystates[SDL_SCANCODE_UP] || keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_LEFT])
    {

      // pVelocity += pAcceleration;
      // if (pVelocity > maxPSpeed)
      //   pVelocity = maxPSpeed;

      if (keystates[SDL_SCANCODE_UP])
      {
        pVelocity -= pAcceleration;
        if (pVelocity < -maxPSpeed)
          pVelocity = -maxPSpeed;
      }
      else if (keystates[SDL_SCANCODE_DOWN])
      {
        pVelocity += pAcceleration;
        if (pVelocity > maxPSpeed)
          pVelocity = maxPSpeed;
      }

      if (keystates[SDL_SCANCODE_RIGHT])
      {
        pVelocity += pAcceleration;
        if (pVelocity > maxPSpeed)
          pVelocity = maxPSpeed;
      }
      else if (keystates[SDL_SCANCODE_LEFT])
      {
        pVelocity -= pAcceleration;
        if (pVelocity < -maxPSpeed)
          pVelocity = -maxPSpeed;
      }
    }
    else
    {
      if (pVelocity < 0)
      {
        pVelocity += pAcceleration * 10;
        if (pVelocity >= 0)
        {
          pVelocity = 0.0f;
          pDirection.x = 0;
          pDirection.y = 0;
        }
      }
      else
      {
        pVelocity -= pAcceleration * 10;
        if (pVelocity <= 0)
        {
          pVelocity = 0.0f;
          pDirection.x = 0;
          pDirection.y = 0;
        }
      }
    }
  }

  //? Normalize
  float _m = sqrt(pDirection.x * pDirection.x + pDirection.y * pDirection.y);
  if (_m == 0)
    _m = 1;

  std::cout << pVelocity << " :: " << pDirection.x / _m << " / " << pDirection.y / _m << std::endl;

  //? Update Player Position based on Veocity
  pPosition.x += int((pDirection.x / _m) * pVelocity);
  pPosition.y += int((pDirection.y / _m) * pVelocity);
}

void render()
{
  //? Clear
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  //? Render Player
  SDL_Vertex vertices[] = {
      {{(float)(pPosition.x), (float)(pPosition.y - 25)}, pColor, {1, 1}},
      {{(float)(pPosition.x + 20), (float)(pPosition.y + 25)}, pColor, {1, 1}},
      {{(float)(pPosition.x - 20), (float)(pPosition.y + 25)}, pColor, {1, 1}}};
  SDL_RenderGeometry(renderer, NULL, vertices, 3, NULL, 0);

  //! Render Food

  //! Render Board

  //? Swipe
  SDL_RenderPresent(renderer);
}

int main(int argc, char const *argv[])
{
  Game *game = new Game();

  bool i = game->init();
  if (!i)
  {
    std::cout << SDL_GetError() << std::endl;
    return EXIT_FAILURE;
  }

  while (game->isRunning())
  {
    int startFrame = SDL_GetTicks();

    game->handleEvents();
    game->update();
    game->render();

    if ((SDL_GetTicks() - startFrame) < FRAME_RATE)
      SDL_Delay(FRAME_RATE - (SDL_GetTicks() - startFrame));
  }

  game->clean();
  return 0;
}
