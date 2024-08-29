#ifndef _PHASE_H
#define _PHASE_H

#include "../../engine/Ente/Ente.h"
#include "../../engine/ResourceManager/ResourceManager.h"
#include "../../engine/CollisionManager/CollisionManager.h"
#include "../Character/Player/Player.h"
#include "../Character/Character.h"
#include "../Character/Enemy/Enemy.h"
#include "../Character/Enemy/Esqueleto.h"
#include "../../lists/ListaEntidades/ListaEntidades.h"
#include "../Obstacles/Plataforma.h"
#include "../Obstacles/Espinhos.h"
#include "../../engine/Savemanager/SaveManager.h"
#include "../Projectile/Projectile.h"
class Phase : public Ente {
private:
    Player jogador;
    Esqueleto inimigo;
    sf::Clock tempo;
    float deltaTime;
    ListaEntidades listaEntidades;

    CollisionManager gColisao;
    Plataforma plataforma;
    Plataforma chao;
    Plataforma plataforma2;
    Plataforma plataforma3;
    Espinhos espinho;
    SaveManager saveManager;
    Projetctile bala;
public:
    Phase();
    virtual ~Phase() noexcept {};
    virtual void executar();
    void gerenciarColisoes() {};
    void criarInimigos() {};
    void criarObstaculos() {};
    
};
#endif