//
// Created by angelica on 26/10/17.
//

#ifndef LARGEMON_BUTTONTEXTURE_H
#define LARGEMON_BUTTONTEXTURE_H


#include "LTexture.h"

class ButtonTexture: public LTexture{

public:
    void setSelected(bool);
    bool isSelected(){return selected;}

private:
    bool selected;

};


#endif //LARGEMON_BUTTONTEXTURE_H
