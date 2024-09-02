#ifndef _SAVEMANAGER_H
#define _SAVEMANAGER_H

#include "../../lists/ListaEntidades/ListaEntidades.h"
#include "../../game/Character/Enemy/Enemy.h"
#include "../../game/Character/Player/Player.h"
#include "../../game/Obstacles/Obstacle.h"
#include "../ResourceManager/ResourceManager.h"
#include "../../../lib/json.hpp"
#include <string>

using json = nlohmann::json;

/**
 * @class SaveManager
 * @brief Classe utilizada para salvar e carregar as entidades do jogo.
 * 
 * Esta classe fornece métodos para salvar e carregar as entidades do jogo,
 * permitindo que essas entidades possam ser recuperadas posteriormente.
 *
 * @author GustavoPellanda
 */

class SaveManager {
private:
    std::string getTipo(const Entity* entidade) const;
    /**
     * @brief Esse método é responsável por identificar qual é o tipo de cada entidade na lista, para que possa ser realizado o salvamento polimórfico.
     */
    Entity* criarEntidade(const std::string& tipo, const json& dados) const;

public:
    SaveManager() = default;
    ~SaveManager() = default;

    void saveEntidades(const ListaEntidades& lista, const std::string& filename);
    /**
     * @brief Esse método recebe a lista de entidades e o nome do arquivo em que ela será salva.
     */
    ListaEntidades loadEntidades();
    /**
     * @brief Esse método carrega o arquivo do save.json e retorna a lista de entidades.
     */
};

#endif
