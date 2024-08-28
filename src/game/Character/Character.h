#ifndef _CHARACTER_H
#define _CHARACTER_H

#include "../Entity/Entity.h"
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
class Character : public Entity {
protected:
    int nVidas; ///< Número de vidas do personagem.

public:
    /**
     * @brief Construtor da classe Character.
     * @param vidas Número inicial de vidas do personagem. O valor padrão é 0.
     */
    Character(int x = 0, int y = 0, int vidas = 0) : Entity(x, y), nVidas(vidas) {};
    Character(int x, int y, int vidas, sf::Texture& textura) : Entity(x, y, textura), nVidas(vidas) {};
 
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
};

#endif