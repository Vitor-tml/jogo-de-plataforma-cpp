#include <SFML/Graphics.hpp>
#include "engine/Renderer/Renderer.h"
#include "engine/Resourcemanager/TextureManager.h"
#include "game/Player/Player.h"
#include "engine/Scene/Menu/MenuScene.h"

int main()
{
    Renderer* janela = Renderer::getRenderer(800, 600, "Jogo de Plataforma");

    TextureManager gerenciadorDeTextura;

    gerenciadorDeTextura.loadTexture("jogador", "../assets/textures/knight.png");
    gerenciadorDeTextura.loadTexture("fundo", "../assets/textures/background.png");
    Player jogador(gerenciadorDeTextura.getTexture("jogador"));
    sf::Sprite fundo;
    fundo.setTexture(gerenciadorDeTextura.getTexture("fundo"));
    fundo.setTextureRect(sf::IntRect(0, 200, 900, 600));
    
    sf::Clock tempo;
    float deltaTime;

    SceneManager gerenciadorDeCenas;
    gerenciadorDeCenas.mudaCena(std::make_unique<MenuScene>(gerenciadorDeCenas));

    while(janela->isOpen())
    {
        deltaTime = tempo.restart().asSeconds();
        sf::Event evento;
        //gerenciadorDeCenas.userInputCenaAtual(evento);
        gerenciadorDeCenas.updateCenaAtual(deltaTime);
        gerenciadorDeCenas.renderizaCenaAtual();        
    }
    return 0;
}