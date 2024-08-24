#include "Lista.h"

template<class TIPO>
Lista<TIPO>::Lista() {
    inicializarLista(100, 0);
}

template<class TIPO>
Lista<TIPO>::Lista(int maxEle) {
    inicializarLista(maxEle, 0);
}

template<class TIPO>
void Lista<TIPO>::inicializarLista(int maxEle, int countEle) {
    maxElementos = maxEle;
    countElementos = countEle;
    pPrimeiroElemento = nullptr;
    pUltimoElemento = nullptr;
}

template<class TIPO>
Lista<TIPO>::~Lista() {
    ElementoLista<TIPO>* pAux1 = pPrimeiroElemento, *pAux2;

    while (pAux1 != nullptr) {
        pAux2 = pAux1->getProximoElemento();
        delete pAux1;
        pAux1 = pAux2;
    }

    pPrimeiroElemento = nullptr;
    pUltimoElemento = nullptr;
}

template<class TIPO>
ElementoLista<TIPO>* Lista<TIPO>::getPrimeiroElemento() {
    return pPrimeiroElemento;
}

template<class TIPO>
void Lista<TIPO>::incluirElemento(ElementoLista<TIPO>* pEle) {
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

template<class TIPO>
void Lista<TIPO>::listarElementos() {
    ElementoLista<TIPO>* pAux = pPrimeiroElemento;
    while (pAux != nullptr) {
        std::cout << pAux->getInfo()->getInfo() << std::endl;
        pAux = pAux->getProximoElemento();
    }
}
