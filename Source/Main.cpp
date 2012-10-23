#include "s3e.h"
#include "Iw2D.h"
#include "IwGx.h"

void DrawSprite(CIw2DImage* image, int at_pos_x, int at_pos_y, iwangle angle = 0, iwfixed scale = IW_GEOM_ONE)
{
    CIwMat2D m;
    m.SetRot(angle);
    
    m.ScaleRot(scale);
    
    m.SetTrans(CIwSVec2(at_pos_x, at_pos_y));
    
    Iw2DSetTransformMatrix(m);
    
    int x = -(image->GetWidth() / 2);
    int y = -(image->GetHeight() / 2);
    Iw2DDrawImage(image, CIwSVec2(x, y));
}

int main()
{
    IwGxInit();
    Iw2DInit();
    
    IwGxSetColClear(0, 0, 0, 0);
    
    CIw2DImage* image1 = Iw2DCreateImage("Projectile.png");
    CIw2DImage* image2 = Iw2DCreateImage("Projectile.png");
    
    int surface_width = Iw2DGetSurfaceWidth();
    int surface_height = Iw2DGetSurfaceHeight();
    
    iwangle angle = 0;
    
    while (!s3eDeviceCheckQuitRequest())
    {
        s3eKeyboardUpdate();
        if (s3eKeyboardGetState(s3eKeyAbsBSK) & S3E_KEY_STATE_DOWN)   
            break;
        
        s3ePointerUpdate();
        
        IwGxClear(IW_GX_COLOUR_BUFFER_F | IW_GX_DEPTH_BUFFER_F);
        
        DrawSprite(image1, surface_width / 4, surface_height / 2, -angle,IW_GEOM_ONE);
        DrawSprite(image2, surface_width / 2, surface_height / 2, angle, IW_GEOM_ONE);
        
        angle += IW_ANGLE_2PI / 60;
        
        Iw2DSurfaceShow();
        
        s3eDeviceYield(0);
    }
    
    if (image2 != NULL)
        delete image2;
    if (image1 != NULL)
        delete image1;
    
    Iw2DTerminate();
    IwGxTerminate();
    
    return 0;
}