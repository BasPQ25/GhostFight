#include"Graphics.h"

bool Graphics::Create(std::string id, std::string filename)
{
    SDL_Surface* surface = IMG_Load( filename.c_str() );
    if(surface == nullptr)
    {
        SDL_Log("Failed to load texture: %s %s" , filename.c_str() , SDL_GetError() );
        return false;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface( Engine::Game()->GetRenderer(), surface );
    if( texture == nullptr)
    {
        SDL_Log("Failed to create texture from surface %s", SDL_GetError() );
        return false;
        
    }

    ImagesMap[id] = texture;
    
    return true;
}

void Graphics::Destroy(std::string id)
{
    SDL_DestroyTexture(ImagesMap[id]);
    ImagesMap.erase(id);
}

void Graphics::Clean()
{
    std::unordered_map<std::string,SDL_Texture*>::iterator it;
    for(it = ImagesMap.begin(); it != ImagesMap.end(); it++)
    {
        ImagesMap.clear();
    }
}

void Graphics::DrawFrame(std::string id, int x, int y, int width, int height, int row, int frame,  SDL_RendererFlip flip)
{
    
    SDL_Rect srcRect = {width*frame , height*row  , width , height};
    SDL_Rect dstRect = {x,y,width,height};

    SDL_RenderCopyEx(Engine::Game()->GetRenderer() , ImagesMap[id], &srcRect, &dstRect, 0, nullptr,flip);
}

