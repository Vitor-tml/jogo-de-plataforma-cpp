#ifndef _ESFERAMAGICA_H
#define _ESFERAMAGICA_H

class EsferaMagica : public Obstacle {
private:
    int elasticidade;

public:
    EsferaMagica(int xx, int yy, sf::Texture &textura, int offsetX = 0, int offsetY = 0);
    ~EsferaMagica();
    void executar(float deltaTime);
    void obstacular(Player *jogador);
    void obstacular(Entity *p);

};

#endif