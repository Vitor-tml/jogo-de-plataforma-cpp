#include "Elemento.h"

template<class TE>
Elemento<TE>::Elemento() : pInfo(nullptr), pProximo(nullptr) {}

template<class TE>
Elemento<TE>::~Elemento() {
    delete pInfo;
}

template<class TE>
void Elemento<TE>::setInfo(TE* pInfoEle) {
    pInfo = pInfoEle;
}

template<class TE>
TE* Elemento<TE>::getInfo() {
    return pInfo;
}

template<class TE>
void Elemento<TE>::setProximo(Elemento<TE>* pProxEle) {
    pProximo = pProxEle;
}

template<class TE>
Elemento<TE>* Elemento<TE>::getProximo() {
    return pProximo;
}
