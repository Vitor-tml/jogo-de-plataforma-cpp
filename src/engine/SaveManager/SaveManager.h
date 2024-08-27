#ifndef _SAVEMANAGER_H
#define _SAVEMANAGER

#include "../../game/Entity/Entity.h"
#include "../../lists/ListaEntidades/ListaEntidades.h"

class SaveManager {
private:

public:
    SaveManager();
    ~SaveManager();

    void saveEntidades(const Lista<Entity>& lista);
    Lista<Entity> loadEntidades();
};

#endif
