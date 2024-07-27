#include "MenuScene.h"
#include <iostream>
MenuScene::MenuScene()
{

}

void MenuScene::inicializar()
{
    if(!fonte.loadFromFile("../assets/fonts/Revorioum.ttf"))
    {
        std::cerr << "Problema ao carregar fontes! " << std::endl;
        exit(1);
    }

    texto.setFont(fonte);
    texto.setString("Menu");
    texto.setCharacterSize(30);
    texto.setFillColor(sf::Color (69, 60, 92));
    texto.setPosition(sf::Vector2f(10, 10));
}

void MenuScene::finalizar()
{

}

void MenuScene::atualizar(float deltaTime)
{

}

void MenuScene::renderizar()
{
    Renderer::getRenderer()->addDrawable(texto);
    Renderer::getRenderer()->render();
}

void MenuScene::processarEventos(const sf::Event& evento)
{

}