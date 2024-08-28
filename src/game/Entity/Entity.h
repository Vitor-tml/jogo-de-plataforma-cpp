#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "../../engine/Ente/Ente.h"
#include "../../../lib/json.hpp"

/**
 * @class Entity
 * @brief Classe base para entidades no jogo.
 * 
 * Esta é uma classe abstrata que define a interface para todas as entidades no jogo.
 * As classes derivadas devem implementar os métodos puros virtuais `executar` e `salvar`.
 * @see Ente
 * @author Vitor-tml
 */
class Entity : public Ente {
protected:
    int x; ///< Coordenada x da entidade.
    int y; ///< Coordenada y da entidade.

public:
    /**
     * @brief Construtor padrão da classe Entity.
     * Inicializa as coordenadas x e y para 0.
     */
    Entity(int xx = 0, int yy = 0): Ente(), x(xx), y(yy) {};
    Entity(int xx, int yy, sf::Texture& textura): Ente(textura), x(xx), y(yy) {};
    /**
     * @brief Destruidor da classe Entity.
     * O destruidor é virtual para garantir a destruição correta das classes derivadas, nessa classe coloca as coordenadas em -1.
     */
    virtual ~Entity() { x = -1; y = -1; };
    /**
     * @brief Método puramente virtual para executar a lógica da entidade.
     * 
     * Este método deve ser implementado pelas classes derivadas para definir o comportamento específico da entidade.
     */
    virtual void executar() = 0;
    virtual void executar(float deltaTime) = 0;
    /**
     * @brief Método puramente virtual para salvar o estado da entidade.
     * 
     * Este método deve ser implementado pelas classes derivadas para definir como o estado da entidade deve ser salvo e a lógica de permanência de objeto.
     */
    virtual nlohmann::json salvar() const = 0;

    int getID() const { return id; }
};

#endif
