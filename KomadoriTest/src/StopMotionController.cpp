#include "StopMotionController.h"

StopMotionController::StopMotionController()
{
    
}

StopMotionController::~StopMotionController()
{
    
}

bool StopMotionController::load(const string &dirPath)
{
    mFrames.clear();
    
    ofDirectory dir;
    if (dir.listDir(dirPath) == 0) return false;
    for (auto innerData : dir)
    {
        ofLogNotice() << "load: " << dir.path();
        if (innerData.isDirectory())
        {
            ofDirectory innerDir;
            innerDir.listDir(innerData.path());
            mFrames.push_back(ofPtr<Frame>(new Frame()));
            vector<ofPixels> *imageArray = &mFrames.back()->imageArray;
            for (auto innerFile : innerDir)
            {
                imageArray->push_back(ofPixels());
                if (ofLoadImage(imageArray->back(), innerFile.getAbsolutePath()) == false)
                {
                    ofLogError() << "failed load image: " << innerFile.path();
                    imageArray->pop_back();
                }
                ofLogNotice() << "load image: " << innerFile.path();
            }
            if (imageArray->empty() == false) mFrames.back()->currentIndex = 0;
        }
    }
    if (mFrames.empty()) return false;
    mCurrentFrame = mFrames[0].get();
    return true;
}

void StopMotionController::setLevel(float level)
{
    mLevel = ofClamp(level, 0., 1.);
}

void StopMotionController::update()
{
    const int level = (int) floorf(mLevel * (mFrames.size() - 1));
    mCurrentFrame = mFrames[level].get();
    const int currentIndex = mCurrentFrame->currentIndex;
    
    for (int i = 0; i < 999; ++i)
    {
        int newIndex = (int) ofRandom(0, mCurrentFrame->size());
        if (newIndex != currentIndex)
        {
            mCurrentFrame->currentIndex = newIndex;
            mTexture.loadData(mCurrentFrame->getImage(), GL_RGB);
            break;
        }
    }
}

void StopMotionController::draw(float x, float y) const
{
    mTexture.draw(x, y);
}

void StopMotionController::draw(float x, float y, float w, float h) const
{
    mTexture.draw(x, y, w, h);
}

float StopMotionController::getHeight() const
{
    return mTexture.getHeight();
}

float StopMotionController::getWidth() const
{
    return mTexture.getWidth();
}
