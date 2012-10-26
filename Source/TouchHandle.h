//
//  TouchHandle.h
//  BasicMKB
//
//  Created by Richard Humphries on 26/10/2012.
//
//

#ifndef __BasicMKB__TouchHandle__
#define __BasicMKB__TouchHandle__

#include <iostream>
#include "s3ePointer.h"
#include "s3e.h"

struct Touch
{
public:
    float x;
    float y;
    bool isDown;
};

class TouchHandle
{
public:
    int numOfTouches;
    Touch currentTouch;
    void init();
    void Update();
};

extern TouchHandle touchSystem;

#endif /* defined(__BasicMKB__TouchHandle__) */