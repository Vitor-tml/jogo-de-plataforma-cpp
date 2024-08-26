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
        {
            tratarColisoes(obstaculo);
        }
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

void CollisionManager::tratarColisoes(Obstacle* obstaculo)
{
    sf::FloatRect playerBox = jogador->getCaixaColisao().getGlobalBounds();
    sf::FloatRect obstacleBox = obstaculo->getCaixaColisao().getGlobalBounds();

    float overlapX = std::min(playerBox.left + playerBox.width - obstacleBox.left,
                              obstacleBox.left + obstacleBox.width - playerBox.left);
    float overlapY = std::min(playerBox.top + playerBox.height - obstacleBox.top,
                              obstacleBox.top + obstacleBox.height - playerBox.top);

    if (overlapX < overlapY)
    {
        // Colisão horizontal
        if (playerBox.left < obstacleBox.left)
            jogador->setVelocidade(sf::Vector2f(-100.f, jogador->getVelocidade().y)); // Empurrar para a esquerda
        else
            jogador->setVelocidade(sf::Vector2f(100.f, jogador->getVelocidade().y)); // Empurrar para a direita
    }
    else
    {
        // Colisão vertical
        if (playerBox.top < obstacleBox.top)
        {
            jogador->setVelocidade(sf::Vector2f(jogador->getVelocidade().x, -100.f)); // Empurrar para cima
            jogador->setNoChao(true); // Marcar o jogador como estando no chão
        }
        else
        {
            jogador->setVelocidade(sf::Vector2f(jogador->getVelocidade().x, 100.f)); // Empurrar para baixo
        }
    }
}