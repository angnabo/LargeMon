//
// Created by angelica on 22/10/17.
//

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>

#ifndef LARGEMON_LTEXTURE_H
#define LARGEMON_LTEXTURE_H

using namespace std;

class GTexture {
public:
    //Initializes variables
    GTexture();

    //Deallocates memory
    ~GTexture();

    void setSize(int, int);

    //Loads image at specified path
    bool loadFromFile(SDL_Renderer *gRenderer, std::string path);

    //Deallocates texture
    void free();

    //Renders texture at given point
    void render(SDL_Renderer *gRenderer, int x, int y);

    void renderSprite(SDL_Renderer *gRenderer, int x, int y, SDL_Rect *clip);

    void setColor(Uint8 red, Uint8 green, Uint8 blue);

    //Gets image dimensions
    int getWidth();

    int getHeight();

    int getOriginalWidth();

    //The window renderer
    bool loadFont(SDL_Renderer *gRenderer, TTF_Font *gFont, std::string textureText, SDL_Color textColor);

private:
    //The actual hardware texture
    SDL_Texture *mTexture;
    //Image dimensions
    int mWidth;
    int mHeight;
    int originalWidth;
    int originalHeight;
};
#endif //LARGEMON_LTEXTURE_H
