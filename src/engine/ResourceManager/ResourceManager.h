#ifndef _TEXTUREMANAGER_H
#define _TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

/**
 * @class ResourceManager
 * @brief Gerencia o carregamento e acesso de recursos, como texturas e fontes.
 * 
 * O ResourceManager é um singleton responsável por carregar, armazenar e fornecer acesso a texturas e fontes
 * usadas no jogo. Ele garante que cada recurso seja carregado apenas uma vez e seja acessível por meio de 
 * um identificador único.
 * 
 * @author Vitor-tml
 */
class ResourceManager{
private:
    static ResourceManager *singleton; ///< Instância singleton do gerenciador de recursos
    ResourceManager(){}; ///< Construtora privada para evitar outras instâncias
    std::unordered_map<std::string, sf::Texture> texturas; ///< Conjunto de texturas (chave, textura)
    std::unordered_map<std::string, sf::Font> fontes;///< Conjunto de fontes (chave, fonte)
public:
    ~ResourceManager(){};
    /**
     * @brief Retorna o ponteiro para a instância singleton do gerenciador
     * @throw Na primeira chamar aloca o gerenciador.
     * @return Ponteiro para a instância.
     */
    static ResourceManager* getInstance();
    ResourceManager(const ResourceManager&) = delete; ///< Previne cópia.
    ResourceManager& operator=(const ResourceManager&) = delete; ///< Previne atribuição.
    /**
     * @brief Carrega textura e armazena com indentificador.
     * @param id identificador da textura a ser usado posteriormente.
     * @param filename Caminho relativo para o arquivo da textura.
     * @note O caminho é relativo ao executável do programa.
     * @return true se a textura foi carregada com sucesso, false caso não.
     */
    bool loadTexture(const std::string& id, const std::string& filename);
    /**
     * @brief Carrega fonte e armazena com indentificador.
     * @param id identificador da fonte a ser usado posteriormente.
     * @param filename Caminho relativo para o arquivo da fonte.
     * @note O caminho é relativo ao executável do programa.
     * @return true se a fonte foi carregada com sucesso, false caso não.
     */
    bool loadFont(const std::string& id, const std::string& filename);
    /**
     * @brief Retorna uma textura posteriormente carregada, a partir de um identificador.
     * @param id Identificador da textura já armazenada.
     * @return Referência a textura relativa ao ID.
     */
    sf::Texture& getTexture(const std::string& id);
    /**
     * @brief Retorna uma fonte posteriormente carregada, a partir de um identificador.
     * @param id Identificador da fonte já armazenada.
     * @return Referência a fonte relativa ao ID.
     */
    sf::Font& getFont(const std::string& id);
};
#endif