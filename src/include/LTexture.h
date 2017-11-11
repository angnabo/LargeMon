//
// Created by angelica on 22/10/17.
//

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#ifndef LARGEMON_LTEXTURE_H
#define LARGEMON_LTEXTURE_H


class LTexture
{
public:
    //Initializes variables
    LTexture();

    //Deallocates memory
    ~LTexture();

    void setSize(int, int);

    //Loads image at specified path
    bool loadFromFile(SDL_Renderer* gRenderer, std::string path );

    //Deallocates texture
    void free();

    //Renders texture at given point
    void render(SDL_Renderer* gRenderer, int x, int y );


    void renderEnlarge(SDL_Renderer *gRenderer, int x, int y, int w, int h);

    void renderSprite(SDL_Renderer *gRenderer, int x, int y, SDL_Rect *clip);

    void setColor(Uint8 red, Uint8 green, Uint8 blue);

    //Gets image dimensions
    int getWidth();
    int getHeight();

private:
    //The actual hardware texture
    SDL_Texture* mTexture;

    //Image dimensions
    int mWidth;
    int mHeight;
    //The window renderer
};


#endif //LARGEMON_LTEXTURE_H
