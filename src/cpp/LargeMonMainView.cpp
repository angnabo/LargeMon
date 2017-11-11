//
// Created by angelica on 11/11/17.
//

#include "LargeMonMainView.h"
//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "../include/LTexture.h"
#include "../include/ButtonTexture.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Texture wrapper class


//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Scene textures
LTexture gPlayerTexture;
LTexture gEnemyTexture;
LTexture gBackgroundTexture;
ButtonTexture gTopLeftButton;
ButtonTexture gTopRightButton;
ButtonTexture gBottomLeftButton;
ButtonTexture gBottomRightButton;
ButtonTexture buttons[4];
SDL_Rect gSpriteClips[ 4 ];
LTexture gSpriteSheetTexture;
//SDL_Texture *gViewport;
SDL_Texture* loadTexture( std::string path );
SDL_Texture* gTexture = NULL;


//int selectedButton;



bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }
            }
        }
    }

    return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;



    //Load player texture
    if( !gPlayerTexture.loadFromFile( gRenderer, "/home/angelica/Development/CLion/LargeMon/src/resources/onion.bmp" ) )
    {
        printf( "Failed to load Foo' texture image!\n" );
        success = false;
    }
    //Load enemy texture
    if( !gEnemyTexture.loadFromFile( gRenderer, "/home/angelica/Development/CLion/LargeMon/src/resources/onion.bmp" ) )
    {
        printf( "Failed to load Foo' texture image!\n" );
        success = false;
    }
    //Load background texture
    if( !gBackgroundTexture.loadFromFile(gRenderer, "/home/angelica/Development/CLion/LargeMon/src/resources/mountains.png" ) )
    {
        printf( "Failed to load background texture image!\n" );
        success = false;
    }

    //Load background texture
    if( !gTopLeftButton.loadFromFile(gRenderer, "/home/angelica/Development/CLion/LargeMon/src/resources/button.bmp" ) )
    {
        printf( "Failed to load background texture image!\n" );
        success = false;
    }
    gTopRightButton.setSelected(true);
    //Load background texture
    if( !gTopRightButton.loadFromFile(gRenderer, "/home/angelica/Development/CLion/LargeMon/src/resources/button.bmp" ) )
    {
        printf( "Failed to load background texture image!\n" );
        success = false;
    }
    //Load background texture
    if( !gBottomLeftButton.loadFromFile(gRenderer, "/home/angelica/Development/CLion/LargeMon/src/resources/button.bmp" ) )
    {
        printf( "Failed to load background texture image!\n" );
        success = false;
    }
    //Load background texture
    if( !gBottomRightButton.loadFromFile(gRenderer, "/home/angelica/Development/CLion/LargeMon/src/resources/button.bmp" ) )
    {
        printf( "Failed to load background texture image!\n" );
        success = false;
    }

    gTopLeftButton.setColor(70, 70, 70);

    buttons[0] = gTopLeftButton;
    buttons[1] = gTopRightButton;
    buttons[2] = gBottomLeftButton;
    buttons[3] = gBottomRightButton;


    //Load sprite sheet texture
    if( !gSpriteSheetTexture.loadFromFile( gRenderer, "/home/angelica/Development/CLion/LargeMon/src/resources/buttons.bmp" ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }
    else
    {
        //Set top left sprite
        gSpriteClips[ 0 ].x =   0;
        gSpriteClips[ 0 ].y =   0;
        gSpriteClips[ 0 ].w = 300;
        gSpriteClips[ 0 ].h = 75;

        //Set top right sprite
        gSpriteClips[ 1 ].x = 300;
        gSpriteClips[ 1 ].y =   0;
        gSpriteClips[ 1 ].w = 300;
        gSpriteClips[ 1 ].h = 75;

        //Set bottom left sprite
        gSpriteClips[ 2 ].x =   0;
        gSpriteClips[ 2 ].y = 75;
        gSpriteClips[ 2 ].w = 300;
        gSpriteClips[ 2 ].h = 75;

        //Set bottom right sprite
        gSpriteClips[ 3 ].x = 300;
        gSpriteClips[ 3 ].y = 75;
        gSpriteClips[ 3 ].w = 300;
        gSpriteClips[ 3 ].h = 75;
    }

//    //Load texture
//    gTexture = loadTexture( "/home/angelica/Development/CLion/LazyFoo/tut10/viewport.png" );
//    if( gTexture == NULL )
//    {
//        printf( "Failed to load texture image!\n" );
//        success = false;
//    }

    return success;
}

void close()
{
    //Free loaded images
    gPlayerTexture.free();
    gEnemyTexture.free();
    gBackgroundTexture.free();
    //Free loaded image
    SDL_DestroyTexture( gTexture );
    gTexture = NULL;

    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}



//SDL_Texture* loadTexture( std::string path )
//{
//    //The final texture
//    SDL_Texture* newTexture = NULL;
//
//    //Load image at specified path
//    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
//    if( loadedSurface == NULL )
//    {
//        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
//    }
//    else
//    {
//        //Create texture from surface pixels
//        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
//        if( newTexture == NULL )
//        {
//            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
//        }
//
//        //Get rid of old loaded surface
//        SDL_FreeSurface( loadedSurface );
//    }
//
//    return newTexture;
//}

int getSelected(){
    for (int i = 0; i < 4; i ++){
        if(buttons[i].isSelected()){
            return i;
        }
    }
}

int handleUP(int* selected){
    if (*selected == 0 || *selected == 1){

    } else if (*selected == 2){
        *selected = 0;
    } else {
        *selected = 1;
    }
    return *selected;
}

