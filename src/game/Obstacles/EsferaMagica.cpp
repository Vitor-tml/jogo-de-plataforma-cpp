#include EsferaMagica.h

EsferaMagica::EsferaMagica(int xx, int yy, sf::Texture &textura, int offsetX = 0, int offsetY = 0) : 
Obstacle(xx, yy, textura, offsetX, offsetY),
elasticidade(1) {}

EsferaMagica::~EsferaMagica() {}

void EsferaMagica::executar(float deltaTime)
{

}

void EsferaMagica::obstacular(Player* jogador) {
    // Vamos verificar a colisão vertical com a esfera
    sf::FloatRect playerBox = jogador->getCaixaColisao().getGlobalBounds();
    sf::FloatRect obstacleBox = this->getCaixaColisao().getGlobalBounds();

    if (playerBox.intersects(obstacleBox)) {
        // Se o jogador estiver na base da esfera e colidindo com ela, aplica o impulso
        if (jogador->getNoChao() && playerBox.top + playerBox.height >= obstacleBox.top) {
            sf::Vector2f velocidadeAtual = jogador->getVelocidade();
            velocidadeAtual.y -= elasticidade; // Aplicando a elasticidade como impulso para cima
            jogador->setVelocidade(velocidadeAtual);
            jogador->setNoChao(false); // O jogador foi arremessado para cima, portanto não está mais no chão
        }
    }
}


void EsferaMagica::obstacular(Entity *p)
{
    
}