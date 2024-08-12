#ifndef _MENU_H
#define _MENU_H

#include <SFML/Graphics.hpp>
#include "../../../engine/SceneManager/SceneManager.h"
#include "../../../engine/SceneManager/Scene.h"
#include "../../../engine/Renderer/Renderer.h"
#include "../../../engine/ResourceManager/ResourceManager.h"

class MenuScene : public Scene {
private:
    sf::Font fonte;
    sf::Text texto;
public:
    MenuScene();
    ~MenuScene(){};
    void inicializar() override;
    void finalizar() override;
    void atualizar() override;
    void renderizar() override;
    void processarEventos(const sf::Event& evento) override;
};
#endif