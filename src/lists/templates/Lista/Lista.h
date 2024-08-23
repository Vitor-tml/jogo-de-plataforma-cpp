#ifndef LISTA_H
#define LISTA_H

#include <iostream>

#include "../Elemento/Elemento.h"

template<class TE>
class Lista {
private:
    Elemento<TE>* pPrimeiro;
    Elemento<TE>* pUltimo;

public:
    Lista();
    ~Lista();

    Elemento<TE>* getPrimeiro();
    void incluir(TE* pInfo);
    void percorrer();
};

#endif