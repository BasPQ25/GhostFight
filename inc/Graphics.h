#ifndef GRAPHICS_H
#define GRAPHICS_H

#include"Engine.h"

#include<string>
#include<unordered_map>

class Graphics
{
    private:
        //Graphics variables
            inline static Graphics* GameGraphics_Instance = nullptr; 
            std::unordered_map<std::string , SDL_Texture*> ImagesMap;
            

    public:

        //Constructor
            Graphics(){}

        //Public variables
            int frame = 0;
            
            //Animation speed functions
                unsigned int AnimationSpeed = 100; //trebe refacut
                unsigned int AnimationSpeed_time_keeper = 0;

            int row = 0;
        //Graphics initialization functions
            bool Create(std::string id, std::string filename);
        
        //Graphics in game running functions
            void Destroy(std::string id);
            void Clean(); 
            void DrawFrame(std::string id, int x, int y, int width, int height, int row, int frame,  SDL_RendererFlip flip = SDL_FLIP_NONE);

        //Graphics initialization only once
            static Graphics* GameGraphics()
            {
                return GameGraphics_Instance = (GameGraphics_Instance != nullptr) ? GameGraphics_Instance : new Graphics();
            }

        
};

#endif