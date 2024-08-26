#include "PhysicsComponent.h"

PhysicsComponent::PhysicsComponent(float gravity, float jumpHeight)
    : gravidade(gravity), alturaPulo(jumpHeight){}

void PhysicsComponent::aplicaFisica(sf::Sprite& entidade, sf::Vector2f& velocidade, float deltaTime, bool& estaNoChao)
{
    // Aplica a gravidade
    velocidade.y += gravidade * deltaTime;

    // Atualiza a posição
    entidade.move(velocidade * deltaTime);

    // Verifica colisão com o chão ou outras plataformas
    if (estaNoChao)
    {
        // Apenas aplicando a gravidade se não estiver no chão
        velocidade.y = 0;
    }
}

float PhysicsComponent::getPulo()const
{
    return alturaPulo; 
}