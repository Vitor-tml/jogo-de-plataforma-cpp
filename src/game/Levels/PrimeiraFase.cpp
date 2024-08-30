#include "PrimeiraFase.h"

PrimeiraFase::PrimeiraFase() :
    Phase(gRecursos->getTexture("fundo")),
    inimigo(gRecursos->getTexture("inimigo")),
    plataforma(0, 500, gRecursos->getTexture("plataforma")),
    plataforma2(0, 500, gRecursos->getTexture("plataforma")),
    plataforma3(100, 436, gRecursos->getTexture("plataforma")),
    bala(0, 400, gRecursos->getTexture("bala"), 0, 0),
    chao(0, -190, gRecursos->getTexture("chao"), 0, 726),
    legolas(300, 300, gRecursos->getTexture("arqueiro")),
    espinho(500, 500, gRecursos->getTexture("espinho"))
{
    // Iniciar local?
    //sprite.setOrigin()
    sprite.setTextureRect(sf::IntRect(0, 200, 900, 600));
    
    listaEntidades.incluir(&jogador);
    listaEntidades.incluir(&jogador2);
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
    
    gColisao2.incluirObstaculo(&plataforma); 
    gColisao2.incluirObstaculo(&plataforma2); 
    gColisao2.incluirObstaculo(&plataforma3); 
    gColisao2.incluirObstaculo(&chao); 
    gColisao2.incluirObstaculo(&espinho); 
    gColisao2.incluirInimigos(&inimigo); 
    gColisao2.incluirInimigos(&legolas); 
}

void PrimeiraFase::executar()
{
    deltaTime = tempo.restart().asSeconds();

    renderizar(0);
    for (int i = 0; i < listaEntidades.getTamanho(); i++) {
        listaEntidades[i]->executar(deltaTime);
        listaEntidades[i]->renderizar(i + 1);
        listaEntidades[i]->renderizarCaixaColisao();
    }

    //gGrafico->setCentroCamera(jogador.getPosicao().x, jogador.getPosicao().y); // Jogador controla a própria câmera ou a fase?
    gGrafico->render();
    
    gColisao.tratarColisoes();
    gColisao2.tratarColisoes();
    saveManager.saveEntidades(listaEntidades, "save.txt");

    // Onde colocar o setCentroCamera?
    gGrafico->clearDrawables();
}