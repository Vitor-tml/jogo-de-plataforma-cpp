#ifndef _PLAYER_H
#define _PLAYER_H

#include <SFML/Graphics.hpp>
#include "../Character.h"

#include "../../../engine/Animation/Animation.h"
#include <map>
#include <iostream>

/**
 * @class Player
 * @brief A classe que representa o jogador dentro do programa
 * 
 * A classe player encapsula a lógica de controle, física e animação do personagem principal do jogo
 * 
 * @author Vitor-tml
 */
class Player : public Character{
private:
    int pontos;

    const float velocidadeHorizontal = 200.f;
    
    /**
     * @brief Componente que controlam o estado atual da sprite do player, gerando a animação.
     * @see Animation
     */
    Animation parado; // 0 0
    Animation andando;// 0 68
    Animation *animacaoAtual;
    /**
     * @brief Muda o estado atual da animação do player
     * @param name nome definido para a animação (hard code)
     */
    void setAnimation(const std::string& name);

public:
    /**
     * @brief construtora do player, carrega o spritesheet do personagem.
     * @param textura imagem que irá representar o player
     * @todo Valor padrão para ser também uma construtora sem parâmetros
     */
    Player(sf::Texture& textura);
    /**
     * @todo Perguntar quando a sobrecarga e de método para o professor
     */
    void executar() override {};
    /**
     * @brief Atualiza o estado da animação e le a entrada do usuário
     * @param deltaTime Tempo decorrido entra a ultima chamada da função
     * @todo Testar implementação por evento, em vez de deltaTime
     */
    void executar(float deltaTime);
    /**
     * @brief Atualiza animação e estado do player de acordo com a entrada do usuário, responsável pela movimentação do personagem.
     */
    void userInput();
    /**
     * @brief Retorna sprite atual do player
     * @return Estado atual da animação/player para renderização
     */
    sf::Sprite& getSprite();
    /**
     * @brief Método responsável pela permanência de objeto da classe player.
     * @todo Implementar quando decidido sobre a lógica de permanencia e controle de arquivos.
     */
    int getVida();
    /**
     * @brief Retorna vida atual do player.
     */
    void setVida(int vida);
    /**
     * @brief Altera o valor da vida atual do player.
     */
    void salvar() override { std::cout << "Sem metodo de salvar ainda." << std::endl;};
    /**
     * @brief Retorna posição do personagem
     * 
     */
    

    
};
#endif