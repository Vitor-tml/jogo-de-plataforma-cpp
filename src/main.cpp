#include <SFML/Graphics.hpp>
#include <iostream>

#include "engine/SceneManager/SceneManager.h"
#include "engine/CollisionManager/CollisionManager.h"
#include "game/Scenes/Menu/MenuScene.h"
#include "game/Scenes/Editor/EditorScene.h"
#include "game/Scenes/Testes/TestScene.h"
#include "game/Levels/Phase.h"
#include "game/Menu/Menu.h"
#include "game/Obstacles/Obstacle.h"

int main()
{
    Renderer* janela = Renderer::getRenderer(800, 600, "Jogo de Plataforma");

    ResourceManager* gRecursos = ResourceManager::getInstance();
    
    // Carregamento de recursos -> usado em várias -> Perguntar para o professor onde deve ser colocado?
    gRecursos->loadTexture("jogador",    "../assets/textures/knight.png");
    gRecursos->loadTexture("fundo",      "../assets/textures/background.png");
    gRecursos->loadTexture("plataforma", "../assets/textures/plataforma.png");
    gRecursos->loadTexture("menu",       "../assets/textures/cenaMenu.png");
    gRecursos->loadTexture("inimigo",       "../assets/textures/skeleton.png");
    gRecursos->loadImage("jogador",      "../assets/textures/knight.png");
    Phase menu;
    while (janela->isOpen())
    {
        sf::Event evento;
        while(janela->pollEvent(evento))
        {
            if(evento.type == sf::Event::Closed)
                janela->close();    
        }
        
        menu.executar();
    }
    

    // Antigo sistema de cenas
    /*
    SceneManager* gerenciadorDeCenas = SceneManager::getInstance();
    //gerenciadorDeCenas->mudarCena(std::make_unique<EditorScene>());
    gerenciadorDeCenas->empilharCena(std::make_unique<TestScene>());
    gerenciadorDeCenas->empilharCena(std::make_unique<MenuScene>());
       
    while(janela->isOpen())
    {
        sf::Event evento;
        while(janela->pollEvent(evento))
        {
            gerenciadorDeCenas->processarEventosCenaAtual(evento);
            if(evento.type == sf::Event::Closed)
                janela->close();            
        }
        
        gerenciadorDeCenas->atualizarCenaAtual();
        gerenciadorDeCenas->renderizarCenaAtual();
    }
    */
        
    return 0;
}