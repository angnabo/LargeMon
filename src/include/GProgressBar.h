//
// Created by angelica on 14/11/17.
//

#ifndef LARGEMON_GPROGRESSBAR_H
#define LARGEMON_GPROGRESSBAR_H

#include <string>
using namespace std;
#include "GTexture.h"

class GProgressBar : public GTexture {
public:
    GProgressBar();
    bool updateProgress(SDL_Renderer *gRenderer, GTexture &bar, TTF_Font *gHpFont, GTexture &text, float percent, string hp);
private:
    //To work out the new size as a percentage of the old size
    int originalWidth;


};


#endif //LARGEMON_HEALTHBARTEXTURE_H
