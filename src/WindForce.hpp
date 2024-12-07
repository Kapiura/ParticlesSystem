#pragma once

#include "Force.hpp"
#include <glm/glm.hpp>

class WindForce : public Force
{
  public:
	glm::vec3 direction;
	float strength;

	WindForce (glm::vec3 dir, float str) : direction (dir), strength (str)
	{
	}

	void apply (Particle &particle, float deltaTime) override
	{
		particle.addVelocity (direction * strength * deltaTime);
	}
};