#include "Renderer.h"
#include <algorithm>
#include <iostream>

// Cria janela, e setta FPS em 60
Renderer::Renderer(int largura, int altura, const std::string& titulo)
:janela(sf::VideoMode(largura, altura), titulo) 
{
        janela.setFramerateLimit(60);
}

void Renderer::run(){

    while(janela.isOpen()){

        sf::Event evento;
        while(janela.pollEvent(evento)){
            if(evento.type == sf::Event::Closed)
                janela.close();
        }
        render();
    }

}

void Renderer::addDrawable(const sf::Drawable& drawable, int camada){
        drawables.push_back(std::make_pair(&drawable, camada));
}

void Renderer::clearDrawables(){
    drawables.clear();
}

void Renderer::render()
{
    janela.clear(sf::Color::Black);

    // Ordena os elementos com base na camada
    std::sort(drawables.begin(), // inicio do vetor
              drawables.end(),   // fim do vetor (iteradores para o sort())
              [](const std::pair<const sf::Drawable*, int>& a, const std::pair<const sf::Drawable*, int>& b) 
                {
                    return a.second < b.second; // Função lambda que define como comparar dois elementos
                }

                );

    for(const auto& drawable : drawables){
        janela.draw(*drawable.first);
    }

    janela.display();
}

bool Renderer::isOpen()const
{
    return janela.isOpen();
}