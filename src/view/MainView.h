//
// Created by angelica on 11/11/17.
//
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <ctime>
#include <string>
#include <iostream>
#include <utility>
#include "graphics/Texture.h"
#include "graphics/ProgressBar.h"
#include "../model/BattleInstance.h"
#include "../model/observer/FileWriter.h"
#include "graphics/Texture.h"
#include "graphics/ProgressBar.h"
#include "../model/observer/FileWriter.h"

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

    void loadUI(Texture &, string);

    void loadUIText(Texture &, TTF_Font *, string);

    bool render();

    void menuPanel(string);

    int buttonTextPosition(int, int);

    bool winnerText(string text);

    void updateSprites(Texture &sprite, string state, bool);

    void updateHealthBar(ProgressBar &bar, Texture &hpText, float percent, string hp);

    ProgressBar *getPlayerHealthbar() { return &gPlayerHpBarFG; }

    ProgressBar *getEnemyHealthbar() { return &gEnemyHpBarFG; }

    Texture *getPlayerHpText() { return &gPlayerCurrentHPText; }

    Texture *getEnemyHpText() { return &gEnemyCurrentHPText; }

    Texture *getPlayerSprite() { return &gPlayerSpriteSheetTexture; }

    Texture *getEnemySprite() { return &gEnemySpriteSheetTexture; }

    void attackAnimation();

private:
    //Screen dimensions
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    const int PANEL_FONT_SIZE = 30;
    const int HP_FONT_SIZE = 27;
    int X_LEFT_BTN_OFFSET = 270;//where the left hand-side buttons are on the x-axis
    int X_RIGHT_BTN_OFFSET = 454;//where the right hand-side buttons are on the x-axis
    int Y_BUTTON_OFFSET = 30;

    //Unselected button colour
    Uint8 unslct = 255;
    //Selected button colour
    Uint8 slct = 70;

    TTF_Font *gFont = NULL;
    TTF_Font *gHpFont = NULL;
    SDL_Window *gWindow = NULL;
    SDL_Renderer *renderer = NULL;
    Mix_Music *gMusic = NULL;
    SDL_Color textColor;

    //Textures
    Texture gPlayerTexture;
    Texture gEnemyTexture;
    Texture gBackgroundTexture;
    Texture gTopLeftButton;
    Texture gTopRightButton;
    Texture gBottomLeftButton;
    Texture gBottomRightButton;
    Texture gReplayBtn;
    Texture gExitBtn;
    Texture gReplayText;
    Texture gExitText;
    Texture gWinnerText;
    Texture gBottomTextPanel;
    Texture gMenuPanel;
    Texture gPlayerInfoPanel;
    Texture gEnemyInfoPanel;
    Texture gPlayerTypeIcon;
    Texture gEnemyTypeIcon;
    Texture gPlayerHpBarBG;
    ProgressBar gPlayerHpBarFG;
    Texture gPlayerCurrentHPText;
    Texture gPlayerHealthText;
    Texture gEnemyHpBarBG;
    ProgressBar gEnemyHpBarFG;
    Texture gEnemyHealthText;
    Texture gEnemyCurrentHPText;
    Texture gTopLeftButtonText;
    Texture gTopRightButtonText;
    Texture gBottomLeftButtonText;
    Texture gBottomRightButtonText;
    Texture gPanelText;
    Texture buttons[4];
    SDL_Rect gSpriteClips[2];
    Texture gPlayerSpriteSheetTexture;
    Texture gEnemySpriteSheetTexture;
    Texture gEnemyAttackPoints;
    Texture gPlayerAttackPoints;
    Texture gPlayerShieldSprite;
    Texture gEnemyShieldSprite;
    Texture gPlayerIgniteSprite;
    Texture gEnemyIgniteSprite;
    Texture gPlayerStunnedSprite;
    Texture gEnemyStunnedSprite;
    Texture gDot;
};

#endif //LARGEMON_LARGEMONMAINVIEW_H
