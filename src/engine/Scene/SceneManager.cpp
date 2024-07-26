#include "SceneManager.h"

void SceneManager::mudaCena(std::unique_ptr<Scene> novaCena)
{
    while(!pilhaDeCenas.empty())
    {
        pilhaDeCenas.pop();
    }
    pilhaDeCenas.push(std::move(novaCena));
}

void SceneManager::pushCena(std::unique_ptr<Scene> novaCena)
{
    pilhaDeCenas.push(std::move(novaCena));
}

void SceneManager::popCena()
{
    if(!pilhaDeCenas.emplace())
        pilhaDeCenas.pop();
}

void SceneManager::updateCenaAtual(float deltaTime)
{
    if(!pilhaDeCenas.empty()){
        pilhaDeCenas.top()->update(deltaTime);
    }
}

void SceneManager::renderizaCenaAtual()
{
    if(!pilhaDeCenas.empty())
    {
        pilhaDeCenas.top()->render(); // Ver como fica com o singleton
    }
}

// void SceneManager::userInputCenaAtual(const sf::Event& event)
// {
//     if(!pilhaDeCenas.empty())
//     {
//         pilhaDeCenas.top()->userInput(event);
//     }
// }