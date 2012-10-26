//
//  TouchHandle.cpp
//  BasicMKB
//
//  Created by Richard Humphries on 26/10/2012.
//
//
#include "TouchHandle.h"

TouchHandle touchSystem;

void SingleTouch (s3ePointerEvent* event)
{
    touchSystem.numOfTouches++;
    Touch cache;
    cache.x = event->m_x;
    cache.y = event->m_y;
    touchSystem.currentTouch = cache;
};

void TouchHandle::init()
{
    s3ePointerRegister(S3E_POINTER_BUTTON_EVENT, (s3eCallback)SingleTouch, NULL);
    numOfTouches = 0;
};

void TouchHandle::Update()
{
    s3ePointerUpdate();
};