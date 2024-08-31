#ifndef LEADBOARD_H
#define LEADBOARD_H

#include "../../engine/Ente/Ente.h"
#include "../Character/Player/Player.h"
#include "../../../lib/json.hpp"

/**
 * @class Lista
 * @brief Classe para guardar e mostrar na tela os melhores jogadores.
 * @author GustavoPellanda
 */

class LeadBoard : public Ente {
private:
    std::vector<std::pair<std::string, int>> pontuacoes;

public:
    LeadBoard();
    ~LeadBoard();
    void executar();
    std::string getNomeJogador() const;
    void salvarPontos(Player* jogador);
    /**
     * @brief A ideia do salva pontos é ser chamada uma única vez no final do jogo.
     * Esse método cria um arquivo com as cinco melhores pontuações. Elas são sobrescritas quando uma nova pontuação mais alta for recebida.
     * Se ela ficar no loop infinito, ele sobrescreverá as cinco pontuações consecutivamente (o que não é o desejado). 
     */
    void carregarPontos();
    /**
     * @brief Retorna uma lista com as cinco melhores pontuações. 
     */
    void mostrarTela();
};

#endif
