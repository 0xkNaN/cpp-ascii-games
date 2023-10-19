/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-19 22:49:01
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-19 23:32:50
 */

#include "Player.h"

#include "Game.h"

Player::Player() : GameObject()
{
}

void Player::load()
{
  color = {0, 255, 0, 255};

  acceleration = 2;
  // const float maxPSpeed = 20.0f;

  //! Player AngVel

  velocity = {0, 0};
  position = {(int)(TheGame::Instance()->getWidth() / 2), (int)(TheGame::Instance()->getHeight() / 2)};
}

void Player::update()
{
  const Uint8 *keystates = TheGame::Instance()->getKeyStates();

  SDL_Point direction = {0, 0};

  if (keystates[SDL_SCANCODE_UP])
  {
    direction.y = -1;
  }
  if (keystates[SDL_SCANCODE_DOWN])
  {
    direction.y = 1;
  }
  if (keystates[SDL_SCANCODE_LEFT])
  {
    direction.x = -1;
  }
  if (keystates[SDL_SCANCODE_RIGHT])
  {
    direction.x = 1;
  }

  if (direction.x != 0 || direction.y != 0)
  {
    //! Normalize direction
    //! Use Max Speed
    std::cout << "Click" << std::endl;
    velocity.x += direction.x * acceleration;
    velocity.y += direction.y * acceleration;
  }
  else
  {
    //! Apply Friction
    velocity.x = 0;
    velocity.y = 0;
  }

  //? Normalize
  // float _m = sqrt(pDirection.x * pDirection.x + pDirection.y * pDirection.y);
  // if (_m == 0)
  //   _m = 1;

  //? Update Player Position based on Veocity
  position.x += velocity.x;
  position.y += velocity.y;
}

void Player::draw()
{
  //? Render Player
  SDL_Vertex vertices[] = {
      {{(float)(position.x), (float)(position.y - 25)}, color, {1, 1}},
      {{(float)(position.x + 20), (float)(position.y + 25)}, color, {1, 1}},
      {{(float)(position.x - 20), (float)(position.y + 25)}, color, {1, 1}}};
  SDL_RenderGeometry(TheGame::Instance()->getRenderer(), NULL, vertices, 3, NULL, 0);
}