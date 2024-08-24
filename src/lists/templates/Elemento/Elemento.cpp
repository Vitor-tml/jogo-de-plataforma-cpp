template<class TIPO>
Elemento<TIPO>::Elemento() {
    pInfoElemento = nullptr;
    pProximoElemento = nullptr;
    pAnteriorElemento = nullptr;
}

template<class TIPO>
Elemento<TIPO>::~Elemento() {
    delete pInfoElemento;
}

template<class TIPO>
void Elemento<TIPO>::setInfo(TIPO* pInfoEle) {
    pInfoElemento = pInfoEle;
}

template<class TIPO>
TIPO* Elemento<TIPO>::getInfo() {
    return pInfoElemento;
}

template<class TIPO>
void Elemento<TIPO>::setProximoElemento(Elemento<TIPO>* pProxEle) {
    pProximoElemento = pProxEle;
}

template<class TIPO>
Elemento<TIPO>* Elemento<TIPO>::getProximoElemento() {
    return pProximoElemento;
}

template<class TIPO>
void Elemento<TIPO>::setAnteriorElemento(Elemento<TIPO>* pAnteEle) {
    pAnteriorElemento = pAnteEle;
}

template<class TIPO>
Elemento<TIPO>* Elemento<TIPO>::getAnteriorElemento() {
    return pAnteriorElemento;
}