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
    gRecursos->loadTexture("espinho",      "../assets/textures/espinho.png");
    gRecursos->loadTexture("esfera",      "../assets/textures/esferaMagica.png");
    gRecursos->loadImage("jogador",      "../assets/textures/knight.png");
}

Game::~Game()
{

}

void Game::executar()
{
    int estado = 0;
    Menu menu(&estado);
    Phase fase1;
    while (janela->isOpen())
    {
        sf::Event evento;
        while(janela->pollEvent(evento))
        {
            if(evento.type == sf::Event::Closed)
                janela->close();    
        }
        switch (estado)
        {
        case 0:
            menu.executar();
            estado = menu.getEstado();
            break;
        case 1:
            fase1.executar();
            break;
        default:
            break;
        }
    }
}