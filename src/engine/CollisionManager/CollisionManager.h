#ifndef _COLLISION_MANAGER_H
#define _COLLISION_MANAGER_H

#include <vector>
#include <list>
#include "../../game/Character/Enemy/Enemy.h"
#include "../../game/Obstacles/Obstacle.h"
#include "../../game/Character/Player/Player.h"
class CollisionManager {
private:
    std::vector<Enemy*> lInimigos;
    std::list<Obstacle*> lObstaculos;
    Player* jogador;
public:
    CollisionManager(): jogador(nullptr)    {};
    CollisionManager(Player *p): jogador(p) {};
    ~CollisionManager();
    void incluirObstaculo(Obstacle *p);
    void incluirInimigos(Enemy *p);
    void verificaColisaoObstaculo();
    void verificaColisaoInimigo();
    void tratarColisoesObstaculo(Obstacle* obstaculo);
    void CollisionManager::tratarColisoesInimigoObstaculo(Enemy* inimigo, Obstacle* obstaculo);
    // void verificaColisao();
};

float positivoOuLimite(float a);
#endif