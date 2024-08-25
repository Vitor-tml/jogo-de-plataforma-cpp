#ifndef _MENU_SCENE_H
#define _MENU_SCENE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../../engine/SceneManager/SceneManager.h"
#include "../../../engine/SceneManager/Scene.h"
#include "../../../engine/Renderer/Renderer.h"
#include "../../../engine/ResourceManager/ResourceManager.h"

/**
 * @class MenuScene
 * @brief Cena responsável pelo menu do jogo que leva para os outros estados do mesmo.
 * @todo Animação da seleção dos botões
 * @todo Melhorar spites
 * @see SceneManager
 */
class MenuScene : public Scene {
private:
    sf::Font fonte;
    sf::Text texto;
    sf::Sprite fundo;
public:
    /**
     * @brief Constutora da cena do menu
     * Inicializa recursos usados na cena
     */
    MenuScene();
    /**
     * @brief Destrutora da cena do menu
     */
    ~MenuScene(){};
    /**
     * @brief Inicializa objetos utilizados um as fontes e texturas carregadas na construtora
     */
    void inicializar() override;
    /**
     * @brief Finaliza cena
     * Apenas para cumprir necessidade da classe abstrata, não é necessário nenhuma finalização
     */
    void finalizar() override {};
    /**
     * @brief Atualiza estado da cena
     * Responsável pela animação de seleção a UI
     * @todo Colocar animação de fundo aqui
     */
    void atualizar() override;
    /**
     * @brief Renderizador de cena de menu
     * Adiciona os elementos a serem renderizados na ordem para serem renderizados
     */
    void renderizar() override;
    /**
     * @brief Trata os eventos que o menu é responsável
     */
    void processarEventos(const sf::Event& evento) override;
};
#endif