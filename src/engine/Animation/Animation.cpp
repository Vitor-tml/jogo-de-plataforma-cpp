#include "Animation.h"
#include <iostream>

Animation::Animation(sf::Texture& textura , int frameLargura, int frameAltura, int nFrames, float duracao)
: sprite(textura), currentTime(0), frameDuration(duracao / nFrames), currentFrameIndex(0), looping(true), finalizada(false)
{
    // Calcula os sub-retângulos da textura (diferentes estados da animação)
    for(int i = 0; i < nFrames; i++) // colocar variável para inicio do frame na textura
        frames.emplace_back(i * frameLargura, 0, frameLargura, frameAltura);

    sprite.setTextureRect(frames[0]);
    sprite.setScale(3.f, 2.f);
}

void Animation::update(float deltaTempo)
{
    if(finalizada) return; // Animação finalizada não tem atualização

    if(currentTime >= frameDuration){
        currentFrameIndex = 0;
        ++currentFrameIndex;

        if(currentFrameIndex >= frames.size()){
            if(looping)
                currentFrameIndex = 0;
            else {
                currentFrameIndex = frames.size() - 1;
                finalizada = true;
            }
        }
        sprite.setTextureRect(frames[currentFrameIndex]);
    }
}

sf::Sprite& Animation::getCurrentFrame()
{
    return sprite;
}

void Animation::setLooping(bool loop)
{
    looping = loop;
}

bool Animation::isFinished() const
{
    return finalizada;
}