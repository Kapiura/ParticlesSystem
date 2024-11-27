#include "Emitter.hpp"
#include "ofMain.h"
#include <algorithm>

void Emitter::update()
{
  float currentTime = ofGetElapsedTimef();

  if (currentTime - lastTime >= (1.0f / rate))
  {
    lastTime = currentTime;
    glm::vec3 velocity = glm::vec3(ofRandom(-1, 1), ofRandom(-1, 1), 0);
    ofColor color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    particles.push_back(Particle(position, velocity, color, 5, 5.0f));
  }

  for (auto &p : particles)
    p.update();

  particles.erase(
    std::remove_if(
        particles.begin(),
        particles.end(),
        [](const Particle &p) { return !p.alive(); }),
        particles.end());
}

void Emitter::draw()
{
  for (auto &p : particles)
    p.draw();
}