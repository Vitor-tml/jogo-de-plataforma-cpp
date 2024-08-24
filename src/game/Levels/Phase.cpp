#include "Phase.h"

Phase::Phase() :
    Ente(gRecursos->getTexture("fundo")),
    jogador(gRecursos->getTexture("jogador")),
    inimigo(gRecursos->getTexture("inimigo")),
    listaEntidades()
{
    // Iniciar local?
    //sprite.setOrigin()
    sprite.setTextureRect(sf::IntRect(0, 200, 900, 600));
    listaEntidades.incluir(&jogador);
    listaEntidades.incluir(&inimigo);
}

int aux = 0;
void Phase::executar()
{
    deltaTime = tempo.restart().asSeconds();
    jogador.executar(deltaTime);

    gGrafico->clearDrawables();
    renderizar();
    jogador.renderizar();
    inimigo.executar(deltaTime);
    inimigo.renderizar();
    gGrafico->setCentroCamera(jogador.getPosicao().x, jogador.getPosicao().y); // Jogador controla a própria câmera ou a fase?
    gGrafico->render();
    
    listaEntidades.imprimirElementos();
    //jogador.renderizar();
    // Onde colocar o setCentroCamera?
}