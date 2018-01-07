//
// Created by angelica on 14/11/17.
//

#include "GProgressBar.h"


GProgressBar::GProgressBar()
        : GTexture() {

}

bool GProgressBar::updateProgress(SDL_Renderer * gRenderer, GTexture & bar, TTF_Font * gHpFont, GTexture & text, float percent, string hp) {

        SDL_Color textColor = { 0, 0, 0 };
        bool success = true;

        if( !text.loadFont( gRenderer, gHpFont, hp, textColor ) )
        {
            printf( "Failed to render text texture!\n" );
            success = false;
        }
        int pw = (int)((float)bar.getOriginalWidth() * percent);
        bar.setSize(pw,17);
        SDL_RenderPresent(gRenderer);
        return success;

}

