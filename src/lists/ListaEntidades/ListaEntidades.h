#ifndef LISTAENTIDADES_H
#define LISTAENTIDADES_H

#include <iostream>

#include "../templates/Lista.h"
#include "../../game/Entity/Entidade.h"

class ListaEntidades {
private:
    Lista<Entidade> LEs;

public:
    ListaEntidades();
    ~ListaEntidades();

    void incluir(Entidade* pEntidade);
    void percorrer();
    void imprimirElementos();
};

#endif