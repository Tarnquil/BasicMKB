#include "s3e.h"
#include "Iw2D.h"
#include "IwGx.h"
#include "BasicSprite.h"

int main()
{
    IwGxInit();
    Iw2DInit();
    
    BasicSprite sprite1;
    BasicSprite sprite2;
    
    IwGxSetColClear(0, 0, 0, 0);
    
    sprite1.init(100, 100, 1, 90, Iw2DCreateImage("Projectile.png"));
    sprite2.init(200, 100, 1, 90, Iw2DCreateImage("Projectile.png"));
    
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

    sprite1.~BasicSprite();
    sprite2.~BasicSprite();
    
    Iw2DTerminate();
    IwGxTerminate();
    
    return 0;
}