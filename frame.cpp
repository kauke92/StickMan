#include "frame.h"

Frame* Frame::frame =0 ;
Frame::~Frame()
{
    delete frame;
}

Frame* Frame::getFrame(int frameWidth, int frameHeight)
{
    if (frame == 0) {
        frame = new Frame(frameWidth,frameHeight);
    }
    return frame;
}

int Frame::getFrameWidth() const
{
    return m_frameWidth;
}

int Frame::getFrameHeight() const
{
    return m_frameHeight;

}

Frame::Frame(int frameWidth, int frameHeight) :
    m_frameWidth(frameWidth),
    m_frameHeight(frameHeight)
{

}
