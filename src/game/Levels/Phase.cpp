#include "Phase.h"

Phase::Phase() :
    Ente(gRecursos->getTexture("fundo")),
    jogador(gRecursos->getTexture("jogador")),
    inimigo(gRecursos->getTexture("inimigo")),
    plataforma(0, 500, gRecursos->getTexture("plataforma")),
    plataforma2(0, 500, gRecursos->getTexture("plataforma")),
    plataforma3(100, 436, gRecursos->getTexture("plataforma")),
    chao(0, -190, gRecursos->getTexture("chao"), 0, 726),
    gColisao(&jogador),
    esfera(100, 200, gRecursos->getTexture("esfera")),
    espinho(100, 500, gRecursos->getTexture("espinho")),
    listaEntidades()
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
    listaEntidades.incluir(&espinho);
    listaEntidades.incluir(&esfera);
    gColisao.incluirObstaculo(&plataforma); 
    gColisao.incluirObstaculo(&plataforma2); 
    gColisao.incluirObstaculo(&plataforma3); 
    gColisao.incluirObstaculo(&chao); 
    gColisao.incluirObstaculo(&espinho); 
    gColisao.incluirObstaculo(&esfera);
    gColisao.incluirInimigos(&inimigo); 
}

void Phase::executar()
{
    deltaTime = tempo.restart().asSeconds();

    renderizar();
    for (int i = 0; i < listaEntidades.getTamanho(); i++) {
        listaEntidades[i]->executar(deltaTime);
        listaEntidades[i]->renderizar(i+1);
        listaEntidades[i]->renderizarCaixaColisao();
    }

    gGrafico->setCentroCamera(jogador.getPosicao().x, jogador.getPosicao().y); // Jogador controla a própria câmera ou a fase?
    gGrafico->render();
    
    gColisao.tratarColisoes();
    saveManager.saveEntidades(listaEntidades, "save.json");

    // Onde colocar o setCentroCamera?
    gGrafico->clearDrawables();
}