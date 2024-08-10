#ifndef _TEXTUREMANAGER_H
#define _TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

class ResourceManager{
private:
    std::unordered_map<std::string, sf::Texture> texturas;
    std::unordered_map<std::string, sf::Font> fontes;
public:
    ResourceManager(){};
    ~ResourceManager(){};
    bool loadTexture(const std::string& id, const std::string& filename);
    bool loadFont(const std::string& id, const std::string& filename);
    sf::Texture& getTexture(const std::string& id);
    sf::Font& getFont(const std::string& id);

};
#endif