#include <SFML/Graphics.hpp>
#include "engine/Renderer/Renderer.h"
#include "engine/Resourcemanager/TextureManager.h"

int main()
{
    Renderer janela(800, 600, "batata");

    TextureManager gerenciadorTextura;
    gerenciadorTextura.loadTexture("fundo", "../assets/textures/background.png");
    gerenciadorTextura.loadTexture("player", "../assets/textures/knight.png");

    sf::Sprite fundo;
    fundo.setTexture(gerenciadorTextura.getTexture("fundo"));
    fundo.setTextureRect(sf::IntRect(0, 200, 927, 634));
    fundo.setPosition(0.f, 0.f);

    sf::Sprite jogador;
    jogador.setTexture(gerenciadorTextura.getTexture("player"));
    jogador.setTextureRect(sf::IntRect(8, 8, 22, 28));
    jogador.setScale(sf::Vector2f(3, 3));
    jogador.setPosition(400.f, 300.f);


    janela.addDrawable(fundo);
    janela.addDrawable(jogador);

    janela.run();
    return 0;
}