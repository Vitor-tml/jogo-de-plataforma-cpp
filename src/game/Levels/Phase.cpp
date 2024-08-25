#include "Phase.h"

Phase::Phase() :
    Ente(gRecursos->getTexture("fundo")),
    jogador(gRecursos->getTexture("jogador")),
    inimigo(gRecursos->getTexture("inimigo")),
    listaEntidades(),
    plataforma(0, 500, gRecursos->getTexture("plataforma")),
    gColisao(&jogador)
{
    // Iniciar local?
    //sprite.setOrigin()
    sprite.setTextureRect(sf::IntRect(0, 200, 900, 600));
    
    listaEntidades.incluir(&jogador);
    listaEntidades.incluir(&inimigo);
    gColisao.incluirObstaculo(&plataforma);   
}

int aux = 0;
void Phase::executar()
{
    deltaTime = tempo.restart().asSeconds();
    jogador.executar(deltaTime);
    gColisao.verificaColisaoObstaculo();

    gGrafico->clearDrawables();
    renderizar();
    plataforma.renderizar();
    plataforma.renderizarCaixaColisao();
    jogador.renderizar();
    inimigo.executar(deltaTime);
    inimigo.renderizar();
    jogador.renderizarCaixaColisao();
    gGrafico->setCentroCamera(jogador.getPosicao().x, jogador.getPosicao().y); // Jogador controla a própria câmera ou a fase?
    gGrafico->render();
    
    //listaEntidades.imprimirElementos();
    //jogador.renderizar();
    // Onde colocar o setCentroCamera?
}