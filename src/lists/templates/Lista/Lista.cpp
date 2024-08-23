#include "Lista.h"

template<class TE>
Lista<TE>::Lista() : pPrimeiro(nullptr), pUltimo(nullptr) {}

template<class TE>
Lista<TE>::~Lista() {
    Elemento<TE>* pAux1 = pPrimeiro, *pAux2;
    while (pAux1 != nullptr) {
        pAux2 = pAux1->getProximo();
        delete pAux1;
        pAux1 = pAux2;
    }
}

template<class TE>
Elemento<TE>* Lista<TE>::getPrimeiro() {
    return pPrimeiro;
}

template<class TE>
void Lista<TE>::incluir(TE* pInfo) {
    Elemento<TE>* pNovo = new Elemento<TE>();
    pNovo->setInfo(pInfo);

    if (pUltimo == nullptr) {
        pPrimeiro = pNovo;
    } else {
        pUltimo->setProximo(pNovo);
    }
    pUltimo = pNovo;
}

template<class TE>
void Lista<TE>::percorrer() {
    Elemento<TE>* pAux = pPrimeiro;
    while (pAux != nullptr) {
        std::cout << pAux->getInfo() << std::endl;
        pAux = pAux->getProximo();
    }
}