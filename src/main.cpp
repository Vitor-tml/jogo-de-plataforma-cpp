#include <SFML/Graphics.hpp>
#include "engine/Renderer/Renderer.h"

int main()
{
    Renderer janela(400, 600, "batata");

    janela.run();
    return 0;
}