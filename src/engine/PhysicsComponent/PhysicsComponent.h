#ifndef _FISICA_H
#define _FISICA_H

#include <SFML/Graphics.hpp>

class PhysicsComponent{
private:
    float gravidade;
    float alturaPulo;
public:
    PhysicsComponent(float gravity = 980.f, float jumpHeight = 300.f);
    ~PhysicsComponent(){};
    void aplicaFisica(sf::Sprite& entidade, sf::Vector2f& velocidade, float deltaTime, bool& estaNoChao);
    float getPulo()const;
};
#endif