int handleDOWN(int* selected){
    if (*selected == 0){
        *selected = 2;
    } else if( *selected == 1){
        *selected = 3;
    }
    return *selected;
}


int handleRight(int* selected){
    if (*selected == 0){
        *selected = 1;

    } else if (*selected == 2){
        *selected = 3;
    }
    return *selected;
}

int handleLeft(int* selected){
    if (*selected == 1){
        *selected = 0;
    } else if (*selected == 3){
        *selected = 2;
    }
    return *selected;
}



int main( int argc, char* args[] ) {
    //Start up SDL and create window
    if (!init()) {
        printf("Failed to initialize!\n");
    } else {
        //Load media
        if (!loadMedia()) {
            printf("Failed to load media!\n");
        } else {
            //Main loop flag
            bool quit = false;


            //Event handler
            SDL_Event e;

            //Modulation components
            Uint8 r = 255;
            Uint8 g = 255;
            Uint8 b = 255;

            //Modulation components
            Uint8 rSelected = 70;
            Uint8 gSelected = 70;
            Uint8 bSelected = 70;

            int selectedButton = 0;

            //While application is running
            while (!quit) {
                //Handle events on queue
                while (SDL_PollEvent(&e) != 0) {
                    //User requests quit
                    if (e.type == SDL_QUIT) {
                        quit = true;
                    }
                        //On keypress change rgb values
                    else if (e.type == SDL_KEYDOWN) {
                        switch (e.key.keysym.sym) {

                                //Handle LEFT key press
                            case SDLK_UP:
                                buttons[selectedButton].setColor(r, g, b);
                                handleUP(&selectedButton);
                                buttons[selectedButton].setColor(rSelected, gSelected, bSelected);
                                break;

                                //Handle RIGHT key press
                            case SDLK_RIGHT:
                                buttons[selectedButton].setColor(r, g, b);
                                handleRight(&selectedButton);
                                buttons[selectedButton].setColor(rSelected, gSelected, bSelected);
                                break;

                                //Handle UP key press
                            case SDLK_LEFT:
                                buttons[selectedButton].setColor(r, g, b);
                                handleLeft(&selectedButton);
                                buttons[selectedButton].setColor(rSelected, gSelected, bSelected);
                                break;

                                //Handle DOWN key press
                            case SDLK_DOWN:
                                buttons[selectedButton].setColor(r, g, b);
                                handleDOWN(&selectedButton);
                                buttons[selectedButton].setColor(rSelected, gSelected, bSelected);
                                break;

                        }
                    }
                }

                //Clear screen
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(gRenderer);

                //Top viewport
                SDL_Rect topViewport;
                topViewport.x = 0;
                topViewport.y = 0;
                topViewport.w = SCREEN_WIDTH;
                topViewport.h = SCREEN_HEIGHT;
                SDL_RenderSetViewport(gRenderer, &topViewport);

                //Render background texture to screen
                gBackgroundTexture.render(gRenderer, 0, 0);

                //Render player to the screen
                gPlayerTexture.render(gRenderer, 60, 190);

                //Render enemy to the screen
                gEnemyTexture.render(gRenderer, 340, 190);


                //Bottom viewport
                SDL_Rect bottomViewport;
                bottomViewport.x = 0;
                bottomViewport.y = static_cast<int>(SCREEN_HEIGHT / 1.5);
                bottomViewport.w = SCREEN_WIDTH;
                bottomViewport.h = SCREEN_HEIGHT / 3;
                SDL_RenderSetViewport(gRenderer, &bottomViewport);

                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);


                gTopLeftButton.render(gRenderer, 0, 0);
                gTopRightButton.render(gRenderer, SCREEN_WIDTH - gTopRightButton.getWidth(), 0);
                gBottomLeftButton.render(gRenderer, 0, SCREEN_HEIGHT / 3 - gBottomLeftButton.getHeight());
                gBottomRightButton.render(gRenderer, SCREEN_WIDTH - gBottomRightButton.getWidth(),
                                          SCREEN_HEIGHT / 3 - gBottomRightButton.getHeight());
//                gTopLeftButton.setColor(r, g, b);
//                gTopRightButton.setColor(r, g, b);
//                gBottomLeftButton.setColor(r, g, b);
//                gBottomRightButton.setColor(r, g, b);

//				gSpriteSheetTexture.renderSprite( gRenderer, 0, 0, &gSpriteClips[ 0 ] );
//				//gSpriteSheetTexture.setColor(r, b, g);
//				//Render top right sprite
//				gSpriteSheetTexture.renderSprite( gRenderer,SCREEN_WIDTH - gSpriteClips[ 1 ].w, 0, &gSpriteClips[ 1 ] );
//
//				//Render bottom left sprite
//				gSpriteSheetTexture.renderSprite( gRenderer, 0, SCREEN_HEIGHT / 3 - gSpriteClips[ 2 ].h, &gSpriteClips[ 2 ] );
//
//				//Render bottom right sprite
//				gSpriteSheetTexture.renderSprite( gRenderer, SCREEN_WIDTH - gSpriteClips[ 3 ].w, SCREEN_HEIGHT/3 - gSpriteClips[ 3 ].h, &gSpriteClips[ 3 ] );


                //SDL_Texture texture = (SDL_Texture) gViewport;

                //Render texture to screen
                //SDL_RenderCopy( gRenderer, gViewport, NULL, NULL );

                //Update screen
                SDL_RenderPresent(gRenderer);
            }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}