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
    std::ifstream inFile("pontos.json");
    nlohmann::json jsonData;

    if (inFile.is_open()) {
        inFile >> jsonData;
        inFile.close();
    } else {
        std::cout << "Arquivo nao abriu!" << std::endl;
    }

    std::vector<nlohmann::json> pontuacoes;

    // Verifica se "pontuacoes" existe e se é um array:
    if (jsonData.contains("pontuacoes") && jsonData["pontuacoes"].is_array()) {
        for (auto& pontos : jsonData["pontuacoes"]) {
            pontuacoes.push_back(pontos);
        }
    }

    // Adiciona a nova pontuação com o nome do jogador:
    nlohmann::json novaPontuacao = {
        {"nome", getNomeJogador()},
        {"pontos", jogador->getPontos()}
    };
    pontuacoes.push_back(novaPontuacao);

    // Ordena as pontuações em ordem decrescente:
    std::sort(pontuacoes.begin(), pontuacoes.end(), [](const nlohmann::json& a, const nlohmann::json& b) {
        return a["pontos"] > b["pontos"];
    });

    // Mantém apenas as cinco maiores pontuações:
    if (pontuacoes.size() > 5) {
        pontuacoes.resize(5);
    }

    // Salva as pontuações de volta no arquivo:
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