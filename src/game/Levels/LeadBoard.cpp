#include "LeadBoard.h"
#include<iostream>
#include <fstream>

LeadBoard::LeadBoard() : pontuacoes() {}

LeadBoard::~LeadBoard() {}

void LeadBoard::executar() 
{
    carregarPontos();
    mostrarTela();
}

void LeadBoard::salvarPontos(Player* jogador) 
{
    // Carrega pontuações existentes no arquivo:
    std::ifstream inFile("pontos.json");
    nlohmann::json jsonData;
    if (inFile.is_open()) {
        inFile >> jsonData;
        inFile.close();
    }

    // Cria uma lista com as pontuações existentes e a nova pontuação:
    std::vector<int> pontuacoes;
    for (auto& pontos : jsonData["pontuacoes"]) {
        pontuacoes.push_back(pontos);
    }
    pontuacoes.push_back(jogador->getPontos());

    // Ordena as pontuações em ordem decrescente:
    std::sort(pontuacoes.begin(), pontuacoes.end(), std::greater<int>());

    // Mantém apenas as cinco maiores pontuações:
    if (pontuacoes.size() > 5) {
        pontuacoes.resize(5);
    }

    // Salva as cinco maiores pontuações de volta no arquivo:
    jsonData["pontuacoes"] = pontuacoes;
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
        for (auto& pontos : jsonData["pontuacoes"]) {
            pontuacoes.push_back(pontos);
        }
    }
}

void LeadBoard::mostrarTela() {
    for (size_t i = 0; i < pontuacoes.size(); i++) {
        sf::Text texto;
        texto.setFont(gRecursos->getFont("fonte"));
        texto.setString("Rank " + std::to_string(i + 1) + ": " + std::to_string(pontuacoes[i]));
        texto.setPosition(100.0f, 50.0f + i * 30.0f);
        texto.setCharacterSize(24);
        texto.setFillColor(sf::Color::White);

        gGrafico->addDrawable(texto);
    }
    gGrafico->render();
}