#ifndef _PHASE_H
#define _PHASE_H

#include "../../engine/Ente/Ente.h"
#include "../../engine/ResourceManager/ResourceManager.h"
#include "../Character/Player/Player.h"

class Phase : public Ente {
private:
    Player jogador;
    static ResourceManager* gerenciadorDeRecursos;
    sf::Clock tempo;
    float deltaTime;
public:
    Phase();
    ~Phase() {};
    virtual void executar();
    void gerenciarColisoes() {};
    void criarInimigos() {};
    void criarObstaculos() {};
};
#endif