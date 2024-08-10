#include "ResourceManager.h"
#include <iostream>

ResourceManager* ResourceManager::singleton = nullptr;
ResourceManager* ResourceManager::getInstance()
{
    if(singleton == nullptr)
        singleton = new ResourceManager;

    return singleton;
}

bool ResourceManager::loadTexture(const std::string& id, const std::string& filename){
    sf::Texture textura;
    if(textura.loadFromFile(filename)){
        texturas[id] = textura;
        return true;
    }
    std::cerr << "Erro ao carregar textura: " << filename << std::endl;
    exit(1);         // Fechar o programa se erro
    // return false; // Tratar erro na main
}

sf::Texture& ResourceManager::getTexture(const std::string& id)
{
    return texturas.at(id);
}

bool ResourceManager::loadFont(const std::string& id, const std::string& filename)
{
    sf::Font fonte;
    if(fonte.loadFromFile(filename)){
        fontes[id] = fonte;
        return true;
    }
    std::cerr << "Erro ao carregar textura: " << filename << std::endl;
    exit(1);         // Fechar o programa se erro
    // return false; // Tratar erro na main
}

sf::Font& ResourceManager::getFont(const std::string& id)
{
    return fontes.at(id);
}
