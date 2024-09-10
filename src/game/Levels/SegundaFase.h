#ifndef SEGUNDA
#define SEGUNDA

#include "Phase.h"
#include <vector>
#include <cstdlib>  // Para rand() e srand()
#include <ctime>    // Para time()

class SegundaFase : public Phase{
private:
    Plataforma chao;
    std::vector<Esqueleto*> esqueletos;
    std::vector<Arqueiro*> arqueiros;
    std::vector<Plataforma*> plataformas;
    std::vector<Projetil*> balas;
    std::vector<Espinhos*> espinhos;
    
public:
    SegundaFase(Player* p, Player2 *p2);
    ~SegundaFase() {};
    void criarEsqueletos();
    void criarArqueiros();
    void criarPlataformas();
    void criaEspinhos();
};
#endif