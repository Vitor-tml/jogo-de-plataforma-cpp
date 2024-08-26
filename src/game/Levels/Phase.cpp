#include "Phase.h"

Phase::Phase() :
    Ente(gRecursos->getTexture("fundo")),
    jogador(gRecursos->getTexture("jogador")),
    inimigo(gRecursos->getTexture("inimigo")),
    plataforma(0, 500, gRecursos->getTexture("plataforma")),
    chao(0, -190, gRecursos->getTexture("chao"), 0, 726),
    listaEntidades(),
    gColisao(&jogador)
{
    // Iniciar local?
    //sprite.setOrigin()
    sprite.setTextureRect(sf::IntRect(0, 200, 900, 600));
    
    listaEntidades.incluir(&jogador);
    listaEntidades.incluir(&inimigo);
    gColisao.incluirObstaculo(&plataforma); 
    gColisao.incluirObstaculo(&chao); 
    gColisao.incluirInimigos(&inimigo); 
}

void Phase::executar()
{
    deltaTime = tempo.restart().asSeconds();
    gColisao.verificaColisaoObstaculo();
    gColisao.verificaColisaoInimigo();

    gGrafico->clearDrawables();
    
    renderizar(0);
    chao.renderizar(1);
    chao.renderizarCaixaColisao();

    jogador.executar(deltaTime);
    jogador.renderizar(2);
    jogador.renderizarCaixaColisao();
    
    plataforma.renderizar(1);
    plataforma.renderizarCaixaColisao();

    inimigo.executar(deltaTime);
    inimigo.renderizar(1);
    inimigo.renderizarCaixaColisao();
    
    gGrafico->setCentroCamera(jogador.getPosicao().x, jogador.getPosicao().y);
    gGrafico->render();
}