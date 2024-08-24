#ifndef LISTAENTIDADES_H
#define LISTAENTIDADES_H

#include "../templates/Lista/Lista.h"
#include "../../game/Entity/Entity.h"

class ListaEntidades {
private:
    Lista<Entity> listaEntidades;

public:
    ListaEntidades();
    ListaEntidades(int maxElementos);
    ~ListaEntidades();

    void incluir(Entity* pEntidade);
    void imprimirElementos();
    Entity* getPrimeiroElemento();
};

#endif