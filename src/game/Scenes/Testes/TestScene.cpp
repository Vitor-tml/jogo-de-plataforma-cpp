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
   Gerenciador::Renderer* gGrafico = Gerenciador::Renderer::getRenderer();

    gGrafico->clearDrawables();
    gGrafico->addDrawable(fundo, 0);
    gGrafico->addDrawable(jogador.getSprite(), 1);
    gGrafico->setCentroCamera(jogador.getSprite().getPosition().x, jogador.getSprite().getPosition().y);
    gGrafico->render();
}

void TestScene::atualizar()
{
    deltaTime = tempo.restart().asSeconds();
    jogador.executar(deltaTime);
}

void TestScene::processarEventos(const sf::Event& evento)
{
}