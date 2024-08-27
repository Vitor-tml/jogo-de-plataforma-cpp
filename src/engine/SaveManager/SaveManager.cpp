#include "SaveManager.h"
#include "../../game/Character/Player/Player.h"
#include "../../game/Character/Enemy/Enemy.h"
#include <fstream>
#include <typeinfo>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

SaveManager::SaveManager() {}

SaveManager::~SaveManager() {}

void SaveManager::saveEntidades(const Lista<Entity>& lista) {
    json j;
    int count = lista.getTamanho();
    j["count"] = count;

    for (int i = 0; i < count; ++i) {
        Entity* entity = lista[i];
        if (dynamic_cast<Player*>(entity)) {
            j["entities"].push_back("Player");
        } else if (dynamic_cast<Enemy*>(entity)) {
            j["entities"].push_back("Enemy");
        }
    }

    std::ofstream file("entities.json");
    if (!file.is_open()) {
        std::cerr << "Failed to open file for saving entities!" << std::endl;
        return;
    }

    file << j.dump(4); // Serialize JSON with an indentation of 4 spaces
    file.close();
}

Lista<Entity> SaveManager::loadEntidades() {
    Lista<Entity> lista;
    std::ifstream file("entities.json");

    if (!file.is_open()) {
        std::cerr << "Failed to open file for loading entities!" << std::endl;
        return lista;
    }

    json j;
    file >> j;
    file.close();

    int count = j["count"];
    for (int i = 0; i < count; ++i) {
        std::string tipo = j["entities"][i];
        Entity* entity = criarEntidade(tipo);
        if (entity) {
            lista.incluirElemento(new Elemento<Entity>(entity));
        }
    }

    return lista;
}