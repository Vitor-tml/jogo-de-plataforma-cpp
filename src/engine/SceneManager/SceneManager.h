/*
    1. Menu
    2. Cena configurações
    3. Cena fase(s)
*/

#ifndef _GERENCIADOR_DE_CENAS_H
#define _GERENCIADOR_DE_CENAS_H

#include <stack>
#include <memory>
#include "Scene.h"

class SceneManager{
private:
    // Definições do padrão de projeto
    static SceneManager *singleton;
    SceneManager(){};
    // Funcão oficial da classe
    std::stack<std::unique_ptr<Scene>> cenas;
public:
    // Definições do padrão de projeto
    // Apagando operações
    void operator=(const SceneManager&) = delete;
    SceneManager(const SceneManager&) = delete;
    ~SceneManager();
    static SceneManager* getInstance();
    
    // Funcão oficial da classe
    void mudarCena(std::unique_ptr<Scene> novaCena);
    void empilharCena(std::unique_ptr<Scene> novaCena);
    void desempilharCena();
    void atualizarCenaAtual();
    void renderizarCenaAtual();
    void processarEventosCenaAtual(const sf::Event& evento);
};
#endif