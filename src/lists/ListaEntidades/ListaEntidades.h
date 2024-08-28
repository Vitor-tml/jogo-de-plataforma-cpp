#ifndef LISTAENTIDADES_H
#define LISTAENTIDADES_H

#include "../templates/Lista/Lista.h"
#include "../../game/Entity/Entity.h"
#include <string>

/**
 * @class ListaEntidades
 * @brief Classe utilizada para criar uma lista de entidades do jogo.
 * @author GustavoPellanda
 */

class ListaEntidades {
private:
    Lista<Entity> listaEntidades;

public:
    ListaEntidades();
    ListaEntidades(int maxElementos);
    ~ListaEntidades() = default;

    void incluir(Entity* pEntidade);
    void imprimirElementos();

    Entity* operator[](int index) const;
    int getTamanho() const;
};

#endif