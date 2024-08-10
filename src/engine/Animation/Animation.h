
#ifndef _ANIMATION_H
#define _ANIMATION_H

#include <SFML/Graphics.hpp>
#include <vector>

/**
 * @class Animation
 * @brief Gerencia a animação de sprites com base em frames e tempo.
 * 
 * A classe Animation lida com a atualização e controle dos frames de uma animação, 
 * baseada em uma textura e um conjunto de retângulos (frames) que definem as diferentes 
 * fases da animação.
 * 
 * @note Esta classe não permite cópia. O operador de atribuição é deletado.
 * @todo Mudar para não ter tempo para a animação finalizar
 * @author Vitor-tml
 */
class Animation{
private:
    const sf::Texture& textura;      ///< Spritesheet da animação
    std::vector<sf::IntRect> frames; ///< Vetor de frames da animação. Ponto inicial (x0, y0) ponto final (xfinal, yfinal)
    float duracao;                   ///< Duração de CADA FRAME, ou seja, velocidade da animação
    float tempoDecorrido;            ///< Tempo decorrido desde o inicio da animação
    size_t indexFrameAtual;
    bool finalizada;
public:
    /**
     * @brief Construtora da classe de animação
     * @param texture Spritesheet da animação
     * @param frames VETOR de retângulos do SFML onde estão cada frame (declarar na sequência da animação)
     * @param duration duração (em segundos) de cada frame
     */
    Animation(sf::Texture& texture, std::vector<sf::IntRect> frames, float duration);
    /**
     * @brief Atualiza a animação de acordo com o tempo passado
     * @todo Verificar possibilidade de não precisar passar deltatime
     * @param deltaTime tempo decorrido desde a última chamada
     */
    void update(float deltaTime);
    /**
     * @brief Retorna frame a ser renderizado.
     * @return Retângulo do frame atual
     */
    sf::IntRect getFrameAtual()const;
    /**
     * @return true quando a aniamção já finalizou, caso contrário false.
     */
    bool isFinished()const;

    Animation& operator=(const Animation& other) = delete; ///< Deleta operação de atribuição
};
#endif