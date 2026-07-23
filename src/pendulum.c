#include "pendulum.h"
#include <math.h>
void UpdatePendulum(Pendulum* pendulum, float dt){
    float angular_a = (-1.0f * GRAVITY / pendulum->position.length) * sinf(pendulum->position.angle);

    pendulum->position.angular_v += angular_a * dt;
    pendulum->position.angle += pendulum->position.angular_v * dt;
    pendulum->position.angular_v *= DAMPING;
}
Vector2 GetBallPosition(Pendulum* pendulum){
    Vector2 AnchorPosition = {
        .x = pendulum->anchor.x + pendulum->position.length*PIXELS_PER_METER*sinf(pendulum->position.angle),
        .y = pendulum->anchor.y + pendulum->position.length*PIXELS_PER_METER*cosf(pendulum->position.angle)
    };
    return AnchorPosition;
}
void DrawPendulum(Pendulum pendulum){
    DrawCircleV(pendulum.anchor, 2.0f, RED);
    DrawLineV(pendulum.anchor, GetBallPosition(&pendulum), FOREGROUND);
    DrawCircleV(GetBallPosition(&pendulum), 10.0f, FOREGROUND);
}

Pendulum_position GetPendulumPosition(Pendulum pendulum, Particle particle){
    float dx = particle.position.x - pendulum.anchor.x;
    float dy = particle.position.y - pendulum.anchor.y;
    float lengthInPixels = hypotf(dx, dy);
    if (lengthInPixels < 0.0001f) {
        return (Pendulum_position){ .angle = 0.0f, .angular_v = 0.0f, .length = 0.1f };
    }
    float lengthInMeters = lengthInPixels / PIXELS_PER_METER;
    float angle = atan2f(dx, dy);
    float angular_v = (dy * particle.velocity.x - dx * particle.velocity.y) / (lengthInPixels * lengthInPixels);
    return (Pendulum_position){
        .angle = angle,
        .angular_v = angular_v,
        .length = lengthInMeters
    };
}
Particle GetParticleFromPendulum(Pendulum pendulum){
    Vector2 pos = GetBallPosition(&pendulum);
    float lengthInPixels = pendulum.position.length * PIXELS_PER_METER;
    float vx =  lengthInPixels * pendulum.position.angular_v * cosf(pendulum.position.angle);
    float vy = -lengthInPixels * pendulum.position.angular_v * sinf(pendulum.position.angle);
    return (Particle){
        .position = pos,
        .velocity = (Vector2){ vx, vy }
    };
}