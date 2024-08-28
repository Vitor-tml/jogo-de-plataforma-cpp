#include "SaveManager.h"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

void SaveManager::saveEntidades(const ListaEntidades& lista, const std::string& filename) {
    json jLista = json::array();

    for (int i = 0; i < lista.getTamanho(); i++) {
        json jEntidade;
        jEntidade["pointer"] = reinterpret_cast<uintptr_t>(lista[i]);
        jLista.push_back(jEntidade);
    }

    try {
        std::ofstream arquivo(filename);
        if (!arquivo.is_open()) {
            throw std::ios_base::failure("Erro ao abrir o arquivo para escrita.");
        }
        arquivo << jLista.dump(4); // Salvando com indentação
        if (!arquivo) {
            throw std::ios_base::failure("Erro ao escrever no arquivo.");
        }
    } catch (const std::ios_base::failure& e) {
        std::cerr << "Erro ao salvar entidades: " << e.what() << std::endl;
    }
}

ListaEntidades SaveManager::loadEntidades(const std::string& filename) {
    ListaEntidades listaCarregada;

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

        for (const auto& jEntidade : jLista) {
            Entity* entidade = reinterpret_cast<Entity*>(jEntidade["pointer"].get<uintptr_t>());
            listaCarregada.incluir(entidade);
        }
    } catch (const std::ios_base::failure& e) {
        std::cerr << "Erro ao carregar entidades: " << e.what() << std::endl;
    }

    return listaCarregada;
}
