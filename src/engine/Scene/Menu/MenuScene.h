#ifndef _MENU_H
#define _MENU_H

#include <SFML/Graphics.hpp>
#include "../Scene.h"
#include "../SceneManager.h"
#include "../../Renderer/Renderer.h"

class MenuScene : public Scene {
private:
    SceneManager& gerenciadorDeCena;
    sf::Font fonte;
    sf::Text textoInicial;
    sf::Text textoEditor;
    sf::Text textoSaida;
    sf::Text textoTitulo;

    int opcao;
    const int nOpcoes = 3;
    void selectOption();
public:
    MenuScene(SceneManager& sceneManager);
    void update(float deltaTime) override;
    void render() override;
    //void userInput(const sf::Event& evento) override;

};
#endif