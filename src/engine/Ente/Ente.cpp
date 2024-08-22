#include "Ente.h"
#include <iostream>
int Ente::cont = 0;
Renderer* Ente::gGrafico = Renderer::getRenderer();
ResourceManager* Ente::gRecursos = ResourceManager::getInstance();
Ente::Ente():
    id(++cont)
{
    std::cout << "Construtora sem parametro (ente). Adicionando placeHolder na sprite" << std::endl;
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
    // gGrafico = nullptr; ///< Não fazer isso porque a variável é compartilhada entre TODOS os entes.
}

void Ente::renderizar(int camada)
{
    // O objeto deve apenas se inserir na fila de renderização, a renderização final fica por parte da cena

    // DEBUG -> caixas de colisão
    sf::FloatRect areaColisao = sprite.getGlobalBounds();
    caixaColisao.setSize(sf::Vector2f(areaColisao.width, areaColisao.height));
    caixaColisao.setPosition(areaColisao.left, areaColisao.top);
    caixaColisao.setOutlineColor(sf::Color::Red);
    caixaColisao.setOutlineThickness(2);
    caixaColisao.setFillColor(sf::Color::Transparent);

    gGrafico->addDrawable(sprite, camada);
    gGrafico->addDrawable(caixaColisao, camada + 1);
}

sf::Sprite Ente::getSprite() const
{ 
    return sprite;
}

void Ente::setTexture(sf::Texture& textura)
{
    sprite.setTexture(textura);
}