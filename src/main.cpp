#include <SFML/Graphics.hpp>

int main()
{
    const int largura = 800;
    const int altura = 600;
    const int fpsLimit = 60;
    sf::RenderWindow janela(sf::VideoMode(largura, altura), "Jogo de Plataforma");

    janela.setFramerateLimit(fpsLimit);

    // Loop principla do jogo
    while(janela.isOpen())
    {
        sf::Event evento;

        while (janela.pollEvent(evento))
        {
            if(evento.type == sf::Event::Closed)
                janela.close();
        }
        
        // Limpa a tela com uma cor de fundo
        janela.clear(sf::Color::Black);

        // Desenhar elementos aqui

        // Atualiza a janela
        janela.display();
    }
    return 0;
}