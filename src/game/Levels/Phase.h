#ifndef _PHASE_H
#define _PHASE_H

#include "../../engine/Ente/Ente.h"
#include "../../engine/ResourceManager/ResourceManager.h"
#include "../../engine/CollisionManager/CollisionManager.h"
#include "../Character/Player/Player.h"
#include "../Character/Enemy/Enemy.h"
#include "../../lists/ListaEntidades/ListaEntidades.h"

class Phase : public Ente {
private:
    Player jogador;
    Enemy inimigo;
    sf::Clock tempo;
    float deltaTime;
    ListaEntidades listaEntidades;

    CollisionManager gColisao;
    Obstacle plataforma;
    Obstacle plataforma2;
    Obstacle plataforma3;
    Obstacle chao;

public:
    Phase();
    virtual ~Phase() noexcept {};
    virtual void executar();
    void gerenciarColisoes() {};
    void criarInimigos() {};
    void criarObstaculos() {};
    
};
#endif