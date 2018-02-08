//
// Created by angelica on 11/11/17.
//
#include <ctime>
#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>
#include <utility>
#include "../graphics/GTexture.h"
#include "../graphics/GProgressBar.h"
#include "../graphics/GButtonTexture.h"
#include "../model/BattleInstance.h"
#include "../utility/FileWriter.h"
#include "LargeMonMainView.h"



bool LargeMonMainView::init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );

        //Create window
        gWindow = SDL_CreateWindow("Largemon", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(gWindow == nullptr)
        {
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if(gRenderer == nullptr)
            {
                success = false;
            }
            else
            {
                if(( IMG_Init( IMG_INIT_PNG ) & IMG_INIT_PNG) == 0)
                {
                    success = false;
                }
                //Initialize SDL_ttf
                if(TTF_Init() == -1)
                {
                    success = false;
                }
            }
        }
    }
    return success;
}

bool LargeMonMainView::loadUI(GTexture & texture, string path){
    bool success = true;
    if( !texture.loadFromFile(gRenderer, std::move(path)) )
    {
        cout << "Failed to load Foo' texture image!\n";
        success = false;
    }
    return success;
}

bool LargeMonMainView::loadUIText(GTexture & texture, TTF_Font * font, std::string text){
    bool success = true;
    if( !texture.loadFont(gRenderer, font, text, textColor) )
    {
        cout << "Failed to load Foo' texture image!\n";
        success = false;
    }
    return success;
}

bool LargeMonMainView::loadMedia(vector<string> args)
{
    //Loading success flag
    bool success = true;
    textColor = { 0, 0, 0 };

    loadUI(gBackgroundTexture, "/home/angelica/Development/CLion/LargeMon/resources/ui/mountains.png");
    loadUI(gBottomTextPanel,"/home/angelica/Development/CLion/LargeMon/resources/ui/bottom_panel.bmp" );
    loadUI(gPlayerHpBarBG,"/home/angelica/Development/CLion/LargeMon/resources/ui/health_bar_bg.bmp" );
    loadUI(gPlayerHpBarFG,"/home/angelica/Development/CLion/LargeMon/resources/ui/health_bar_fg.bmp" );
    loadUI(gEnemyHpBarBG,"/home/angelica/Development/CLion/LargeMon/resources/ui/health_bar_bg.bmp" );
    loadUI(gEnemyHpBarFG,"/home/angelica/Development/CLion/LargeMon/resources/ui/health_bar_fg.bmp" );
    loadUI(gPlayerSpriteSheetTexture,args[3] );
    loadUI(gEnemySpriteSheetTexture,args[4] );
    //Load Button Textures
    loadUI(gTopLeftButton, "/home/angelica/Development/CLion/LargeMon/resources/ui/button.bmp");
    loadUI(gTopRightButton, "/home/angelica/Development/CLion/LargeMon/resources/ui/button.bmp");
    loadUI(gBottomLeftButton, "/home/angelica/Development/CLion/LargeMon/resources/ui/button.bmp");
    loadUI(gBottomRightButton, "/home/angelica/Development/CLion/LargeMon/resources/ui/button.bmp");
    gTopLeftButton.setColor(70, 70, 70);

    buttons[0] = gTopLeftButton;
    buttons[1] = gTopRightButton;
    buttons[2] = gBottomLeftButton;
    buttons[3] = gBottomRightButton;

    //Set bottom left sprite
    gSpriteClips[ 0 ].x = 0;
    gSpriteClips[ 0 ].y = 120;
    gSpriteClips[ 0 ].w = 120;
    gSpriteClips[ 0 ].h = 120;
    //Set top right sprite
    gSpriteClips[ 1 ].x = 2040;
    gSpriteClips[ 1 ].y = 120;
    gSpriteClips[ 1 ].w = 120;
    gSpriteClips[ 1 ].h = 120;

    //Load ttf pixel font large size
    gFont = TTF_OpenFont( "/home/angelica/Development/CLion/LargeMon/resources/fonts/alterebro-pixel-font.ttf", 30 );
    if( gFont == nullptr )
    {
        cout << "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError();
        success = false;
    } else {
        //Render text
        loadUIText(gTopLeftButtonText, gFont, "Attack");
        loadUIText(gTopRightButtonText, gFont, "Defend");
        loadUIText(gBottomLeftButtonText, gFont, "Special Attack");
        loadUIText(gBottomRightButtonText, gFont, "Special Attack");
        loadUIText(gPanelText, gFont, args[0]);
    }
    //Open ttf pixel font small size
    gHpFont = TTF_OpenFont( "/home/angelica/Development/CLion/LargeMon/resources/fonts/alterebro-pixel-font.ttf", 20 );
    if( gHpFont == nullptr )
    {
        cout << "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError();
        success = false;
    } else {
        loadUIText(gPlayerHealthText, gHpFont, args[1]);
        loadUIText(gEnemyHealthText, gHpFont, args[2]);
    }

    return success;
}

