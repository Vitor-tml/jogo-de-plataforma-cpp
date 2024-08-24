#ifndef LISTA_H
#define LISTA_H

#include "../Elemento/Elemento.h"
#include <iostream>

template<class TL>
class Lista {
private:
    int maxElementos;
    int countElementos;

    Elemento<TL>* pPrimeiroElemento;
    Elemento<TL>* pUltimoElemento;

public:
    Lista(int numEle);
    Lista();
    ~Lista();

    void inicializarLista(int numEle, int countEle);
    
    Elemento<TL>* getPrimeiroElemento();

    void incluirElemento(Elemento<TL>* pEle);
    void listarElementos();
};

#include "Lista.cpp"

#endif
