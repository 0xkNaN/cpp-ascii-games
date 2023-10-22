/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-19 22:49:01
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-22 01:02:34
 */

#include "Player.h"

#include <cmath>
#include <algorithm>

#include "Game.h"

constexpr double pi = 3.14159265358979323846;

Player::Player() : GameObject()
{
}

void Player::load(int posX, int posY)
{
  color = {0, 145, 55, 255};

  speed = 15.0f;
  acceleration = 2.0f;

  velocity = new Vector2D();
  position = new Vector2D(posX, posY);

  radius = 15;
  rotate = 0.0f;
}

void Player::update()
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

    //? Rotation
    if (keystates[SDL_SCANCODE_RIGHT])
      rotate = 0;
    if (keystates[SDL_SCANCODE_DOWN])
      rotate = 90;
    if (keystates[SDL_SCANCODE_LEFT])
      rotate = 180;
    if (keystates[SDL_SCANCODE_UP])
      rotate = 270;
    // ...
    if (keystates[SDL_SCANCODE_RIGHT] && keystates[SDL_SCANCODE_DOWN])
      rotate = 45;
    if (keystates[SDL_SCANCODE_DOWN] && keystates[SDL_SCANCODE_LEFT])
      rotate = 135;
    if (keystates[SDL_SCANCODE_LEFT] && keystates[SDL_SCANCODE_UP])
      rotate = 225;
    if (keystates[SDL_SCANCODE_UP] && keystates[SDL_SCANCODE_RIGHT])
      rotate = 315;
  }
  else
  {
    velocity->setX(0);
    velocity->setY(0);
  }

  //? Update Player Position based on Velocity
  position->setX(std::max(std::min(int(position->getX() + velocity->getX()), TheGame::Instance()->getWidth()), 0));
  position->setY(std::max(std::min(int(position->getY() + velocity->getY()), TheGame::Instance()->getHeight()), 0));
}

void Player::draw()
{
  //? Render Player
  SDL_FPoint pT = {
      (float)(position->getX() + std::cos(rotate * pi / 180) * radius),
      (float)(position->getY() + std::sin(rotate * pi / 180) * radius)};
  SDL_FPoint pR = {
      (float)(position->getX() + std::cos((rotate * pi / 180) + (2 * pi / 2.666)) * radius),
      (float)(position->getY() + std::sin((rotate * pi / 180) + (2 * pi / 2.666)) * radius)};
  SDL_FPoint pL = {
      (float)(position->getX() + std::cos((rotate * pi / 180) + (-2 * pi / 2.666)) * radius),
      (float)(position->getY() + std::sin((rotate * pi / 180) + (-2 * pi / 2.666)) * radius)};
  // ...
  SDL_Vertex vertices[] = {
      {pT, color, {1, 1}},
      {pR, color, {1, 1}},
      {pL, color, {1, 1}}};

  //?
  SDL_RenderGeometry(TheGame::Instance()->getRenderer(), NULL, vertices, 3, NULL, 0);
}