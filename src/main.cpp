#include <SFML/Graphics.hpp>
#include "engine/Renderer/Renderer.h"
#include "engine/Resourcemanager/ResourceManager.h"
#include "game/Player/Player.h"
#include "engine/SceneManager/SceneManager.h"
#include "game/Scenes/Menu/MenuScene.h"
#include "game/Scenes/Editor/EditorScene.h"
int main()
{
    Renderer* janela = Renderer::getRenderer(800, 600, "Jogo de Plataforma");

    ResourceManager* gerenciadorDeRecursos = gerenciadorDeRecursos;
    gerenciadorDeRecursos->loadTexture("jogador", "../assets/textures/knight.png");
    gerenciadorDeRecursos->loadTexture("fundo", "../assets/textures/background.png");
    gerenciadorDeRecursos->loadTexture("plataforma", "../assets/textures/plataforma.png");
    Player jogador(gerenciadorDeRecursos->getTexture("jogador"));
    sf::Sprite fundo;
    fundo.setTexture(gerenciadorDeRecursos->getTexture("fundo"));
    fundo.setTextureRect(sf::IntRect(0, 200, 900, 600));
    sf::Sprite plataforma;
    plataforma.setTexture(gerenciadorDeRecursos->getTexture("plataforma"));
    plataforma.setPosition(300, 500);
    sf::Clock tempo;
    float deltaTime;

    SceneManager::getInstance()->mudarCena(std::make_unique<EditorScene>());
    SceneManager::getInstance()->mudarCena(std::make_unique<MenuScene>());
    while(janela->isOpen())
    {
        deltaTime = tempo.restart().asSeconds();
        sf::Event evento;
        Renderer::getRenderer()->addDrawable(fundo, 0);
        Renderer::getRenderer()->addDrawable(plataforma, 1);
        Renderer::getRenderer()->addDrawable(jogador.getSprite(), 2);
        Renderer::getRenderer()->setTamanhoCamera(400, 400);
        Renderer::getRenderer()->setCentroCamera(jogador.getSprite().getPosition().x,jogador.getSprite().getPosition().y);
        jogador.update(deltaTime);
        Renderer::getRenderer()->render();
        // SceneManager::getInstance()->renderizarCenaAtual();
    }
        
    return 0;
}