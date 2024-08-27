#include "Game.h"

Game::Game():
    janela(Renderer::getRenderer(800, 600, "Cavaleiro Vagante.")),
    gRecursos(ResourceManager::getInstance())
{
    gRecursos->loadTexture("jogador",    "../assets/textures/knight.png");
    gRecursos->loadTexture("fundo",      "../assets/textures/background.png");
    gRecursos->loadTexture("plataforma", "../assets/textures/plataforma.png");
    gRecursos->loadTexture("menu",       "../assets/textures/cenaMenu.png");
    gRecursos->loadTexture("inimigo",       "../assets/textures/skeleton.png");
    gRecursos->loadTexture("chao",       "../assets/textures/chao.png");
    gRecursos->loadImage("jogador",      "../assets/textures/knight.png");
}

Game::~Game()
{

}

void Game::executar()
{
    Menu menu;
    Phase fase1;
    while (janela->isOpen())
    {
        sf::Event evento;
        while(janela->pollEvent(evento))
        {
            if(evento.type == sf::Event::Closed)
                janela->close();    
        }
        
        fase1.executar();
    }
}