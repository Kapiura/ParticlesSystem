#pragma once
#include "ofMain.h"

#ifndef PARTICLE_HPP
#define PARTICLE_HPP

class Particle {
public:
    Particle(glm::vec3 pos, glm::vec3 vel, ofColor col, float life, float rad);

    void update(float deltaTime);
    void draw() const;

    bool isDead() const { return lifeTime <= 0; }
    bool isAlphaZero() const {return color.a <= 0; }
    void changeAlphaColor(float a);

    float getAlpha() const { return color.a; };

private:
    glm::vec3 position;
    glm::vec3 velocity;
    glm::vec3 acceleration;
    float lifeTime;
    float radius;
    ofColor color;
};

#endif