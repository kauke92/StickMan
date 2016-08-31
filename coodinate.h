#ifndef COODINATE_H
#define COODINATE_H


class Coodinate
{
public:
    Coodinate(double x, double y);
    double getQtRenderingX();
    double getQtRenderingY();
    double getXCoordinate();
    double getYCoordinate();
    ~Coodinate();
private:
    double m_x;
    double m_y;
};

#endif // COODINATE_H
