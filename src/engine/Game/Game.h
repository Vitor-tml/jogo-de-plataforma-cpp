#ifndef _PRINCIPAL_H
#define _PRINCIPAL_H

#include "../Renderer/Renderer.h"
#include "../ResourceManager/ResourceManager.h"
#include "../../game/Character/Player/Player.h"
#include "../../game/Menu/Menu.h"
#include "../../game/Levels/Phase.h"
#include "../../game/Levels/PrimeiraFase.h"
#include "../../game/Levels/SegundaFase.h"
// #include "../../game/Levels/TerceiraFase.h"
#include "../../game/Levels/LeadBoard.h"

class Game{
private:
    Gerenciador::Renderer* janela;
    ResourceManager* gRecursos;
    
public:
    Game();
    ~Game();
    void executar();
};
#endif