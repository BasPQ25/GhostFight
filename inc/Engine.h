#ifndef GAME_H
#define GAME_H


#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>

#define SCREEN_WIDTH 1915
#define SCREEN_HEIGHT 1070


class Engine
{
    private:
        //Game running variables
            inline static Engine* Game_Instance = nullptr;
            inline static bool  GameIsRunning = false; 

        //SDL variables
            SDL_Window* Window;
            SDL_Renderer* Renderer;



    public:
        //Constructor
            Engine(){}

        //Initialization functions
            bool Init();
            bool Clean();
            void Quit();

        //Game Running Functions
            void Update();
            void Render();
            void Events();

        //Game Initialization only once
            static Engine* Game()
            {
                return Game_Instance = (Game_Instance != nullptr) ? Game_Instance : new Engine();   
            }
        
        //Renderer intialization only once
            inline  SDL_Renderer* GetRenderer()
            {
                return Renderer;
            }
        //Game running Function
            inline bool IsRunning()
            {
                return GameIsRunning;
            }

};

#endif