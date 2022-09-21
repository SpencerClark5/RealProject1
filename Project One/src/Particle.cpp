#include "Particle.h"

float Particle::getLife() const
{
	return this->lifeTime;
}

void Particle::update(float dt)
{	
	//updates the time left that the particle is on screen
	this->lifeTime -= dt;

	//slowly rise up the position as its lifetime goes down

}
