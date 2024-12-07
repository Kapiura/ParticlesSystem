#pragma once

#include "Particle.hpp"
#include <glm/glm.hpp>

class Force
{
  public:
	virtual void apply (Particle &particle, float deltaTime) = 0;
};