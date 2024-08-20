#include <SFML/Graphics.hpp>
#include <iostream>

#include "engine/SceneManager/SceneManager.h"
#include "game/Scenes/Menu/MenuScene.h"
#include "game/Scenes/Editor/EditorScene.h"
#include "game/Scenes/Testes/TestScene.h"
#include "game/Levels/Phase.h"
int main()
{
    Renderer* janela = Renderer::getRenderer(800, 600, "Jogo de Plataforma");

    ResourceManager* gerenciadorDeRecursos = ResourceManager::getInstance();
    
    // Carregamento de recursos -> usado em várias, deixar aqui
    gerenciadorDeRecursos->loadTexture("jogador", "../assets/textures/knight.png");
    gerenciadorDeRecursos->loadTexture("fundo", "../assets/textures/background.png");
    gerenciadorDeRecursos->loadTexture("plataforma", "../assets/textures/plataforma.png");
    gerenciadorDeRecursos->loadTexture("menu", "../assets/textures/cenaMenu.png");

    Phase fase;

    while (janela->isOpen())
    {
        sf::Event evento;
        while(janela->pollEvent(evento))
        {
            if(evento.type == sf::Event::Closed)
                janela->close();
            
            fase.executar();
        }
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