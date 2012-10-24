#include "s3e.h"
#include "Iw2D.h"
#include "IwGx.h"
#include "BasicSprite.h"

int main()
{
    IwGxInit();
    Iw2DInit();

    IwGxSetColClear(0, 0, 0, 0);
    
    CIw2DImage* image1 = Iw2DCreateImage("Projectile.png");
    
    
    BasicSprite sprite1 (100, 100, 1, 90, image1);
    BasicSprite sprite2 (200, 100, 1, 90, image1);
    
    int surface_width = Iw2DGetSurfaceWidth();
    int surface_height = Iw2DGetSurfaceHeight();
    
    while (!s3eDeviceCheckQuitRequest())
    {
        s3eKeyboardUpdate();
        if (s3eKeyboardGetState(s3eKeyAbsBSK) & S3E_KEY_STATE_DOWN)   
            break;
        
        s3ePointerUpdate();
        
        IwGxClear(IW_GX_COLOUR_BUFFER_F | IW_GX_DEPTH_BUFFER_F);
        
        sprite1.DrawSprite();
        sprite2.DrawSprite();
        sprite1.Update();
        sprite2.Update();
        
        Iw2DSurfaceShow();
        
        s3eDeviceYield(0);
    }

    if (image1 != NULL)
        delete image1;
    
    Iw2DTerminate();
    IwGxTerminate();
    
    return 0;
}