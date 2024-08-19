#ifndef _TEST_H
#define _TEST_H
#include <iostream>
#include "../../../engine/SceneManager/Scene.h"
#include "../../../engine/Renderer/Renderer.h"
#include "../../../engine/ResourceManager/ResourceManager.h"
#include "../../Character/Player/Player.h"

class TestScene : public Scene{
private:
    Player jogador;
    sf::Sprite fundo;
public:
    TestScene();
    ~TestScene(){};
    void renderizar() override;
    void atualizar() override;
    void inicializar();

    // temporário
    void finalizar(){}
    void processarEventos(const sf::Event& evento);
    void pausar() {}
    void retomar(){}
};
#endif