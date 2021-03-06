#ifndef _GameState_h_
#define _GameState_h_

#include <Core/CoreState.h>
#include <Utils/FpsCounter.h>

class ParticleEmitter;

class GameState : public CoreState
{
    private:
    TexturePtr background;
    Text text;
    ParticleEmitter* emitter;
    bool held;

    FpsCounter fps;

    public:
    GameState();
    ~GameState();

    void init(ResourceManager& resources);
    void deinit();

    void handleInput(Input& input, int value, int action);
    void logic(float timeStep);
    void draw();
};

#endif

