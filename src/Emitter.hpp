#pragma once
#include "Force.hpp"
#include "Particle.hpp"
#include "ofMain.h"
#include <vector>

#ifndef EMITTER_HPP
#define EMITTER_HPP

class Emitter
{
  private:
	Emitter ();
	glm::vec3 emitPositon;
	std::vector<Particle> particles;
	std::vector<Particle> deadParticles;
	std::vector<Particle> boomParticles;
	std::vector<Force *> forces;

  public:
	Emitter (glm::vec3 pos) : emitPositon (pos) {};

	Particle emit (ofxIntSlider &timeLife);
	Particle emit (float &timeLife);
	Particle emit ();
	void update (float deltaTime, ofxIntSlider &timeLife, const glm::vec3 &sphereCenter, float sphereRadius);
	void update (float deltaTime, float timeLife);
	void updateBoom (float deltaTime);
	void draw (ofxFloatSlider &rad, ofxColorSlider &color) const;
	void draw (float rad, ofColor color) const;
	void drawBoom (float rad, ofColor color) const;
	void addForce (Force *force);
	bool deleteLastForce ();
	bool checkCollision (const glm::vec3 &particlePos, const glm::vec3 &sphereCenter, float sphereRadius);
	void resolveCollision (Particle &particle, const glm::vec3 &sphereCenter, float sphereRadius);
};

#endif