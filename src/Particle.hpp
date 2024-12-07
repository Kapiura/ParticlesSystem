#pragma once
#include "ofMain.h"
#include "ofxGui.h"

#ifndef PARTICLE_HPP
#define PARTICLE_HPP

class Particle
{
  public:
	Particle (glm::vec3 pos, glm::vec3 vel, ofColor col, float life);

	void update (float deltaTime);
	void draw (ofxFloatSlider &rad, ofxColorSlider &color) const;
	void draw (float rad, ofColor color) const;

	bool isDead () const
	{
		return lifeTime <= 0;
	}
	bool isAlphaZero () const
	{
		return color.a <= 0;
	}
	void changeAlphaColor (float a);

	float getAlpha () const
	{
		return color.a;
	};

	void addVelocity (const glm::vec3 &vel)
	{
		velocity += vel;
	};
	void setVelocity (const glm::vec3 &vel)
	{
		velocity = vel;
	};
	glm::vec3 getPosition () const
	{
		return position;
	};
	glm::vec3 getVelocity () const
	{
		return velocity;
	};
	void setPosition (const glm::vec3 &vel)
	{
		position = vel;
	};

  private:
	glm::vec3 position;
	glm::vec3 velocity;
	glm::vec3 acceleration;
	float lifeTime;
	ofColor color;
};

#endif