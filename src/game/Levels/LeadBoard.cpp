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
    else
    {
        std::cout << "Arquivo nao abriu!" << std::endl;
    }

    // Cria uma lista com as pontuações existentes e a nova pontuação:
    // std::vector<int> pontuacoes;
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

std::string getNomeJogador(){
    // Pensar como a gente vai pegar o nome do jogador
    return "Nome de teste";
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