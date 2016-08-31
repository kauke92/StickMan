#ifndef FRAME_H
#define FRAME_H


class Frame
{
public:
    Frame();
    ~Frame();
    static Frame* getFrame(int frameWidth, int frameHeight);
    int getFrameWidth() const;
    int getFrameHeight() const;
    Frame(int frameWidth, int frameHeight);
private:
    static Frame* frame;
    int m_frameWidth;
    int m_frameHeight;

};

#endif // FRAME_H
