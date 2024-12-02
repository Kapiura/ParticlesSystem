#include "Emitter.hpp"
#include "Particle.hpp"
#include <utility>


Particle Emitter::emit()
{
  return Particle(
    glm::vec3(emitPositon),                                              // vec pos
    glm::vec3(ofRandom(-1,1), ofRandom(-1,1), ofRandom(-1,1)) * ofRandom(50, 100),   // vec velocity
    ofColor(255, 255, ofRandom(0,255)),                                 // color
    ofRandom(1, 5),                                                     // life time
    ofRandom(2,3));
}

void Emitter::update(float deltaTime)
{
  if(particles.size() < 1000)
    particles.push_back(emit());

  for(auto& el: particles)
  {
    el.update(deltaTime);
    if(el.isDead())
    {
      deadParticles.push_back(el);
    }
  }

  particles.erase(std::remove_if(
    particles.begin(),
    particles.end(),
    [](Particle& p) { return p.isDead(); }), particles.end());

  for(auto& el: particles)
    el.changeAlphaColor(el.getAlpha() - 0.2f);

  deadParticles.erase(std::remove_if(
    deadParticles.begin(),
    deadParticles.end(),
    [](Particle& p) { return p.isAlphaZero(); }), deadParticles.end());

}
void Emitter::draw() const
{
  for(auto& el: particles)
    el.draw();
}