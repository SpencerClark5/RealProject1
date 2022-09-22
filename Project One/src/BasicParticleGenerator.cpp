#include "BasicParticleGenerator.h"

void BasicParticleGenerator::respawn(BasicParticle& particle) const
{	
	particle.setLife(1.0f);
	particle.pos = vec3((rand() % 10001) / 1.0, (rand() % 10001) / 1.0, 0);

	//randomize things
}
