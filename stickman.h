#ifndef STICKMAN_H
#define STICKMAN_H
#include <string>
#include "coordinate.h"
#include <QPainter>
using namespace std;

class Stickman
{
public:
    Stickman( string size, Coordinate coordinate, double velocity);
    ~Stickman();
    static Stickman* getStickman( string size, Coordinate coordinate, double velocity);
    string getSize() const;
    Coordinate getCoordinate() const;
    double getVelocity() const;
    void render(QPainter &painter);
    void changeSize();
    void changePosition();
    bool getUpdateVariable() const;
    void changeUpdateVariable();
    void changeColour();
    QColor getColour() const;
private:
    static Stickman* stickman;
    Coordinate m_coordinate;
    double m_velocity;
    string m_size;
    QColor m_colour;
    bool updated; // whether the new config file needs updated
};

#endif // STICKMAN_H
