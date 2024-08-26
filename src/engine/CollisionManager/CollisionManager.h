#ifndef _COLLISION_MANAGER_H
#define _COLLISION_MANAGER_H

#include <vector>
#include <list>
#include "../../game/Character/Enemy/Enemy.h"
#include "../../game/Obstacles/Obstacle.h"
class CollisionManager {
private:
    std::vector<Enemy*> lInimigos;
    std::list<Obstacle*> lObstaculos;  
public:
    void incluirObstaculos();
    void tratarColisoesObs();
    void tratarColisoes();
};
#endif