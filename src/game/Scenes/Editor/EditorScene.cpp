#include "EditorScene.h"
#include <iostream>
EditorScene::EditorScene()
{

}

void EditorScene::inicializar()
{
    if(!fonte.loadFromFile("../assets/fonts/Revorioum.ttf"))
    {
        std::cerr << "Problema ao carregar fontes! " << std::endl;
        exit(1);
    }

    texto.setFont(fonte);
    texto.setString("Editor");
    texto.setCharacterSize(50);
    texto.setFillColor(sf::Color::Blue);
    texto.setPosition(sf::Vector2f(0, 0));
}

void EditorScene::finalizar()
{

}

void EditorScene::atualizar()
{

}

void EditorScene::renderizar()
{
    Gerenciador::Renderer::getRenderer()->addDrawable(texto);
    Gerenciador::Renderer::getRenderer()->render();
}

void EditorScene::processarEventos(const sf::Event& evento)
{

}