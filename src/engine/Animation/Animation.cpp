#include "Animation.h"
#include <iostream>

Animation::Animation(sf::Texture& texture, std::vector<sf::IntRect> frames, float duration)
    : textura(texture), frames(frames)
{
    duracao = duration;
    tempoDecorrido = 0;
    indexFrameAtual = 0;
    finalizada = false;
}

void Animation::update(float deltaTime)
{
    if(finalizada) return;

    tempoDecorrido += deltaTime;
    if(tempoDecorrido >= duracao){ // Duração do frame!
        tempoDecorrido = 0;
        indexFrameAtual = (indexFrameAtual + 1) % frames.size();
    }

    if(indexFrameAtual == frames.size() - 1 && tempoDecorrido == 0)
    {
        // Mudar para true
        finalizada = false;
    }
}

sf::IntRect Animation::getFrameAtual()const
{
    return frames[indexFrameAtual];
}

bool Animation::isFinished()const
{
    return finalizada;
}