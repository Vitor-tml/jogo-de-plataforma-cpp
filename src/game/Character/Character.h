#ifndef _CHARACTER_H
#define _CHARACTER_H

#include "../Entity/Entity.h"
#include "../../engine/PhysicsComponent/PhysicsComponent.h"
#include "../../../lib/json.hpp"

/**
 * @class Character
 * @brief Classe base para personagens no jogo.
 * 
 * Esta classe herda de `Entity` e define a estrutura básica para personagens no jogo.
 * A classe é abstrata e deve ser estendida por classes derivadas que forneçam implementações
 * concretas para os métodos `executar` e `salvar`.
 * @see Entity Ente
 * @author Vitor-tml
 */ 
class Entity;
class Character : public Entity {
protected:
    int nVidas; ///< Número de vidas do personagem.
    const float tempoInvulnerabilidade = 1.0f; // Tempo em segundos
    sf::Clock relogioDano; // Relógio para controlar o tempo entre danos
public:
    /**
     * @brief Construtor da classe Character.
     * @param vidas Número inicial de vidas do personagem. O valor padrão é 0.
     */
    Character(int x = 0, int y = 0, int vidas = 0) : Entity(x, y), nVidas(vidas) {};
    Character(int x, int y, float offSetColisorX, float offSetColisorY, int vidas, sf::Texture& textura) : Entity(x, y, offSetColisorX, offSetColisorY, textura), nVidas(vidas) {};
 
    /**
     * @brief Destruidor da classe Character.
     * O destruidor é virtual para garantir a destruição correta das classes derivadas.
     */
    virtual ~Character() {};

    /**
     * @brief Método puramente virtual para executar a lógica do personagem.
     * Este método deve ser implementado pelas classes derivadas para definir o comportamento específico do personagem.
     */
    virtual void executar() = 0;

    /**
     * @brief Método puramente virtual para salvar o estado do personagem.
     * 
     * Este método deve ser implementado pelas classes derivadas para definir como o estado do personagem deve ser salvo e lógica de permanência de objeto.
     */
    virtual nlohmann::json salvar() const = 0;
    const int getVida() const { return nVidas; }

    void operator--() 
    {
        if (nVidas > 0 && relogioDano.getElapsedTime().asSeconds() >= tempoInvulnerabilidade) {
            --nVidas;
            relogioDano.restart(); // Reinicia o relógio após receber dano
        }
    }

    // Pós-decremento (a--)
    void operator--(int) 
    {
        if (nVidas > 0 && relogioDano.getElapsedTime().asSeconds() >= tempoInvulnerabilidade) {
            --nVidas;
            relogioDano.restart(); // Reinicia o relógio após receber dano
        }
    }
};

#endif