# Jogo de Plataforma em CPP
Este é um projeto de um jogo de plataforma 2D desenvolvido em C++ com foco em criar uma game engine personalizada que suporte mecânicas complexas de jogos de plataforma.

## Introdução

O objetivo deste projeto é criar um jogo de plataforma com elementos clássicos como saltos, coleta de itens, inimigos, e fases desafiadoras. A engine é desenvolvida do zero, focando em modularidade e eficiência.

## Compilação
### Pré-Requisitos
- **CMAKE**: Certifique-se que o CMAKE está instalado. [Instalar CMake](https://cmake.org/install/).
- **MAKE**: Certifique-se que o MAKE está instalar. [Instalar MAKE](https://gnuwin32.sourceforge.net/packages/make.htm)
- **SFML**: Versão GCC 13.10 MinGW 64bit. [Baixar Biblioteca](https://www.sfml-dev.org/files/SFML-2.6.1-windows-gcc-13.1.0-mingw-64-bit.zip)

### Passo-a-passo
1.  Clone o repositório.
    ```bash
    git clone https://github.com/Vitor-tml/jogo-de-plataforma-cpp
    cd jogo-de-platforma-cpp
    ```
2. Crie os caminhos necessários.
    
    Pasta da biblioteca
    ```bash
    mkdir libs
    ```
    (mover a pasta do SFML para ```libs```)
    
    Pasta para compilação
    ```bash
    mkdir build
    ```
3. Gere os arquivos de compilação na pastal ```build``` (necessário a cada novo arquivo do projeto).
    ```bash
    cd build
    cmake ..
    ```
4. _Cruze os dedos_ e compile o projeto.
    ```bash
    make -j16
    ```
    ```-j16``` esse parâmetro define quantas threads serão usadas na compilação.
5. Execute o programa.
    
    #### Caso esteja no windows:
    
    1. Copie as dlls da do caminho ```.\libs\SFML-2.6.1\bin\``` para a pasta ```build``` ou outro caminho do executável.    
    2. Execute o programa:
        ```bash
        ./game.exe
        ```
    #### Caso esteja no linux:
    1. Seja feliz.
    2. Execute o programa:
        ```bash
        ./game
        ```
## Estrutura do Projeto

```plaintext
JogoPlataforma/
├── src/
│   ├── main.cpp
│   ├── engine/
│   │   ├── Renderer/          # Sistema de Renderização
│   │   ├── ResourceManager/   # Gerenciamento de Recursos
│   │   ├── Input/             # Sistema de Entrada
│   │   ├── Physics/           # Sistema de Física
│   │   ├── Audio/             # Sistema de Áudio
│   │   ├── ECS/               # Entidades e Componentes
│   │   ├── AI/                # Inteligência Artificial
│   │   ├── Scene/             # Gerenciamento de Cena
│   │   ├── UI/                # Sistema de Interface do Usuário
│   │   ├── SaveLoad/          # Sistema de Salvamento e Carregamento
│   │   └── DevelopmentTools/  # Ferramentas de Desenvolvimento
│   ├── game/
│   │   ├── Player/            # Implementação do Jogador
│   │   ├── Enemies/           # Implementação dos Inimigos
│   │   ├── Obstacles/         # Implementação dos Obstáculos
│   │   └── Levels/            # Implementação dos Níveis
│   └── utils/                 # Utilitários e Funções Auxiliares
├── assets/                    # Recursos do Jogo
│   ├── textures/              # Texturas e Sprites
│   ├── audio/                 # Sons e Músicas
│   ├── fonts/                 # Fontes para Texto
│   └── levels/                # Dados dos Níveis
├── include/                   # Headers Externos (opcional)
├── libs/                      # Bibliotecas Externas
├── build/                     # Arquivos de Compilação
└── CMakeLists.txt             # Configuração do CMake

```
## To Do List do Projeto

1. Sistema de Renderização
    - [x] Renderização de Sprites
    - [x] Animações
    - [x] Camadas

2. Gerenciamento de Recursos
    - [ ] Carregamento de:
        - [x]  Texturas
        - [ ]  Áudio
        - [ ]  Fontes
        
3. Sistema de Entrada
    - [x] Teclado
    - [ ] Mouse
4. Sistema de Física
    - [ ] Colisões
    - [ ] Resposta a colisões
    - [x] Gravidade
    - [x] Movimentação
5. Sistema de Áudio
    - [ ] Efeitos
    - [ ] Música
    - [ ] Volume
6. Entidades e Componentes
    - [ ] Inimigos
    - [ ] Obstáculos
7. Sistema de Scripts (Próximas versões)
8. Sistema de Câmera (Próximas versões)
9. Gerenciamento de Cena
    - [ ] Transição de fases
10. Inteligência Artificial (IA)
    - [ ] Perseguir player
    - [ ] Atacar player
11. Sistema de UI (Interface do Usuário)
    - [ ] Botões
    - [ ] Menus
12. Sistema de Salvamento e Carregamento
    - [ ] Salvar pontuação 
    - [ ] Salvar jogada
13. Ferramentas de Desenvolvimento
    - [ ] Editor de níveis
    - [ ] Ferramentar de depuração
