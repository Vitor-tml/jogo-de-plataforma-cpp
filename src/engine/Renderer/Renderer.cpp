#include "Renderer.h"
#include <algorithm>

// Inicia o ponteiro do singleton para todas os fins
Renderer* Renderer::singleton = nullptr;

// Construtora (chamada apenas uma vez)
Renderer::Renderer(int largura, int altura, const std::string &titulo)
    : janela(sf::VideoMode(largura, altura), titulo),
      camera(sf::FloatRect(0, 0, largura, altura)) // Inicia câmera com tamanho da janela
{
    janela.setFramerateLimit(60);
}
// Apaga instância do renderizador
Renderer::~Renderer()
{
    delete singleton;
}

// Retorna instância única do gerenciador gráfico
Renderer* Renderer::getRenderer(int largura, int altura, const std::string& titulo)
{
    if(singleton == nullptr)
        singleton = new Renderer(largura, altura, titulo);
    
    return singleton;
}


// Adiciona elementos renderizáveis na pilha de renderização
void Renderer::addDrawable(const sf::Drawable &drawable, int camada)
{
    drawables.push_back(std::make_pair(&drawable, camada));
}

// Limpa pilha de renderizaçõa
void Renderer::clearDrawables()
{
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

// Ordena (por camadas) e renderiza os elementos da pilha
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

// Verifica se a janela do jogo foi fechada
bool Renderer::isOpen()
{
    sf::Event evento;
    while (janela.pollEvent(evento))
    {
        if (evento.type == sf::Event::Closed)
            janela.close();
    }
    return janela.isOpen();
}