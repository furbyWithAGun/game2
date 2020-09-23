#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

class Texture
{
    public:
        std::string filePath;
        int height;
        int width;
        SDL_Texture* texture;
        Texture(std::string path);
        ~Texture();
        void free();
};

