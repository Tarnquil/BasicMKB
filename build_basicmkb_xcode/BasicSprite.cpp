#include "BasicSprite.h"

void BasicSprite::init(int _x, int _y, float _scale, iwangle _rot, CIw2DImage* _image)
{
    x = _x;
    y = _y;
    scale = _scale;
    image = _image;
    rot = _rot;
}

void BasicSprite::DrawSprite()
{

    iwangle angle = 0;
    
    CIwMat2D m;
    m.SetRot(rot);
    
    m.ScaleRot(IW_GEOM_ONE * scale);
    
    m.SetTrans(CIwSVec2(x, y));
    
    Iw2DSetTransformMatrix(m);
    
    int xS = -(image->GetWidth() / 2);
    int yS = -(image->GetHeight() / 2);
    
    Iw2DDrawImage(image, CIwSVec2(xS, yS));
}

void BasicSprite::Update()
{
    rot += IW_ANGLE_2PI / 60;
}
