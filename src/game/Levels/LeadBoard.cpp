#include "LeadBoard.h"
#include<iostream>

LeadBoard::LeadBoard() {}

LeadBoard::~LeadBoard() {}

void LeadBoard::executar() 
{
    carregarPontos();
    mostrarTela();
}

void LeadBoard::salvarPontos(Player* jogador) 
{
    std::cout << jogador->getPontos() << std::endl;
}

void LeadBoard::carregarPontos() {}

void LeadBoard::mostrarTela() {}