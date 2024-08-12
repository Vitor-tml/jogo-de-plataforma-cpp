#include "TestScene.h"

TestScene::TestScene():
    jogador(ResourceManager::getInstance()->getTexture("jogador")),
    fundo(ResourceManager::getInstance()->getTexture("fundo"))
{
    fundo.setTextureRect(sf::IntRect(0, 200, 900, 600));

    // Settando movimento de câmera
    Renderer::getRenderer()->setTamanhoCamera(400, 300); // mesma proporção da janela
}

void TestScene::renderizar()
{
    Renderer* gerenciadorGrafico = Renderer::getRenderer();

    gerenciadorGrafico->addDrawable(fundo, 0);
    gerenciadorGrafico->addDrawable(jogador.getSprite(), 1);
    gerenciadorGrafico->setCentroCamera(jogador.getSprite().getPosition().x, jogador.getSprite().getPosition().y);
    gerenciadorGrafico->render();
}

void TestScene::atualizar()
{
    deltaTime = tempo.restart().asSeconds();
    jogador.update(deltaTime);
}
