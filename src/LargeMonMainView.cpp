//
// Created by angelica on 11/11/17.
//

//#include "include/LargeMonMainView.h"
//Using SDL, SDL_image, standard IO, and strings
#include <ctime>
#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>
#include "graphics/GTexture.h"
#include "graphics/GProgressBar.h"
#include "graphics/GButtonTexture.h"
#include "controller/ControllerBattleInstance.h"
#include "controller/FileWriter.h"
#include "../test/ControllerTest.cpp"
#include "../test/Test.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Globally used font
TTF_Font *gFont = NULL;
TTF_Font *gHpFont = NULL;

//Battle Instance Controller
ControllerBattleInstance battleInstance;
FileWriter * writer;

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

//Bottom Panel Text
string panelTextString;

SDL_Color col1;
SDL_Color col2;


//Scene textures
GTexture gPlayerTexture;
GTexture gEnemyTexture;
GTexture gBackgroundTexture;
GButtonTexture gTopLeftButton;
GButtonTexture gTopRightButton;
GButtonTexture gBottomLeftButton;
GButtonTexture gBottomRightButton;

GTexture gBottomTextPanel;
GTexture gBottomPanelFull;

GTexture gPlayerHpBarBG;
GProgressBar gPlayerHpBarFG;
GTexture gPlayerHealthText;

GTexture gEnemyHpBarBG;
GProgressBar gEnemyHpBarFG;
GTexture gEnemyHealthText;

GTexture gTopLeftButtonText;
GTexture gTopRightButtonText;
GTexture gBottomLeftButtonText;
GTexture gBottomRightButtonText;
GTexture gPanelText;

GButtonTexture buttons[4];
SDL_Rect gSpriteClips[ 2 ];
GTexture gSpriteSheetTexture;
SDL_Texture* loadTexture( std::string path );
SDL_Texture* gTexture = NULL;

bool init()
{
    writer = new FileWriter(&battleInstance);
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
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
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

                //Initialize SDL_ttf
                if( TTF_Init() == -1 )
                {
                    printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
                    success = false;
                }
            }
        }
    }

    return success;
}

