#include <SFML/Graphics.hpp>
#include <iostream>

#include "engine/SceneManager/SceneManager.h"
#include "game/Scenes/Menu/MenuScene.h"
#include "game/Scenes/Editor/EditorScene.h"
#include "game/Scenes/Testes/TestScene.h"

int main()
{
    Renderer* janela = Renderer::getRenderer(800, 600, "Jogo de Plataforma");

    ResourceManager* gerenciadorDeRecursos = ResourceManager::getInstance();
    
    // Carregamento de recursos -> usado em várias, deixar aqui
    gerenciadorDeRecursos->loadTexture("jogador", "../assets/textures/knight.png");
    gerenciadorDeRecursos->loadTexture("fundo", "../assets/textures/background.png");
    gerenciadorDeRecursos->loadTexture("plataforma", "../assets/textures/plataforma.png");


    // Definição de elementos
    Player jogador(gerenciadorDeRecursos->getTexture("jogador"));
    sf::Sprite fundo;
    fundo.setTexture(gerenciadorDeRecursos->getTexture("fundo"));
    fundo.setTextureRect(sf::IntRect(0, 200, 900, 600));
    sf::Sprite plataforma;
    plataforma.setTexture(gerenciadorDeRecursos->getTexture("plataforma"));
    plataforma.setPosition(300, 500);

    sf::Clock tempo;
    float deltaTime;

    // Declaração das cenas
    SceneManager* gerenciadorDeCenas = SceneManager::getInstance();
    gerenciadorDeCenas->mudarCena(std::make_unique<TestScene>());
    gerenciadorDeCenas->mudarCena(std::make_unique<MenuScene>());
    gerenciadorDeCenas->mudarCena(std::make_unique<EditorScene>());
    
    /**
     * "Cena" atual
     * @todo Implementar aqui gerenciador de cenas 
    */    
    while(janela->isOpen())
    {
        gerenciadorDeCenas->atualizarCenaAtual();
        gerenciadorDeCenas->renderizarCenaAtual();
    }
        
    return 0;
}