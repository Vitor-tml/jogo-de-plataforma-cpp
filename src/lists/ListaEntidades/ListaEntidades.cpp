#include "ListaEntidades.h"

ListaEntidades::ListaEntidades() {}

ListaEntidades::~ListaEntidades() {}

void ListaEntidades::incluir(Entidade* pEntidade) {
    LEs.incluir(pEntidade);
}

void ListaEntidades::percorrer() {
    LEs.percorrer();
}

void ListaEntidades::imprimirElementos() {
    Elemento<Entidade>* pAux = LEs.getPrimeiro();

    while (pAux != nullptr) {
        std::cout << "Entidade: " << pAux->getInfo()->getInfo() << std::endl;
        pAux = pAux->getProximo();
    }
}