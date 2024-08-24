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

#include "Elemento.cpp"

#endif
