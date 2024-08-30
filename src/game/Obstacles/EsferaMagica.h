#ifndef _ESFERAMAGICA_H
#define _ESFERAMAGICA_H

#include "Obstacle.h"
#include "../Character/Player/Player.h"

class EsferaMagica : public Obstacle {
private:
    int elasticidade;

public:
    EsferaMagica(int xx, int yy, sf::Texture &textura, int offsetX = 0, int offsetY = 0);
    ~EsferaMagica();
    void executar(float deltaTime);
    void obstacular(Player *jogador);
    //void obstacular(Entity *p);

};

#endif