//
// Created by angelica on 26/10/17.
//

#ifndef LARGEMON_BUTTONTEXTURE_H
#define LARGEMON_BUTTONTEXTURE_H


#include "GTexture.h"

class ButtonTexture: public GTexture{

public:
    void setSelected(bool);
    bool isSelected(){return selected;}

private:
    bool selected;

};


#endif //LARGEMON_BUTTONTEXTURE_H
