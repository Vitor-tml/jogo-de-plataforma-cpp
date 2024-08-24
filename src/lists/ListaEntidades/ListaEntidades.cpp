#include "ListaEntidades.h"
#include <iostream>

ListaEntidades::ListaEntidades() : listaEntidades(100) { // Inicializa com capacidade padrão
}

ListaEntidades::ListaEntidades(int maxElementos) : listaEntidades(maxElementos) { // Inicializa com capacidade definida
}

ListaEntidades::~ListaEntidades() {}

void ListaEntidades::incluir(Entidade* pEntidade) {
    Elemento<Entidade>* novoElemento = new Elemento<Entidade>();
    novoElemento->setInfo(pEntidade);
    listaEntidades.incluirElemento(novoElemento);
}

void ListaEntidades::percorrer() {
    listaEntidades.listarElementos();
}

void ListaEntidades::imprimirElementos() {
    Elemento<Entidade>* pAux = listaEntidades.getPrimeiroElemento();

    while (pAux != nullptr) {
        std::cout << "Entidade: " << pAux->getInfo()->getInfo() << std::endl;
        pAux = pAux->getProximoElemento();
    }
}

Entidade* ListaEntidades::getPrimeiroElemento() {
    if (listaEntidades.getPrimeiroElemento() != nullptr) {
        return listaEntidades.getPrimeiroElemento()->getInfo();
    }
    return nullptr;
}
