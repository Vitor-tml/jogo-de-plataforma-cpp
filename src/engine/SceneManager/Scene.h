#ifndef _CENA_H
#define _CENA_H

#include <SFML/Graphics.hpp>

class Scene{
public:
    virtual void inicializar() = 0;
    virtual void finalizar() = 0;
    virtual void atualizar(float deltaTime) = 0;
    virtual void renderizar() = 0;
    virtual void processarEventos(const sf::Event& evento) = 0;
    virtual void pausar() {};  // Verificar necessidade de uma cena específica 
    virtual void retomar(){};  // Verificar estado aqui
};
#endif