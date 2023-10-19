/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-18 23:06:43
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-18 23:35:03
 */

#pragma one

#include "SDL2/SDL.h"

//! Convet this to singleton

class Game
{
public:
  Game();
  ~Game() {}

  bool init();
  void clean();

  void handleEvents();
  void update();
  void render();

  SDL_Renderer *getRenderer() { return renderer; }

  bool isRunning() { return running; }

private:
  int wWidth;
  int wHeight;

  SDL_Window *window;
  SDL_Renderer *renderer;

  const Uint8 *keystates;

  int level;
  bool running;
};
