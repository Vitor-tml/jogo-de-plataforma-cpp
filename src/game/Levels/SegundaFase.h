#ifndef _SEGUNNDAFASE_H
#define _SEGUNNDAFASE_H

#include "Phase.h"

class SegundaFase : public Phase{
private:
    Plataforma chao;
    Esqueleto esqueleto;
    Arqueiro arqueiro;
    Projetil bala;
    EsferaMagica esfera;
public:
    SegundaFase(Player* p, Player2 *p2);
    ~SegundaFase() {};
    void executar() override;
};
#endif