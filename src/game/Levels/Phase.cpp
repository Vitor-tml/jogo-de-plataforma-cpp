#include "Phase.h"

ResourceManager* Phase::gerenciadorDeRecursos = ResourceManager::getInstance();
Phase::Phase() :
    Ente(gerenciadorDeRecursos->getTexture("fundo")),
    jogador(gerenciadorDeRecursos->getTexture("jogador"))
{
    shape.setTextureRect(sf::IntRect(0, 200, 900, 600));
}

void Phase::executar()
{
    // deltaTime = tempo.restart().asSeconds();
    // jogador.executar(deltaTime);

    std::cout << "Cheguei aqui!" << std::endl;
    gerenciadorGrafico->clearDrawables();
    gerenciadorGrafico->addDrawable(shape);
    gerenciadorGrafico->render();
    
    // jogador.renderizar();
    // gerenciadorGrafico->setCentroCamera(jogador.getSprite().getPosition().x, jogador.getSprite().getPosition().y);
}