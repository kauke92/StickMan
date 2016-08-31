#include "coordinate.h"

Coordinate::Coordinate(double x, double y, Frame* frame):
    m_x(x),
    m_y(y),
    m_frame(frame)
{

}

Coordinate::~Coordinate()

{

}

double Coordinate::getQtRenderingX() const{
    return m_x;
}

double Coordinate::getQtRenderingY() const {
    return m_frame->getFrameHeight() - m_y;
}

void Coordinate::transformXCoordinate(double change)
{
    m_x += change;
}

void Coordinate::transformYCoordinate(double change)
{
    m_y += change;
}

void Coordinate::transformCoordinates(double x_change, double y_change)
{
    m_x += x_change;
    m_y += y_change;
}

double Coordinate::getXCoordinate() const
{
    return m_x;
}

double Coordinate::getYCoordinate() const
{
    return m_y;
}

void Coordinate::setCoordinates(double p_x_coordinate, double p_y_coordinate)
{
    m_x = p_x_coordinate;
    m_y = p_y_coordinate;
}

int Coordinate::getFrameWidth() const
{
    return m_frame->getFrameWidth();
}

int Coordinate::getFrameHeight() const
{
    return m_frame->getFrameHeight();
}

