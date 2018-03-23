//
// Created by angelica on 14/11/17.
//
#include "Texture.h"
#include <string>

#ifndef LARGEMON_GPROGRESSBAR_H
#define LARGEMON_GPROGRESSBAR_H

using namespace std;

class ProgressBar : public Texture {
public:
    ProgressBar();

    bool updateProgress(SDL_Renderer *renderer, Texture &bar, TTF_Font *gHpFont, Texture &text, float percent, string hp);
};
#endif //LARGEMON_HEALTHBARTEXTURE_H
