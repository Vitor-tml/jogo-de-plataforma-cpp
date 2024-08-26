#include "Obstacle.h"

Obstacle::Obstacle(int xx, int yy, sf::Texture& textura, int offX, int offY):
Entity(xx, yy, offX, offY, textura)
{
    inicializarCaixaColisao();
}