/**
 * @Author: Hassen Rmili
 * @Date:   2023-10-22 23:53:04
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2023-10-23 01:00:14
 */

#include "CollisionManager.h"

CollisionManager *CollisionManager::instance = 0;

void CollisionManager::checkCollision()
{
  std::vector<GameObject *> gbs = TheGame::Instance()->getGameObjects();

  for (unsigned int i = 0; i < gbs.size(); i++)
  {

    for (unsigned int j = 0; j < gbs.size(); j++)
    {
      if (i != j)
      {
        GameObject *iGO = gbs[i];
        GameObject *jGO = gbs[j];

        SDL_Rect result;
        bool isCollided = SDL_IntersectRect(iGO->getCollider(), jGO->getCollider(), &result);

        if (isCollided)
        {
          iGO->onCollideWith(jGO->getCollider(), &result);
          jGO->onCollideWith(iGO->getCollider(), &result);
        }
      }
    }
  }
}
