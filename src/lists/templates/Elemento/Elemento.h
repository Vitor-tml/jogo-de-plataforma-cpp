#ifndef _ELEMENTO_H_
#define _ELEMENTO_H_

template<class TIPO>
class Elemento {
private:
    TIPO* pInfoElemento;    
    Elemento<TIPO>* pProximoElemento;
    Elemento<TIPO>* pAnteriorElemento;

public:
    Elemento();
    ~Elemento();

    void setInfo(TIPO* pInfoEle);
    TIPO* getInfo();

    void setProximoElemento(Elemento<TIPO>* pProxEle);
    Elemento<TIPO>* getProximoElemento();

    void setAnteriorElemento(Elemento<TIPO>* pAnteEle);
    Elemento<TIPO>* getAnteriorElemento();
};

#include "Elemento.cpp"

#endif
