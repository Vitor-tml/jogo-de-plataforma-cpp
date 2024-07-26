#include "MenuScene.h"

MenuScene::MenuScene(SceneManager& sceneManager)
    : gerenciadorDeCena(sceneManager), opcao(0)
{
    if(!fonte.loadFromFile("../assets/fonts/Revorioum.ttf")){
        exit(1);
    }
    textoTitulo.setFont(fonte);
    textoTitulo.setString("Meu Jogo 2D");
    textoTitulo.setCharacterSize(50);
    textoTitulo.setFillColor(sf::Color::White);
    textoTitulo.setPosition(300, 100);

    textoInicial.setFont(fonte);
    textoInicial.setString("Iniciar Jogo");
    textoInicial.setCharacterSize(30);
    textoInicial.setFillColor(sf::Color::Yellow);
    textoInicial.setPosition(300, 200);

    textoEditor.setFont(fonte);
    textoEditor.setString("Editor de Niveis");
    textoEditor.setCharacterSize(30);
    textoEditor.setFillColor(sf::Color::White);
    textoEditor.setPosition(300, 250);

    textoSaida.setFont(fonte);
    textoSaida.setString("Sair");
    textoSaida.setCharacterSize(30);
    textoSaida.setFillColor(sf::Color::White);
    textoSaida.setPosition(300, 300);
}

// Animação e lógica do menu
void MenuScene::update(float deltaTime)
{

}

void MenuScene::render()
{
    Renderer *janela = Renderer::getRenderer();

    janela->addDrawable(textoTitulo);
    janela->addDrawable(textoInicial);
    janela->addDrawable(textoEditor);
    janela->addDrawable(textoSaida);
    janela->render();
}