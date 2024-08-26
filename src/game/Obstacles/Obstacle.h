#ifndef _OBSTACLE_H
#define _OBSTACLE_H

#include "../Entity/Entity.h"

class Player;
class Obstacle : public Entity {
protected:
    bool danoso;
public:
    Obstacle(int xx, int yy, sf::Texture& textura, int offX = 0, int offY = 0);
    ~Obstacle(){};
    virtual void executar(){};                  // Depois colocar virtual pura
    virtual void obstacular(Player *jogador){}; // Depois colocar virtual pura
    void salvar(){};
};
#endif