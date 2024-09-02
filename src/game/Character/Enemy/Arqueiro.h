#ifndef _ARQUEIRO_H
#define _ARQUEIRO_H

#include "Enemy.h"
#include "../../Projetil/Projetil.h"
class Arqueiro : public Enemy{
private:
    int nBalas;
    Projetil *bala;
    bool olhandoDireita;
    float tempoDecorrido;             // Tempo decorrido desde a última mudança de direção
    float tempoDecorridoTiro;
    const float intervaloTroca = 2.0f;
    const float intervaloTiro = 2.5f;
public:
    Arqueiro(int xx, int yy, sf::Texture& textura);
    ~Arqueiro(){};
    void mover(float deltaTime);
    void executar(float deltaTime);                 // Transformar em virtual futuramente
    void danificar(Player* jogador);           // Transformar em virtual futuramente
    void executar() {};
    void atirar(float deltaTime);
    void setBala(Projetil *b);
    Projetil* getBala()const;
    nlohmann::json salvar() const;
};
#endif