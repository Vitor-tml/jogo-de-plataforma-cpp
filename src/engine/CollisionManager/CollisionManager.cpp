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
    for(Enemy* inimigo : lInimigos){
        if(jogador->getCaixaColisao().getGlobalBounds().intersects(inimigo->getCaixaColisao().getGlobalBounds()))
            inimigo->danificar(jogador);
        if(jogador2->getCaixaColisao().getGlobalBounds().intersects(inimigo->getCaixaColisao().getGlobalBounds()))
            inimigo->danificar(jogador2);
    }
}

int CollisionManager::tratarColisoesJogadorProjetil()
{
    int aux = -1;
    for(std::vector<Projetil*>::iterator it = lProjetil.begin(); it != lProjetil.end();)
    {
        Projetil* bala = *it;

        if(jogador->getCaixaColisao().getGlobalBounds().intersects(bala->getCaixaColisao().getGlobalBounds()))
        {
            std::cout << "Jogador1" << std::endl;
            bala->danificar(jogador);
            aux = bala->getID();
            // Remover a bala da lista após colidir e causar dano ao jogador
            // delete bala;
            it = lProjetil.erase(it);
        }
        else if(jogador2->getCaixaColisao().getGlobalBounds().intersects(bala->getCaixaColisao().getGlobalBounds()))
        {
            std::cout << "Jogador2" << std::endl;
            bala->danificar(jogador2);
            aux = bala->getID();
            // Remover a bala da lista após colidir e causar dano ao segundo jogador
            // delete bala;
            it = lProjetil.erase(it);
        }
        else
        {
            ++it;
        }
    }
    return aux;
}