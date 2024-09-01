#include "SegundaFase.h"

SegundaFase::SegundaFase() :
Phase(gRecursos->getTexture("fundo2")),
chao(0, -190, gRecursos->getTexture("chao"), 0, 726),
esqueleto(gRecursos->getTexture("inimigo"), 1),
arqueiro(100, 500, gRecursos->getTexture("arqueiro"))
{
    // sprite.setTextureRect(sf::IntRect(0,0,0,0));
    listaEntidades.incluir(&chao);
    listaEntidades.incluir(&esqueleto);
    // listaEntidades.incluir(&arqueiro);

    gColisao.incluirObstaculo(&chao);
    gColisao.incluirInimigos(&esqueleto);
    // gColisao.incluirInimigos(&arqueiro);

}

void SegundaFase::executar()
{
    deltaTime = tempo.restart().asSeconds();

    renderizar();
     for (int i = 0; i < listaEntidades.getTamanho(); i++) {
        listaEntidades[i]->executar(deltaTime);
        listaEntidades[i]->renderizar(i + 1);
        listaEntidades[i]->renderizarCaixaColisao();
    }

    //gGrafico->setCentroCamera(jogador.getPosicao().x, jogador.getPosicao().y); // Jogador controla a própria câmera ou a fase?
    gGrafico->render();
    
    gColisao.tratarColisoes();
    
    saveManager.saveEntidades(listaEntidades, "save.txt");

    // Onde colocar o setCentroCamera?
    gGrafico->clearDrawables();
}