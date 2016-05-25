#include "ofApp.h"

void ofApp::setup()
{
    ofSetFrameRate(24);
    
    mAnimation = make_shared<StopMotionController>();
    mAnimation->load("paper");
    
    mGui.setup("PARAMETERS");
    mParams.setName("AUDIO");
    mParams.add(mLevel.set("LEVEL", 0, 0, 1));
    mParams.add(mGain.set("GAIN", 1, 0, 10));
    mParams.add(mDecay.set("DECAY", 0.9, 0., 1.));
    mGui.add(mParams);
    
    ofSoundStreamSetup(0, 1);
}

void ofApp::update()
{
    const float level = mLevel;
    mAnimation->setLevel(level);
    mLevel *= mDecay;

    
    mAnimation->update();
}

void ofApp::draw()
{
    mAnimation->draw(0, 0, ofGetWidth(), ofGetHeight());
    mGui.draw();
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
    float amp = buffer.getRMSAmplitude() * mGain;
    if (amp > mLevel) mLevel = MIN(amp, 1.);
}
