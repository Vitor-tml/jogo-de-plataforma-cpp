#include "Phase.h"

Phase::Phase() :
    Ente(gRecursos->getTexture("fundo")),
    jogador(gRecursos->getTexture("jogador"))
{
    // Iniciar local?
    //sprite.setOrigin()
    sprite.setTextureRect(sf::IntRect(0, 200, 900, 600));
}

int aux = 0;
void Phase::executar()
{
    deltaTime = tempo.restart().asSeconds();
    jogador.executar(deltaTime);

    gGrafico->clearDrawables();
    renderizar();
    jogador.renderizar();
    gGrafico->setCentroCamera(jogador.getPosicao().x, jogador.getPosicao().y); // Jogador controla a própria câmera ou a fase?
    gGrafico->render();
    

    //jogador.renderizar();
    // Onde colocar o setCentroCamera?
}