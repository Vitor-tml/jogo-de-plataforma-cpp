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

    TL* operator[](int index);
    int getTamanho() const; 
};

template<class TL>
Lista<TL>::Lista() {
    inicializarLista(100, 0);
}

template<class TL>
Lista<TL>::Lista(int maxEle) {
    inicializarLista(maxEle, 0);
}

template<class TL>
void Lista<TL>::inicializarLista(int maxEle, int countEle) {
    maxElementos = maxEle;
    countElementos = countEle;
    pPrimeiroElemento = nullptr;
    pUltimoElemento = nullptr;
}

template<class TL>
Lista<TL>::~Lista() {
    // Elemento<TL>* pAux1 = pPrimeiroElemento, *pAux2;

    // while (pAux1 != nullptr) {
    //     pAux2 = pAux1->getProximoElemento();
    //     delete pAux1;
    //     pAux1 = pAux2;
    // }

    // pPrimeiroElemento = nullptr;
    // pUltimoElemento = nullptr;
}

template<class TL>
Elemento<TL>* Lista<TL>::getPrimeiroElemento() {
    return pPrimeiroElemento;
}

template<class TL>
void Lista<TL>::incluirElemento(Elemento<TL>* pEle) {
    if (pEle == nullptr) return;
    if (countElementos >= maxElementos) {
        std::cout << "Limite de elementos na lista já atingido!" << std::endl;
        return;
    }

    if (pPrimeiroElemento == nullptr) { // Lista vazia
        pPrimeiroElemento = pEle;
        pUltimoElemento = pEle;
    } else { // Insere o novo objeto na lista:
        pUltimoElemento->setProximoElemento(pEle);
        pEle->setAnteriorElemento(pUltimoElemento);
        pUltimoElemento = pEle;
    }

    countElementos++;
}

template<class TL>
void Lista<TL>::listarElementos() {
    Elemento<TL>* pAux = pPrimeiroElemento;
    while (pAux != nullptr) {
        std::cout << pAux->getInfo() << std::endl;
        pAux = pAux->getProximoElemento();
    }
}

// -- Métodos criados para facilitar a iteração pela lista: -- 

template<class TL>
int Lista<TL>::getTamanho() const {
    return countElementos;
}

// Sobrecarga do operador []
template<class TL>
TL* Lista<TL>::operator[](int index) {
    if (index < 0 || index >= countElementos) {
        std::cerr << "Índice fora dos limites!" << std::endl;
        return nullptr;
    }

    Elemento<TL>* pAux = pPrimeiroElemento;
    for (int i = 0; i < index; ++i) {
        pAux = pAux->getProximoElemento();
    }
    return pAux->getInfo();
}


#endif
