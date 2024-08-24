#include "Lista.h"

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
    ElementoLista<TL>* pAux1 = pPrimeiroElemento, *pAux2;

    while (pAux1 != nullptr) {
        pAux2 = pAux1->getProximoElemento();
        delete pAux1;
        pAux1 = pAux2;
    }

    pPrimeiroElemento = nullptr;
    pUltimoElemento = nullptr;
}

template<class TL>
ElementoLista<TL>* Lista<TL>::getPrimeiroElemento() {
    return pPrimeiroElemento;
}

template<class TL>
void Lista<TL>::incluirElemento(ElementoLista<TL>* pEle) {
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
    pEle->getInfo()->setID(countElementos);
}

template<class TL>
void Lista<TL>::listarElementos() {
    ElementoLista<TL>* pAux = pPrimeiroElemento;
    while (pAux != nullptr) {
        std::cout << pAux->getInfo()->getInfo() << std::endl;
        pAux = pAux->getProximoElemento();
    }
}
