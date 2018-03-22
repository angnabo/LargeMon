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

class Texture {
public:
    //Initializes variables
    Texture();

    //Deallocates memory
    ~Texture();

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

    void setPosition(int,int);

    int getXposition() { return x_position;}
    int getYposition() { return y_position;}

    void setHidden(bool b){ hidden = b; }
    bool isHidden() { return hidden; }
    void render(SDL_Renderer *gRenderer);

    void setBlendMode(SDL_BlendMode blending);

    void setAlpha(Uint8 alpha);

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

    int x_position;
    int y_position;

    bool hidden = false;

};
#endif //LARGEMON_LTEXTURE_H
