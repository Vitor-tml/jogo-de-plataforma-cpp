template<class TE>
Elemento<TE>::Elemento() {
    pInfoElemento = nullptr;
    pProximoElemento = nullptr;
    pAnteriorElemento = nullptr;
}

template<class TE>
Elemento<TE>::~Elemento() {
    delete pInfoElemento;
}

template<class TE>
void Elemento<TE>::setInfo(TE* pInfoEle) {
    pInfoElemento = pInfoEle;
}

template<class TE>
TE* Elemento<TE>::getInfo() {
    return pInfoElemento;
}

template<class TE>
void Elemento<TE>::setProximoElemento(Elemento<TE>* pProxEle) {
    pProximoElemento = pProxEle;
}

template<class TE>
Elemento<TE>* Elemento<TE>::getProximoElemento() {
    return pProximoElemento;
}

template<class TE>
void Elemento<TE>::setAnteriorElemento(Elemento<TE>* pAnteEle) {
    pAnteriorElemento = pAnteEle;
}

template<class TE>
Elemento<TE>* Elemento<TE>::getAnteriorElemento() {
    return pAnteriorElemento;
}