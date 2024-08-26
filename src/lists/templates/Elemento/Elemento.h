#ifndef _ELEMENTO_H_
#define _ELEMENTO_H_

template<class TE>
class Elemento {
private:
    TE* pInfoElemento;    
    Elemento<TE>* pProximoElemento;
    Elemento<TE>* pAnteriorElemento;

public:
    Elemento();
    ~Elemento();

    void setInfo(TE* pInfoEle);
    TE* getInfo();

    void setProximoElemento(Elemento<TE>* pProxEle);
    Elemento<TE>* getProximoElemento();

    void setAnteriorElemento(Elemento<TE>* pAnteEle);
    Elemento<TE>* getAnteriorElemento();
};

template<class TE>
Elemento<TE>::Elemento() : pInfoElemento(nullptr), pProximoElemento(nullptr), pAnteriorElemento(nullptr) {
}

template<class TE>
Elemento<TE>::~Elemento() {
    //delete pInfoElemento;
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

#endif
