#ifndef _PRIMEIRAFASE_H
#define _PRIMEIRAFASE_H

#include "Phase.h"
#include <vector>
#include <cstdlib>  // Para rand() e srand()
#include <ctime>    // Para time()

class PrimeiraFase : public Phase{
private:
    Plataforma chao;
    std::vector<Esqueleto*> esqueletos;
    std::vector<Arqueiro*> arqueiros;
    std::vector<Plataforma*> plataformas;
std::vector<Projetil*> balas;
public:
    PrimeiraFase(Player* p, Player2 *p2);
    ~PrimeiraFase() {};
    void criarEsqueletos();
    void criarArqueiros();
    void criarPlataformas();
};
#endif