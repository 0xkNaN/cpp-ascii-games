/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-21 22:20:55
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-23 10:39:11
 */

#include <cmath>

#include "Enemy.h"
#include "Game.h"
#include "Player.h"

Enemy::Enemy() : GameObject()
{
}

void Enemy::load(int posX, int posY)
{
  color = {1, 62, 187, 255};

  speed = 2.0f;
  acceleration = 1.0f;

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
  //? Collider
  collider = {(int)(position->getX() - 21), (int)(position->getY() - 11), 42, 22};
  SDL_SetRenderDrawColor(TheGame::Instance()->getRenderer(), 0, 0, 0, 255);
  SDL_RenderDrawRect(TheGame::Instance()->getRenderer(), &collider);

  //? Shape
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

void Enemy::onCollideWith(SDL_Rect *col, SDL_Rect *res)
{

  //? Direction To Avoid
  Vector2D *d = new Vector2D();
  d->setX(col->x - collider.x);
  d->setY(col->y - collider.y);
  d->normalize();

  //? Force
  Vector2D *f = new Vector2D();
  f->setX(res->x);
  f->setY(res->y);

  std::cout << "Force :: " << f->length() << std::endl;

  if (d->length())
  {
    velocity->setX(velocity->getX() - d->getX() * f->length());
    velocity->setY(velocity->getY() - d->getY() * f->length());
  }
}