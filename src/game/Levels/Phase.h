#ifndef _PHASE_H
#define _PHASE_H

#include "../../engine/Ente/Ente.h"
#include "../../engine/ResourceManager/ResourceManager.h"
#include "../../engine/CollisionManager/CollisionManager.h"
#include "../Character/Player/Player.h"
class Phase : public Ente {
private:
    Player jogador;
    sf::Clock tempo;
    float deltaTime;

    CollisionManager gColisao;
    Obstacle plataforma;

public:
    Phase();
    virtual ~Phase() noexcept {};
    virtual void executar();
    void gerenciarColisoes() {};
    void criarInimigos() {};
    void criarObstaculos() {};
    
};
#endif