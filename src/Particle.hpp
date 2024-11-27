#pragma once

#include "ofMain.h"

class Particle {
private:
    glm::vec3 position;
    glm::vec3 velocity;
    glm::vec3 acceleration;
    ofColor color;
    float lifeTime;
    float size;
    bool isAlive;

public:
    Particle(glm::vec3 initPos, glm::vec3 initVel, ofColor initColor, float initSize, float initLifeTime)
    : position(initPos), velocity(initVel), color(initColor), size(initSize), lifeTime(initLifeTime), isAlive(true) {}

    bool alive() const {return isAlive;};

    void update();
    void draw();
};
