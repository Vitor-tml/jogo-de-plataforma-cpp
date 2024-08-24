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

void ListaEntidades::percorrer() {
    listaEntidades.listarElementos();
}

void ListaEntidades::imprimirElementos() {
    Elemento<Entity>* pAux = listaEntidades.getPrimeiroElemento();

    while (pAux != nullptr) {
        std::cout << "Entidade: " << pAux->getInfo()->getInfo() << std::endl;
        pAux = pAux->getProximoElemento();
    }
}

Entity* ListaEntidades::getPrimeiroElemento() {
    if (listaEntidades.getPrimeiroElemento() != nullptr) {
        return listaEntidades.getPrimeiroElemento()->getInfo();
    }
    return nullptr;
}
