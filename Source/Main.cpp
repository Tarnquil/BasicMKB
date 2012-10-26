#include "s3e.h"
#include "Iw2D.h"
#include "IwGx.h"
#include "BasicSprite.h"
#include "TouchHandle.h"

int main()
{
    IwGxInit();
    Iw2DInit();
    
    IwGxSetColClear(0, 0, 0, 0);
    
    CIw2DImage* image1 = Iw2DCreateImage("Projectile.png");
    
    touchSystem.init();
    BasicSprite sprite1 = BasicSprite(100, 100, 1, 90, image1);
    
    int surface_width = Iw2DGetSurfaceWidth();
    int surface_height = Iw2DGetSurfaceHeight();
    
    while (!s3eDeviceCheckQuitRequest())
    {
        s3eKeyboardUpdate();
        if (s3eKeyboardGetState(s3eKeyAbsDown) == S3E_KEY_STATE_DOWN)
            break;
        
        touchSystem.Update();
        
        IwGxClear(IW_GX_COLOUR_BUFFER_F | IW_GX_DEPTH_BUFFER_F);
        
        if (touchSystem.numOfTouches > 0)
        {
            sprite1.x = touchSystem.currentTouch.x;
            sprite1.y = touchSystem.currentTouch.y;
        }
        
        sprite1.Update();
        sprite1.DrawSprite();
        
        Iw2DSurfaceShow();
        
        s3eDeviceYield(0);
    }
    
    if (image1 != NULL)
        delete image1;
    
    Iw2DTerminate();
    IwGxTerminate();
    
    return 0;
}