/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-21 22:20:55
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-22 00:19:24
 */

#include <cmath>

#include "Enemy.h"
#include "Game.h"
#include "Player.h"

Enemy::Enemy()
{
}

void Enemy::load(int posX, int posY)
{
  color = {1, 62, 187, 255};

  speed = 7.0f;
  acceleration = 1.0f;

  velocity = new Vector2D();
  position = new Vector2D(posX, posY);
}

void Enemy::update(float deltaFrame)
{
  Player *player = TheGame::Instance()->getPlayer();
  Vector2D *pPosition = player->getPosition();

  Vector2D *direction = new Vector2D();

  //? Distance
  float distance = std::sqrt(
      std::pow(position->getX() - pPosition->getX(), 2) + std::pow(position->getY() - pPosition->getY(), 2));

  //? Direction To player
  if (distance > 100)
  {
    direction->setX(pPosition->getX() - position->getX());
    direction->setY(pPosition->getY() - position->getY());
    direction->normalize();
  }
  else
  {
    direction->setX(0);
    direction->setY(0);
  }

  //? Velocity
  velocity->setX(velocity->getX() + direction->getX() * acceleration);
  velocity->setY(velocity->getY() + direction->getY() * acceleration);
  if (velocity->length() > speed)
    velocity->normalize(speed);

  //? Position
  position->setX(position->getX() + velocity->getX());
  position->setY(position->getY() + velocity->getY());
}

void Enemy::draw()
{
  SDL_Vertex verticesT[] = {
      {{(float)(position->getX()), (float)(position->getY() - 10)}, color, {1, 1}},
      {{(float)(position->getX() + 20), (float)(position->getY() + 10)}, color, {1, 1}},
      {{(float)(position->getX() - 20), (float)(position->getY() + 10)}, color, {1, 1}}};
  SDL_RenderGeometry(TheGame::Instance()->getRenderer(), NULL, verticesT, 3, NULL, 0);

  SDL_Vertex verticesB[] = {
      {{(float)(position->getX()), (float)(position->getY() + 10)}, color, {1, 1}},
      {{(float)(position->getX() - 20), (float)(position->getY() - 10)}, color, {1, 1}},
      {{(float)(position->getX() + 20), (float)(position->getY() - 10)}, color, {1, 1}}};
  SDL_RenderGeometry(TheGame::Instance()->getRenderer(), NULL, verticesB, 3, NULL, 0);

  SDL_SetRenderDrawColor(TheGame::Instance()->getRenderer(), color.r, color.g, color.b, color.a);
  SDL_RenderDrawPoint(TheGame::Instance()->getRenderer(), position->getX(), position->getY());
}