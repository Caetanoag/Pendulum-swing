#include "particle.h"
#include "pendulum.h"
void UpdateParticle(Particle* particle, float dt){

    particle->velocity.y += (GRAVITY * PIXELS_PER_METER) * dt;
    particle->position.x += particle->velocity.x * dt;
    particle->position.y += particle->velocity.y * dt;

    if(particle->position.x + 10.0f >= GetScreenWidth() || particle->position.x - 10.0f <= 0){
        particle->velocity.x *= -ENERGY_LOSS;
        particle->velocity.y *= ENERGY_LOSS;
    }
    if(particle->position.y + 10.0f >= GetScreenHeight() || particle->position.y - 10.0f <= 0){
        particle->velocity.x *= ENERGY_LOSS;
        particle->velocity.y *= -ENERGY_LOSS;
    }
    if(particle->position.y + 10.0f >= GetScreenHeight()){
        particle->position.y = GetScreenHeight() - 10.0f;
    }
    if(particle->position.y - 10.0f <= 0.0f){
        particle->position.y = 10.0f;
    }
    if(particle->position.x - 10.0f <= 0.0f){
        particle->position.x = 10.0f;
    }
    if(particle->position.x + 10.0f >= GetScreenWidth()){
        particle->position.x = GetScreenWidth() - 10.0f;
    }
}
void DrawParticle(Particle* particle){
    DrawCircleV(particle->position, 10.0f, FOREGROUND);
}