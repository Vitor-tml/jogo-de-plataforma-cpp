#ifndef _PHASE_H
#define _PHASE_H

#include "../../engine/Ente/Ente.h"
#include "../../engine/ResourceManager/ResourceManager.h"
#include "../../engine/CollisionManager/CollisionManager.h"
#include "../Character/Player/Player.h"
#include "../Character/Character.h"
#include "../Character/Enemy/Enemy.h"
#include "../Character/Enemy/Esqueleto.h"
#include "../Character/Enemy/Arqueiro.h"
#include "../../lists/ListaEntidades/ListaEntidades.h"
#include "../Obstacles/Plataforma.h"
#include "../Obstacles/Espinhos.h"
#include "../../engine/Savemanager/SaveManager.h"
#include "../Projectile/Projectile.h"

class Phase : public Ente {
protected:
    Player jogador;
    sf::Clock tempo;
    float deltaTime;
    ListaEntidades listaEntidades;
    SaveManager saveManager;
    CollisionManager gColisao;

    
public:
    Phase(sf::Texture& fundo);
    virtual ~Phase() noexcept {};
    virtual void executar();
    void gerenciarColisoes(){};
    void criarInimigos() {};
    void criarObstaculos() {};
    
};
#endif