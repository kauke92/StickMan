#include "cloud.h"
int Cloud::m_next = 0;

Cloud::Cloud(Coordinate coordinate, string size) :
    m_coordinate(coordinate),
    m_inital(coordinate),
    m_size(size),
    m_id(m_next)
{
    m_next++;
}

Cloud::~Cloud()
{

}

void Cloud::render(QPainter &painter)
{
    painter.setPen ( Qt::white );
    painter.setBrush( QBrush( QColor(0, 0, 255, 127)  ));

    int m_radius;

    //the radius of the cloud depends on the given size
    if (m_size == "tiny")
    {
        m_radius = 10;
    } else  if (m_size == "normal")
    {
        m_radius = 20;
    } else  if (m_size == "large")
    {
        m_radius = 30;
    } else m_radius = 40;

    //draw a ellipse denoting the cloud
    painter.drawEllipse(m_coordinate.getQtRenderingX(), m_coordinate.getQtRenderingY() - 2 * m_radius - 1 ,
                       2*  m_radius , m_radius);
}

void Cloud::updateByTime(double change)
{
    m_coordinate.transformXCoordinate(-change);

    //repeat the clouds
    if (m_coordinate.getXCoordinate()< -10 * change)
    {
        m_coordinate.setCoordinates(m_coordinate.getFrameWidth()+50, m_coordinate.getYCoordinate());
    }
}

string Cloud::getSize() const
{
    return m_size;
}

Coordinate Cloud::getCoordinate() const
{
    return m_coordinate;
}

Coordinate Cloud::getInitalCoordinate() const
{
    return m_inital;
}
