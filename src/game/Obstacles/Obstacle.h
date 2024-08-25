#ifndef _OBSTACLE_H
#define _OBSTACLE_H

#include "../Entity/Entity.h"

class Player;
class Obstacle : public Entity {
protected:
    bool danoso;
public:
    virtual void executar() = 0;
    virtual void obstacular(Player *jogador) = 0;
};
#endif