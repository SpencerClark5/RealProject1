#pragma once
#include "Particle.h"

class BasicParticle : public Particle {
public:
    // Gets how much life the particle has left.  
    // When a particle's life is reduced to zero, it will be removed from the particle system.
    virtual float getLife() const override;

    void setLife(float life);

    virtual int getTexture() const;

    // Updates the particle for a specified time increment (dt).
    virtual void update(float dt) override;

    float x = -5 + (rand() % (10 + 1));
    float y = -5 + (rand() % (10 + 1));
    //spawns mostly transparent
    float opacity;
    //makes a random position for the particle
    vec3 pos = vec3(x / 13, y / 13, 0);
    int texture = rand() % 2;

private:
    float lifeTime = 1.0f;

};
