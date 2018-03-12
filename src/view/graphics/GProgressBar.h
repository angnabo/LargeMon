//
// Created by angelica on 14/11/17.
//
#include "GTexture.h"
#include <string>

#ifndef LARGEMON_GPROGRESSBAR_H
#define LARGEMON_GPROGRESSBAR_H

using namespace std;

class GProgressBar : public GTexture {
public:
    GProgressBar();

    bool updateProgress(SDL_Renderer *gRenderer, GTexture &bar, TTF_Font *gHpFont, GTexture &text, float percent, string hp);
};
#endif //LARGEMON_HEALTHBARTEXTURE_H
