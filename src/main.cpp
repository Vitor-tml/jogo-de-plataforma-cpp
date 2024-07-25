#include <SFML/Graphics.hpp>
#include "engine/Renderer/Renderer.h"
#include "engine/Resourcemanager/TextureManager.h"
#include "engine/Animation/Animation.h"

int main()
{
    Renderer janela(800, 600, "batata");

    TextureManager gerenciadorTextura;
    gerenciadorTextura.loadTexture("player", "..\\assets\\textures\\knight.png");

    Animation animacaoJogador(gerenciadorTextura.getTexture("player"), 32, 32, 4, 100000.f);

    sf::Clock clock;
    float deltaTime;
    
    while(janela.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        animacaoJogador.update(deltaTime);
        janela.clearDrawables();
        janela.addDrawable(animacaoJogador.getCurrentFrame(), 1);
        janela.render();
    }

    return 0;
}