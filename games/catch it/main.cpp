/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-16 21:26:36
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-17 00:12:25
 */

#include <iostream>
#include <algorithm>
#include <time.h>
#include <math.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 1440
#define SCREEN_HEIGH 720
#define FPS 60
#define FRAME_RATE 1000.0f / FPS

SDL_Window *window;
SDL_Renderer *renderer;

bool gameIsRunning = false;
const Uint8 *keystates;
unsigned int currTime;
unsigned int level;

SDL_Color pColor = {0, 255, 0, 255};
SDL_Point pPos = {(int)(SCREEN_WIDTH / 2), (int)(SCREEN_HEIGH / 2)};
SDL_Point pVel = {0, 0};
SDL_Point pAcc = {0, 0};

//! Player AngVel

bool intWindow()
{
  if (!!SDL_Init(SDL_INIT_EVERYTHING))
    return false;

  if (!!SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_WIDTH, 0, &window, &renderer))
    return false;

  //?
  SDL_SetWindowTitle(window, "Catch The Ball");
  SDL_SetWindowSize(window, SCREEN_WIDTH, SCREEN_HEIGH);
  SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

  return true;
}

void clean()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void handleEvent()
{
  SDL_Event event;
  SDL_PollEvent(&event);
  keystates = SDL_GetKeyboardState(0);

  switch (event.type)
  {
  case SDL_QUIT:
    gameIsRunning = false;
    break;

  default:
    break;
  }
}

void update()
{
  level = (int)(currTime / 10000); //? Level every 10 seconds
  // std::cout << level << std::endl;

  // pAcc = {0, 0};
  pVel = {0, 0};

  if (keystates != 0)
  {
    if (keystates[SDL_SCANCODE_UP])
    {
      pVel.y = -10;
      // pAcc.y = -1;
    }

    if (keystates[SDL_SCANCODE_DOWN])
    {
      pVel.y = 10;
      // pAcc.y = 1;
    }

    if (keystates[SDL_SCANCODE_RIGHT])
    {
      pVel.x = 10;
      // pAcc.x = 1;
    }

    if (keystates[SDL_SCANCODE_LEFT])
    {
      pVel.x = -10;
      // pAcc.x = -1;
    }
  }

  pVel.x += pAcc.x;
  pVel.y += pAcc.y;
  pPos.x = std::min(std::max(pPos.x + pVel.x, 0), SCREEN_WIDTH);
  pPos.y = std::min(std::max(pPos.y + pVel.y, 0), SCREEN_HEIGH);
}

void render()
{
  //? Clear
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  //? Render pPos
  SDL_Vertex vertices[] = {
      {{(float)(pPos.x), (float)(pPos.y - 25)}, pColor, {1, 1}},
      {{(float)(pPos.x + 20), (float)(pPos.y + 25)}, pColor, {1, 1}},
      {{(float)(pPos.x - 20), (float)(pPos.y + 25)}, pColor, {1, 1}}};
  SDL_RenderGeometry(renderer, NULL, vertices, 3, NULL, 0);

  //! Render Food

  //! Render Board

  //? Swipe
  SDL_RenderPresent(renderer);
}

int main(int argc, char const *argv[])
{
  gameIsRunning = intWindow();
  if (!gameIsRunning)
    return -1;

  while (gameIsRunning)
  {
    currTime = SDL_GetTicks();

    handleEvent();
    update();
    render();

    if ((SDL_GetTicks() - currTime) < FRAME_RATE)
      SDL_Delay(FRAME_RATE - (SDL_GetTicks() - currTime));
  }

  clean();
  return 0;
}
