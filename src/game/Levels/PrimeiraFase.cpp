#include "PrimeiraFase.h"

PrimeiraFase::PrimeiraFase(Player* p, Player2 *p2):
    Phase(gRecursos->getTexture("fundo"), p, p2),
    inimigo(gRecursos->getTexture("inimigo")),
    plataforma(0, 500, gRecursos->getTexture("plataforma")),
    plataforma2(0, 500, gRecursos->getTexture("plataforma")),
    plataforma3(100, 436, gRecursos->getTexture("plataforma")),
    bala(0, 400),
    chao(0, -190, gRecursos->getTexture("chao"), 0, 726),
    legolas(300, 300, gRecursos->getTexture("arqueiro")),
    espinho(500, 500, gRecursos->getTexture("espinho")),
    esfera(500, 500, gRecursos->getTexture("esfera"))
{
    // Iniciar local?
    //sprite.setOrigin()
    sprite.setTextureRect(sf::IntRect(0, 200, 900, 600));
    
    
    // ========= Entidade
    listaEntidades.incluir(&inimigo);
    listaEntidades.incluir(&plataforma);
    listaEntidades.incluir(&plataforma2);
    listaEntidades.incluir(&plataforma3);
    listaEntidades.incluir(&chao);
    listaEntidades.incluir(&espinho);
    listaEntidades.incluir(&bala);
    listaEntidades.incluir(&legolas);
    listaEntidades.incluir(&esfera);

    // ======== Colisao
    gColisao.incluirObstaculo(&plataforma); 
    gColisao.incluirObstaculo(&plataforma2); 
    gColisao.incluirObstaculo(&plataforma3); 
    gColisao.incluirObstaculo(&chao); 
    gColisao.incluirObstaculo(&espinho); 
    gColisao.incluirObstaculo(&esfera);

    gColisao.incluirInimigos(&inimigo); 
    gColisao.incluirInimigos(&legolas); 
    
    gColisao.incluirProjetil(&bala);

    // ======== Relações
    legolas.setBala(&bala);
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
    
    saveManager.saveEntidades(listaEntidades, "save.json");

    // Onde colocar o setCentroCamera?
    gGrafico->clearDrawables();
}