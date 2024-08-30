#ifndef _COLLISION_MANAGER_H
#define _COLLISION_MANAGER_H

#include <vector>
#include <list>
#include "../../game/Character/Enemy/Enemy.h"
#include "../../game/Character/Player/Player.h"
#include "../../game/Character/Player/Player2.h"
#include "../../game/Obstacles/Obstacle.h"
class CollisionManager {
private:
    std::vector<Enemy*> lInimigos;
    std::list<Obstacle*> lObstaculos;
    Player* jogador;
    Player2* jogador2;
public:
    CollisionManager(): jogador(nullptr), jogador2(nullptr)    {};
    CollisionManager(Player *p, Player2 *q): jogador(p), jogador2(q) {};
    ~CollisionManager();
    
    void incluirObstaculo(Obstacle *p);
    void incluirInimigos(Enemy *p);
    void tratarColisoesJogadorObstaculo();
    void tratarColisoesInimigoObstaculo();
    void tratarColisoes();
    // void tratarColisoesJogadorInimigo();
};
#endif