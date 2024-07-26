#ifndef _GERENCIADOR_DE_CENA_H
#define _GERENCIADOR_DE_CENA_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <stack>
#include "Scene.h"

class SceneManager{
private:
    std::stack<std::unique_ptr<Scene>> pilhaDeCenas;
public:
    void mudaCena(std::unique_ptr<Scene> novaCena);
    void pushCena(std::unique_ptr<Scene> novaCena);
    void popCena();

    void updateCenaAtual(float deltaTime);
    //void userInputCenaAtual(const sf::Event& evento);
    void renderizaCenaAtual();
};
#endif