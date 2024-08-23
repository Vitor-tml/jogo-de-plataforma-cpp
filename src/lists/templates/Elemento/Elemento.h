#ifndef ELEMENTO_H
#define ELEMENTO_H

template<class TE>
class Elemento {
private:
    TE* pInfo;
    Elemento<TE>* pProximo;

public:
    Elemento();
    ~Elemento();

    void setInfo(TE* pInfoEle);
    TE* getInfo();

    void setProximo(Elemento<TE>* pProxEle);
    Elemento<TE>* getProximo();
};

#endif
