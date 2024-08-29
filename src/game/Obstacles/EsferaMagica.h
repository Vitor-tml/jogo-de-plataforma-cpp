#ifndef _ESFERAMAGICA_H
#define _ESFERAMAGICA_H

class Esferamagica : public Obstacle {
private:
    int elasticidade;

public:
    Esferamagica(int xx, int yy, sf::Texture &textura, int offsetX = 0, int offsetY = 0);
    ~Esferamagica();
    void executar(float deltaTime);
    void obstacular(Player *jogador);
    void obstacular(Entity *p);

}

#endif