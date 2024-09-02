#ifndef _TERCEIRAFASE_H
#define _TERCEIRAFASE_H

#include "Phase.h"

class TerceiraFase : public Phase{
private:

public:
    TerceiraFase(Player* p, Player2 *p2);
    ~TerceiraFase() {};
    void executar() override;
};

#endif