#include "Phase.h"

Phase::Phase(sf::Texture& fundo) :
    Ente(gRecursos->getTexture("fundo")),
    jogador(gRecursos->getTexture("jogador")),
    jogador2(gRecursos->getTexture("jogador")),
    listaEntidades(),
    gColisao(&jogador, &jogador2)
{
    // Iniciar local?
    //sprite.setOrigin()
    sprite.setTextureRect(sf::IntRect(0, 200, 900, 600));
    listaEntidades.incluir(&jogador);
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
    saveManager.saveEntidades(listaEntidades, "save.json");

    // Onde colocar o setCentroCamera?
    gGrafico->clearDrawables();
}