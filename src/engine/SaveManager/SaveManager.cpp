#include "SaveManager.h"
#include <fstream>

using json = nlohmann::json;

void SaveManager::saveEntidades(const ListaEntidades& lista, const std::string& filename) {
    json jLista = json::array();

    for (int i = 0; i < lista.getTamanho(); i++) {
        json jEntidade;
        jEntidade["pointer"] = reinterpret_cast<uintptr_t>(lista[i]);
        jLista.push_back(jEntidade);
    }

    std::ofstream arquivo(filename);
    if (arquivo.is_open()) {
        arquivo << jLista.dump(4); // Salvando com indentação
        arquivo.close();
    } else {
        // Lidar com erro ao abrir o arquivo
    }
}

ListaEntidades SaveManager::loadEntidades(const std::string& filename) {
    ListaEntidades listaCarregada;
    std::ifstream arquivo(filename);

    if (arquivo.is_open()) {
        json jLista;
        arquivo >> jLista;
        arquivo.close();

        for (const auto& jEntidade : jLista) {
            Entity* entidade = reinterpret_cast<Entity*>(jEntidade["pointer"].get<uintptr_t>());
            listaCarregada.incluir(entidade);
        }
    } else {
        // Lidar com erro ao abrir o arquivo
    }

    return listaCarregada;
}
