#include "TextureManager.h"
#include <iostream>

bool TextureManager::loadTexture(const std::string& id, const std::string& filename){
    sf::Texture textura;
    if(textura.loadFromFile(filename)){
        texturas[id] = textura;
        return true;
    }
    std::cerr << "Erro ao carregar textura: " << filename << std::endl;
    exit(1);         // Fechar o programa se erro
    // return false; // Tratar erro na main
}

sf::Texture& TextureManager::getTexture(const std::string& id){
    return texturas.at(id);
}