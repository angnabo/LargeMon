//
// Created by angelica on 11/11/17.
//

#ifndef LARGEMON_LARGEMONMAINVIEW_H
#define LARGEMON_LARGEMONMAINVIEW_H


#include "LTexture.h"
#include "ButtonTexture.h"

using namespace std;

class LargeMonMainView {
private:
    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

//The window renderer
    SDL_Renderer* gRenderer = NULL;

//Bottom Panel Text
    string panelTextString;

    SDL_Color col1;
    SDL_Color col2;

//Scene textures
    LTexture gPlayerTexture;
    LTexture gEnemyTexture;
    LTexture gBackgroundTexture;
    ButtonTexture gTopLeftButton;
    ButtonTexture gTopRightButton;
    ButtonTexture gBottomLeftButton;
    ButtonTexture gBottomRightButton;

    LTexture gBottomTextPanel;
    LTexture gBottomPanelFull;

    LTexture gPlayerHpBarBG;
    LTexture gPlayerHpBarFG;
    LTexture gPlayerHealthText;

    LTexture gEnemyHpBarBG;
    LTexture gEnemyHpBarFG;
    LTexture gEnemyHealthText;


    LTexture gTopLeftButtonText;
    LTexture gTopRightButtonText;
    LTexture gBottomLeftButtonText;
    LTexture gBottomRightButtonText;
    LTexture gPanelText;

    ButtonTexture buttons[4];
    SDL_Rect gSpriteClips[ 4 ];
    LTexture gSpriteSheetTexture;
    SDL_Texture* loadTexture( std::string path );
    SDL_Texture* gTexture = NULL;
};


#endif //LARGEMON_LARGEMONMAINVIEW_H
