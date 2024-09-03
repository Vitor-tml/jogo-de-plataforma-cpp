#include "TerceiraFase.h"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

TerceiraFase::TerceiraFase(Player* p, Player2* p2): 
    Phase(gRecursos->getTexture("fundo2"), p, p2),
    chao(0, -190, gRecursos->getTexture("chao"), 0, 726)
{
    listaEntidades.incluir(&chao);
    gColisao.incluirObstaculo(&chao);

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
            criarEntidades(tipo, jEntidade["dados"]);
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

void TerceiraFase::criarEntidades(const std::string& tipo, const json& dados)
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
        listaEntidades.incluir(jogador);
    }
    else if (tipo == "Arqueiro") {
        if (dados.contains("posX") && dados.contains("posY")) {
            int posX = dados["posX"];
            int posY = dados["posY"];
            Arqueiro* arqueiro = new Arqueiro(posX, posY, gRecursos->getTexture("arqueiro"));
            listaEntidades.incluir(arqueiro);
            gColisao.incluirInimigos(arqueiro);
        }
    }
    else if (tipo == "Esqueleto") {
        if (dados.contains("posX") && dados.contains("posY")) {
            int posX = dados["posX"];
            int posY = dados["posY"];
            int maldade = 1;
            if (dados.contains("maldade")) {
                maldade = dados["maldade"];
            }
            Esqueleto* esqueleto = new Esqueleto(gRecursos->getTexture("esqueleto"), maldade, posX, posY);
            listaEntidades.incluir(esqueleto);
            gColisao.incluirInimigos(esqueleto);
        }
    }
    else if (tipo == "EsferaMagica") {
        if (dados.contains("posX") && dados.contains("posY")) {
            int posX = dados["posX"];
            int posY = dados["posY"];
            EsferaMagica* esfera = new EsferaMagica(posX, posY, gRecursos->getTexture("esfera_magica"));
            listaEntidades.incluir(esfera);
            gColisao.incluirObstaculo(esfera); 
        }
    }
    else if (tipo == "Espinhos") {
        if (dados.contains("posX") && dados.contains("posY")) {
            int posX = dados["posX"];
            int posY = dados["posY"];
            Espinhos* espinhos = new Espinhos(posX, posY, gRecursos->getTexture("espinhos"));
            listaEntidades.incluir(espinhos);
            gColisao.incluirObstaculo(espinhos);
        }
    }
}