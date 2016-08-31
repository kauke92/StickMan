#ifndef CLOUD_H
#define CLOUD_H
#include "coordinate.h"
#include <string>
#include <QPainter>
using namespace std;
class Cloud
{
public:
    Cloud(Coordinate Coordinate, string size);
    ~Cloud();
    void render(QPainter &painter);
    void updateByTime( double change);
    string getSize() const;
    Coordinate getCoordinate() const;
    Coordinate getInitalCoordinate() const;
private:
    Coordinate m_coordinate;
    const Coordinate m_inital ; //the inital coordinate of cloud, for writing new config file
    string m_size;
    int m_id;
    static int m_next;
};

#endif // CLOUD_H
