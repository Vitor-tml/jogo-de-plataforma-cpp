#include "TestScene.h"

TestScene::TestScene():
    jogador(ResourceManager::getInstance()->getTexture("jogador")),
    fundo(ResourceManager::getInstance()->getTexture("fundo"))
{
}

void TestScene::inicializar()
{
    fundo.setTextureRect(sf::IntRect(0, 200, 900, 600));
    //Renderer::getRenderer()->setTamanhoCamera(400, 300);
}
void TestScene::renderizar()
{
    Renderer* gerenciadorGrafico = Renderer::getRenderer();

    gerenciadorGrafico->clearDrawables();
    gerenciadorGrafico->addDrawable(fundo, 0);
    gerenciadorGrafico->addDrawable(jogador.getSprite(), 1);
    gerenciadorGrafico->setCentroCamera(jogador.getSprite().getPosition().x, jogador.getSprite().getPosition().y);
    gerenciadorGrafico->render();
}

void TestScene::atualizar()
{
    deltaTime = tempo.restart().asSeconds();
    jogador.executar(deltaTime);
}

void TestScene::processarEventos(const sf::Event& evento)
{
}