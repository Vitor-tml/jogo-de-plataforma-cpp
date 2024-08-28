#include "Entity.h"

Entity::Entity(int xx, int yy): 
    Ente(),
    offSetColisao(0.f, 0.f),
    pontoOrigem(0.5f),
    caixaColisao(sf::Vector2f(0.f, 0.f))
{
    x = xx;
    y = yy;
    sprite.setPosition(x, y);
}
Entity::Entity(int xx, int yy, float offSetColisorX, float offSetColisorY, sf::Texture& textura):
    Ente(textura),
    offSetColisao(offSetColisorX, offSetColisorY),
    pontoOrigem(0.5f),
    caixaColisao(sf::Vector2f(0.f, 0.f))
{
    x = xx;
    y = yy;
    sprite.setPosition(x, y);
}

sf::RectangleShape Entity::getCaixaColisao() const
{
    return caixaColisao;
}

void Entity::renderizarCaixaColisao()
{
    gGrafico->addDrawable(caixaColisao, 3);
}

void Entity::inicializarCaixaColisao()
{
    sf::FloatRect caixa = sprite.getGlobalBounds();
    sf::Vector2f tamanho(caixa.width - offSetColisao.x, caixa.height - offSetColisao.y);
    caixaColisao.setSize(tamanho);
    caixaColisao.setOrigin(sprite.getOrigin());
    
    caixaColisao.setOutlineColor(sf::Color::Red);
    caixaColisao.setOutlineThickness(2);
    caixaColisao.setFillColor(sf::Color::Transparent);
    atualizarCaixaColisao();
}
void Entity::inicializarCaixaColisao(int largura, int altura)
{
    sf::Vector2f tamanho(largura - 4, altura - 4); // retirando bordas!
    caixaColisao.setSize(tamanho);
    caixaColisao.setOrigin(sprite.getOrigin());
    caixaColisao.setOutlineColor(sf::Color::Red);
    caixaColisao.setOutlineThickness(2);
    caixaColisao.setFillColor(sf::Color::Transparent);
    atualizarCaixaColisao();
}

void Entity::atualizarCaixaColisao()
{
    // Considera a origem do sprite e a posição ao ajustar a hitbox
    sf::Vector2f pos = sprite.getPosition();
    caixaColisao.setPosition(pos.x + offSetColisao.x/2, pos.y + offSetColisao.y);
}

void Entity::setVelocidade(const sf::Vector2f& novaVelocidade)
{
    this->velocidade = novaVelocidade;
}

sf::Vector2f Entity::getVelocidade() const 
{
    return this->velocidade;
}


void Entity::setNoChao(bool noChao)
{
    estaNoChao = noChao;
}

bool Entity::getNoChao() const
{
    return estaNoChao;
}

void Entity::setPosicao(int xx, int yy)
{
    sprite.setPosition(xx, yy);
}
void Entity::setPosicao(sf::Vector2f posicao)
{
    sprite.setPosition(posicao);
}
