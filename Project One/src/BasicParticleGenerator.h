#pragma once
#include "Particle.h"
#include "BasicParticle.h"

class BasicParticleGenerator : public ParticleGenerator<BasicParticle>
{

	virtual void respawn(BasicParticle& particle) const override;




};
