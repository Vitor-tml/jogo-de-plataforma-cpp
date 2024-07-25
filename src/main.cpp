#include <SFML/Graphics.hpp>
#include "engine/Renderer/Renderer.h"
#include "engine/Resourcemanager/TextureManager.h"
#include "game/Player/Player.h"

int main()
{
    Renderer janela(800, 600, "Jogo de Plataforma");

    TextureManager gerenciadorDeTextura;

    gerenciadorDeTextura.loadTexture("jogador", "../assets/textures/knight.png");
    gerenciadorDeTextura.loadTexture("fundo", "../assets/textures/knight.png");

    Player jogador(gerenciadorDeTextura.getTexture("jogador"));

    sf::Clock tempo;
    float deltaTempo;

    while(janela.isOpen())
    {
        deltaTempo = tempo.restart().asSeconds();

        jogador.update(deltaTempo);
        janela.clearDrawables();
        janela.addDrawable(jogador.getSprite(), 1);
        janela.render();
    }
    return 0;
}