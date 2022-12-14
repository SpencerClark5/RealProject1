#pragma once
#include "ofMain.h"
#include <stdlib.h>     /* srand, rand */
using namespace glm;
// An interface for a particle.
class Particle
{
public:
    // Virtual destructor to ensure polymorphic cleanup.
    virtual ~Particle() {};

    // Gets how much life the particle has left.  
    // When a particle's life is reduced to zero, it will be removed from the particle system.
    virtual float getLife() const = 0;

    // Updates the particle for a specified time increment (dt).
    virtual void update(float dt) = 0;

    float vel = 10.0;   

    //lifetime of 1 second ( i hope )
    float lifeTime = 1;
    //makes a random position for the particle
    vec3 pos = vec3( (rand() % 1001)/1000.0 , (rand() % 1001) / 1000.0 , 0);
    //cannot create a vector here
};

// An interface for a particle generator that spawns particles of some specific type.
template <typename ParticleType>
class ParticleGenerator
{
public:
    // Virtual destructor to ensure polymorphic cleanup.
    virtual ~ParticleGenerator() {};

    // Called when a new particle needs to be generated. When the function returns, the particle 
    // referenced by the parameter should be reinitialied as a new, random particle.
    virtual void respawn(ParticleType& particle) const = 0;
};
