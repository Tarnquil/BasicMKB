#ifndef __BasicMKB__BasicSprite__
#define __BasicMKB__BasicSprite__

#include <iostream>
#include "s3e.h"
#include "Iw2D.h"
#include "IwGx.h"

class BasicSprite
{
public:
    int x;
    int y;
    float scale;
    CIw2DImage* image;
    iwangle rot;
    void init(int _x, int _y, float _scale, iwangle rot, CIw2DImage* _image);
    void DrawSprite();
    void Update();
    BasicSprite(int _x, int _y, float _scale, iwangle rot, CIw2DImage* _image);
};

#endif /* defined(__BasicMKB__BasicSprite__) */