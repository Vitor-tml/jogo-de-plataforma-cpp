#ifndef _PLATAFORMA_H
#define _PLATAFORMA_H
#include "Obstacle.h"

class Player;
class Plataforma : public Obstacle{
private:
    sf::Vector2f empuxo;
public:
    Plataforma(int xx, int yy, sf::Texture &textura, int offsetX = 0, int offsetY = 0);
    ~Plataforma() {};
    void executar();
    void executar(float deltaTime){};
    void obstacular(Player *p);
    void obstacular(Entity *p);
};
#endif