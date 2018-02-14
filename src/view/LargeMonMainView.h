//
// Created by angelica on 11/11/17.
//

#ifndef LARGEMON_LARGEMONMAINVIEW_H
#define LARGEMON_LARGEMONMAINVIEW_H


#include "../graphics/GTexture.h"
#include "../graphics/GButtonTexture.h"
#include "../graphics/GProgressBar.h"
#include "../model/utility/FileWriter.h"

using namespace std;

class LargeMonMainView {
public:
    bool init();
    bool loadMedia(vector<string>);
    void close();
    bool updateText(string);
    void updateButtons(int);
    bool run(vector<string> args);
    void updatePlayerHealthBar(float, string);
    void updateEnemyHealthBar(float, string);
    bool loadUI(GTexture &, string);
    bool loadUIText(GTexture &, TTF_Font *, string);
    bool render();
private:
//Screen dimension constants
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    const int PANEL_FONT_SIZE = 30;
    const int HP_FONT_SIZE  = 27;
    //Unselected button colour
    Uint8 unslct = 255;
    //Selected button colour
    Uint8 slct = 70;

    int X_BUTTON_OFFSET = 270;
    int Y_BUTTON_OFFSET = 20;

//Globally used font
    TTF_Font *gFont = NULL;
    TTF_Font *gHpFont = NULL;

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

    GTexture gPlayerInfoPanel;
    GTexture gEnemyInfoPanel;

    GTexture gPlayerHpBarBG;
    GProgressBar gPlayerHpBarFG;
    GTexture gPlayerCurrentHPText;
    GTexture gPlayerHealthText;

    GTexture gEnemyHpBarBG;
    GProgressBar gEnemyHpBarFG;
    GTexture gEnemyHealthText;
    GTexture gEnemyCurrentHPText;

    GTexture gTopLeftButtonText;
    GTexture gTopRightButtonText;
    GTexture gBottomLeftButtonText;
    GTexture gBottomRightButtonText;
    GTexture gPanelText;

    GButtonTexture buttons[4];
    SDL_Rect gSpriteClips[ 2 ];
    GTexture gPlayerSpriteSheetTexture;
    GTexture gEnemySpriteSheetTexture;
    SDL_Texture* loadTexture( std::string path );
    SDL_Texture* gTexture = NULL;
    SDL_Color textColor;

};


#endif //LARGEMON_LARGEMONMAINVIEW_H
