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
    gColisao.incluirInimigos(&inimigo); 
}

int aux = 0;
void Phase::executar()
{
    deltaTime = tempo.restart().asSeconds();
    gColisao.verificaColisaoObstaculo();
    gColisao.verificaColisaoInimigo();

    gGrafico->clearDrawables();
    
    renderizar(0);
    jogador.executar(deltaTime);
    jogador.renderizar(2);
    jogador.renderizarCaixaColisao();
    
    plataforma.renderizar(1);
    plataforma.renderizarCaixaColisao();

    inimigo.executar(deltaTime);
    inimigo.renderizar(1);
    inimigo.renderizarCaixaColisao();
    
    gGrafico->setCentroCamera(jogador.getPosicao().x, jogador.getPosicao().y); // Jogador controla a própria câmera ou a fase?
    gGrafico->render();
    
    //listaEntidades.imprimirElementos();
    //jogador.renderizar();
    // Onde colocar o setCentroCamera?
}