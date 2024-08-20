#include "Phase.h"

ResourceManager* Phase::gerenciadorDeRecursos = ResourceManager::getInstance();
Phase::Phase() :
    Ente(gerenciadorDeRecursos->getTexture("fundo")),
    jogador(gerenciadorDeRecursos->getTexture("jogador"))
{
    sprite.setTextureRect(sf::IntRect(0, 200, 900, 600));
}

int aux = 0;
void Phase::executar()
{
    deltaTime = tempo.restart().asSeconds();
    jogador.executar(deltaTime);

    gerenciadorGrafico->clearDrawables();
    renderizar();
    jogador.renderizar();
    gerenciadorGrafico->setCentroCamera(jogador.getPosicao().x, jogador.getPosicao().y);
    gerenciadorGrafico->render();
    

    //jogador.renderizar();
    // Onde colocar o setCentroCamera?
}