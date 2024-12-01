#pragma once
#include "Particle.hpp"
#include "ofMain.h"
#include <vector>

#ifndef EMITTER_HPP
#define EMITTER_HPP

class Emitter {
private:
    glm::vec3 emitPositon;
    glm::vec3 emitDirection;
    std::vector<Particle> particles;
    std::vector<Particle> deadParticles;
    //std::vector<Force> forces;

public:
    Emitter(glm::vec3 pos):emitPositon(pos){};

    Particle emit();
    void update(float deltaTime);
    void draw() const;
};

#endif