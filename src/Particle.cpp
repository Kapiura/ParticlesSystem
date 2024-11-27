#include "Particle.hpp"

void Particle::update()
{
    velocity += acceleration;
    position += velocity;
    lifeTime -= ofGetLastFrameTime();
    if (lifeTime <= 0)
        isAlive = false;
}

void Particle::draw()
{
    if (isAlive)
    {
        ofSetColor(color);
        ofDrawCircle(position, size);
    }
}