#ifndef _TEXTUREMANAGER_H
#define _TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

class TextureManager{
private:
    std::unordered_map<std::string, sf::Texture> texturas;
public:
    TextureManager(){};
    ~TextureManager(){};
    bool loadTexture(const std::string& id, const std::string& filename);
    sf::Texture& getTexture(const std::string& id);
};
#endif