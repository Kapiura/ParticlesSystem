#pragma once

#include "ofMain.h"
#include "Particle.hpp"

class Emitter {
private:
    glm::vec3 position;
    float rate;
    float lastTime;
    std::vector<Particle> particles;

public:
    Emitter(glm::vec3 initPos, float emitRate)
    : position(initPos), rate(emitRate), lastTime(0) {}

    void update();
    void draw();
};
