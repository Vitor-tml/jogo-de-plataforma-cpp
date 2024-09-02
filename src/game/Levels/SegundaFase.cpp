#include "SegundaFase.h"

SegundaFase::SegundaFase(Player* p, Player2 *p2) :
Phase(gRecursos->getTexture("fundo2"), p, p2),
chao(0, -190, gRecursos->getTexture("chao"), 0, 726),
esqueleto(gRecursos->getTexture("inimigo"), 1),
arqueiro(300, 500, gRecursos->getTexture("arqueiro"))
// bala(100, 450)
{
    bala = new Projetil(100, 450, 0, 0);
    // sprite.setTextureRect(sf::IntRect(0,0,0,0));
    listaEntidades.incluir(&chao);
    listaEntidades.incluir(&esqueleto);
    // listaEntidades.incluir(&arqueiro);
    listaEntidades.incluir(bala);

    gColisao.incluirObstaculo(&chao);
    gColisao.incluirInimigos(&esqueleto);
    // gColisao.incluirInimigos(&arqueiro);

    gColisao.incluirProjetil(bala);

    arqueiro.setBala(bala);
}

void SegundaFase::executar()
{
    deltaTime = tempo.restart().asSeconds();

    renderizar();
    for (int i = 0; i < listaEntidades.getTamanho(); i++) {
        if(listaEntidades[i] != nullptr){
        listaEntidades[i]->executar(deltaTime);
        listaEntidades[i]->renderizar(i + 1);
        listaEntidades[i]->renderizarCaixaColisao();
        }
    }

    //gGrafico->setCentroCamera(jogador.getPosicao().x, jogador.getPosicao().y); // Jogador controla a própria câmera ou a fase?
    gGrafico->render();
    
    gColisao.tratarColisoes();
    

    // Onde colocar o setCentroCamera?
    gGrafico->clearDrawables();
}