#include "Plataforma.h"
#include <algorithm>
#include "../Character/Player/Player.h"

Plataforma::Plataforma(int xx, int yy, sf::Texture &textura, int offsetX, int offsetY):
    Obstacle(xx, yy, textura, offsetX, offsetY)
{
    // Colocar o empuxo para zerar a gravidade

}

void Plataforma::executar()
{
    
}

void Plataforma::obstacular(Player *jogador)
{   
    // std::cout << "Tratando colisao: Obstaculo jogador" << std::endl;
    sf::FloatRect playerBox   = jogador->getCaixaColisao().getGlobalBounds();
    sf::FloatRect obstacleBox = this->getCaixaColisao().getGlobalBounds();

    const int ESQUERDA = 0;
    const int DIREITA  = 1;
    const int TOPO     = 2;
    const int FUNDO    = 3;
    float vJogador[4]   =  {playerBox.left, playerBox.left + playerBox.width,
                            playerBox.top,  playerBox.top  + playerBox.height};
    float vObstaculo[4] =  {obstacleBox.left, obstacleBox.left + obstacleBox.width,
                            obstacleBox.top,  obstacleBox.top  + obstacleBox.height};

    float overlapEsquerda = std::min((vJogador[DIREITA]   - vObstaculo[ESQUERDA]), 1000000.f);
    float overlapDireita  = std::min((vObstaculo[DIREITA] - vJogador[ESQUERDA])  , 1000000.f);
    float overlapCima     = std::min((vJogador[FUNDO]     - vObstaculo[TOPO])    , 1000000.f);
    float overlapBaixo    = std::min((vObstaculo[FUNDO]   - vJogador[TOPO])      , 1000000.f);

    float menorOverlap = std::min({overlapEsquerda, overlapDireita, overlapCima, overlapBaixo});
    
    
    if(menorOverlap == overlapEsquerda){
        // std::cout << "Esquerda" << std::endl;
        jogador->setPosicao(jogador->getPosicao() - sf::Vector2f(overlapEsquerda, 0));
        jogador->setVelocidade(sf::Vector2f(10.f, jogador->getVelocidade().y));
    }else if(menorOverlap == overlapDireita){
        // std::cout << "Direita" << std::endl;
        jogador->setPosicao(jogador->getPosicao() + sf::Vector2f(overlapDireita, 0));
        jogador->setVelocidade(sf::Vector2f(-10.f, jogador->getVelocidade().y));
    }else if(menorOverlap == overlapCima){
        // std::cout << "Cima" << std::endl;
        // jogador->setPosicao(jogador->getPosicao() - sf::Vector2f(0, overlapCima));
        jogador->setVelocidade(sf::Vector2f(jogador->getVelocidade().x, -100.f));
        jogador->setNoChao(true);
    }else if(menorOverlap == overlapBaixo){
        // std::cout << "Baixo" << std::endl;
        jogador->setPosicao(jogador->getPosicao() + sf::Vector2f(0, overlapBaixo));
        jogador->setVelocidade(sf::Vector2f(jogador->getVelocidade().x, 100.f));
        jogador->setNoChao(true);
    }
}

void Plataforma::obstacular(Entity *p)
{   
    // std::cout << "Tratando colisao: Obstaculo entidade" << std::endl;
    sf::FloatRect playerBox   = p->getCaixaColisao().getGlobalBounds();
    sf::FloatRect obstacleBox = this->getCaixaColisao().getGlobalBounds();

    const int ESQUERDA = 0;
    const int DIREITA  = 1;
    const int TOPO     = 2;
    const int FUNDO    = 3;
    float vJogador[4]   =  {playerBox.left, playerBox.left + playerBox.width,
                            playerBox.top,  playerBox.top  + playerBox.height};
    float vObstaculo[4] =  {obstacleBox.left, obstacleBox.left + obstacleBox.width,
                            obstacleBox.top,  obstacleBox.top  + obstacleBox.height};

    float overlapEsquerda = std::min((vJogador[DIREITA]   - vObstaculo[ESQUERDA]), 1000000.f);
    float overlapDireita  = std::min((vObstaculo[DIREITA] - vJogador[ESQUERDA])  , 1000000.f);
    float overlapCima     = std::min((vJogador[FUNDO]     - vObstaculo[TOPO])    , 1000000.f);
    float overlapBaixo    = std::min((vObstaculo[FUNDO]   - vJogador[TOPO])      , 1000000.f);

    float menorOverlap = std::min({overlapEsquerda, overlapDireita, overlapCima, overlapBaixo});
    
    if(menorOverlap == overlapEsquerda){
        // std::cout << "Esquerda" << std::endl;
        p->setPosicao(p->getPosicao() - sf::Vector2f(overlapEsquerda + 1, 0));
        p->setVelocidade(sf::Vector2f(-10.f, p->getVelocidade().y));
    }else if(menorOverlap == overlapDireita){
        // std::cout << "Direita" << std::endl;
        p->setPosicao(p->getPosicao() + sf::Vector2f(overlapDireita + 1, 0));
        p->setVelocidade(sf::Vector2f(10.f, p->getVelocidade().y));
    }else if(menorOverlap == overlapCima){
        // std::cout << "Cima" << std::endl;
        // p->setPosicao(p->getPosicao() - sf::Vector2f(0, overlapCima));
        p->setVelocidade(sf::Vector2f(p->getVelocidade().x, -10.f));
        p->setNoChao(true);
    }else if(menorOverlap == overlapBaixo){
        // std::cout << "Baixo" << std::endl;
        p->setPosicao(p->getPosicao() + sf::Vector2f(0, overlapBaixo));
        p->setVelocidade(sf::Vector2f(p->getVelocidade().x, 10.f));
        p->setNoChao(true);
    }
}