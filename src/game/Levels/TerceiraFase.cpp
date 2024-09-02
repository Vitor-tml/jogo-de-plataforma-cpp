#include "TerceiraFase.h"

TerceiraFase::TerceiraFase(Player* p, Player2 *p2)
    : Phase(gRecursos->getTexture("fundo2"), p, p2)
{
    listaEntidades = saveManager.loadEntidades();
}

void TerceiraFase::executar()
{
    deltaTime = tempo.restart().asSeconds();

    renderizar(0);
    for (int i = 0; i < listaEntidades.getTamanho(); i++) {
        listaEntidades[i]->executar(deltaTime);
        listaEntidades[i]->renderizar(i + 1);
        listaEntidades[i]->renderizarCaixaColisao();
    }

    gGrafico->render();
    gColisao.tratarColisoes();
    gGrafico->clearDrawables();
    
    saveManager.saveEntidades(listaEntidades, "save.json");
}
