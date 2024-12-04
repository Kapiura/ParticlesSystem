#pragma once
#include "Force.hpp"
#include "Particle.hpp"
#include "ofMain.h"
#include <vector>

#ifndef EMITTER_HPP
#define EMITTER_HPP

class Emitter {
private:
  Emitter();
  glm::vec3 emitPositon;
  std::vector<Particle> particles;
  std::vector<Particle> deadParticles;
  std::vector<Force *> forces;

public:
  Emitter(glm::vec3 pos) : emitPositon(pos) {};

  Particle emit(ofxIntSlider &timeLife);
  void update(float deltaTime, ofxIntSlider &timeLife, const glm::vec3& sphereCenter, float sphereRadius);
  void draw(ofxFloatSlider &rad, ofxColorSlider &color) const;
  void addForce(Force *force);
  bool deleteLastForce();
  bool checkCollision(const glm::vec3& particlePos, const glm::vec3& sphereCenter, float sphereRadius);
  void resolveCollision(Particle& particle, const glm::vec3& sphereCenter, float sphereRadius);

};

#endif