bool LargeMonMainView::updateText(string text)
{
    //SDL_Color textColor = { 0, 0, 0 };
    bool success = true;
    if( !loadUIText(gPanelText, gFont, text))
    {
        cout <<  "Failed to render text texture!\n";
        success = false;
    }
    render();
    return success;
}

/*
   color - Returns an SDL_Color with the appropriate values
*/
SDL_Color color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_Color col = {r,g,b,a};
    return col;
}

void LargeMonMainView::close()
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
    gFont = nullptr;

    //Free loaded image
    SDL_DestroyTexture( gTexture );
    gTexture = nullptr;

    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = nullptr;
    gRenderer = nullptr;

    //Quit SDL subsystems
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

bool LargeMonMainView::run(vector<string> args) {

//    SDL_Color col1 = color(0, 168, 107, 50);
//    SDL_Color col2 = color(188, 3, 107, 50);

    //Start up SDL and create window
    if (!init()) {
        cout << "Failed to initialize!\n";
    } else if (!loadMedia(std::move(args))) {
        cout << "Failed to load media!\n";
    } else {
            render();
    }

    return true;
}

void LargeMonMainView::updateButtons(int pressedButton) {
    //Not selected button colour
    Uint8 unslct = 255;

    //Selected button colour
    Uint8 slct = 70;

    for(int i = 0; i<4; i++){
        if(i!=pressedButton){
            buttons[i].setColor(unslct,unslct,unslct);
        }
    }
    buttons[pressedButton].setColor(slct, slct, slct);
    render();

}

void LargeMonMainView::updatePlayerHealthBar(float percent, string hp) {
    gPlayerHpBarFG.updateProgress(gRenderer, gPlayerHpBarFG, gHpFont, gPlayerHealthText, percent, std::move(hp));
    render();
}

void LargeMonMainView::updateEnemyHealthBar(float percent, string hp) {
    gEnemyHpBarFG.updateProgress(gRenderer, gEnemyHpBarFG, gHpFont, gEnemyHealthText, percent, std::move(hp));
    render();
}

bool LargeMonMainView::render() {
    SDL_RenderClear(gRenderer);
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    //Top viewport
    SDL_Rect topViewport{};
    topViewport.x = 0;
    topViewport.y = 0;
    topViewport.w = SCREEN_WIDTH;
    topViewport.h = SCREEN_HEIGHT;
    SDL_RenderSetViewport(gRenderer, &topViewport);


    //Render background texture to screen
    gBackgroundTexture.render(gRenderer, 0, 0);

    //Render player to the screen
    //gPlayerTexture.render(gRenderer, -20, 170);
    gPlayerSpriteSheetTexture.renderSprite(gRenderer, 20, 190, &gSpriteClips[0]);

    //Render enemy to the screen
    //gEnemyTexture.render(gRenderer, 430, 40);
    gEnemySpriteSheetTexture.renderSprite(gRenderer, 465, 125, &gSpriteClips[1]);

    gPlayerHpBarBG.render(gRenderer, 30, 300);
    gPlayerHpBarFG.render(gRenderer, 31, 301);
    gPlayerHealthText.render(gRenderer, 35,301);

    gEnemyHpBarBG.render(gRenderer, 480, 237);
    gEnemyHpBarFG.render(gRenderer, 481, 238);
    gEnemyHealthText.render(gRenderer, 485,238);

    //Bottom viewport
    SDL_Rect bottomViewport{};
    bottomViewport.x = 0;
    bottomViewport.y = static_cast<int>(SCREEN_HEIGHT / 1.4);
    bottomViewport.w = SCREEN_WIDTH;
    bottomViewport.h = SCREEN_HEIGHT / 3;
    SDL_RenderSetViewport(gRenderer, &bottomViewport);

    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    gBottomTextPanel.render(gRenderer, 10, 0);
    gPanelText.render(gRenderer,30, 10);

    int X_BUTTON_OFFSET = 270;
    int Y_BUTTON_OFFSET = 20;

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
