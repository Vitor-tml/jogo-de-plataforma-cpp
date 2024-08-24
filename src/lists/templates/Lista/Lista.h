#ifndef LISTA_H
#define LISTA_H

#include "../Elemento/Elemento.h"
#include <iostream>

template<class TIPO>
class Lista {
private:
    int maxElementos;
    int countElementos;

    ElementoLista<TIPO>* pPrimeiroElemento;
    ElementoLista<TIPO>* pUltimoElemento;

public:
    Lista(int numEle);
    Lista();
    ~Lista();

    void inicializarLista(int numEle, int countEle);
    
    ElementoLista<TIPO>* getPrimeiroElemento();

    void incluirElemento(ElementoLista<TIPO>* pEle);
    void listarElementos();
};

#include "Lista.cpp"

#endif
