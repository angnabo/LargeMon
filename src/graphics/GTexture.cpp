//
// Created by angelica on 22/10/17.
//

#include "GTexture.h"


GTexture::GTexture()
{
    //Initialize
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}

GTexture::~GTexture()
{
    //Deallocate
    free();
}

/**
 * Load a texture from file
 * @param gRenderer rendered to which to render
 * @param path to the texture
 * @return
 */
bool GTexture::loadFromFile( SDL_Renderer* gRenderer, std::string path )
{
    //Get rid of preexisting texture
    free();

    SDL_Texture* newTexture = NULL;

    //Load image
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        cout << "Could not load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError();

    }
    else
    {
        //Color key image to get rid of background colour
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if( newTexture == NULL )
        {
            cout << "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError();
        }
        else
        {
            //Get image dimensions
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
            originalWidth = loadedSurface->w;
            originalHeight = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    //Return success
    mTexture = newTexture;
    return mTexture != NULL;
}

/**
 * Load a TTF font
 * @param gRenderer
 * @param gFont pointer to a font
 * @param textureText string of text to render
 * @param textColor colour of text
 * @return
 */
bool GTexture::loadFont(SDL_Renderer * gRenderer, TTF_Font * gFont, std::string textureText, SDL_Color textColor )
{
    //Get rid of preexisting texture
    free();

    //Determine the size of text before wrapping
    SDL_Surface* textSurfaceTest = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor);

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
    SDL_Surface* textSurface = TTF_RenderText_Blended_Wrapped( gFont, textureText.c_str(), textColor, mWidth );
    if( textSurface == NULL )
    {
       cout << "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError();
    }
    else
    {
        //Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
        if( mTexture == NULL )
        {
            cout << "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError();
        }
        else
        {
            if (textSurface->w > 225) {
                mWidth = 225;
            } else {
                mWidth = textSurface->w;
            }
            //Get image dimensions
            //mWidth = textSurface->w;
            mHeight = textSurface->h;
        }

        //Get rid of old surface
        SDL_FreeSurface( textSurface );
    }

    //Return success
    return mTexture != NULL;
}
/**
 * Free existing texture
 */
void GTexture::free()
{
    if( mTexture != NULL )
    {
        SDL_DestroyTexture( mTexture );
        mTexture = NULL;
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
void GTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
    SDL_SetTextureColorMod( mTexture, red, green, blue );
}

/**
 * Render the texture
 * @param gRenderer rendered to which to render
 * @param x position
 * @param y position
 */
void GTexture::render(SDL_Renderer* gRenderer, int x, int y )
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };
    SDL_RenderCopy( gRenderer, mTexture, NULL, &renderQuad );
}

/**
 * Set size of texture
 * @param x
 * @param y
 */
void GTexture::setSize(int x, int y) {
    mWidth = x;
    mHeight = y;
}


/**
 * Render from a sprite sheet
 * @param gRenderer
 * @param x position of sprite sheet
 * @param y position of sprite sheet
 * @param clip
 */
void GTexture::renderSprite( SDL_Renderer* gRenderer, int x, int y, SDL_Rect* clip )
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };

    //Set clip rendering dimensions
    if( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    //Render to screen
    SDL_RenderCopy( gRenderer, mTexture, clip, &renderQuad );
}

int GTexture::getWidth()
{
    return mWidth;
}

int GTexture::getHeight()
{
    return mHeight;
}

int GTexture::getOriginalWidth() {
    return originalWidth;
}

int GTexture::getOriginalHeight() {
    return originalHeight;
}

