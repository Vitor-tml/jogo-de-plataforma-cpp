#include "CollisionManager.h"
#include <math.h>
#include <set>
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
        {

        }
            // std::cout << "Jogador colidiu com um inimigo!" << std::endl;
    }
}

void CollisionManager::tratarColisoes(Obstacle* obstaculo)
{
    std::set<float> overlaps;
    sf::FloatRect playerBox = jogador->getCaixaColisao().getGlobalBounds();
    sf::FloatRect obstacleBox = obstaculo->getCaixaColisao().getGlobalBounds();

    const int ESQUERDA = 0;
    const int DIREITA  = 1;
    const int TOPO     = 2;
    const int FUNDO    = 3;
    float vJogador[4]   =  {playerBox.left, playerBox.left + playerBox.width,
                            playerBox.top, playerBox.top + playerBox.height};
    float vObstaculo[4] =  {obstacleBox.left, obstacleBox.left + obstacleBox.width,
                            obstacleBox.top, obstacleBox.top + obstacleBox.height};

    float overlapEsquerda = positivoOuLimite(vJogador[DIREITA]  - vObstaculo[ESQUERDA]);
    float overlapDireita  = positivoOuLimite(vObstaculo[DIREITA] - vJogador[ESQUERDA]);
    float overlapCima     = positivoOuLimite(vJogador[FUNDO]    - vObstaculo[TOPO]);
    float overlapBaixo    = positivoOuLimite(vObstaculo[FUNDO] - vJogador[TOPO]);

    float menorOverlap = std::min({overlapEsquerda, overlapDireita, overlapCima, overlapBaixo});
    
    if(menorOverlap == overlapEsquerda){
        // std::cout << "Esquerda" << std::endl;
        jogador->setPosicao(jogador->getPosicao() - sf::Vector2f(overlapEsquerda, 0));
        jogador->setVelocidade(sf::Vector2f(0, jogador->getVelocidade().y));
    }else if(menorOverlap == overlapDireita){
        // std::cout << "Direita" << std::endl;
        jogador->setPosicao(jogador->getPosicao() + sf::Vector2f(overlapDireita, 0));
        jogador->setVelocidade(sf::Vector2f(0, jogador->getVelocidade().y));
    }else if(menorOverlap == overlapCima){
        // std::cout << "Cima" << std::endl;
        jogador->setPosicao(jogador->getPosicao() - sf::Vector2f(0, overlapCima));
        jogador->setVelocidade(sf::Vector2f(jogador->getVelocidade().x, 0));
        jogador->setNoChao(true);
    }else if(menorOverlap == overlapBaixo){
        // std::cout << "Baixo" << std::endl;
        jogador->setPosicao(jogador->getPosicao() + sf::Vector2f(0, overlapBaixo));
        jogador->setVelocidade(sf::Vector2f(jogador->getVelocidade().x, 0));
        jogador->setNoChao(true);
    }
    
}

float positivoOuLimite(float a)
{
    if(a > 0)
        return a;
    return 1000000;
}