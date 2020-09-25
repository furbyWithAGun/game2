#include "Texture.h"

Texture::Texture(std::string path) {
    filePath = path;
    height = 0;
    width = 0;
}

Texture::Texture() {

}

Texture::~Texture() {
    free();
}

void Texture::free() {

    if (texture != NULL)
    {
        //SDL_DestroyTexture(texture);
        //texture = NULL;
        width = 0;
        height = 0;
    }
}

bool Texture::resize(int newHeight, int newWidth) {
    height = newHeight;
    width = newWidth;
    return true;
}
