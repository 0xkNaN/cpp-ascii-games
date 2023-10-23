/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-21 22:20:55
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-23 01:49:39
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

  speed = 2.0f;
  acceleration = 1.0f;

  minDistanceToPlayer = 100;
  maxDistanceToPlayer = 200;

  velocity = new Vector2D();
  position = new Vector2D(posX, posY);
}

void Enemy::update()
{
  Player *player = TheGame::Instance()->getPlayer();
  Vector2D *pPosition = player->getPosition();

  Vector2D *direction = new Vector2D();

  //? Distance
  float distance = std::sqrt(
      std::pow(position->getX() - pPosition->getX(), 2) + std::pow(position->getY() - pPosition->getY(), 2));

  //? Direction To player
  direction->setX(pPosition->getX() - position->getX());
  direction->setY(pPosition->getY() - position->getY());
  direction->normalize();

  //? Velocity
  if (distance > maxDistanceToPlayer)
  {
    velocity->setX(velocity->getX() + direction->getX() * acceleration);
    velocity->setY(velocity->getY() + direction->getY() * acceleration);
  }

  if (velocity->length() > speed)
      velocity->normalize(speed);

  //? Position
  position->setX(position->getX() + velocity->getX());
  position->setY(position->getY() + velocity->getY());
}

void Enemy::draw()
{
  //? Render Collider
  collider = {(int)(position->getX() - 21), (int)(position->getY() - 11), 42, 22};
  SDL_SetRenderDrawColor(TheGame::Instance()->getRenderer(), 0, 0, 0, 255);
  SDL_RenderDrawRect(TheGame::Instance()->getRenderer(), &collider);

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

void Enemy::onCollideWith(SDL_Rect *col, SDL_Rect *results)
{

  //? Direction To Avoid
  Vector2D *dir = new Vector2D();
  dir->setX(col->x - collider.x);
  dir->setY(col->y - collider.y);
  dir->normalize();

  if (dir->length())
  {
    velocity->setX(velocity->getX() - dir->getX());
    velocity->setY(velocity->getY() - dir->getY());
  }
}