#include "pendulum.h"
#include "particle.h"
int main(){
    InitWindow(1920, 1200, "Pendulum Simulation");
    SetTargetFPS(60);
    Particle p1 = {
        .position = (Vector2){
            GetRandomValue(0, GetScreenWidth()/4),
            GetRandomValue(0, GetScreenHeight()*0.8f),
        },
        .velocity = (Vector2){
            600.0f, -300.0f
        }
    };
    Pendulum pendulum = {
        .anchor = {
            .x = (float)GetScreenWidth() / 2.0f,
            .y = (float)GetScreenHeight() / 2.0f
        }
    };
    bool isParticleSelected = false;
    while (!WindowShouldClose()){
        float dt = GetFrameTime();
        if(IsKeyPressed(KEY_E)){
            if(!isParticleSelected){
                pendulum.position = GetPendulumPosition(pendulum, p1);
            }
            if(isParticleSelected){
                p1 = GetParticleFromPendulum(pendulum);
                pendulum.position = (Pendulum_position){};
            }
            isParticleSelected = !isParticleSelected;
        }
        BeginDrawing();
            ClearBackground(BACKGROUND);
            if(isParticleSelected){
                UpdatePendulum(&pendulum, dt);
                DrawPendulum(pendulum);
                p1.position = GetBallPosition(&pendulum);
                if (IsKeyDown(KEY_Q)) {
                    float ratio = (pendulum.position.length/(pendulum.position.length - 1.5f * dt));
                    pendulum.position.angular_v = pendulum.position.angular_v * ratio * ratio;
                    pendulum.position.length -= 1.5f * dt; 
                    if (pendulum.position.length < 0.2f) {
                        pendulum.position.length = 0.2f;
                    }
                }
                if(IsKeyDown(KEY_A)){
                    float ratio = (pendulum.position.length/(pendulum.position.length + 1.5f * dt));
                    pendulum.position.angular_v = pendulum.position.angular_v * ratio * ratio;
                    pendulum.position.length += 1.5f*dt;
                }
            }
            else {
                UpdateParticle(&p1, dt);
                DrawParticle(&p1);
            } 
        EndDrawing();
    }
    CloseWindow();
}