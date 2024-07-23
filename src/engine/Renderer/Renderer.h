#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class Renderer {
private:
    sf::RenderWindow janela;
    std::vector<std::pair<const sf::Drawable*, int>> drawables; // vetor de pares de int e drawable
    void render(); // Executa a renderização dos elementos
public:
    Renderer(int altura, int largura, const std::string& titulo);
    void run(); // Método do loop de renderização
    void addDrawable(const sf::Drawable& drawable, int camada = 0); // Adiciona um elemento para ser desenhado
    void clearDrawables(); // limpa todos os elementos
};

#endif