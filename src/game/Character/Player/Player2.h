#ifndef _PLAYERDOIS_H
#define _PLAYERDOIS_H

#include "Player.h"
class Player2 : public Player{
    private:
        int aux;
    public:
        Player2(sf::Texture& textura): Player(textura){};
        void userInput()
        {
            std::cout << "Player 2" << std::endl;

            // Zera velocidade horizontal para não ter aceleração infinita
            velocidade.x = 0;

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                velocidade.x -= velocidadeHorizontal;
                sprite.setScale(sf::Vector2f(-1 , 1)); ///< Muda a direção da sprite
                animacaoAtual = &andando;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                velocidade.x += velocidadeHorizontal;
                sprite.setScale(sf::Vector2f(1 , 1)); ///< Muda a direção da sprite
                animacaoAtual = &andando;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && estaNoChao){
                velocidade.y += -fisica.getPulo();
                estaNoChao = false;
            }

            if(velocidade.x == 0)
            {
                animacaoAtual = &parado;
            }
        }
};
#endif