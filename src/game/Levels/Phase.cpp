#include "Phase.h"

Phase::Phase() :
    Ente(gRecursos->getTexture("fundo")),
    jogador(gRecursos->getTexture("jogador")),
    inimigo(gRecursos->getTexture("inimigo")),
    plataforma(0, 500, gRecursos->getTexture("plataforma")),
    plataforma2(0, 500, gRecursos->getTexture("plataforma")),
    plataforma3(100, 436, gRecursos->getTexture("plataforma")),
    chao(0, -190, gRecursos->getTexture("chao"), 0, 726),
    listaEntidades(),
    gColisao(&jogador),
    espinho(100, 500, gRecursos->getTexture("espinho"))
{
    // Iniciar local?
    //sprite.setOrigin()
    sprite.setTextureRect(sf::IntRect(0, 200, 900, 600));
    
    listaEntidades.incluir(&jogador);
    listaEntidades.incluir(&inimigo);
    listaEntidades.incluir(&plataforma);
    listaEntidades.incluir(&plataforma2);
    listaEntidades.incluir(&plataforma3);
    listaEntidades.incluir(&chao);
    gColisao.incluirObstaculo(&plataforma); 
    gColisao.incluirObstaculo(&plataforma2); 
    gColisao.incluirObstaculo(&plataforma3); 
    gColisao.incluirObstaculo(&chao); 
    gColisao.incluirObstaculo(&espinho); 
    gColisao.incluirInimigos(&inimigo); 
}

void Phase::executar()
{
    deltaTime = tempo.restart().asSeconds();
    
    gGrafico->clearDrawables();
    jogador.setNoChao(false);
    
    
    
    gColisao.tratarColisoes();
    renderizar(0);

    espinho.renderizar();
    espinho.renderizarCaixaColisao();

    chao.renderizar(1);
    chao.renderizarCaixaColisao();

    
    jogador.executar(deltaTime);
    jogador.renderizar(2);
    jogador.renderizarCaixaColisao();
    
    plataforma.renderizar(1);
    plataforma.renderizarCaixaColisao();
    plataforma2.renderizar(1);
    plataforma2.renderizarCaixaColisao();
    plataforma3.renderizar(1);
    plataforma3.renderizarCaixaColisao();

    inimigo.executar(deltaTime);
    inimigo.renderizar(1);
    inimigo.renderizarCaixaColisao();
    
    
    gGrafico->setCentroCamera(jogador.getPosicao().x, jogador.getPosicao().y);
    gGrafico->render();
}