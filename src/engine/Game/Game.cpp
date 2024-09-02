#include "Game.h"

Game::Game():
    janela(Renderer::getRenderer(800, 600, "Cavaleiro Vagante.")),
    gRecursos(ResourceManager::getInstance())
{
    gRecursos->loadTexture("jogador",    "../assets/textures/knight.png");
    gRecursos->loadTexture("fundo",      "../assets/textures/background.png");
    gRecursos->loadTexture("plataforma", "../assets/textures/plataforma.png");
    gRecursos->loadTexture("menu",       "../assets/textures/fundomenu.png");
    gRecursos->loadTexture("inimigo",    "../assets/textures/skeleton.png");
    gRecursos->loadTexture("chao",       "../assets/textures/chao.png");
    gRecursos->loadTexture("espinho",    "../assets/textures/espinho.png");
    gRecursos->loadTexture("bala",       "../assets/textures/bala.png");
    gRecursos->loadTexture("arqueiro",   "../assets/textures/arqueiro.png");
    gRecursos->loadTexture("icones",     "../assets/textures/menu.png");
    gRecursos->loadTexture("esfera",      "../assets/textures/esferaMagica.png");
    gRecursos->loadTexture("coracao",      "../assets/textures/coracao.png");
    gRecursos->loadTexture("fundo2",      "../assets/textures/fundo2.jpg");

    gRecursos->loadImage("jogador",      "../assets/textures/knight.png");
    gRecursos->loadFont("fonte",         "../assets/fonts/Revorioum.ttf");
}

Game::~Game()
{

}

void Game::executar()
{
    int estado = 5;
    Player jogador(gRecursos->getTexture("jogador")); // Criei para testar o LeadBoard
    Player2 jogador2(gRecursos->getTexture("jogador")); // Criei para testar o LeadBoard
    Menu menu(&estado);
    PrimeiraFase fase1(&jogador, &jogador2);
    SegundaFase fase2(&jogador, &jogador2);
    LeadBoard leadboard;
    while (janela->isOpen())
    {
        sf::Event evento;
        while(janela->pollEvent(evento))
        {
            if(evento.type == sf::Event::Closed)
                janela->close();    
        }
        switch (estado)
        {
        case 0:
            menu.executar();
            break;
        case 1:
            fase1.executar();
            break;
        case 2:
            fase2.executar();
            break;
        case 4:
            leadboard.executar();
            break;
        case 5:
            leadboard.salvarPontos(&jogador);
            jogador.setVida(20);
            jogador2.setVida(20);
            estado = 0;
            break;
        default:
            break;
        }
        if(jogador.getVida() <= 0 || jogador2.getVida() <= 0)
            estado = 5;
        // std::cout << "Opcao: " << estado << std::endl;
    }
} 