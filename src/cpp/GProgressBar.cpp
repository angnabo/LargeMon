//
// Created by angelica on 14/11/17.
//

#include "../include/GProgressBar.h"


GProgressBar::GProgressBar()
        : GTexture() {

}

bool GProgressBar::updateProgress(SDL_Renderer * gRenderer, GTexture & bar, TTF_Font * gHpFont, GTexture & text, float percent, string hp) {

        SDL_Color textColor = { 0, 0, 0 };
        bool success = true;

        if( !text.loadFromRenderedText( gRenderer, gHpFont, hp, textColor ) )
        {
            printf( "Failed to render text texture!\n" );
            success = false;
        }
        text.render(gRenderer,35, 31);
        int pw = (int)((float)bar.getOriginalWidth() * percent);
        bar.setSize(pw,17);
        SDL_RenderPresent(gRenderer);
        return success;

}

