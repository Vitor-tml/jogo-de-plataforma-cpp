#ifndef _TEST_H
#define _TEST_H
#include "../../../engine/SceneManager/Scene.h"
#include "../../../engine/Renderer/Renderer.h"
#include "../../../engine/ResourceManager/ResourceManager.h"
#include "../../Player/Player.h"

class TestScene : public Scene{
private:
    Player jogador;
    sf::Sprite fundo;
public:
    TestScene();
    ~TestScene(){};
    void renderizar() override;
    void atualizar() override;

    // temporário
    void inicializar(){}
    void finalizar(){}
    void processarEventos(const sf::Event& evento){}
    void pausar() {}
    void retomar(){}
};
#endif