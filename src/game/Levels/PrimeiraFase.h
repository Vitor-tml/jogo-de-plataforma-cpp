#ifndef _PRIMEIRAFASE_H
#define _PRIMEIRAFASE_H

#include "Phase.h"

class PrimeiraFase : public Phase{
private:
    Esqueleto inimigo;
    Arqueiro legolas;
    Plataforma plataforma;
    Plataforma chao;
    Plataforma plataforma2;
    Plataforma plataforma3;
    Espinhos espinho;
    Projetil bala;
    EsferaMagica esfera;
public:
    PrimeiraFase();
    ~PrimeiraFase() {};
    void executar() override;
};
#endif