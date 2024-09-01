#ifndef _SEGUNNDAFASE_H
#define _SEGUNNDAFASE_H

#include "Phase.h"

class SegundaFase : public Phase{
private:
    Plataforma chao;
public:
    SegundaFase();
    ~SegundaFase() {};
    void executar() override;
};
#endif