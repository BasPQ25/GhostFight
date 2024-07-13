#ifndef NINJA_H
#define NINJA_H

#include"Character.h"

#define NINJA_WIDTH 100
#define NINJA_HEIGHT 100
#define NINJA_TEXTUREID "ninja"



class Ninja: public Character
{
    public:
        //Constructor
            Ninja(std::string TextureID, int Width, int Height, SDL_RendererFlip Flip) : Character(TextureID,Width,Height,Flip) {}
        
        //Variables
            int AnimationSpeed = 100; // milliseconds
            int Frames = 6;

        //Functions
            virtual void Draw(std::string id, int x, int y, int width, int height, int row, int frame,  SDL_RendererFlip flip);
            virtual void Update(float dt);
            virtual void Clean();



};


#endif