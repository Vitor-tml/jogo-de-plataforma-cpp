#ifndef _PRINCIPAL_H
#define _PRINCIPAL_H

#include "../Renderer/Renderer.h"
#include "../ResourceManager/ResourceManager.h"
#include "../../game/Character/Player/Player.h"
#include "../../game/Menu/Menu.h"
#include "../../game/Levels/Phase.h"

class Game{
private:
    Renderer* janela;
    ResourceManager* gRecursos;
    
public:
    Game();
    ~Game();
    void executar();
};
#endif