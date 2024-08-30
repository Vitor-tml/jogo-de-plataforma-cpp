#ifndef _OBSTACLE_H
#define _OBSTACLE_H

#include "../../../lib/json.hpp"
#include "../Entity/Entity.h"

class Player;
class Obstacle : public Entity {
protected:
    bool danoso;
public:
    Obstacle(int xx, int yy, sf::Texture& textura, int offX = 0, int offY = 0);
    ~Obstacle(){};
    virtual void executar(){};                  // Depois colocar virtual pura
    virtual void obstacular(Player *jogador){}; // Depois colocar virtual pura
    virtual void obstacular(Entity *p){}; // Depois colocar virtual pura
    
    nlohmann::json salvar() const override {
        // Implementação temporária para testes
        nlohmann::json j;
        j["id"] = getID();
        j["posX"] = 10;
        j["posY"] = 10;
        j["health"] = 10;
        return j;
    }
};
#endif