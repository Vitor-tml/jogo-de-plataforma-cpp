#ifndef _MENU_H
#define _MENU_H

#include "../../engine/Ente/Ente.h"

/*
    class ente
    const int id;                        //< Indentificador para permanência de objeto
    static int cont;                     //< Contador de ID
    static Renderer* gGrafico; //< Instância única do renderer
    sf::Sprite sprite;                   //< Shape a ser desenhado do elemento.
    
    Ente(sf::Texture& figura);

 */
/**
 * @brief 
 * 
 */
class Menu : public Ente {
private:
    int* estado;
    int opcaoSelecionada;
    const int numOpcoes;
    float tempoUltimaPressao;
    const float intervaloTroca;
    sf::Clock tempo;
    float deltaTime;
    sf::Sprite botoes[4];
    sf::Sprite escolhido[4];
    sf::Text texto[4];

    float tempoPressaoEnter; // Tempo desde que a tecla Enter foi pressionada
public:
    Menu(int* i);
    ~Menu() {};
    void setEstado(int i);
    void executar(float deltaTime) {};
    void executar();
};
#endif