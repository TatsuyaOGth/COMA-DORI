#pragma once

#include "ofMain.h"
#include "StopMotionController.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp
{
    shared_ptr<StopMotionController> mAnimation;
    
    ofxPanel mGui;
    ofParameterGroup mParams;
    ofParameter<float> mLevel;
    ofParameter<float> mGain;
    ofParameter<float> mDecay;
    
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void audioIn(ofSoundBuffer& buffer);
};
