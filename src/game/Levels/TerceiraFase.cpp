#include "TerceiraFase.h"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

TerceiraFase::TerceiraFase(Player* p, Player2* p2)
    : Phase(gRecursos->getTexture("fundo2"), p, p2)
{
    std::ifstream arquivo("save.json");
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo save.json" << std::endl;
        return;
    }

    json jLista;
    try {
        arquivo >> jLista;
        if (arquivo.fail()) {
            throw std::ios_base::failure("Erro ao ler o arquivo save.json");
        }

        for (const auto& jEntidade : jLista) {
            std::string tipo = jEntidade["tipo"];
            criarEntidadeDoTipo(tipo, jEntidade["dados"]);
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro ao carregar entidades: " << e.what() << std::endl;
    }
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
    
    // saveManager.saveEntidades(listaEntidades, "save.json");
}

void TerceiraFase::criarEntidadeDoTipo(const std::string& tipo, const json& dados)
{
    if (tipo == "Player") {
        Player* jogador = new Player(gRecursos->getTexture("jogador"));
        if (dados.contains("posX") && dados.contains("posY")) {
            int posX = dados["posX"];
            int posY = dados["posY"];
            jogador->setPosicao(posX, posY);
        }
        if (dados.contains("vida")) {
            int vida = dados["vida"];
            jogador->setVida(vida);
        }

        listaEntidades.incluir(jogador);;
    }
    else if (tipo == "Enemy") {
        Enemy* inimigo = new Enemy(gRecursos->getTexture("enemy"));
        listaEntidades.incluir(inimigo);
    }
    else if (tipo == "Obstacle") {
        Obstacle* obstaculo = new Obstacle(gRecursos->getTexture("obstacle"));
        listaEntidades.incluir(obstaculo);
    }
}