bool loadMedia(string panel_text)
{
    //Loading success flag
    bool success = true;

    //Load player texture
    if( !gPlayerTexture.loadFromFile( gRenderer, "/home/angelica/Development/CLion/LargeMon/resources/shibainu.bmp" ) )
    {
        printf( "Failed to load Foo' texture image!\n" );
        success = false;
    }
    //Load enemy texture
    if( !gEnemyTexture.loadFromFile( gRenderer, "/home/angelica/Development/CLion/LargeMon/resources/shiba-inu-21.bmp" ) )
    {
        printf( "Failed to load Foo' texture image!\n" );
        success = false;
    }
    //Load background texture
    if( !gBackgroundTexture.loadFromFile(gRenderer, "/home/angelica/Development/CLion/LargeMon/resources/mountains.png" ) )
    {
        printf( "Failed to load background texture image!\n" );
        success = false;
    }
    //Load bottom panel
    if( !gBottomTextPanel.loadFromFile(gRenderer, "/home/angelica/Development/CLion/LargeMon/resources/bottom_panel.bmp" ) )
    {
        printf( "Failed to load background texture image!\n" );
        success = false;
    }
    //Load large bottom panel
    if( !gBottomPanelFull.loadFromFile(gRenderer, "/home/angelica/Development/CLion/LargeMon/resources/bottom_panel_full.bmp" ) )
    {
        printf( "Failed to load background texture image!\n" );
        success = false;
    }
    //Load large bottom panel
    if( !gPlayerHpBarBG.loadFromFile(gRenderer, "/home/angelica/Development/CLion/LargeMon/resources/health_bar_bg.bmp" ) )
    {
        printf( "Failed to load background texture image!\n" );
        success = false;
    }
    //Load large bottom panel
    if( !gPlayerHpBarFG.loadFromFile(gRenderer, "/home/angelica/Development/CLion/LargeMon/resources/health_bar_fg.bmp" ) )
    {
        printf( "Failed to load background texture image!\n" );
        success = false;
    }
    //Load large bottom panel
    if( !gEnemyHpBarBG.loadFromFile(gRenderer, "/home/angelica/Development/CLion/LargeMon/resources/health_bar_bg.bmp" ) )
    {
        printf( "Failed to load background texture image!\n" );
        success = false;
    }
    //Load large bottom panel
    if( !gEnemyHpBarFG.loadFromFile(gRenderer, "/home/angelica/Development/CLion/LargeMon/resources/health_bar_fg.bmp" ) )
    {
        printf( "Failed to load background texture image!\n" );
        success = false;
    }
    //Load player texture
    if( !gSpriteSheetTexture.loadFromFile( gRenderer, "/home/angelica/Development/CLion/LargeMon/resources/shiba_inu_sprite_sheet.bmp" ) )
    {
        printf( "Failed to load Foo' texture image!\n" );
        success = false;
    } else
    {
        //Set bottom left sprite
        gSpriteClips[ 0 ].x =   0;
        gSpriteClips[ 0 ].y =   0;
        gSpriteClips[ 0 ].w = 362;
        gSpriteClips[ 0 ].h = 300;

        //Set top right sprite
        gSpriteClips[ 1 ].x = 362;
        gSpriteClips[ 1 ].y =   0;
        gSpriteClips[ 1 ].w = 203;
        gSpriteClips[ 1 ].h = 200;
    }

    //Load ttf pixel font large size
    gFont = TTF_OpenFont( "/home/angelica/Development/CLion/LargeMon/resources/alterebro-pixel-font.ttf", 30 );
    if( gFont == NULL )
    {
        printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    } else {
        //Render text
        SDL_Color textColor = { 0, 0, 0 };
        if( !gTopLeftButtonText.loadFromRenderedText( gRenderer, gFont, "Attack", textColor ) )
        {
            printf( "Failed to render text texture!\n" );
            success = false;
        }
        if( !gTopRightButtonText.loadFromRenderedText( gRenderer, gFont, "Defend", textColor ) )
        {
            printf( "Failed to render text texture!\n" );
            success = false;
        }
        if( !gBottomLeftButtonText.loadFromRenderedText( gRenderer, gFont, "Special Attack 1", textColor ) )
        {
            printf( "Failed to render text texture!\n" );
            success = false;
        }
        if( !gBottomRightButtonText.loadFromRenderedText( gRenderer, gFont, "Special Attack 2", textColor ) )
        {
            printf( "Failed to render text texture!\n" );
            success = false;
        }
        if( !gPanelText.loadFromRenderedText( gRenderer, gFont, panel_text, textColor ) )
        {
            printf( "Failed to render text texture!\n" );
            success = false;
        }
    }
    //Open ttf pixel font small size
    gHpFont = TTF_OpenFont( "/home/angelica/Development/CLion/LargeMon/resources/alterebro-pixel-font.ttf", 20 );
    if( gHpFont == NULL )
    {
        printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    } else {
        SDL_Color textColor = { 0, 0, 0 };
        if( !gPlayerHealthText.loadFromRenderedText( gRenderer, gHpFont, to_string(battleInstance.getPlayerCurrentHp()), textColor ) )
        {
            printf( "Failed to render text texture!\n" );
            success = false;
        }
        if( !gEnemyHealthText.loadFromRenderedText( gRenderer, gHpFont, to_string(battleInstance.getEnemyCurrentHp()), textColor ) )
        {
            printf( "Failed to render text texture!\n" );
            success = false;
        }
    }

    //Load Button Textures
    if( !gTopLeftButton.loadFromFile(gRenderer, "/home/angelica/Development/CLion/LargeMon/resources/button.bmp" ) )
    {
        printf( "Failed to load background texture image!\n" );
        success = false;
    }
    if( !gTopRightButton.loadFromFile(gRenderer, "/home/angelica/Development/CLion/LargeMon/resources/button.bmp" ) )
    {
        printf( "Failed to load background texture image!\n" );
        success = false;
    }
    if( !gBottomLeftButton.loadFromFile(gRenderer, "/home/angelica/Development/CLion/LargeMon/resources/button.bmp" ) )
    {
        printf( "Failed to load background texture image!\n" );
        success = false;
    }
    if( !gBottomRightButton.loadFromFile(gRenderer, "/home/angelica/Development/CLion/LargeMon/resources/button.bmp" ) )
    {
        printf( "Failed to load background texture image!\n" );
        success = false;
    }

    gTopLeftButton.setColor(70, 70, 70);

    buttons[0] = gTopLeftButton;
    buttons[1] = gTopRightButton;
    buttons[2] = gBottomLeftButton;
    buttons[3] = gBottomRightButton;

    return success;
}

bool updateText(string text)
{
    SDL_Color textColor = { 0, 0, 0 };
    bool success = true;
    //Load font again
    if( !gBottomPanelFull.loadFromFile(gRenderer, "/home/angelica/Development/CLion/LargeMon/resources/bottom_panel_full.bmp" ) )
    {
        printf( "Failed to load background texture image!\n" );
        success = false;
    }
    if( !gPanelText.loadFromRenderedText( gRenderer, gFont, text, textColor ) )
    {
        printf( "Failed to render text texture!\n" );
        success = false;
    }
    gBottomPanelFull.render(gRenderer, 10, 0);
    gPanelText.render(gRenderer,30, 10);
    return success;
}

/*

   color - Returns an SDL_Color with the appropriate values

*/

SDL_Color color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_Color col = {r,g,b,a};
    return col;
}

