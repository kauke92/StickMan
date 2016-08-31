#ifndef COORDINATE_H
#define COORDINATE_H

#include "frame.h"

class Coordinate
{
public:
    Coordinate(double x, double y, Frame* frame);
    double getQtRenderingX() const;
    double getQtRenderingY( )const;

    void transformXCoordinate(double change);
    void transformYCoordinate(double change);
    void transformCoordinates(double x_change, double y_change);

    double getXCoordinate() const;
    double getYCoordinate() const;

    void setCoordinates(double p_x_coordinate, double p_y_coordinate);

    int getFrameWidth() const ;
    int getFrameHeight() const;
    ~Coordinate();
private:
    double m_x;
    double m_y;
    Frame* m_frame;
};

#endif // COORDINATE_H
