#pragma once
#include "Particle.h"

class BasicParticle : public Particle {
public:
    // Gets how much life the particle has left.  
    // When a particle's life is reduced to zero, it will be removed from the particle system.
    virtual float getLife() const override;

    void setLife(float life);

    // Updates the particle for a specified time increment (dt).
    virtual void update(float dt) override;



    float vel = 1000.0;

    //lifetime of 1 second ( i hope )

    //makes a random position for the particle
    vec3 pos = vec3((rand() % 10001) / 1.0, (rand() % 10001) / 1.0, 0);

private:
    float lifeTime = 1;

};
