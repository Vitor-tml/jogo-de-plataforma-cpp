#ifndef _ESPINHOS_H
#define _ESPINHOS_H

#include "Obstacle.h"
class Espinhos : public Obstacle{
private:
    int dano;
public:
    Espinhos(int xx, int yy, sf::Texture &textura, int offsetX = 0, int offsetY = 0);
    ~Espinhos(){};
    void executar(){};
    void obstacular(Player *jogador);
    void obstacular(Entity *p){};
};
#endif