#include "Obstacle.h"

Obstacle::Obstacle(int xx, int yy, sf::Texture& textura):
Entity(xx, yy, 0, 0, textura)
{
    inicializarCaixaColisao();
}