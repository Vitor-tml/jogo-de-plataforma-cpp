#include "SaveManager.h"
#include <fstream>
#include <iostream>
#include <memory>

using json = nlohmann::json;

std::string SaveManager::getTipo(const Entity* entidade) const {
    if (dynamic_cast<const Enemy*>(entidade)) return "Enemy";
    if (dynamic_cast<const Player*>(entidade)) return "Player";
    if (dynamic_cast<const Obstacle*>(entidade)) return "Obstacle";
    return "Entidade";
}


void SaveManager::saveEntidades(const ListaEntidades& lista, const std::string& filename) {
    json jLista = json::array();

    for (int i = 0; i < lista.getTamanho(); i++) {
        json jEntidade;
        const Entity* entidade = lista[i];
        jEntidade["tipo"] = getTipo(entidade);        // Usa o método getTipo para identificar o qual é a entidade
        jEntidade["dados"] = entidade->salvar();      // Usa o método salvar de cada entidade para buscar os dados próprios delas
        jLista.push_back(jEntidade);                  // Insere as informações de cada entidade no JSON
    }

    try {
        std::ofstream arquivo(filename);
        if (!arquivo.is_open()) {
            throw std::ios_base::failure("Erro ao abrir o arquivo para escrita.");
        }
        
        arquivo << jLista.dump(4); // Salva o JSON no arquivo
        std::cout << filename << std::endl;
        if (!arquivo) {
            throw std::ios_base::failure("Erro ao escrever no arquivo.");
        }
        
        //std::cout << "Lista de entidades salva com sucesso no arquivo: " << filename << std::endl;
    
    } catch (const std::ios_base::failure& e) {
        std::cerr << "Erro ao salvar entidades: " << e.what() << std::endl;
    }
}

ListaEntidades SaveManager::loadEntidades() {
    ListaEntidades listaCarregada;
    const std::string filename = "save.json";

    try {
        std::ifstream arquivo(filename);
        if (!arquivo.is_open()) {
            throw std::ios_base::failure("Erro ao abrir o arquivo para leitura.");
        }

        json jLista;
        arquivo >> jLista;
        if (!arquivo) {
            throw std::ios_base::failure("Erro ao ler o arquivo.");
        }

        std::cout << "Entidades carregadas:" << std::endl;
        for (const auto& jEntidade : jLista) {
            std::string tipo = jEntidade["tipo"];
            std::cout << tipo << std::endl;
        }
    } catch (const std::ios_base::failure& e) {
        std::cerr << "Erro ao carregar entidades: " << e.what() << std::endl;
    }

    std::cout << "Número total de entidades carregadas: " << listaCarregada.getTamanho() << std::endl;
    return listaCarregada;
}


