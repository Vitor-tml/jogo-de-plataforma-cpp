#include "LeadBoard.h"
#include<iostream>
#include <fstream>
#include <string>
LeadBoard::LeadBoard() : 
Ente(gRecursos->getTexture("menu")),
pontuacoes()
{

}

LeadBoard::~LeadBoard() {}

void LeadBoard::executar() 
{
    // carregarPontos();
    mostrarTela();
}

std::string LeadBoard::getNomeJogador() const
{
    // Pensar como a gente vai pegar o nome do jogador
    return "Nome de teste";
}

void LeadBoard::salvarPontos(Player* jogador)
{
    // Carrega pontuações existentes no arquivo:
    std::ifstream inFile("pontos.json");
    nlohmann::json jsonData;

    if (inFile.is_open()) {
        inFile >> jsonData;
        inFile.close();
    } else {
        std::cout << "Arquivo não abriu!" << std::endl;
    }

    // Cria uma lista com as pontuações e nomes existentes:
    std::vector<std::pair<std::string, int>> pontuacoes;
    for (auto& item : jsonData["pontuacoes"]) {
        std::string nome = item["nome"];
        int pontos = item["pontos"];
        pontuacoes.push_back({nome, pontos});
    }

    // Adiciona a nova pontuação e nome:
    pontuacoes.push_back({getNomeJogador(), jogador->getPontos()});

    // Ordena as pontuações em ordem decrescente:
    std::sort(pontuacoes.begin(), pontuacoes.end(), 
              [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
                  return a.second > b.second;
              });

    // Mantém apenas as cinco maiores pontuações:
    if (pontuacoes.size() > 5) {
        pontuacoes.resize(5);
    }

    // Salva as cinco maiores pontuações e nomes de volta no arquivo:
    jsonData["pontuacoes"].clear();
    for (const auto& item : pontuacoes) {
        jsonData["pontuacoes"].push_back({{"nome", item.first}, {"pontos", item.second}});
    }

    std::ofstream outFile("pontos.json");
    if (outFile.is_open()) {
        outFile << jsonData.dump(4);
        outFile.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo para salvar os pontos." << std::endl;
    }
}


void LeadBoard::carregarPontos() 
{
    // Carrega pontuações existentes do arquivo:
    std::ifstream inFile("pontos.json");
    nlohmann::json jsonData;
    if (inFile.is_open()) {
        inFile >> jsonData;
        inFile.close();

        // Limpa o vetor atual e preenche com as novas pontuações:
        pontuacoes.clear();
        // for (auto& pontos : jsonData["pontuacoes"])  //< Não pode usar auto
        for (nlohmann::json::iterator it = jsonData["pontuacoes"].begin(); it != jsonData["pontuacoes"].end(); ++it)
        {
            int pontos = *it;
            pontuacoes.push_back(pontos);
        }
    }
    else{
        std::cout << "Arquivo nao aberto: carregar pontos." << std::endl;
    }
}

void LeadBoard::mostrarTela() {

    renderizar();
    sf::Text texto[5];
    std::string aux;
    for (int i = 0; i < pontuacoes.size(); i++) {
        texto[i].setCharacterSize(24);
        texto[i].setFont(gRecursos->getFont("fonte"));
        texto[i].setFillColor(sf::Color::Black);
        aux = "Rank " + std::to_string(i + 1) + ": " + std::to_string(pontuacoes[i]);
        texto[i].setString(aux);
        texto[i].setPosition(100.0f, 50.0f + i * 30.0f);
        gGrafico->addDrawable(texto[i], 1);
        std::cout << "Rank: " << std::to_string(i + 1) << " Pontuacao: " << std::to_string(pontuacoes[i]) << std::endl;
    }
    gGrafico->render();
}