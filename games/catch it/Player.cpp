/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-19 22:49:01
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-21 13:33:18
 */

#include "Player.h"

#include "Game.h"

Player::Player() : GameObject()
{
}

void Player::load()
{
  color = {0, 255, 0, 255};

  speed = 30;
  acceleration = 2;
  //! Player AngVel

  velocity = new Vector2D();
  position = new Vector2D(
      (int)(TheGame::Instance()->getWidth() / 2),
      (int)(TheGame::Instance()->getHeight() / 2));
}

void Player::update()
{
  const Uint8 *keystates = TheGame::Instance()->getKeyStates();

  Vector2D *direction = new Vector2D(
      (int)(keystates[SDL_SCANCODE_RIGHT]) - (int)(keystates[SDL_SCANCODE_LEFT]),
      (int)(keystates[SDL_SCANCODE_DOWN]) - (int)(keystates[SDL_SCANCODE_UP]));

  // if (direction.x != 0 || direction.y != 0)
  // {
  //   //! Normalize direction
  //   //! Use Max Speed
  // std::cout << "Click" << std::endl;
  // velocity.x += direction.x * acceleration;
  // velocity.y += direction.y * acceleration;

  // if (velocity.x > speed)
  // {
  //   velocity.x = speed;
  // }
  // if (velocity.x > speed)
  // {
  //   velocity.x = speed;
  // }

  // if (velocity.y > speed)
  // {
  //   velocity.y = speed;
  // }
  // }
  // else
  // {
  //! Apply Friction
  // velocity.x = 0;
  // velocity.y = 0;
  // }

  //? Update Player Position based on Veocity
  // position.x += velocity.x;
  // position.y += velocity.y;
}

void Player::draw()
{
  //? Render Player
  SDL_Vertex vertices[] = {
      {{(float)(position->getX()), (float)(position->getY() - 25)}, color, {1, 1}},
      {{(float)(position->getX() + 20), (float)(position->getY() + 25)}, color, {1, 1}},
      {{(float)(position->getX() - 20), (float)(position->getY() + 25)}, color, {1, 1}}};
  SDL_RenderGeometry(TheGame::Instance()->getRenderer(), NULL, vertices, 3, NULL, 0);
}