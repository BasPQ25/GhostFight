
#include"Engine.h"


int main()
{
    Engine::Game()->Init();


    while( Engine::Game()->IsRunning() )
    {
        Engine::Game()->Events();
        Engine::Game()->Update();
        Engine::Game()->Render();
    }

    Engine::Game()->Clean();

}