/**
 * The main view for the largmeon game
 *
 * Created by angelica on 11/11/17.
 */

#include "MainView.h"

/**
 * Initialise the window and SDL
 * @return
 */
bool LargemonMainView::init() {
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        success = false;
    } else {
        if (Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640) < 0) {
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
            renderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (renderer == nullptr) {
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

/**
 * Load a Texture
 * @param texture
 * @param path
 * @return
 */
void LargemonMainView::loadUI(Texture &texture, string path) {
    if (!texture.loadFromFile(renderer, std::move(path))) {
        cout << "Failed to load texture image!\n";
    }
}

/**
 * Load a TTF font
 * @param texture to which to load
 * @param font ttf font to use
 * @param text to create
 * @return success
 */
void LargemonMainView::loadUIText(Texture &texture, TTF_Font *font, std::string text) {
    if (!texture.loadFont(renderer, font, text, textColor)) {
        cout << "Failed to load text!\n";
    }
}

/**
 * Load textures, fonts and music
 * @param args
 * @return
 */
bool LargemonMainView::loadMedia(vector<string> args) {
    bool success = true;
    textColor = {0, 0, 0};

    // load ui components
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
    loadUI(gDot, "../resources/ui/dot.png");

    //load music
    gMusic = Mix_LoadMUS("../resources/sound/Rolemusic-02-Leafless-Quince-Tree.mp3");
    if (gMusic == NULL) {
        cout << "Failed to load music! SDL_mixer Error: %s\n" << Mix_GetError();
        success = false;
    }

    // play the music
    Mix_PlayMusic(gMusic, -1);
    // set volume to 1/8 of max volume
    Mix_VolumeMusic(MIX_MAX_VOLUME/8);

    //set buffs/debuffs to hidden
    gPlayerShieldSprite.setHidden(true);
    gEnemyShieldSprite.setHidden(true);
    gPlayerIgniteSprite.setHidden(true);
    gEnemyIgniteSprite.setHidden(true);
    gPlayerStunnedSprite.setHidden(true);
    gEnemyStunnedSprite.setHidden(true);

    //set blend mode for shield
    gPlayerShieldSprite.setBlendMode(SDL_BLENDMODE_BLEND);
    gPlayerShieldSprite.setAlpha(100);
    gEnemyShieldSprite.setBlendMode(SDL_BLENDMODE_BLEND);
    gEnemyShieldSprite.setAlpha(100);

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
        cout << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << endl;
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
        cout << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << endl;
        success = false;
    } else {
        loadUIText(gPlayerHealthText, gHpFont, "/" + args[1]);
        loadUIText(gEnemyHealthText, gHpFont, "/" + args[2]);
        loadUIText(gPlayerCurrentHPText, gHpFont, args[1]);
        loadUIText(gEnemyCurrentHPText, gHpFont, args[2]);
        loadUIText(gPlayerAttackPoints, gHpFont, "Dmg: " + args[9]);
        loadUIText(gEnemyAttackPoints, gHpFont, "Dmg: " + args[10]);
    }
    return success;
}

/**
 * Free loaded textures
 */
void LargemonMainView::close() {
    // free textures
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
    gEnemyAttackPoints.free();
    gPlayerAttackPoints.free();
    gPlayerShieldSprite.free();
    gEnemyShieldSprite.free();
    gPlayerIgniteSprite.free();
    gEnemyIgniteSprite.free();
    gPlayerStunnedSprite.free();
    gEnemyStunnedSprite.free();
    gDot.free();


    Mix_CloseAudio();

    Mix_FreeMusic(gMusic);
    gMusic = nullptr;

    TTF_CloseFont(gFont);
    gFont = nullptr;

    //Destroy window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    renderer = nullptr;

    //Quit SDL subsystems
    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

/**
 * Run the view
 * @param args
 * @return
 */
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

/**
 * Render a menu panel with play again/exit buttons
 * @param text
 */
void LargemonMainView::menuPanel(string text) {
    //Top viewport
    SDL_Rect topViewport{};
    topViewport.x = 0;
    topViewport.y = 0;
    topViewport.w = SCREEN_WIDTH;
    topViewport.h = SCREEN_HEIGHT;
    SDL_RenderSetViewport(renderer, &topViewport);

    gMenuPanel.render(renderer, 180, 100);

    // winner text
    winnerText(text);
    int winnerTextPos = buttonTextPosition(gMenuPanel.getWidth(), gWinnerText.getWidth());
    gWinnerText.render(renderer, 180 + winnerTextPos, 120);

    // buttons
    gReplayBtn.render(renderer, 200, 200);
    gExitBtn.render(renderer, 350, 200);

    int playAgainTxtPos = 200 + buttonTextPosition(gReplayBtn.getWidth(), gReplayText.getWidth());
    int exitTxtPos = 350 + buttonTextPosition(gExitBtn.getWidth(), gExitText.getWidth());

    gReplayText.render(renderer, playAgainTxtPos, 210);
    gExitText.render(renderer, exitTxtPos, 210);

    SDL_RenderPresent(renderer);
}

bool LargemonMainView::updateText(string text) {
    loadUIText(gPanelText, gFont, text);
    render();
}

bool LargemonMainView::winnerText(string text) {
    loadUIText(gWinnerText, gFont, text);
}


/**
 * Colour the selected button and un-colour the un-selected buttons
 * @param pressedButton
 */
void LargemonMainView::updateButtons(int pressedButton) {

    for (int i = 0; i < 4; i++) {
        if (i != pressedButton) {
            buttons[i].setColor(unslct, unslct, unslct);
        }
    }
    buttons[pressedButton].setColor(slct, slct, slct);
    render();
}

/**
 * Colour the selected button and un-colour the un-selected buttons in the menu
 * @param pressedButton
 */
void LargemonMainView::updateMenuButtons(int pressedButton) {
    if (pressedButton == 0) {
        gExitBtn.setColor(unslct, unslct, unslct);
        gReplayBtn.setColor(slct, slct, slct);
    } else {
        gReplayBtn.setColor(unslct, unslct, unslct);
        gExitBtn.setColor(slct, slct, slct);
    }
}

/**
 * Calculates the position in pixels to centre the given text on a button
 * @param btnWidth button width
 * @param txtWidth  text width
 * @return
 */
int LargemonMainView::buttonTextPosition(int btnWidth, int txtWidth) {
    int buttonWidth = btnWidth;
    int textWidth = txtWidth;
    int offset = (buttonWidth - textWidth) / 2;
    return offset;
}

/**
 * Update buffs/debuffs on largemon
 * @param sprite to update
 * @param state buff or bebuff
 * @param isPlayer
 */
void LargemonMainView::updateSprites(Texture &sprite, string state, bool isPlayer) {
    if (state != "normal") {
        if (state == "stunned") {
            if (isPlayer) {
                gPlayerStunnedSprite.setHidden(false);
            } else {
                gEnemyStunnedSprite.setHidden(false);
            }
        }
        if (state == "shielded") {
            if (isPlayer) {
                gPlayerShieldSprite.setHidden(false);
            } else {
                gEnemyShieldSprite.setHidden(false);
            }
        }
        if (state == "tick") {
            if (isPlayer) {
                gPlayerIgniteSprite.setHidden(false);
            } else {
                gEnemyIgniteSprite.setHidden(false);
            }
        }
    } else {
        if (isPlayer) {
            gPlayerShieldSprite.setHidden(true);
            gPlayerIgniteSprite.setHidden(true);
            gPlayerStunnedSprite.setHidden(true);
        } else {
            gEnemyShieldSprite.setHidden(true);
            gEnemyIgniteSprite.setHidden(true);
            gEnemyStunnedSprite.setHidden(true);
        }
    }
}

/**
 * Updates the health bar by calling the ProgressBar's method
 * @param bar
 * @param hpText
 * @param percent
 * @param hp
 */
void LargemonMainView::updateHealthBar(ProgressBar &bar, Texture &hpText, float percent, string hp) {
    bar.updateProgress(renderer, bar, gHpFont, hpText, percent, std::move(hp));
    render();
}

/**
 * Renders the textures to screen
 * @return
 */
bool LargemonMainView::render() {
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    //Top viewport
    SDL_Rect topViewport{};
    topViewport.x = 0;
    topViewport.y = 0;
    topViewport.w = SCREEN_WIDTH;
    topViewport.h = SCREEN_HEIGHT;
    SDL_RenderSetViewport(renderer, &topViewport);

    //Render background texture to screen
    gBackgroundTexture.render(renderer, 0, 0);

    //Render info panels
    gPlayerInfoPanel.render(renderer, 30, 170);
    gEnemyInfoPanel.render(renderer, 390, 90);

    //Render player to the screen
    gPlayerSpriteSheetTexture.renderSprite(renderer, 60, 200, &gSpriteClips[0]);

    //Render enemy to the screen
    gEnemySpriteSheetTexture.renderSprite(renderer, 430, 115, &gSpriteClips[1]);

    //Render information panel content
    gPlayerHpBarBG.render(renderer, 44, 180);
    gPlayerHpBarFG.render(renderer, 46, 182);

    gPlayerCurrentHPText.render(renderer, 48, 200);
    gPlayerHealthText.render(renderer, 72, 200);

    gEnemyHpBarBG.render(renderer, 404, 100);
    gEnemyHpBarFG.render(renderer, 406, 102);

    gEnemyCurrentHPText.render(renderer, 408, 120);
    gEnemyHealthText.render(renderer, 432, 120);

    gPlayerTypeIcon.render(renderer, 44, 137);
    gEnemyTypeIcon.render(renderer, 404, 57);

    gPlayerAttackPoints.render(renderer, 153, 200);
    gEnemyAttackPoints.render(renderer, 510, 120);

    //Render shield/bubble/ignite if not hidden
    if (!gPlayerShieldSprite.isHidden()) {
        gPlayerShieldSprite.render(renderer, 60, 200);
    }
    if (!gEnemyShieldSprite.isHidden()) {
        gEnemyShieldSprite.render(renderer, 430, 115);
    }

    if (!gPlayerIgniteSprite.isHidden()) {
        gPlayerIgniteSprite.render(renderer, 60, 200);
    }
    if (!gEnemyIgniteSprite.isHidden()) {
        gEnemyIgniteSprite.render(renderer, 430, 115);
    }

    if (!gPlayerStunnedSprite.isHidden()) {
        gPlayerStunnedSprite.render(renderer, 60, 200);
    }
    if (!gEnemyStunnedSprite.isHidden()) {
        gEnemyStunnedSprite.render(renderer, 435, 115);
    }

    //Bottom viewport
    SDL_Rect bottomViewport{};
    bottomViewport.x = 0;
    bottomViewport.y = static_cast<int>(SCREEN_HEIGHT / 1.5);
    bottomViewport.w = SCREEN_WIDTH;
    bottomViewport.h = SCREEN_HEIGHT / 3;
    SDL_RenderSetViewport(renderer, &bottomViewport);

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    gBottomTextPanel.render(renderer, 10, 0);
    gPanelText.render(renderer, 30, 10);

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
    gTopLeftButton.render(renderer, X_LEFT_BTN_OFFSET, Y_BUTTON_OFFSET);
    gTopRightButton.render(renderer, X_RIGHT_BTN_OFFSET, Y_BUTTON_OFFSET);
    gBottomLeftButton.render(renderer, X_LEFT_BTN_OFFSET, Y_BUTTON_OFFSET + gTopRightButton.getHeight() + 5);
    gBottomRightButton.render(renderer, X_RIGHT_BTN_OFFSET, Y_BUTTON_OFFSET + gTopRightButton.getHeight() + 5);
    //render button text
    gTopLeftButtonText.render(renderer, topLeftBtnTxtPos, Y_BUTTON_OFFSET + 9);
    gTopRightButtonText.render(renderer, topRightBtnTxtPos, Y_BUTTON_OFFSET + 9);
    gBottomLeftButtonText.render(renderer, bottomLeftBtnTxtPos, Y_BUTTON_OFFSET + gTopRightButton.getHeight() + 14);
    gBottomRightButtonText.render(renderer, bottomRightBtnTxtPos, Y_BUTTON_OFFSET + gTopRightButton.getHeight() + 14);

    //Update screen
    SDL_RenderPresent(renderer);
}


