#include <SFML/Graphics.hpp>
#include "engine/Renderer/Renderer.h"
#include "engine/Resourcemanager/TextureManager.h"
#include "game/Player/Player.h"
#include "engine/SceneManager/SceneManager.h"
#include "game/Scenes/Menu/MenuScene.h"
#include "game/Scenes/Editor/EditorScene.h"
int main()
{
    Renderer* janela = Renderer::getRenderer(800, 600, "Jogo de Plataforma");

    TextureManager gerenciadorDeTextura;

    gerenciadorDeTextura.loadTexture("jogador", "../assets/textures/knight.png");
    gerenciadorDeTextura.loadTexture("fundo", "../assets/textures/background.png");
    gerenciadorDeTextura.loadTexture("plataforma", "../assets/textures/plataforma.png");
    Player jogador(gerenciadorDeTextura.getTexture("jogador"));
    sf::Sprite fundo;
    fundo.setTexture(gerenciadorDeTextura.getTexture("fundo"));
    fundo.setTextureRect(sf::IntRect(0, 200, 900, 600));
    sf::Sprite plataforma;
    plataforma.setTexture(gerenciadorDeTextura.getTexture("plataforma"));
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