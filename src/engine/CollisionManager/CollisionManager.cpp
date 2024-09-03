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
    tratarColisoesJogadorInimigo();
    tratarColisoesInimigoObstaculo();
    tratarColisoesJogadorProjetil();
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

void CollisionManager::incluirProjetil(Projetil *p)
{
    if(p == nullptr)
    {
        std::cout << "ERRO: Obstaculo nulo sendo inserido" << std::endl;
        return;
    }

    lProjetil.push_back(p);
}

void CollisionManager::tratarColisoesJogadorObstaculo()
{
    if(jogador == nullptr)
    {
        std::cout << "TratarColisoesJogadorObstaculo: Jogador nulo." << std::endl;
        return;
    }
    jogador->setNoChao(false); 
    jogador2->setNoChao(false);
    for(Obstacle* obstaculo : lObstaculos)
    {
        if(jogador->getCaixaColisao().getGlobalBounds().intersects(obstaculo->getCaixaColisao().getGlobalBounds()))
        {
            // std::cout << "Colisao: jogador/obstaculo" << std::endl;
            obstaculo->obstacular(jogador);
        }
        if(jogador2->getCaixaColisao().getGlobalBounds().intersects(obstaculo->getCaixaColisao().getGlobalBounds()))
        {
            // std::cout << "Colisao: jogador/obstaculo" << std::endl;
            obstaculo->obstacular(jogador2);
        }
    }
}
void CollisionManager::tratarColisoesInimigoObstaculo()
{
    for(Enemy* inimigo : lInimigos){
        inimigo->setNoChao(false);
        for(Obstacle* obstaculo : lObstaculos){
            if(inimigo->getCaixaColisao().getGlobalBounds().intersects(obstaculo->getCaixaColisao().getGlobalBounds())){
                obstaculo->obstacular(inimigo);
            }
        }

    }
}

void CollisionManager::tratarColisoesJogadorInimigo()
{
    std::vector<Enemy*>::iterator it = lInimigos.begin();
    while (it != lInimigos.end())
    {
        Enemy* inimigo = *it;

        if (jogador->getCaixaColisao().getGlobalBounds().intersects(inimigo->getCaixaColisao().getGlobalBounds()))
        {
            if (jogador->getAtaque()) {
                inimigo->operator--();
                // Verifica se o inimigo foi derrotado
                if (inimigo->getVida() <= 0) {
                    // std::cout << "Inimigo derrotado" << std::endl;
                    jogador++;
                    it = lInimigos.erase(it); // Remove o inimigo e atualiza o iterador
                    continue; // Pula para a próxima iteração sem incrementar o iterador
                }
            } else {
                inimigo->danificar(jogador);
            }
        }

        if (jogador2->getCaixaColisao().getGlobalBounds().intersects(inimigo->getCaixaColisao().getGlobalBounds()))
        {
            if (jogador2->getAtaque()) {
                inimigo->operator--();
                if (inimigo->getVida() <= 0) {
                    it = lInimigos.erase(it);
                    jogador2++;
                    continue;
                }
            } else {
                inimigo->danificar(jogador2);
            }
        }

        ++it; // Incrementa o iterador apenas se não foi removido
    }
}


void CollisionManager::tratarColisoesJogadorProjetil()
{
    for(Projetil* bala : lProjetil){
        if(jogador->getCaixaColisao().getGlobalBounds().intersects(bala->getCaixaColisao().getGlobalBounds()))
            bala->danificar(jogador);
        if(jogador2->getCaixaColisao().getGlobalBounds().intersects(bala->getCaixaColisao().getGlobalBounds()))
            bala->danificar(jogador2);
    }    
}