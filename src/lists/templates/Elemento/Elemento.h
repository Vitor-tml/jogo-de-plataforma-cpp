#ifndef _ELEMENTO_H_
#define _ELEMENTO_H_

/**
 * @class Lista
 * @brief Template de um elemento que pode ser inserido em uma lista.
 * @author GustavoPellanda
 */


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
    /**
     * @brief Info guarda o ponteiro do objeto que será guardado pelo elemento de lista.
     */
    void setProximoElemento(Elemento<TE>* pProxEle);
    Elemento<TE>* getProximoElemento();
    /**
     * @brief Ponteiro para o próximo elemento da lista.
     */
    void setAnteriorElemento(Elemento<TE>* pAnteEle);
    Elemento<TE>* getAnteriorElemento();
    /**
     * @brief Ponteiro para o elemento anterior da lista.
     */
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
