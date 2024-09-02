#include "Menu.h"
#include <iostream>

Menu::Menu(int* i):
    Ente(gRecursos->getTexture("menu")),
    numOpcoes(4),
    estado(i),
    intervaloTroca(0.2f),
    opcaoSelecionada(0) // Inicia a seleção na primeira opção
{   

    int eX = gGrafico->getTamanho().x;
    int eY = gGrafico->getTamanho().y;
    eY = (eY - 130)/numOpcoes ;
    sprite.setOrigin(0, 0);
    for(int i = 0; i < numOpcoes; i++)
    {
        botoes[i].setTexture(gRecursos->getTexture("icones"));
        botoes[i].setTextureRect(sf::IntRect(0, 230, 250, 80));
        botoes[i].setPosition(eX/2 - botoes[i].getGlobalBounds().width/2, i * eY + 80);
        
        escolhido[i].setTexture(gRecursos->getTexture("icones"));
        escolhido[i].setTextureRect(sf::IntRect(250, 230, 250, 80));
        escolhido[i].setPosition(eX/2 - escolhido[i].getGlobalBounds().width/2, i * eY + 80);
    
        texto[i].setFont(gRecursos->getFont("fonte")); // Certifique-se de ter carregado a fonte
        texto[i].setString("Opção " + std::to_string(i + 1)); // Texto padrão
        texto[i].setCharacterSize(23); // Tamanho da fonte
        texto[i].setFillColor(sf::Color::Black); // Cor do texto
        texto[i].setPosition(eX / 2 - 60, i * eY + 110); // Ajuste a posição do texto
    }

    // Aqui você pode inicializar a quantidade de opções
    texto[0].setString("Primeira Fase");
    texto[1].setString("Segunda Fase");
    texto[2].setString("Terceira Fase");
    texto[3].setString("Rank");
    tempoUltimaPressao = 0;
    tempoPressaoEnter = 0;
}

void Menu::setEstado(int i)
{
    *estado = i;
}

void Menu::executar()
{
    // Limpa buffer de teclas
    for (int i = 0; i < sf::Keyboard::KeyCount; ++i) {
            sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(i));
    }

    deltaTime = tempo.restart().asSeconds();
    tempoUltimaPressao += deltaTime;
    tempoPressaoEnter += deltaTime;
    // std::cout << "Enter: " << tempoPressaoEnter << " Intervalo: " << intervaloTroca << std::endl;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && tempoUltimaPressao > intervaloTroca) {
        opcaoSelecionada = (opcaoSelecionada + 1) % numOpcoes;
        tempoUltimaPressao = 0.0f;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && tempoUltimaPressao > intervaloTroca) {
        opcaoSelecionada = (opcaoSelecionada - 1 + numOpcoes) % numOpcoes;
        tempoUltimaPressao = 0.0f;
    }
    // Verifica a tecla Enter para seleção
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && tempoPressaoEnter > 1.7f) {
        setEstado(opcaoSelecionada + 1);
        tempoPressaoEnter = 0.0f; // Reinicia o tempo
    }

    renderizar(0);
    for(int i = 0; i < numOpcoes; i++)
    {
        if(i ==  opcaoSelecionada)
            gGrafico->addDrawable(escolhido[i], 1);
        else
            gGrafico->addDrawable(botoes[i], 1);
        gGrafico->addDrawable(texto[i], 2);
    }
    gGrafico->render();
    gGrafico->clearDrawables();
}