#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include "../Entity/Entity.h"
#include "../Character/Player/Player.h"

class Projetil : public Entity{
private:
    float distancia;
    bool empuxo;
    const float velocidadeHorizontal;
public:
    Projetil(int xx, int yy, int offsetX = 0, int offsetY = 0);
    ~Projetil() {};
    void executar(float deltaTime);
    void executar(){};
    void danificar(Player* jogador);
    nlohmann::json salvar() const override { // refazer, implementei só pra nao dar erro
    nlohmann::json jsonObj;
    jsonObj["distancia"] = distancia;
    jsonObj["empuxo"] = empuxo;
    jsonObj["velocidadeHorizontal"] = velocidadeHorizontal;
    // Adicione outros atributos do projétil, se necessário
    return jsonObj;
}
};
#endif