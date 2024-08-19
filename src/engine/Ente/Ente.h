#ifndef _ENTE_H
#define _ENTE_H

#include <SFML/Graphics.hpp>
#include "../Renderer/Renderer.h"

class Ente{
protected:
    const int id;
    static int cont;
    static Renderer* gerenciadorGrafico;
    sf::Sprite figura;    
public:
    Ente();
    ~Ente();
    virtual void executar() = 0;
    void renderizar();
};
#endif