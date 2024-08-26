#include "CollisionManager.h"

CollisionManager::~CollisionManager()
{
    lObstaculos.clear();
    lInimigos.clear();
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

void CollisionManager::verificaColisaoObstaculo()
{
    if(jogador == nullptr)
    {
        std::cout << "ERRO: Jogador nulo, colisao com obstaculos." << std::endl;
        return;
    }
    for(Obstacle* obstaculo : lObstaculos)
    {
        if(jogador->getCaixaColisao().getGlobalBounds().intersects(obstaculo->getCaixaColisao().getGlobalBounds()))
        {}
            // std::cout << "Jogador colidiu com um obstaculo!" << std::endl;
    }
}

void CollisionManager::verificaColisaoInimigo()
{
    if(jogador == nullptr)
    {
        std::cout << "ERRO: Jogador nulo, colisao com obstaculos." << std::endl;
        return;
    }
    for(Enemy* inimigo : lInimigos)
    {
        if(jogador->getCaixaColisao().getGlobalBounds().intersects(inimigo->getCaixaColisao().getGlobalBounds()))
        {}
            // std::cout << "Jogador colidiu com um inimigo!" << std::endl;
    }
}

void CollisionManager::tratarColisoes()
{

}