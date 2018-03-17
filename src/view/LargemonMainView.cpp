//
// Created by angelica on 11/11/17.
//
#include "LargemonMainView.h"

bool LargemonMainView::init() {
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        success = false;
    } else {

        if( Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640) < 0 )
        {
            cout << "SDL_mixer could not initialize! SDL_mixer Error: %s\n" << Mix_GetError();
            success = false;
        }
        //Set texture filtering to linear
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

        //Create window
        gWindow = SDL_CreateWindow("Largemon", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                   SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == nullptr) {
            success = false;
        } else {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (gRenderer == nullptr) {
                success = false;
            } else {
                if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) == 0) {
                    success = false;
                }
                //Initialize SDL_ttf
                if (TTF_Init() == -1) {
                    success = false;
                }
            }
        }
    }
    return success;
}


bool LargemonMainView::loadUI(GTexture &texture, string path) {
    bool success = true;
    if (!texture.loadFromFile(gRenderer, std::move(path))) {
        cout << "Failed to load texture image!\n";
        success = false;
    }
    return success;
}

bool LargemonMainView::loadUIText(GTexture &texture, TTF_Font *font, std::string text) {
    bool success = true;
    if (!texture.loadFont(gRenderer, font, text, textColor)) {
        cout << "Failed to load font texture image!\n";
        success = false;
    }
    return success;
}

bool LargemonMainView::loadMedia(vector<string> args) {
    //Loading success flag
    bool success = true;
    textColor = {0, 0, 0};

    loadUI(gBackgroundTexture, "../resources/ui/mountains.png");
    loadUI(gBottomTextPanel, "../resources/ui/bottom_panel_big.png");
    loadUI(gPlayerInfoPanel, "../resources/ui/info_panel.png");
    loadUI(gEnemyInfoPanel, "../resources/ui/info_panel.png");
    loadUI(gPlayerHpBarBG, "../resources/ui/health_bar_bg.bmp");
    loadUI(gPlayerHpBarFG, "../resources/ui/health_bar_fg.bmp");
    loadUI(gEnemyHpBarBG, "../resources/ui/health_bar_bg.bmp");
    loadUI(gEnemyHpBarFG, "../resources/ui/health_bar_fg.bmp");
    loadUI(gMenuPanel, "../resources/ui/menu_panel.png");
    loadUI(gPlayerShieldSprite, "../resources/ui/shield_sprite.png");
    loadUI(gEnemyShieldSprite, "../resources/ui/shield_sprite.png");
    loadUI(gPlayerIgniteSprite, "../resources/ui/ignite_sprite.png");
    loadUI(gEnemyIgniteSprite, "../resources/ui/ignite_sprite.png");
    loadUI(gPlayerStunnedSprite, "../resources/ui/stunned_sprite.png");
    loadUI(gEnemyStunnedSprite, "../resources/ui/stunned_sprite.png");

    gMusic = Mix_LoadMUS("../resources/sound/Rolemusic-02-Leafless-Quince-Tree.mp3");
    if( gMusic == NULL )
    {
        cout << "Failed to load beat music! SDL_mixer Error: %s\n"<< Mix_GetError() ;
        success = false;
    }

    if( Mix_PlayingMusic() == 0 )
    {

        Mix_PlayMusic( gMusic, -1 );
    }
    Mix_ResumeMusic();

    gPlayerShieldSprite.setHidden(true);
    gEnemyShieldSprite.setHidden(true);
    gPlayerShieldSprite.setBlendMode(SDL_BLENDMODE_BLEND);
    gPlayerShieldSprite.setAlpha(100);
    gEnemyShieldSprite.setBlendMode(SDL_BLENDMODE_BLEND);
    gEnemyShieldSprite.setAlpha(100);

    gPlayerIgniteSprite.setHidden(true);
    gEnemyIgniteSprite.setHidden(true);
    gPlayerStunnedSprite.setHidden(true);
    gEnemyStunnedSprite.setHidden(true);


    loadUI(gPlayerSpriteSheetTexture, args[3]);
    loadUI(gEnemySpriteSheetTexture, args[4]);

    loadUI(gPlayerTypeIcon, args[5]);
    loadUI(gEnemyTypeIcon, args[6]);

    //Load Button Textures
    loadUI(gTopLeftButton, "../resources/ui/button.png");
    loadUI(gTopRightButton, "../resources/ui/button.png");
    loadUI(gBottomLeftButton, "../resources/ui/button.png");
    loadUI(gBottomRightButton, "../resources/ui/button.png");
    gTopLeftButton.setColor(70, 70, 70);

    loadUI(gReplayBtn, "../resources/ui/small_button.png");
    loadUI(gExitBtn, "../resources/ui/small_button.png");
    gReplayBtn.setColor(70, 70, 70);

    buttons[0] = gTopLeftButton;
    buttons[1] = gTopRightButton;
    buttons[2] = gBottomLeftButton;
    buttons[3] = gBottomRightButton;

    //Set bottom left sprite
    gSpriteClips[0].x = 0;
    gSpriteClips[0].y = 120;
    gSpriteClips[0].w = 120;
    gSpriteClips[0].h = 120;
    //Set top right sprite
    gSpriteClips[1].x = 2040;
    gSpriteClips[1].y = 120;
    gSpriteClips[1].w = 120;
    gSpriteClips[1].h = 120;

    //Load ttf pixel font large size
    gFont = TTF_OpenFont("../resources/fonts/alterebro-pixel-font.ttf", PANEL_FONT_SIZE);
    if (gFont == nullptr) {
        cout << "Failed to load lazy font! SDL_ttf Error: " << TTF_GetError() << endl;
        success = false;
    } else {
        //Render text
        loadUIText(gTopLeftButtonText, gFont, "Attack");
        loadUIText(gTopRightButtonText, gFont, "Defend");
        loadUIText(gBottomLeftButtonText, gFont, args[7]);
        loadUIText(gBottomRightButtonText, gFont, args[8]);
        loadUIText(gPanelText, gFont, args[0]);
        loadUIText(gReplayText, gFont, "Play again");
        loadUIText(gExitText, gFont, "Exit");
    }
    //Open ttf pixel font small size
    gHpFont = TTF_OpenFont("../resources/fonts/alterebro-pixel-font.ttf", HP_FONT_SIZE);
    if (gHpFont == nullptr) {
        cout << "Failed to load lazy font! SDL_ttf Error: " << TTF_GetError() << endl;
        success = false;
    } else {
        loadUIText(gPlayerHealthText, gHpFont, "/" + args[1]);
        loadUIText(gEnemyHealthText, gHpFont, "/" + args[2]);
        loadUIText(gPlayerCurrentHPText, gHpFont, args[1]);
        loadUIText(gEnemyCurrentHPText, gHpFont, args[2]);
        loadUIText(gPlayerAttackPoints, gHpFont, "Dmg: " + args[9]);
        loadUIText(gEnemyAttackPoints, gHpFont, "Dmg: "+ args[10]);
    }
    return success;
}

