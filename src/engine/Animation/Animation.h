#ifndef _ANIMATION_H
#define _ANIMATION_H

#include <SFML/Graphics.hpp>
#include <vector>

class Animation{
private:
    const sf::Texture& textura;
    std::vector<sf::IntRect> frames;
    float duracao;
    float tempoDecorrido;
    size_t indexFrameAtual;
    bool finalizada;
public:
    Animation(sf::Texture& texture, std::vector<sf::IntRect> frames, float duration);
    void update(float deltaTime);
    sf::IntRect getFrameAtual()const;
    bool isFinished()const;

    Animation& operator=(const Animation& other) = delete;
};

void printIntRect(sf::IntRect& rect);
#endif