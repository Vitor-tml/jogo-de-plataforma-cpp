#include "Ente.h"
#include <iostream>
int Ente::cont = 0;
Renderer* Ente::gGrafico = Renderer::getRenderer();
ResourceManager* Ente::gRecursos = ResourceManager::getInstance();

Ente::Ente():
    id(++cont)
{
    // std::cout << "Construtora sem parametro (ente). Adicionando placeHolder na sprite" << std::endl;
    sf::Texture placeHolder;
    placeHolder.create(64, 64);
    sprite.setTexture(placeHolder);
}
Ente::Ente(sf::Texture& figura, float offSetx, float OffSety):
    id(++cont)
{
    // std::cout << "Construtora com parametro(ente)" << std::endl;
    sprite.setTexture(figura);
}
Ente::~Ente()
{
    // gGrafico = nullptr; ///< Não fazer isso porque a variável é compartilhada entre TODOS os entes.
}

void Ente::renderizar(int camada)
{
    // O objeto deve apenas se inserir na fila de renderização, a renderização final fica por parte da cena
    gGrafico->addDrawable(sprite, camada);
}

sf::Sprite Ente::getSprite() const
{ 
    return sprite;
}

void Ente::setTexture(sf::Texture& textura)
{
    sprite.setTexture(textura);
}