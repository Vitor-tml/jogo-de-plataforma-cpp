#include "ListaEntidades.h"
#include <iostream>

ListaEntidades::ListaEntidades() : listaEntidades(100) { // Inicializa com capacidade padrão
}

ListaEntidades::ListaEntidades(int maxElementos) : listaEntidades(maxElementos) { // Inicializa com capacidade definida
}

void ListaEntidades::incluir(Entity* pEntidade) {
    Elemento<Entity>* novoElemento = new Elemento<Entity>();
    novoElemento->setInfo(pEntidade);
    listaEntidades.incluirElemento(novoElemento);
}

void ListaEntidades::imprimirElementos() {
    listaEntidades.listarElementos();
}

Entity* ListaEntidades::operator[](int index) const {
    return listaEntidades[index];
}

int ListaEntidades::getTamanho() const {
    return listaEntidades.getTamanho();
}