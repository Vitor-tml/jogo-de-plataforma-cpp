#ifndef _ANIMATION_H
#define _ANIMATION_H

#include <SFML/Graphics.hpp>
#include <vector>

class Animation{
private:
    sf::Sprite sprite;
    std::vector<sf::IntRect> frames;
    float currentTime;
    float frameDuration;
    int currentFrameIndex;
    bool looping;
    bool finalizada;
public:
    Animation(sf::Texture& texture, int frameLargura, int frameAltura, int nFrames, float duracao);
    ~Animation(){};
    void update(float deltaTempo);
    sf::Sprite& getCurrentFrame();
    void setLooping(bool loop);
    bool isFinished()const;
};

#endif