#ifndef _ENEMY_H
#define _ENEMY_H

#include "../Character.h"
class Player;
class Enemy: public Character {
protected:
    int nivelMaldade;
public:
    virtual void executar() = 0; // no momento virtual pura
    virtual void danificar(Player *jogador) = 0;
};
#endif