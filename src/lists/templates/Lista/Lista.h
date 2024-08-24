#ifndef LISTA_H
#define LISTA_H

#include "../Elemento/Elemento.h"
#include <iostream>

template<class TL>
class Lista {
private:
    int maxElementos;
    int countElementos;

    ElementoLista<TL>* pPrimeiroElemento;
    ElementoLista<TL>* pUltimoElemento;

public:
    Lista(int numEle);
    Lista();
    ~Lista();

    void inicializarLista(int numEle, int countEle);
    
    ElementoLista<TL>* getPrimeiroElemento();

    void incluirElemento(ElementoLista<TL>* pEle);
    void listarElementos();
};

#include "Lista.cpp"

#endif
