#include "PrimeiraFase.h"

PrimeiraFase::PrimeiraFase(Player* p, Player2 *p2):
    Phase(gRecursos->getTexture("fundo"), p, p2),
    chao(0, -190, gRecursos->getTexture("chao"), 0, 726)
{
    // Iniciar local?
    //sprite.setOrigin()
    sprite.setTextureRect(sf::IntRect(0, 200, 900, 600));
    
    listaEntidades.incluir(&chao);
    gColisao.incluirObstaculo(&chao); 

    criarPlataformas();
    criarArqueiros();
    criarEsqueletos();
}

void PrimeiraFase::criarPlataformas()
{
    const int nPlataformas = 6;
    plataformas.clear();
    plataformas.reserve(nPlataformas);
    for(int i = 0; i < nPlataformas; i++)
    {
        Plataforma *novaPlataforma = new Plataforma(60 + 32 * i, 440, gRecursos->getTexture("plataforma"));
        novaPlataforma->setExecutar(true);
        plataformas.push_back(novaPlataforma);
        listaEntidades.incluir(novaPlataforma);
        gColisao.incluirObstaculo(novaPlataforma);
    }
}

void PrimeiraFase::criarEsqueletos()
{
    std::srand(static_cast<unsigned>(std::time(nullptr))); // Inicializa o gerador com a semente baseada no tempo
    const int nMin = 3;
    const int nMax = 6;
    int nEsqueletos = nMin +  std::rand() % (nMax - nMin); // Gera um número aleatório
    for(int i = 0; i < nEsqueletos; i++)
    {
        Esqueleto *novoEsqueleto = new Esqueleto(gRecursos->getTexture("inimigo"));
        novoEsqueleto->setPosicao(32 * i, 300);
        novoEsqueleto->setExecutar(true);
        esqueletos.push_back(novoEsqueleto);
        listaEntidades.incluir(novoEsqueleto);
        gColisao.incluirInimigos(novoEsqueleto);
    }
}

void PrimeiraFase::criarArqueiros()
{
    std::srand(static_cast<unsigned>(std::time(nullptr))); // Inicializa o gerador com a semente baseada no tempo
    const int nMin = 3;
    const int nMax = 6;
    int nArqueiros = nMin +  std::rand() % (nMax - nMin); // Gera um número aleatório
    for(int i = 0; i < nArqueiros; i++)
    {
        Arqueiro *novoArqueiro = new Arqueiro(300, 500, gRecursos->getTexture("arqueiro"));
        Projetil *novaBala = new Projetil(0, 0);
        novoArqueiro->setExecutar(true);
        novaBala->setExecutar(true);
        novoArqueiro->setBala(novaBala);
        arqueiros.push_back(novoArqueiro);
        listaEntidades.incluir(novoArqueiro);
        gColisao.incluirInimigos(novoArqueiro);
        gColisao.incluirProjetil(novaBala);
        std::cout << "Incluindo arqueiro" << std::endl;     
    }
}
