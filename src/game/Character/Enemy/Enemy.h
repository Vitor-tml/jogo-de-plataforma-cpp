#ifndef _ENEMY_H
#define _ENEMY_H

class Player;
class Enemy{
protected:
    int nivelMaldade;
public:
    virtual void executar() = 0; // no momento virtual pura
    virtual void danificar(Player *jogador) = 0;
};
#endif