void LargemonMainView::close() {

    gPlayerTexture.free();
    gEnemyTexture.free();

    gBackgroundTexture.free();

    gTopLeftButton.free();
    gTopRightButton.free();
    gBottomLeftButton.free();
    gBottomRightButton.free();

    gReplayBtn.free();
    gExitBtn.free();

    gReplayText.free();
    gExitText.free();

    gWinnerText.free();

    gBottomTextPanel.free();
    gMenuPanel.free();
    gPlayerInfoPanel.free();
    gEnemyInfoPanel.free();

    gPlayerTypeIcon.free();
    gEnemyTypeIcon.free();

    gPlayerHpBarBG.free();
    gPlayerHpBarFG.free();
    gPlayerCurrentHPText.free();
    gPlayerHealthText.free();

    gEnemyHpBarBG.free();
    gEnemyHpBarFG.free();
    gEnemyHealthText.free();
    gEnemyCurrentHPText.free();

    gTopLeftButtonText.free();
    gTopRightButtonText.free();
    gBottomLeftButtonText.free();
    gBottomRightButtonText.free();
    gPanelText.free();

    gPlayerSpriteSheetTexture.free();
    gEnemySpriteSheetTexture.free();

    Mix_FreeMusic(gMusic);

    //Free global font
    TTF_CloseFont(gFont);
    gFont = nullptr;

    //Free loaded image
    SDL_DestroyTexture(gTexture);
    gTexture = nullptr;

    //Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    gRenderer = nullptr;

    //Quit SDL subsystems
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

bool LargemonMainView::run(vector<string> args) {
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

void LargemonMainView::menuPanel(string text) {
    //Top viewport
    SDL_Rect topViewport{};
    topViewport.x = 0;
    topViewport.y = 0;
    topViewport.w = SCREEN_WIDTH;
    topViewport.h = SCREEN_HEIGHT;
    SDL_RenderSetViewport(gRenderer, &topViewport);

    gMenuPanel.render(gRenderer, 180, 100);
    winnerText(text);
    gWinnerText.render(gRenderer, 200, 120);

    gReplayBtn.render(gRenderer, 200, 200);
    gExitBtn.render(gRenderer, 350, 200);

    int playAgainTxtPos = 200 + buttonTextPosition(gReplayBtn.getWidth(), gReplayText.getWidth());
    int exitTxtPos = 350 + buttonTextPosition(gExitBtn.getWidth(), gExitText.getWidth());

    gReplayText.render(gRenderer, playAgainTxtPos, 210);
    gExitText.render(gRenderer, exitTxtPos, 210);

    SDL_RenderPresent(gRenderer);
}

bool LargemonMainView::updateText(string text) {
    bool success = true;
    if (!loadUIText(gPanelText, gFont, text)) {
        cout << "Failed to render text texture!\n";
        success = false;
    }
    render();
    return success;
}

bool LargemonMainView::winnerText(string text) {
    bool success = true;
    if (!loadUIText(gWinnerText, gFont, text)) {
        cout << "Failed to render text texture!\n";
        success = false;
    }
    return success;
}

void LargemonMainView::updateButtons(int pressedButton) {

    for (int i = 0; i < 4; i++) {
        if (i != pressedButton) {
            buttons[i].setColor(unslct, unslct, unslct);
        }
    }
    buttons[pressedButton].setColor(slct, slct, slct);
    render();
}

void LargemonMainView::updateMenuButtons(int pressedButton) {
    if (pressedButton == 0) {
        gExitBtn.setColor(unslct, unslct, unslct);
        gReplayBtn.setColor(slct, slct, slct);
    } else {
        gReplayBtn.setColor(unslct, unslct, unslct);
        gExitBtn.setColor(slct, slct, slct);
    }
}

int LargemonMainView::buttonTextPosition(int btnWidth, int txtWidth) {
    int buttonWidth = btnWidth;
    int textWidth = txtWidth;
    int offset = (buttonWidth - textWidth) / 2;
    return offset;
}

void LargemonMainView::updateSprites(GTexture & sprite, string state, bool isPlayer){
    if(state != "normal"){
        if(state == "stunned"){
            if(isPlayer){
                gPlayerStunnedSprite.setHidden(false);
            } else {
                gEnemyStunnedSprite.setHidden(false);
            }
        }
        if(state == "shielded") {
            if(isPlayer){
                gPlayerShieldSprite.setHidden(false);
            } else {
                gEnemyShieldSprite.setHidden(false);
            }
        }
        if(state == "tick"){
            //sprite.setColor(125, 255, 255);
            if(isPlayer){
                gPlayerIgniteSprite.setHidden(false);
            } else {
                gEnemyIgniteSprite.setHidden(false);
            }
        }
    } else {
        //sprite.setColor(255,255,255);
        if(isPlayer){
            gPlayerShieldSprite.setHidden(true);
            gPlayerIgniteSprite.setHidden(true);
            gPlayerStunnedSprite.setHidden(true);
        } else {
            gEnemyShieldSprite.setHidden(true);
            gEnemyIgniteSprite.setHidden(true);
            gEnemyStunnedSprite.setHidden(true);
        }
    }
    //SDL_RenderPresent(gRenderer);
}

void LargemonMainView::updateHealthBar(GProgressBar & bar, GTexture & hpText, float percent, string hp) {
    bar.updateProgress(gRenderer, bar, gHpFont, hpText, percent, std::move(hp));
    render();
}

bool LargemonMainView::render() {
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

    gPlayerInfoPanel.render(gRenderer, 30, 170);

    gEnemyInfoPanel.render(gRenderer, 390, 90);

    //Render player to the screen
    gPlayerSpriteSheetTexture.renderSprite(gRenderer, 60, 200, &gSpriteClips[0]);
    gPlayerSpriteSheetTexture.setPosition(60, 200);

    //Render enemy to the screen
    gEnemySpriteSheetTexture.renderSprite(gRenderer, 430, 115, &gSpriteClips[1]);
    gEnemySpriteSheetTexture.setPosition(430, 115);

    // render information panel content
    gPlayerHpBarBG.render(gRenderer, 44, 180);
    gPlayerHpBarFG.render(gRenderer, 46, 182);

    gPlayerCurrentHPText.render(gRenderer, 48, 200);
    gPlayerHealthText.render(gRenderer, 72, 200);

    gEnemyHpBarBG.render(gRenderer, 404, 100);
    gEnemyHpBarFG.render(gRenderer, 406, 102);

    gEnemyCurrentHPText.render(gRenderer, 408, 120);
    gEnemyHealthText.render(gRenderer, 432, 120);

    gPlayerTypeIcon.render(gRenderer, 44, 137);
    gEnemyTypeIcon.render(gRenderer, 404, 57);

    gPlayerAttackPoints.render(gRenderer, 153, 200);
    gEnemyAttackPoints.render(gRenderer, 510, 120);

    //gShieldSprite.render(gRenderer, 60, 200);

    //gShieldSprite.render(gRenderer, 400, 200);

    if(!gPlayerShieldSprite.isHidden()){
        gPlayerShieldSprite.render(gRenderer, 60, 200);
    }
    if(!gEnemyShieldSprite.isHidden()){
        gEnemyShieldSprite.render(gRenderer, 430, 115);
    }

    if(!gPlayerIgniteSprite.isHidden()){
        gPlayerIgniteSprite.render(gRenderer, 60, 200);
    }
    if(!gEnemyIgniteSprite.isHidden()){
        gEnemyIgniteSprite.render(gRenderer, 430, 115);
    }

    if(!gPlayerStunnedSprite.isHidden()){
        gPlayerStunnedSprite.render(gRenderer, 60, 200);
    }
    if(!gEnemyStunnedSprite.isHidden()){
        gEnemyStunnedSprite.render(gRenderer, 435, 115);
    }

    //Bottom viewport
    SDL_Rect bottomViewport{};
    bottomViewport.x = 0;
    bottomViewport.y = static_cast<int>(SCREEN_HEIGHT / 1.5);
    bottomViewport.w = SCREEN_WIDTH;
    bottomViewport.h = SCREEN_HEIGHT / 3;
    SDL_RenderSetViewport(gRenderer, &bottomViewport);

    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    gBottomTextPanel.render(gRenderer, 10, 0);
    gPanelText.render(gRenderer, 30, 10);

    //calculate the x-positions of button text
    int topLeftBtnTxtPos =
            X_LEFT_BTN_OFFSET + buttonTextPosition(gTopRightButton.getWidth(), gTopLeftButtonText.getWidth());
    int topRightBtnTxtPos =
            X_RIGHT_BTN_OFFSET + buttonTextPosition(gTopRightButton.getWidth(), gTopRightButtonText.getWidth());
    int bottomLeftBtnTxtPos =
            X_LEFT_BTN_OFFSET + buttonTextPosition(gTopRightButton.getWidth(), gBottomLeftButtonText.getWidth());
    int bottomRightBtnTxtPos =
            X_RIGHT_BTN_OFFSET + buttonTextPosition(gTopRightButton.getWidth(), gBottomRightButtonText.getWidth());
    //render buttons
    gTopLeftButton.render(gRenderer, X_LEFT_BTN_OFFSET, Y_BUTTON_OFFSET);
    gTopRightButton.render(gRenderer, X_RIGHT_BTN_OFFSET, Y_BUTTON_OFFSET);
    gBottomLeftButton.render(gRenderer, X_LEFT_BTN_OFFSET, Y_BUTTON_OFFSET + gTopRightButton.getHeight() + 5);
    gBottomRightButton.render(gRenderer, X_RIGHT_BTN_OFFSET, Y_BUTTON_OFFSET + gTopRightButton.getHeight() + 5);
    //render button text
    gTopLeftButtonText.render(gRenderer, topLeftBtnTxtPos, Y_BUTTON_OFFSET + 9);
    gTopRightButtonText.render(gRenderer, topRightBtnTxtPos, Y_BUTTON_OFFSET + 9);
    gBottomLeftButtonText.render(gRenderer, bottomLeftBtnTxtPos, Y_BUTTON_OFFSET + gTopRightButton.getHeight() + 14);
    gBottomRightButtonText.render(gRenderer, bottomRightBtnTxtPos, Y_BUTTON_OFFSET + gTopRightButton.getHeight() + 14);

    //Update screen
    SDL_RenderPresent(gRenderer);
}


