#include "MenuScene.h"
#include <iostream>
MenuScene::MenuScene()
{
    ResourceManager::getInstance()->loadFont("Menu", "../assets/fonts/Revorioum.ttf");
}

void MenuScene::inicializar()
{
    ResourceManager* gerenciadorDeRecursos = ResourceManager::getInstance();

    texto.setFont(ResourceManager::getInstance()->getFont("Menu"));
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