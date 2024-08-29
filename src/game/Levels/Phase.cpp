#include "Phase.h"

Phase::Phase() :
    Ente(gRecursos->getTexture("fundo")),
    jogador(gRecursos->getTexture("jogador")),
    inimigo(gRecursos->getTexture("inimigo")),
    plataforma(0, 500, gRecursos->getTexture("plataforma")),
    plataforma2(0, 500, gRecursos->getTexture("plataforma")),
    plataforma3(100, 436, gRecursos->getTexture("plataforma")),
    bala(0, 400, gRecursos->getTexture("bala"), 0, 0),
    chao(0, -190, gRecursos->getTexture("chao"), 0, 726),
    legolas(300, 300, gRecursos->getTexture("arqueiro")),
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
    listaEntidades.incluir(&espinho);
    listaEntidades.incluir(&bala);
    listaEntidades.incluir(&legolas);
    gColisao.incluirObstaculo(&plataforma); 
    gColisao.incluirObstaculo(&plataforma2); 
    gColisao.incluirObstaculo(&plataforma3); 
    gColisao.incluirObstaculo(&chao); 
    gColisao.incluirObstaculo(&espinho); 
    gColisao.incluirInimigos(&inimigo); 
    gColisao.incluirInimigos(&legolas); 
}

void Phase::executar()
{
    deltaTime = tempo.restart().asSeconds();

    renderizar(0);
    for (int i = 0; i < listaEntidades.getTamanho(); i++) {
        listaEntidades[i]->executar(deltaTime);
        listaEntidades[i]->renderizar(i + 1);
        listaEntidades[i]->renderizarCaixaColisao();
    }

    gGrafico->setCentroCamera(jogador.getPosicao().x, jogador.getPosicao().y); // Jogador controla a própria câmera ou a fase?
    gGrafico->render();
    
    gColisao.tratarColisoes();
    saveManager.saveEntidades(listaEntidades, "save.txt");

    // Onde colocar o setCentroCamera?
    gGrafico->clearDrawables();
}