#include "Menu.h"

Menu::Menu():
    Ente(gRecursos->getTexture("menu"))
{

}

void Menu::executar()
{
    gGrafico->clearDrawables();
    renderizar();
    gGrafico->render();
}