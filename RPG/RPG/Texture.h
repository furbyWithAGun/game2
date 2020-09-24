#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

class Texture
{
    public:
        //attributes
        std::string filePath;
        int height;
        int width;
        SDL_Texture* texture;

        //constructors
        Texture(std::string path);
        Texture();
        ~Texture();
        void free();

};

