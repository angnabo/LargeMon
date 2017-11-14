//
// Created by angelica on 14/11/17.
//

#include "GProgressBar.h"

bool TextureHpBar::updateProgress(SDL_Renderer * gRenderer, LTexture & bar, TTF_Font * gHpFont, LTexture & text, float percent, string hp) {

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

TextureHpBar::TextureHpBar() {

}
