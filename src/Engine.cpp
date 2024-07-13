
#include"Engine.h"
#include"Graphics.h"

bool Engine::Init()
{
    //initialize SDL
        if(SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0)
        {
            SDL_Log("Failed to Initialize SDL: %s",SDL_GetError() );
            return GameIsRunning = false;
        }
    //Create Window
        Window = SDL_CreateWindow("GhostFight",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,0);
        if(Window == nullptr)
        {
            SDL_Log("Failed to Initialize Window: %s",SDL_GetError() );
            return GameIsRunning = false;
        }
    //Create Renderer , first flag for hardware acceleration and the second for sync with the screen fps
        Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if(Renderer == nullptr)
        {
            SDL_Log( "Falied to initialize Renderer: %s", SDL_GetError() );
            return GameIsRunning = false;
        }

    //Create and Load Graphics
        Graphics::GameGraphics()->Create("ninja","image/StayInPlace.png");

    
    return GameIsRunning = true;  
    
}

bool Engine::Clean()
{  
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    IMG_Quit();
    SDL_Quit();

    SDL_Log("Everything is Cleared!!");
    return 0;

}

void Engine::Quit()
{
    GameIsRunning = false;
}

void Engine::Update()
{

}

void Engine::Render()
{
    //BackGround color
        SDL_SetRenderDrawColor(Renderer, 255 , 255 , 144 , 255 );
        SDL_RenderClear(Renderer);
    
    //ninja animation
        if( SDL_GetTicks() % Graphics::GameGraphics()->AnimationSpeed == 0)
        {
            if(++Graphics::GameGraphics()->frame == 6) Graphics::GameGraphics()->frame = 0 ; 
        }
        Graphics::GameGraphics()->DrawFrame("ninja",100,100,100,100,Graphics::GameGraphics()->row , Graphics::GameGraphics()->frame);

    //show on screen
        SDL_RenderPresent(Renderer);

}
            
void Engine::Events()
{
    
    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type)
    {
        case SDL_QUIT:
            GameIsRunning = false;
            break;

        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    GameIsRunning = false;
                    break;
            }
    }
                
}
