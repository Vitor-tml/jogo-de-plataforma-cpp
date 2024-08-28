#include "CollisionManager.h"
#include <algorithm>
#include <math.h>
#include <set>
CollisionManager::~CollisionManager()
{
    lObstaculos.clear();
    lInimigos.clear();
}

void CollisionManager::tratarColisoes()
{
    tratarColisoesJogadorObstaculo();
    tratarColisoesInimigoObstaculo();
}


void CollisionManager::incluirObstaculo(Obstacle *p)
{
    if(p == nullptr)
    {
        std::cout << "ERRO: Obstaculo nulo sendo inserido" << std::endl;
        return;
    }

    lObstaculos.push_back(p);
}

void CollisionManager::incluirInimigos(Enemy *p)
{
    if(p == nullptr)
    {
        std::cout << "ERRO: Inimigo nulo sendo inserido" << std::endl;
        return;
    }

    lInimigos.push_back(p);
}

void CollisionManager::tratarColisoesJogadorObstaculo()
{
    if(jogador == nullptr)
    {
        std::cout << "TratarColisoesJogadorObstaculo: Jogador nulo." << std::endl;
        return;
    }
    jogador->setNoChao(false);   
    for(Obstacle* obstaculo : lObstaculos)
    {
        if(jogador->getCaixaColisao().getGlobalBounds().intersects(obstaculo->getCaixaColisao().getGlobalBounds()))
        {
            // std::cout << "Colisao: jogador/obstaculo" << std::endl;
            obstaculo->obstacular(jogador);
        }
    }
}
void CollisionManager::tratarColisoesInimigoObstaculo()
{
    for(Enemy* inimigo : lInimigos){
        for(Obstacle* obstaculo : lObstaculos){
            if(inimigo->getCaixaColisao().getGlobalBounds().intersects(obstaculo->getCaixaColisao().getGlobalBounds())){
                obstaculo->obstacular(inimigo);
            }
        }

    }
}
void tratarColisoesJogadorInimigo();