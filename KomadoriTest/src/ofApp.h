#pragma once

#include "ofMain.h"
#include "StopMotionController.h"

class ofApp : public ofBaseApp
{
    StopMotionController mAnimation;
    float mLevel;
    
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void audioIn(ofSoundBuffer& buffer);
};
