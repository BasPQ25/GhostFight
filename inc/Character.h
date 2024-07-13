#ifndef CHARACTER_H
#define CHARACTER_H

#include"Objects.h"
#include"Graphics.h"
#include<string>


class Character: public Objects
{
    private:
        //Characters Characteristics
            std::string  textureID;
            int width, height;
            SDL_RendererFlip flip;
            //Transform* transform;

    public:
        //Constructor
            Character(std::string TextureID, int Width, int Height, SDL_RendererFlip Flip) : textureID(TextureID) , width(Width) , height(Height) , flip(Flip) {}

        //Game Objects BluePrint
            virtual void Draw() = 0;
            virtual void Update(float dt) = 0;
            virtual void Clean() = 0;
};

#endif