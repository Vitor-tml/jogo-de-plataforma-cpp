#ifndef LISTAENTIDADES_H
#define LISTAENTIDADES_H

#include "../templates/Lista.h"
#include "../../game/Entity/Entidade.h"

class ListaEntidades {
private:
    Lista<Entidade> listaEntidades;

public:
    ListaEntidades();
    ListaEntidades(int maxElementos);
    ~ListaEntidades();

    void incluir(Entidade* pEntidade);
    void percorrer();
    void imprimirElementos();
    Entidade* getPrimeiroElemento();
};

#endif