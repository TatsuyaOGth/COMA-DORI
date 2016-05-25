#pragma once

#include "ofMain.h"

class StopMotionController : public ofBaseDraws, public ofBaseUpdates
{
protected:
    class Frame
    {
    public:
        vector<ofPixels> imageArray;
        int currentIndex;
        Frame() : currentIndex(-1) {}
        int size() { return imageArray.size(); }
        const ofPixels& getImage() { return imageArray[currentIndex]; }
    };
    
    float mLevel;
    vector<ofPtr<Frame> > mFrames;
    Frame *mCurrentFrame;
    ofTexture mTexture;
    
public:
    StopMotionController();
    virtual ~StopMotionController();
    
    bool load(const string& dirPath);
    
    void update();
    
    using ofBaseDraws::draw;
    void draw(float x, float y) const;
    void draw(float x, float y, float w, float h) const;
    
    void setLevel(float level);
    
    float getHeight() const;
    float getWidth() const;
};
