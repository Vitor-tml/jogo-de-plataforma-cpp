#include "EsferaMagica.h"

EsferaMagica::EsferaMagica(int xx, int yy, sf::Texture &textura, int offsetX, int offsetY) :
    Obstacle(xx, yy, textura, offsetX, offsetY), 
    elasticidade(1)
{
    sprite.setTexture(textura);
    sprite.setTextureRect(sf::IntRect(0, 0, 96, 96));
    sf::FloatRect tamanho = sprite.getGlobalBounds();
    sprite.setOrigin(sf::Vector2f(tamanho.width/2, tamanho.height));
    sprite.setPosition(x, y);
    inicializarCaixaColisao();
}

EsferaMagica::~EsferaMagica() {}

void EsferaMagica::executar(float deltaTime)
{

}

void EsferaMagica::obstacular(Player* jogador) {
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


//void EsferaMagica::obstacular(Entity *p)
// {
    
// }