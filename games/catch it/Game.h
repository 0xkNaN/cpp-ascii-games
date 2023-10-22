/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-18 23:06:43
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-22 00:25:26
 */

#pragma one

#include <iostream>
#include "vector"
#include "SDL2/SDL.h"

#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"

class Game
{
public:
  ~Game() {}
  static Game *Instance()
  {
    if (instance == 0)
      instance = new Game();

    return instance;
  }

  bool init(const char *title, int width, int height);
  void clean();

  void handleEvents();
  void update();
  void render();

  int getWidth() { return wWidth; }
  int getHeight() { return wHeight; }
  SDL_Renderer *getRenderer() { return renderer; }

  const Uint8 *getKeyStates() { return keystates; }

  bool isRunning() { return running; }

  Player *getPlayer() { return player; }

private:
  Game();
  static Game *instance;

  int wWidth;
  int wHeight;

  SDL_Window *window;
  SDL_Renderer *renderer;

  const Uint8 *keystates;

  std::vector<GameObject *> gameObjects;
  Player *player;

  int level;
  bool running;
};

typedef Game TheGame;
