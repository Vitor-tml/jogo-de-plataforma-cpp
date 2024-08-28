#include "Menu.h"

Menu::Menu(int* i):
    Ente(gRecursos->getTexture("menu")),
    estado(i)
{

}

void Menu::setEstado(int i)
{
    *estado = i;
}

const int Menu::getEstado() const { return *estado;}

void Menu::executar()
{
    gGrafico->clearDrawables();
    renderizar();
    gGrafico->render();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        setEstado(1);
}