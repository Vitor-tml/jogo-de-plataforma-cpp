#include "LeadBoard.h"
#include<iostream>
#include <fstream>

LeadBoard::LeadBoard() {}

LeadBoard::~LeadBoard() {}

void LeadBoard::executar() 
{
    mostrarTela();
}

void LeadBoard::salvarPontos(Player* jogador) 
{
    // Carregar pontuações existentes do arquivo
    std::ifstream inFile("pontos.json");
    nlohmann::json jsonData;
    if (inFile.is_open()) {
        inFile >> jsonData;
        inFile.close();
    }

    // Obter as pontuações existentes e adicionar a nova pontuação
    std::vector<int> pontuacoes;
    for (auto& pontos : jsonData["pontuacoes"]) {
        pontuacoes.push_back(pontos);
    }
    pontuacoes.push_back(jogador->getPontos());

    // Ordenar as pontuações em ordem decrescente
    std::sort(pontuacoes.begin(), pontuacoes.end(), std::greater<int>());

    // Manter apenas as cinco maiores pontuações
    if (pontuacoes.size() > 5) {
        pontuacoes.resize(5);
    }

    // Salvar as cinco maiores pontuações de volta no arquivo
    jsonData["pontuacoes"] = pontuacoes;

    std::ofstream outFile("pontos.json");
    if (outFile.is_open()) {
        outFile << jsonData.dump(4);
        outFile.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo para salvar os pontos." << std::endl;
    }
}

int LeadBoard::carregarPontos() { return 0; }

void LeadBoard::mostrarTela() {}