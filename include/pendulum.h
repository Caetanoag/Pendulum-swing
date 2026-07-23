#pragma once
#include <raylib.h>
#include "particle.h"
#define FOREGROUND WHITE
#define BACKGROUND BLACK

#define GRAVITY 9.8f
#define DAMPING 0.998f
#define PIXELS_PER_METER 150.0f

typedef struct Pendulum_position{
    float angle;
    float angular_v;
    float length;
} Pendulum_position;
typedef struct Pendulum {
    Vector2           anchor;
    Pendulum_position position;
} Pendulum;
void UpdatePendulum(Pendulum* pendulum, float dt);
Vector2 GetBallPosition(Pendulum* pendulum);
void DrawPendulum(Pendulum pendulum);
Pendulum_position GetPendulumPosition(Pendulum pendulum, Particle particle);
Particle GetParticleFromPendulum(Pendulum pendulum);