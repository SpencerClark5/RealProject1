#include "Particle.h"


class Particle {
private:
	//lifetime of 1 second ( i hope )
	float lifeTime = 1;

	//getter for lifeTime
	//unsure what a const getter does, but maybe we should just leave it
	float getLife() const
	{
		return lifeTime;
	}
	//updates information over time
	void update(float dt) {

		//updates how much life is left on the partile
		lifeTime -= dt;

		//depending on the lifetime of the particle, fade it in and out so that it looks natural
		//maybe even change the color



	}









};





