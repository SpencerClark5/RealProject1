#include "BasicParticleGenerator.h"

void BasicParticleGenerator::respawn(BasicParticle& particle) const
{	
	particle.setLife(1.0f);
	float x = -5 + (rand() % (10 + 1));
	float y = -5 + (rand() % (10 + 1));

	particle.pos = vec3(x/13,y/13,-2 + rand() % 3);
	particle.opacity = 1.0f;

	//randomize things
}
