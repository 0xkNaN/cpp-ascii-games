/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-19 22:49:01
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-21 17:31:28
 */

#include "Player.h"

#include "Game.h"

Player::Player() : GameObject()
{
}

void Player::load()
{
  color = {0, 255, 0, 255};

  speed = 15.0f;
  acceleration = 2.0f;
  //! Player AngVel

  velocity = new Vector2D();
  position = new Vector2D(
      (int)(TheGame::Instance()->getWidth() / 2),
      (int)(TheGame::Instance()->getHeight() / 2));
}

void Player::update(float deltaFrame)
{
  const Uint8 *keystates = TheGame::Instance()->getKeyStates();

  //? Direction
  Vector2D *direction = new Vector2D(
      (int)(keystates[SDL_SCANCODE_RIGHT]) - (int)(keystates[SDL_SCANCODE_LEFT]),
      (int)(keystates[SDL_SCANCODE_DOWN]) - (int)(keystates[SDL_SCANCODE_UP]));
  direction->normalize();

  //? Velocity
  if (direction->length())
  {
    velocity->setX(velocity->getX() + direction->getX() * acceleration);
    velocity->setY(velocity->getY() + direction->getY() * acceleration);

    if (velocity->length() > speed)
      velocity->normalize(speed);
  }
  else
  {
    velocity->setX(0);
    velocity->setY(0);
  }

  //? Update Player Position based on Velocity
  position->setX(int(position->getX() + velocity->getX()));
  position->setY(int(position->getY() + velocity->getY()));
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