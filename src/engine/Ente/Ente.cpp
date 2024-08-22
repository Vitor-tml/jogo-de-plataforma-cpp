#include "Ente.h"
#include <iostream>
int Ente::cont = 0;
Renderer* Ente::gGrafico = Renderer::getRenderer();
ResourceManager* Ente::gRecursos = ResourceManager::getInstance();
Ente::Ente():
    id(++cont),
    offSetColisao(0, 0),
    pontoOrigem(10.f)
{
    std::cout << "Construtora sem parametro (ente). Adicionando placeHolder na sprite" << std::endl;
    sf::Texture placeHolder;
    placeHolder.create(64, 64);
    sprite.setTexture(placeHolder);
    pontoOrigem.setFillColor(sf::Color::Blue);
}
Ente::Ente(sf::Texture& figura, float offSetx, float OffSety):
    id(++cont),
    offSetColisao(offSetx, OffSety),
    pontoOrigem(5.f)
{
    std::cout << "Construtora com parametro(ente)" << std::endl;
    sprite.setTexture(figura);
    pontoOrigem.setFillColor(sf::Color::Blue);
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
    caixaColisao.setSize(sf::Vector2f(areaColisao.width - offSetColisao.x, areaColisao.height - offSetColisao.y));
    caixaColisao.setPosition(areaColisao.left, areaColisao.top);
    caixaColisao.setOutlineColor(sf::Color::Red);
    caixaColisao.setOutlineThickness(2);
    caixaColisao.setFillColor(sf::Color::Transparent);

    // DEBUG -> Ponto de Origem
    pontoOrigem.setOrigin(sprite.getOrigin());
    pontoOrigem.setPosition(sprite.getPosition());

    gGrafico->addDrawable(sprite, camada);
    gGrafico->addDrawable(caixaColisao, camada + 1);
    gGrafico->addDrawable(pontoOrigem, camada + 2);
}

sf::Sprite Ente::getSprite() const
{ 
    return sprite;
}

sf::RectangleShape Ente::getCaixaColisao() const
{
    return caixaColisao;
}
void Ente::setTexture(sf::Texture& textura)
{
    sprite.setTexture(textura);
}