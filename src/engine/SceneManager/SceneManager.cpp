#include "SceneManager.h"

// Inicia o ponteiro singleton para todos os fins
SceneManager* SceneManager::singleton = nullptr;

// Aloca a primeira instância depois retorna a unica já gerada
SceneManager* SceneManager::getInstance()
{
    if(singleton == nullptr)
        singleton = new SceneManager;
    return singleton;
}

// Deleta instância alocada
SceneManager::~SceneManager()
{
    delete singleton;
}

// Finaliza e retira cena do topo e adiciona nova cena
void SceneManager::mudarCena(std::unique_ptr<Scene> novaCena)
{
    if(!cenas.empty()){
        cenas.top()->finalizar();
        cenas.pop();
    }
    cenas.push(std::move(novaCena));
    cenas.top()->inicializar();
}

// Pausa cena no topo e adiciona nova cena
void SceneManager::empilharCena(std::unique_ptr<Scene> novaCena)
{
    if(!cenas.empty()){
        cenas.top()->pausar();
    }
    cenas.push(std::move(novaCena));
    cenas.top()->inicializar();
}

// Retira e finaliza cena no topo e retorna cena anterior
void SceneManager::desempilharCena()
{
    if(!cenas.empty()){
        cenas.top()->finalizar();
        cenas.pop();
    }
    if(!cenas.empty()){
        cenas.top()->retomar();
    }
}

// Atualiza cena atual de acondo com o tempo
void SceneManager::atualizarCenaAtual()
{
    if(!cenas.empty()){
        cenas.top()->atualizar();
    }
}

void SceneManager::renderizarCenaAtual()
{
    if(!cenas.empty()){
        cenas.top()->renderizar();
    }
}

// Atualiza cena atual de acordo com eventos
void SceneManager::processarEventosCenaAtual(const sf::Event& evento)
{
    if(!cenas.empty()){
        cenas.top()->processarEventos(evento);
    }
}