#include "Particle.h"

float Particle::getLife() const
{
	return this->lifeTime;
}

void Particle::update(float dt)
{
	this->lifeTime -= dt;
}
