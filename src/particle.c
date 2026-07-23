#include "particle.h"
#include "pendulum.h"
void UpdateParticle(Particle* particle, float dt){

    particle->velocity.y += (GRAVITY * PIXELS_PER_METER) * dt;
    particle->position.x += particle->velocity.x * dt;
    particle->position.y += particle->velocity.y * dt;
}
void DrawParticle(Particle* particle){
    DrawCircleV(particle->position, 10.0f, FOREGROUND);
}