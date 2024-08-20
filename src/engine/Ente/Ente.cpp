#include "Ente.h"
#include <iostream>
int Ente::cont = 0;
Renderer* Ente::gerenciadorGrafico = Renderer::getRenderer();

Ente::Ente():
    id(++cont)
{
    std::cout << "Construtora sem parametro(ente)" << std::endl;
    sf::Texture placeHolder;
    placeHolder.create(64, 64);
    sprite.setTexture(placeHolder);
}
Ente::Ente(sf::Texture& figura):
    id(++cont)
{
    std::cout << "Construtora com parametro(ente)" << std::endl;
    sprite.setTexture(figura);
}
Ente::~Ente()
{
    // gerenciadorGrafico = nullptr; ///< Não fazer isso porque a variável é compartilhada entre TODOS os entes.
}

void Ente::renderizar(int camada)
{
    // O objeto deve apenas se inserir na fila de renderização, a renderização final fica por parte da cena
    gerenciadorGrafico->addDrawable(sprite, camada);
}

sf::Sprite Ente::getSprite() const
{ 
    return sprite;
}

void Ente::setTexture(sf::Texture& textura)
{
    sprite.setTexture(textura);
}