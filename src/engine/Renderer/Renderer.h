#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class Renderer {
private:
    static Renderer* singleton;
    sf::RenderWindow janela;
    sf::View camera;
    std::vector<std::pair<const sf::Drawable*, int>> drawables; // vetor de pares de int e drawable
    Renderer(int largura, int altura, const std::string& titulo);
    ~Renderer();
public:
    // Apagando operações
    void operator=(const Renderer&) = delete;
    Renderer(const Renderer&) = delete;

    // Renderização de cena
    static Renderer *getRenderer(int largura = 800, int altura = 600, const std::string& titulo =  "Nova Janela");
    void addDrawable(const sf::Drawable& drawable, int camada = 0); // Adiciona um elemento para ser desenhado
    void clearDrawables();
    void render();
    bool isOpen();

    // Movimento de câmera
    void moveCamera(float x, float y);
    void setCentroCamera(float x, float y);
    void setTamanhoCamera(float largura, float altura);
};

#endif