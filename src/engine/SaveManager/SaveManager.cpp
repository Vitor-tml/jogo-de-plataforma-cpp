#include "SaveManager.h"
#include <fstream>
#include <iostream>
#include <memory>

using json = nlohmann::json;

std::string SaveManager::getTipo(const Entity* entidade) const {
    if (dynamic_cast<const Enemy*>(entidade)) return "Inimigo";
    if (dynamic_cast<const Player*>(entidade)) return "Jogador";
    if (dynamic_cast<const Obstacle*>(entidade)) return "Obstáculo";
    return "Entidade";
}

Entity* SaveManager::criarEntidade(const std::string& tipo) const {
    // Fazer: tenho que olhar como criar cada uma das classes de acordo com os métodos particulares delas
    // if (tipo == "Enemy") return new Enemy(); 
    // if (tipo == "Player") return new Player();
    // if (tipo == "Obstacle") return new Obstacle();
    return nullptr;
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
        if (!arquivo) {
            throw std::ios_base::failure("Erro ao escrever no arquivo.");
        }
        
        std::cout << "Lista de entidades salva com sucesso no arquivo: " << filename << std::endl;
    
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
            std::string tipo = jEntidade["tipo"];
            Entity* entidade = criarEntidade(tipo);
            if (entidade) {
                listaCarregada.incluir(entidade);
            }
        }
    } catch (const std::ios_base::failure& e) {
        std::cerr << "Erro ao carregar entidades: " << e.what() << std::endl;
    }

    return listaCarregada;
}
