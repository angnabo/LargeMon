//
// Created by angelica on 14/11/17.
//

#include "ProgressBar.h"

ProgressBar::ProgressBar()
        : Texture() {

}

bool ProgressBar::updateProgress(SDL_Renderer *gRenderer, Texture &bar, TTF_Font *gHpFont, Texture &text, float percent,
                             string hp) {
    SDL_Color textColor = {0, 0, 0};
    bool success = true;
    string padding;
    if (stoi(hp) < 100) {
        padding = " ";
    }
    if (stoi(hp) < 10) {
        padding = "  ";
    }
    if (!text.loadFont(gRenderer, gHpFont, padding + hp, textColor)) {
        cout << "Failed to render text texture!\n";
        success = false;
    }
    int pw = (int) ((float) bar.getOriginalWidth() * percent);
    bar.setSize(pw, 17);
    SDL_RenderPresent(gRenderer);
    return success;
}

