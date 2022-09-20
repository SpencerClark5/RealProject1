#include "Particle.h"

float Particle::getLife() const
{
	return Particle::lifeTime;
}

void Particle::update(float dt)
{
	Particle::lifeTime -= dt;
}
