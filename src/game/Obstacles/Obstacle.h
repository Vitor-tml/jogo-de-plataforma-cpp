#ifndef _OBSTACLE_H
#define _OBSTACLE_H

#include "../../../lib/json.hpp"
#include "../Entity/Entity.h"

class Player;
class Obstacle : public Entity {
protected:
    bool danoso;
public:
    virtual void executar() = 0;
    virtual void obstacular(Player *jogador) = 0;
    nlohmann::json salvar() const override {
        nlohmann::json j;
        j["id"] = 1;
        j["posX"] = 10;
        j["posY"] = 10;
        j["health"] = 100;
        return j;
    }
};
#endif