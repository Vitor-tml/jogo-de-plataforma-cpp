# Jogo de Plataforma em CPP
Este é um projeto de um jogo de plataforma 2D desenvolvido em C++ com foco em criar uma game engine personalizada que suporte mecânicas complexas de jogos de plataforma.

## Introdução

O objetivo deste projeto é criar um jogo de plataforma com elementos clássicos como saltos, coleta de itens, inimigos, e fases desafiadoras. A engine é desenvolvida do zero, focando em modularidade e eficiência.

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
    - [ ] Renderização de Sprites
    - [ ] Animações
    - [ ] Camadas

2. Gerenciamento de Recursos
    - [ ] Carregamento de:
        - [ ]  Texturas
        - [ ]  Áudio
        - [ ]  Fontes
        
3. Sistema de Entrada
    - [ ] Mouse e teclado
4. Sistema de Física
    - [ ] Colisões
    - [ ] Resposta a colisões
    - [ ] Gravidade
    - [ ] Movimentação
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
    - [ ] Mesus
12. Sistema de Salvamento e Carregamento
    - [ ] Salvar pontuação 
    - [ ] Salvar jogada
13. Ferramentas de Desenvolvimento
    - [ ] Editor de níveis
    - [ ] Ferramentar de depuração
