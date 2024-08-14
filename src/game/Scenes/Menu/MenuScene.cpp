#include "MenuScene.h"

MenuScene::MenuScene()
{
    ResourceManager::getInstance()->loadFont("Menu", "../assets/fonts/Revorioum.ttf");
}

void MenuScene::inicializar()
{
    ResourceManager* gerenciadorDeRecursos = ResourceManager::getInstance();
    //Renderer::getRenderer()->setTamanhoCamera(800, 600);
    
    texto.setFont(ResourceManager::getInstance()->getFont("Menu"));
    texto.setString("Play");
    texto.setCharacterSize(30);
    texto.setFillColor(sf::Color (69, 60, 92));
    texto.setPosition(sf::Vector2f(10, 10));
    
    
    fundo.setTexture(ResourceManager::getInstance()->getTexture("menu"));
    fundo.setOrigin(sf::Vector2f(0, 0));
    fundo.setTextureRect(sf::IntRect(0, 0, 800, 600));
}

void MenuScene::atualizar()
{
    // Colocar aqui a animação de quando seleciona um botão
}

void MenuScene::renderizar()
{
    Renderer* renderizador = Renderer::getRenderer();
    renderizador->clearDrawables();
    renderizador->addDrawable(fundo, 0);
    renderizador->addDrawable(texto, 1);
    renderizador->render();
}

void MenuScene::processarEventos(const sf::Event& evento)
{
    
    if(evento.type == sf::Event::MouseButtonPressed){
        if(evento.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2f posicaoClique(evento.mouseButton.x, evento.mouseButton.y);
            SceneManager::getInstance()->desempilharCena();
        }
    }
}