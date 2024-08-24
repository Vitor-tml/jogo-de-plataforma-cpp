#include "ListaEntidades.h"
#include <iostream>

ListaEntidades::ListaEntidades() : listaEntidades(100) { // Inicializa com capacidade padrão
}

ListaEntidades::ListaEntidades(int maxElementos) : listaEntidades(maxElementos) { // Inicializa com capacidade definida
}

ListaEntidades::~ListaEntidades() {}

void ListaEntidades::incluir(Entity* pEntidade) {
    Elemento<Entity>* novoElemento = new Elemento<Entity>();
    novoElemento->setInfo(pEntidade);
    listaEntidades.incluirElemento(novoElemento);
}

void ListaEntidades::imprimirElementos() {
    listaEntidades.listarElementos();
}

Entity* ListaEntidades::getPrimeiroElemento() {
    if (listaEntidades.getPrimeiroElemento() != nullptr) {
        return listaEntidades.getPrimeiroElemento()->getInfo();
    }
    return nullptr;
}
