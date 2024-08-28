#ifndef _SAVEMANAGER_H
#define _SAVEMANAGER_H

#include "../../lists/ListaEntidades/ListaEntidades.h"
#include "json.hpp"
#include <string>

class SaveManager {
public:
    SaveManager() = default;
    ~SaveManager() = default;

    void saveEntidades(const ListaEntidades& lista, const std::string& filename);
    ListaEntidades loadEntidades(const std::string& filename);
};

#endif
