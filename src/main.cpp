#include <SFML/Graphics.hpp>
#include "engine/Renderer/Renderer.h"
#include "engine/Resourcemanager/TextureManager.h"
#include "game/Player/Player.h"

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
    float deltaTempo;

    while(janela->isOpen())
    {
        deltaTempo = tempo.restart().asSeconds();

        jogador.update(deltaTempo);
        janela->clearDrawables();
        janela->addDrawable(fundo);
        janela->addDrawable(jogador.getSprite(), 1);
        janela->render();
    }
    return 0;
}