//
// Created by angelica on 14/11/17.
//

#ifndef LARGEMON_HEALTHBARTEXTURE_H
#define LARGEMON_HEALTHBARTEXTURE_H

#include <string>
using namespace std;
#include "../include/LTexture.h"

class TextureHpBar : public LTexture {
public:
    TextureHpBar();
    bool updateProgress();
private:
    //To work out the new size as a percentage of the old size
    int originalWidth;
};


#endif //LARGEMON_HEALTHBARTEXTURE_H
