#include "Particle.hpp"

Particle::Particle(glm::vec3 pos, glm::vec3 vel, ofColor col, float life)
    : position(pos), velocity(vel), color(col), lifeTime(life) {
  acceleration = glm::vec3(0);
}

void Particle::update(float deltaTime) {
  velocity += acceleration * deltaTime;
  position += velocity * deltaTime;
  acceleration = glm::vec3(0);
  lifeTime -= deltaTime;
}

void Particle::draw(ofxFloatSlider &rad, ofxColorSlider &color) const {
  ofSetColor(color);
  ofDrawSphere(position, rad);
}

void Particle::changeAlphaColor(float a) { color.a = a; }
