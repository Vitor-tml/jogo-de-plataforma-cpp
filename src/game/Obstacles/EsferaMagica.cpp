 #include "EsferaMagica.h"

EsferaMagica::EsferaMagica(int xx, int yy, sf::Texture &textura, int offsetX, int offsetY) :
    Obstacle(xx, yy, textura, offsetX, offsetY), 
    elasticidade(100)
{
    sprite.setTexture(textura);
    sprite.setTextureRect(sf::IntRect(30, 460, 100, 100));
    sprite.setScale(sf::Vector2f(0.5,0.5));
    sf::FloatRect tamanho = sprite.getGlobalBounds();
    // sprite.setOrigin(sf::Vector2f(50, 50));
    sprite.setPosition(x, y);
    inicializarCaixaColisao();
}

EsferaMagica::~EsferaMagica() {}

void EsferaMagica::executar(float deltaTime)
{

}

void EsferaMagica::obstacular(Player* jogador) {
    sf::Vector2f velocidadeAtual = jogador->getVelocidade();
    velocidadeAtual.y -= elasticidade; // Aplicando a elasticidade como impulso para cima
    jogador->setVelocidade(velocidadeAtual);
    jogador->setNoChao(false); // O jogador foi arremessado para cima, portanto não está mais no chão
}


//void EsferaMagica::obstacular(Entity *p)
// {
    
// }