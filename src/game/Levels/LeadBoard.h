#ifndef LEADBOARD_H
#define LEADBOARD_H

#include "../Character/Player/Player.h"

class LeadBoard {
private:

public:
    LeadBoard();
    ~LeadBoard();
    void executar();
    void salvarPontos(Player* jogador);
    void carregarPontos();
    void mostrarTela();
};

#endif
