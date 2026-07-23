#pragma once

#include <raylib.h>
typedef struct {
    Vector2 position;
    Vector2 velocity;
} Particle;

void UpdateParticle(Particle* particle, float dt);
void DrawParticle(Particle* particle);
