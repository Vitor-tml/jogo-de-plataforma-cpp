#ifndef _ENTE_H
#define _ENTE_H

#include <SFML/Graphics.hpp>
#include "../Renderer/Renderer.h"
/**
 * @brief Classe base para todos os elementos visuais do jogo.
 * 
 * A classe Ente é responsável por representar elementos visuais
 * no jogo e fornecer funcionalidades básicas como renderização.
 * @author Vitor-tml
 */
class Ente{
protected:
    const int id;                        //< Indentificador para permanência de objeto
    static int cont;                     //< Contador de ID
    static Renderer* gerenciadorGrafico; //< Instância única do renderer
    sf::Sprite figura;                   //< Shape a ser desenhado do elemento.
public:
    /**
     * @brief Construtora da classe-base Ente.
     * Inicia o atríbuto id e inicia "figura" com um place holder.
     */
    Ente();
    /**
     * @brief Destrutora da classe-base Ente.
     * Apenas para criar explicitamente o método.
     */
    ~Ente();
    virtual void executar() = 0;
    /**
     * @brief Método que renderiza o objeto na tela
     * Adiciona a sprite do objeto na fila de renderização do gerenciador gráfico.
     */
    void renderizar();
};
#endif