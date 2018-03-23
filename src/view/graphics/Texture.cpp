//
//Created by angelica on 22/10/17.
//
#include "Texture.h"

Texture::Texture() {
    mTexture = nullptr;
    mWidth = 0;
    mHeight = 0;
}

/**
 * Load a texture from file
 * @param renderer rendered to which to render
 * @param path to the texture
 * @return
 */
bool Texture::loadFromFile(SDL_Renderer *renderer, std::string path) {
    //Get rid of preexisting texture
    free();

    SDL_Texture *newTexture = nullptr;

    //Load image
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        cout << "Could not load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError();

    } else {
        //Color key image to get rid of background colour
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

        //Create texture
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (newTexture == nullptr) {
            cout << "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError();
        } else {
            //Get image dimensions
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
            originalWidth = loadedSurface->w;
            originalHeight = loadedSurface->h;
        }
        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }
    //Return success
    mTexture = newTexture;
    return mTexture != nullptr;
}

/**
 * Load a TTF font
 * @param renderer
 * @param gFont pointer to a font
 * @param textureText string of text to render
 * @param textColor colour of text
 * @return
 */
bool Texture::loadFont(SDL_Renderer *renderer, TTF_Font *gFont, std::string textureText, SDL_Color textColor) {
    //Get rid of preexisting texture
    free();

    //Determine the size of text before wrapping
    SDL_Surface *textSurfaceTest = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);

    int text_x = textSurfaceTest->w;

    //Get rid of the test texture
    free();

    //Determine the size or final wrapped text
    if (text_x > 225) {
        mWidth = 225;
    } else {
        mWidth = textSurfaceTest->w;
    }

    //Render text surface
    SDL_Surface *textSurface = TTF_RenderText_Blended_Wrapped(gFont, textureText.c_str(), textColor, mWidth);
    if (textSurface == nullptr) {
        cout << "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError();
    } else {
        //Create text texture
        mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        if (mTexture == nullptr) {
            cout << "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError();
        } else {
            if (textSurface->w > 225) {
                mWidth = 225;
            } else {
                mWidth = textSurface->w;
            }
            //Get image dimensions
            mHeight = textSurface->h;
        }
        //Get rid of old surface
        SDL_FreeSurface(textSurface);
    }
    //Return success
    return mTexture != nullptr;
}

/**
 * Set the texture blend mode
 * @param blending
 */
void Texture::setBlendMode(SDL_BlendMode blending) {
    //Set blending function
    SDL_SetTextureBlendMode(mTexture, blending);
}

/**
 * Set the alpha to make the texture transparent
 * @param alpha
 */
void Texture::setAlpha(Uint8 alpha) {
    SDL_SetTextureAlphaMod(mTexture, alpha);
}

/**
 * Free existing texture
 */
void Texture::free() {
    if (mTexture != nullptr) {
        SDL_DestroyTexture(mTexture);
        mTexture = nullptr;
        mWidth = 0;
        mHeight = 0;
    }
}

/**
 * Set colour to a texture
 * @param red
 * @param green
 * @param blue
 */
void Texture::setColor(Uint8 red, Uint8 green, Uint8 blue) {
    SDL_SetTextureColorMod(mTexture, red, green, blue);
}

/**
 * Render the texture
 * @param renderer rendered to which to render
 * @param x position
 * @param y position
 */
void Texture::render(SDL_Renderer *renderer, int x, int y) {
    //Set rendering space and render to screen
    SDL_Rect renderQuad = {x, y, mWidth, mHeight};
    SDL_RenderCopy(renderer, mTexture, nullptr, &renderQuad);
}

/**
 * Set size of texture
 * @param x
 * @param y
 */
void Texture::setSize(int x, int y) {
    mWidth = x;
    mHeight = y;
}

/**
 * Render from a sprite sheet
 * @param renderer
 * @param x position of sprite sheet
 * @param y position of sprite sheet
 * @param clip
 */
void Texture::renderSprite(SDL_Renderer *renderer, int x, int y, SDL_Rect *clip) {
    SDL_Rect renderQuad = {x, y, mWidth, mHeight};
    //Set clip dimensions
    if (clip != nullptr) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    //Render to screen
    SDL_RenderCopy(renderer, mTexture, clip, &renderQuad);
}

int Texture::getWidth() {
    return mWidth;
}

int Texture::getHeight() {
    return mHeight;
}

int Texture::getOriginalWidth() {
    return originalWidth;
}

Texture::~Texture() {
    free();
}