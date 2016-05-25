#include "ofApp.h"

void ofApp::setup()
{
    ofSetFrameRate(24);
    
    mAnimation.load("paper");
    
    ofSoundStreamSetup(0, 1);
}

void ofApp::update()
{
    
    mAnimation.update();
}

void ofApp::draw()
{
//    const float level = (float) ofGetMouseX() / (float) ofGetWidth();
    const float level = mLevel;
    mLevel *= 0.9;
    
    mAnimation.setLevel(level);
    mAnimation.draw(0, 0, ofGetWidth(), ofGetHeight());
    ofSetWindowTitle(ofToString(level));
    ofDrawRectangle(0, 0, mLevel * ofGetWidth(), 2);
}

void ofApp::keyPressed(int key)
{
    switch (key)
    {
        case 'f': ofToggleFullscreen(); break;
    }
}

void ofApp::audioIn(ofSoundBuffer &buffer)
{
    float amp = buffer.getRMSAmplitude();
    if (amp > mLevel) mLevel = MIN(amp, 1.);
}
