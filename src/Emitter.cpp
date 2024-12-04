#include "Emitter.hpp"
#include "Particle.hpp"

Emitter::Emitter() {
  particles = std::vector<Particle>(
      1000,
      Particle(glm::vec3(emitPositon), // vec pos
               glm::vec3(ofRandom(-1, 1), ofRandom(-1, 1), ofRandom(-1, 1)) *
                   ofRandom(50, 100),               // vec velocity
               ofColor(255, 255, ofRandom(0, 255)), // color
               ofRandom(2, 3)));
}

Particle Emitter::emit(ofxIntSlider &timeLife) {
  return Particle(glm::vec3(emitPositon), // vec pos
                  glm::vec3(ofRandom(-1, 1), ofRandom(-1, 1), ofRandom(-1, 1)) *
                      ofRandom(50, 100),               // vec velocity
                  ofColor(255, 255, ofRandom(0, 255)), // color
                  ofRandom(1, timeLife));              // life
}

void Emitter::update(float deltaTime, ofxIntSlider &timeLife,
                     const glm::vec3 &sphereCenter, float sphereRadius) {
  particles.erase(std::remove_if(particles.begin(), particles.end(),
                                 [](Particle &p) { return p.isDead(); }),
                  particles.end());

  size_t particlesToAdd = 1000 - particles.size();

  for (size_t i = 0; i < particlesToAdd; i++) {
    particles.push_back(emit(timeLife));
  }

  for (auto &el : particles) {
    for (auto &force : forces) {
      force->apply(el, deltaTime);
    }
    el.update(deltaTime);
    if (el.isDead())
      deadParticles.push_back(std::move(el));
    if (checkCollision(el.getPosition(), sphereCenter, sphereRadius)) {
      resolveCollision(el, sphereCenter, sphereRadius);
    }
  }

  deadParticles.erase(
      std::remove_if(deadParticles.begin(), deadParticles.end(),
                     [](Particle &p) { return p.isAlphaZero(); }),
      deadParticles.end());
}

void Emitter::draw(ofxFloatSlider &rad, ofxColorSlider &color) const {
  for (auto &el : particles)
    el.draw(rad, color);
}

void Emitter::addForce(Force *force) { forces.push_back(force); }

bool Emitter::deleteLastForce() {
  if (forces.size() > 0) {
    forces.pop_back();
    return true;
  }
  return false;
}

bool Emitter::checkCollision(const glm::vec3 &particlePos,
                             const glm::vec3 &sphereCenter,
                             float sphereRadius) {
  float distance = glm::length(particlePos - sphereCenter);
  return distance < sphereRadius;
}

void Emitter::resolveCollision(Particle &particle,
                               const glm::vec3 &sphereCenter,
                               float sphereRadius) {
  glm::vec3 direction = glm::normalize(particle.getPosition() - sphereCenter);
  particle.setPosition(sphereCenter + direction * sphereRadius);
  glm::vec3 velocity = particle.getVelocity();
  glm::vec3 normal = glm::normalize(particle.getPosition() - sphereCenter);
  glm::vec3 reflectedVelocity =
      velocity - 2.0f * glm::dot(velocity, normal) * normal;
  particle.setVelocity(reflectedVelocity * 0.8f);
}