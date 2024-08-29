#include Esferamagica.h

Esferamagica::Esferamagica(int xx, int yy, sf::Texture &textura, int offsetX = 0, int offsetY = 0) : 
Obstacle(xx, yy, textura, offsetX, offsetY),
elasticidade(1) {}

Esferamagica::~Esferamagica() {}

void Esferamagica::executar(float deltaTime)
{

}

void Esferamagica::obstacular(Player* jogador) {
    if (jogador->getNoChao()) {
        sf::Vector2f velocidadeAtual = jogador->getVelocidade();
        velocidadeAtual.y -= elasticidade;        // Aplicando a elasticidade como impulso para cima
        jogador->setVelocidade(velocidadeAtual);  // Aumenta a velocidade vertical do jogador, simulando um salto
        jogador->setNoChao(false);                // Atualiza o estado do jogador para não estar no chão
    }
}


void Esferamagica::obstacular(Entity *p)
{
    
}