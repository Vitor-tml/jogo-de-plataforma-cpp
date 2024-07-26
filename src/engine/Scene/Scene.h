#ifndef _CENA_H
#define _CENA_H

#include <SFML/Graphics.hpp>

class Scene{
public:
    virtual ~Scene() = default;
    virtual void update(float deltaTime) = 0;
    //virtual void userInput(const sf::Event& evento) = 0;
    virtual void render() = 0;
};
#endif