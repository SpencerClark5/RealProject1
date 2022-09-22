#include "BasicParticle.h"

float BasicParticle::getLife() const
{
	return lifeTime;
}

void BasicParticle::setLife(float life)
{
	this->lifeTime = life;
}

//dt is OfGetLastFrame
void BasicParticle::update(float dt)
{
	//updates the time left that the particle is on screen
	//life decreases by .5 every second

	this->lifeTime -= dt * 0.5;
	this->pos = vec3(pos.x, pos.y + dt*vel, pos.z);
	//slowly rise up the position as its lifetime goes down

}
