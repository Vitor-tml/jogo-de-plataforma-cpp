#ifndef _TERCEIRAFASE_H
#define _TERCEIRAFASE_H

#include "Phase.h"
#include "../../../lib/json.hpp"

class TerceiraFase : public Phase {
private:
    void criarEntidades(const std::string& tipo, const json& dados);
    Plataforma chao;

public:
    TerceiraFase(Player* p, Player2* p2);
    ~TerceiraFase() {};
    void executar() override;
};

#endif