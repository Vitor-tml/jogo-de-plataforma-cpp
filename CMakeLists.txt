# Versão mínima requerida do CMake
cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(PrimeiroJogoSFML)

# Definir a versão do C++ utilizada
set(CMAKE_CXX_STANDARD 17)

# Incluir diretórios de inclusão
include_directories(include)
include_directories(${CMAKE_SOURCE_DIR}/lib/SFML-2.6.1/include)

# Definir o diretório onde o SFML está instalado
set(SFML_DIR "C:/Users/vitor/Programas/teste-sfml/SFML-2.6.1")

# Encontrar e carregar o pacote SFML
find_package(SFML 2.6.1 COMPONENTS system window graphics network audio REQUIRED)

# Adicionar arquivos de origem e cabeçalhos
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

# Nome e origem do executável
add_executable(game ${SOURCES} ${HEADERS})

# Vincula as bibliotecas SFML estaticamente
target_link_libraries(game 
    sfml-system
    sfml-window
    sfml-graphics
    sfml-network
    sfml-audio
)

# Copiar as DLLs para o diretório de saída
if (WIN32)
    add_custom_command(TARGET game POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${SFML_DIR}/bin/sfml-system-2.dll"
            "${SFML_DIR}/bin/sfml-window-2.dll"
            "${SFML_DIR}/bin/sfml-graphics-2.dll"
            "${SFML_DIR}/bin/sfml-network-2.dll"
            "${SFML_DIR}/bin/sfml-audio-2.dll"
            $<TARGET_FILE_DIR:game>)
endif()