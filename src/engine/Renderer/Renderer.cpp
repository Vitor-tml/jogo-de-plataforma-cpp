#include "Renderer.h"
#include <algorithm>
#include <iostream>

namespace Gerenciador{
Gerenciador::Renderer* Renderer::singleton = nullptr;
int Renderer::camadaJanela = 0;
Renderer::Renderer(int largura, int altura, const std::string &titulo)
    : janela(sf::VideoMode(largura, altura), titulo),
      camera(sf::FloatRect(0, 0, largura, altura)) // Inicia câmera com tamanho da janela
{
    janela.setFramerateLimit(60);
}

Renderer::~Renderer()
{
    delete singleton;
}

Renderer* Renderer::getRenderer(int largura, int altura, const std::string& titulo)
{
    if(singleton == nullptr)
        singleton = new Renderer(largura, altura, titulo);
    
    return singleton;
}

void Renderer::addDrawable(const sf::Drawable &drawable, int camada)
{
    // if(camada == 0 && !drawables.empty()) ///< Caso a camada seja 0 e não seja a primeira da fila, coloca como última da fila
    //     camada = drawables.size();
    //std::cout << "Rederizando camada: " << camadaJanela << std::endl;
    drawables.push_back(std::make_pair(&drawable, camadaJanela++));
    // drawables.push_back(std::make_pair(&drawable, camadaJanela));
}

void Renderer::clearDrawables()
{
    camadaJanela = 0;
    drawables.clear();
}

void Renderer::moveCamera(float x, float y)
{
    camera.move(x, y);
}

void Renderer::setCentroCamera(float x, float y)
{
    camera.setCenter(x, y);
}

void Renderer::setTamanhoCamera(float largura, float altura)
{
    camera.setSize(altura, largura);
}

void Renderer::render()
{
    janela.clear(sf::Color::Black);

    janela.setView(camera);
    // Ordena os elementos com base na camada
    std::sort(drawables.begin(), // inicio do vetor
              drawables.end(),   // fim do vetor (iteradores para o sort())
              [](const std::pair<const sf::Drawable *, int> &a, const std::pair<const sf::Drawable *, int> &b)
              {
                  return a.second < b.second; // Função lambda que define como comparar dois elementos
              }

    );

    for (const auto &drawable : drawables)
    {
        janela.draw(*drawable.first);
    }

    janela.display();
}

bool Renderer::isOpen()
{
    return janela.isOpen();
}

void Renderer::close()
{
    janela.close();
}
bool Renderer::pollEvent(sf::Event &evento)
{
    return janela.pollEvent(evento);
}
}