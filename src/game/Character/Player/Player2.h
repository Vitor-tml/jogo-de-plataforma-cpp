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
            // std::cout << "Player 2" << std::endl;

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

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)){
                atacar();
            }

            if(velocidade.x == 0 && !ataque)
            {
                animacaoAtual = &parado;
            }
        }
        void renderizaVida()
        {

            std::string aux = "Player 2: " + std::to_string(nVidas);
            vida.setString(aux);
            vida.setPosition(0, 25);
            gGrafico->addDrawable(vida, 4);
        }
};
#endif