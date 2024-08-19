#include "Ente.h"

int Ente::cont = 0;
Renderer* Ente::gerenciadorGrafico = Renderer::getRenderer();

Ente::Ente():
    id(++cont)
{
    // sf::Texture placeHolder;
    // placeHolder.create(64, 64);
    // shape.setTexture(placeHolder);
}
Ente::Ente(sf::Texture figura):
    id(++cont)
{
    shape.setTexture(figura);
}
Ente::~Ente()
{
    // gerenciadorGrafico = nullptr; ///< Não fazer isso porque a variável é compartilhada entre TODOS os entes.
}

void Ente::renderizar()
{
    // O objeto deve apenas se inserir na fila de renderização, a renderização final fica por parte da cena
    gerenciadorGrafico->addDrawable(shape);
}