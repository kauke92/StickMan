#include "stickman.h"
Stickman* Stickman::stickman = 0;
Stickman::Stickman( string size, Coordinate coordinate, double velocity):
        m_size(size),
        m_coordinate(coordinate),
        m_velocity(velocity),
        updated(false),
        m_colour(Qt::yellow)
{

}

Stickman::~Stickman()
{
    delete stickman;
}

Stickman* Stickman::getStickman( string size, Coordinate coordinate, double velocity)
{
    if (stickman == 0) {
        stickman = new Stickman( size,  coordinate, velocity);
    }
    return stickman;
}

string Stickman::getSize() const
{
    return m_size;
}

Coordinate Stickman::getCoordinate()const
{
    return m_coordinate;
}

double Stickman::getVelocity() const
{
    return m_velocity;
}

/*
 * Draw an ellipse denoting the stickman
 */
void Stickman::render(QPainter &painter)
{
    painter.setPen ( Qt::black );
    painter.setBrush( QBrush( m_colour ) );
    int m_radius;

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

    painter.drawEllipse(m_coordinate.getQtRenderingX(),m_coordinate.getQtRenderingY() - 2* m_radius-1 , m_radius * 2, m_radius * 2);
}


/* Update the size of the stickman as user clicks left mouse.
 * The size is updated in circle.
 */
void Stickman::changeSize()
{
    if (m_size == "tiny")
    {
        m_size = "normal";
    } else  if (m_size == "normal")
    {
        m_size = "large";
    } else  if (m_size == "large")
    {
        m_size = "giant";
    } else m_size = "tiny";
}


/*Update the position of the stickman as user clicks right mouse.
 * The x-coordinate is added up 10 units every update, and gets 0 then it is over
 * the frame width
 */
void Stickman::changePosition()
{
    double x= stickman->getCoordinate().getXCoordinate();

    x = x + 10;
    if (x > stickman->getCoordinate().getFrameWidth())
    {
        x = 0;
    }
    stickman->m_coordinate.setCoordinates(x,stickman->getCoordinate().getYCoordinate());
}


bool Stickman::getUpdateVariable() const
{
    return stickman->updated;
}

void Stickman::changeUpdateVariable()
{
   stickman->updated = ! stickman->updated;
}

//change colour of stickman when "C"  key is pressed
void Stickman::changeColour(){
    if (m_colour == Qt::yellow)
    {
        m_colour = Qt::green;
    } else if (m_colour == Qt::green)
    {
        m_colour = Qt::blue;
    } else if (m_colour == Qt::blue)
    {
        m_colour = Qt::darkGreen;
    } else if (m_colour == Qt::darkGreen)
    {
        m_colour = Qt::cyan;
    } else if (m_colour == Qt::cyan)
    {
        m_colour = Qt::yellow;
    }
}

QColor Stickman::getColour() const
{
    return m_colour;
}
