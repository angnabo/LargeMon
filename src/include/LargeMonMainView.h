//
// Created by angelica on 11/11/17.
//

#ifndef LARGEMON_LARGEMONMAINVIEW_H
#define LARGEMON_LARGEMONMAINVIEW_H


#include "GTexture.h"
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
    GTexture gPlayerTexture;
    GTexture gEnemyTexture;
    GTexture gBackgroundTexture;
    ButtonTexture gTopLeftButton;
    ButtonTexture gTopRightButton;
    ButtonTexture gBottomLeftButton;
    ButtonTexture gBottomRightButton;

    GTexture gBottomTextPanel;
    GTexture gBottomPanelFull;

    GTexture gPlayerHpBarBG;
    GTexture gPlayerHpBarFG;
    GTexture gPlayerHealthText;

    GTexture gEnemyHpBarBG;
    GTexture gEnemyHpBarFG;
    GTexture gEnemyHealthText;


    GTexture gTopLeftButtonText;
    GTexture gTopRightButtonText;
    GTexture gBottomLeftButtonText;
    GTexture gBottomRightButtonText;
    GTexture gPanelText;

    ButtonTexture buttons[4];
    SDL_Rect gSpriteClips[ 4 ];
    GTexture gSpriteSheetTexture;
    SDL_Texture* loadTexture( std::string path );
    SDL_Texture* gTexture = NULL;
};


#endif //LARGEMON_LARGEMONMAINVIEW_H
