#ifndef _CENA_H
#define _CENA_H

#include <SFML/Graphics.hpp>

class Scene{
public:
    sf::Clock tempo;
    float deltaTime;
public:
    Scene() {};
    virtual ~Scene() {};
    virtual void inicializar() = 0;
    virtual void finalizar() = 0;
    virtual void atualizar() = 0;
    virtual void renderizar() = 0;
    virtual void processarEventos(const sf::Event& evento) = 0;
    virtual void pausar() {};  // Verificar necessidade de uma cena específica 
    virtual void retomar(){};  // Verificar estado aqui
};
#endif