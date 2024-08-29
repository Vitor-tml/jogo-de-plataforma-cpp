#include "Espinhos.h"
#include "../Character/Player/Player.h"
Espinhos::Espinhos(int xx, int yy, sf::Texture &textura, int offsetX, int offsetY):
    Obstacle(xx, yy, textura, offsetX, offsetY)
{

}

void Espinhos::obstacular(Player *jogador)
{
    // std::cout << "Espinhos" << std::endl;
    jogador->operator--();
}