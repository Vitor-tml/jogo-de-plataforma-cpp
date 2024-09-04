#ifndef _ENTE_H
#define _ENTE_H

#include <SFML/Graphics.hpp>
#include "../Renderer/Renderer.h"
#include "../ResourceManager/ResourceManager.h"
/**
 * @class Ente
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
    static Gerenciador::Renderer* gGrafico; //< Instância única do renderer
    static ResourceManager* gRecursos;   //< Instancia única do gerenciador de recursos
    sf::Sprite sprite;                   //< Shape a ser desenhado do elemento.
public:
    /**
     * @brief Construtora da classe-base Ente.
     * Inicia o atríbuto id e inicia "figura" com um place holder.
     */
    Ente();
    /**
     * @brief Construtora com parâmetros da classe base Ente
     * Inicia o atríbuto id define a textura do sprite
     */
    Ente(sf::Texture& figura, float offSetx = 0, float OffSety = 0);
    /**
     * @brief Destrutora da classe-base Ente.
     * Apenas para criar explicitamente o método.
     */
    virtual ~Ente();
    /**
     * @brief Método puramente virtual para executar a lógica do objeto
     * Deve ser implementada nas classes filhas para trabalhar a lógica do objeto.
     */
    virtual void executar() = 0;
    /**
     * @brief Método que renderiza o objeto na tela
     * Adiciona a sprite do objeto na fila de renderização do gerenciador gráfico.
     */
    void renderizar(int camada = 0);
    /**
     * @brief Retorna o sprite do Ente
     * @return sf::Sprite 
     */
    sf::Sprite getSprite() const;
    /**
     * @brief Nova textura do Ente
     * @param textura nova textura do ente
     */
    void setTexture(sf::Texture& textura);
};
#endif