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
    texto.setString("Aoaoao Abaixo ao pastelao.");
    texto.setCharacterSize(50);
    texto.setFillColor(sf::Color::Blue);
    texto.setPosition(sf::Vector2f(300, 500));
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