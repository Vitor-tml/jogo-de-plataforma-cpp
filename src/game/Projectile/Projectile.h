#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include "../Entity/Entity.h"

class Projetctile : public Entity{
private:
    float distancia;
    bool empuxo;
    const float velocidadeHorizontal;
public:
    Projetctile(int xx, int yy, sf::Texture &textura, int offsetX = 0, int offsetY = 0);
    ~Projetctile() {};
    void executar(float deltaTime);
    void executar(){};
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