void close()
{
    //Free loaded images
    gPlayerTexture.free();
    gEnemyTexture.free();
    gBackgroundTexture.free();
    gBottomTextPanel.free();
    gBottomPanelFull.free();

    //Free health bars
    gPlayerHpBarFG.free();
    gPlayerHpBarBG.free();
    gPlayerHealthText.free();

    gEnemyHpBarFG.free();
    gEnemyHpBarBG.free();
    gEnemyHealthText.free();

    //Free button text
    gTopRightButtonText.free();
    gTopLeftButtonText.free();
    gBottomRightButtonText.free();
    gBottomLeftButtonText.free();

    gBottomLeftButton.free();
    gBottomRightButton.free();
    gTopLeftButton.free();
    gTopRightButton.free();

    gPanelText.free();

    //Free global font
    TTF_CloseFont( gFont );
    gFont = NULL;

    //Free loaded image
    SDL_DestroyTexture( gTexture );
    gTexture = NULL;

    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}


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

    SDL_Color col1 = color(0, 168, 107, 50);
    SDL_Color col2 = color(188, 3, 107, 50);

    Test test;
    test.test();

    panelTextString = "A wild " + battleInstance.getEnemyLargeMonName() + " appears!";
    //Start up SDL and create window
    if (!init()) {
        printf("Failed to initialize!\n");
    } else {
        //Load media
        if (!loadMedia(panelTextString)) {
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
                        if(e.key.keysym.sym == SDLK_RETURN){


                            string textUpdate = "";
                            if(!battleInstance.isGameOver()) {
                                textUpdate = battleInstance.action(&selectedButton);
                                updateText(textUpdate);
                                gPlayerHpBarFG.updateProgress(gRenderer, gPlayerHpBarFG, gHpFont, gPlayerHealthText,
                                         battleInstance.getPlayerLargeMonCurrentHpPercent(),
                                         to_string(battleInstance.getPlayerCurrentHp()));


                                gEnemyHpBarFG.updateProgress(gRenderer, gEnemyHpBarFG, gHpFont, gEnemyHealthText,
                                         battleInstance.getEnemyLargeMonCurrentHpPercent(),
                                         to_string(battleInstance.getEnemyCurrentHp()));
                            } else {
                                //gBottomPanelFull.render(gRenderer, 10,0);
                                updateText(battleInstance.getWinner());
                                //gBottomTextPanel.free();
                                //SDL_RenderPresent(gRenderer);
                                //close();
                            }
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
                //gPlayerTexture.render(gRenderer, -20, 170);
                gSpriteSheetTexture.renderSprite(gRenderer, -20, 170, &gSpriteClips[0]);

                //Render enemy to the screen
                //gEnemyTexture.render(gRenderer, 430, 40);
                gSpriteSheetTexture.renderSprite(gRenderer, 430, 40, &gSpriteClips[1]);

                gPlayerHpBarBG.render(gRenderer, 30, 300);
                gPlayerHpBarFG.render(gRenderer, 31, 301);
                gPlayerHealthText.render(gRenderer, 35,301);

                gEnemyHpBarBG.render(gRenderer, 480, 237);
                gEnemyHpBarFG.render(gRenderer, 481, 238);
                gEnemyHealthText.render(gRenderer, 485,238);

                //Bottom viewport
                SDL_Rect bottomViewport;
                bottomViewport.x = 0;
                bottomViewport.y = static_cast<int>(SCREEN_HEIGHT / 1.4);
                bottomViewport.w = SCREEN_WIDTH;
                bottomViewport.h = SCREEN_HEIGHT / 3;
                SDL_RenderSetViewport(gRenderer, &bottomViewport);

                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                int X_BUTTON_OFFSET = 270;
                int Y_BUTTON_OFFSET = 20;

                gBottomTextPanel.render(gRenderer, 10, 0);
                gPanelText.render(gRenderer,30, 10);

                gTopLeftButton.render(gRenderer, X_BUTTON_OFFSET, Y_BUTTON_OFFSET);
                gTopRightButton.render(gRenderer, SCREEN_WIDTH - gTopRightButton.getWidth()-10, Y_BUTTON_OFFSET);
                gBottomLeftButton.render(gRenderer, X_BUTTON_OFFSET, Y_BUTTON_OFFSET+gTopRightButton.getHeight()+5);
                gBottomRightButton.render(gRenderer, SCREEN_WIDTH - gTopRightButton.getWidth()-10,
                                          Y_BUTTON_OFFSET+gTopRightButton.getHeight()+5);

                gTopLeftButtonText.render(gRenderer, X_BUTTON_OFFSET+10, Y_BUTTON_OFFSET+9);
                gTopRightButtonText.render(gRenderer, SCREEN_WIDTH - gTopRightButton.getWidth(), Y_BUTTON_OFFSET+9);
                gBottomLeftButtonText.render(gRenderer, X_BUTTON_OFFSET+10, Y_BUTTON_OFFSET+gTopRightButton.getHeight()+14);
                gBottomRightButtonText.render(gRenderer, SCREEN_WIDTH - gTopRightButton.getWidth(),
                                              Y_BUTTON_OFFSET+gTopRightButton.getHeight()+14);


                //Update screen
                SDL_RenderPresent(gRenderer);
            }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}