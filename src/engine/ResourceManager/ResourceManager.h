#ifndef _TEXTUREMANAGER_H
#define _TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

class ResourceManager{
private:
    // Elementos do singleton
    static ResourceManager *singleton;
    ResourceManager(){};
    // Elementos da classe
    std::unordered_map<std::string, sf::Texture> texturas;
    std::unordered_map<std::string, sf::Font> fontes;
public:
    ~ResourceManager(){};
    // Retorna uma instância a ser usada no singleton
    static ResourceManager* getInstance();
    // Prevenção de cópia e atribuição
    ResourceManager(const ResourceManager&) = delete;
    // Prevenção de cópia e atribuição
    ResourceManager& operator=(const ResourceManager&) = delete;
    // Carrega texturas (identificador, caminho relativo)
    bool loadTexture(const std::string& id, const std::string& filename);
    // Carrega fonte (identificador, caminho relativo)
    bool loadFont(const std::string& id, const std::string& filename);
    // Retorna uma textura já carregada (identificador)
    sf::Texture& getTexture(const std::string& id);
    // Retorna uma fonte já carregada (identificador)
    sf::Font& getFont(const std::string& id);

};
#endif