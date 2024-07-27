#ifndef _EDITOR_H
#define _EDITOR_H

#include <SFML/Graphics.hpp>
#include "../../../engine/SceneManager/SceneManager.h"
#include "../../../engine/SceneManager/Scene.h"
#include "../../../engine/Renderer/Renderer.h"

class EditorScene : public Scene {
private:
    sf::Font fonte;
    sf::Text texto;
public:
    EditorScene();
    ~EditorScene(){};
    void inicializar() override;
    void finalizar() override;
    void atualizar(float deltaTime) override;
    void renderizar() override;
    void processarEventos(const sf::Event& evento) override;
};
#endif