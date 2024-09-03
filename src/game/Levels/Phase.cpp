#include "Phase.h"

Phase::Phase(sf::Texture& fundo, Player *p, Player2 *p2) :
    Ente(fundo),
    listaEntidades(),
    gColisao(jogador, jogador2),
    jogador(p),
    jogador2(p2)
{
    // Iniciar local?
    //sprite.setOrigin()
    sprite.setTextureRect(sf::IntRect(0, 200, 900, 600));
    listaEntidades.incluir(jogador);
    listaEntidades.incluir(jogador2);
}

void Phase::executar()
{
        
    deltaTime = tempo.restart().asSeconds();

    renderizar(0);
    for (int i = 0; i < listaEntidades.getTamanho(); i++) {
        if(listaEntidades[i] != nullptr && listaEntidades[i]->getExecutar()){
        listaEntidades[i]->executar(deltaTime);
        listaEntidades[i]->renderizar(i + 1);
        listaEntidades[i]->renderizarCaixaColisao();
        }
    }
    gerenciarColisoes();
    gGrafico->render();
    gGrafico->clearDrawables();
}

void Phase::gerenciarColisoes()
{
    gColisao.tratarColisoes();
}