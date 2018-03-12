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
#include "graphics/GTexture.h"
#include "graphics/GProgressBar.h"
#include "../model/BattleInstance.h"
#include "../model/utility/FileWriter.h"
#include "graphics/GTexture.h"
#include "graphics/GProgressBar.h"
#include "../model/utility/FileWriter.h"

#ifndef LARGEMON_LARGEMONMAINVIEW_H
#define LARGEMON_LARGEMONMAINVIEW_H

using namespace std;

class LargemonMainView {
public:
    bool init();

    bool loadMedia(vector<string>);

    void close();

    bool updateText(string);

    void updateButtons(int);

    void updateMenuButtons(int);

    bool run(vector<string> args);

    void updatePlayerHealthBar(float, string);

    void updateEnemyHealthBar(float, string);

    bool loadUI(GTexture &, string);

    bool loadUIText(GTexture &, TTF_Font *, string);

    bool render();

    void menuPanel(string);

    int buttonTextPosition(int, int);

    bool winnerText(string text);

private:
    //Screen dimensions
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    const int PANEL_FONT_SIZE = 30;
    const int HP_FONT_SIZE = 27;

    //Unselected button colour
    Uint8 unslct = 255;
    //Selected button colour
    Uint8 slct = 70;

    int X_LEFT_BTN_OFFSET = 270;//where the left hand-side buttons are on the x-axis
    int X_RIGHT_BTN_OFFSET = 454;//where the right hand-side buttons are on the x-axis
    int Y_BUTTON_OFFSET = 30;

    int BUTTON_WIDTH = 174;
    int SMALL_BUTTON_WIDTH = 140;

    //Globally used font
    TTF_Font *gFont = NULL;
    TTF_Font *gHpFont = NULL;

    //The window
    SDL_Window *gWindow = NULL;

    //The window renderer
    SDL_Renderer *gRenderer = NULL;

    //Textures
    GTexture gPlayerTexture;
    GTexture gEnemyTexture;
    GTexture gBackgroundTexture;
    GTexture gTopLeftButton;
    GTexture gTopRightButton;
    GTexture gBottomLeftButton;
    GTexture gBottomRightButton;
    GTexture gReplayBtn;
    GTexture gExitBtn;
    GTexture gReplayText;
    GTexture gExitText;
    GTexture gWinnerText;
    GTexture gBottomTextPanel;
    GTexture gMenuPanel;
    GTexture gPlayerInfoPanel;
    GTexture gEnemyInfoPanel;
    GTexture gPlayerTypeIcon;
    GTexture gEnemyTypeIcon;
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
    GTexture buttons[4];
    SDL_Rect gSpriteClips[2];
    GTexture gPlayerSpriteSheetTexture;
    GTexture gEnemySpriteSheetTexture;

    SDL_Texture *gTexture = NULL;
    SDL_Color textColor;
};
#endif //LARGEMON_LARGEMONMAINVIEW_H
