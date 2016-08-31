#include "dialog.h"
#include "ui_dialog.h"
#include "stickman.h"

Dialog::Dialog(QWidget *parent, ConfigHandler *confighandler) :
    QDialog(parent),
    ui(new Ui::Dialog),
    cloudcollection(CloudCollection::getCloudCollection()),
    m_frame(Frame::getFrame(1000,600))

{
    m_stickman= Stickman::getStickman(confighandler->getSize(),
                                      Coordinate(confighandler->getXCoordinate(),0,m_frame),confighandler->getVelocity());
    ui->setupUi(this);
    this->resize(1000, 600);

    //create and add clouds to the collection
    for (int i = 0; i < (int) confighandler->getNumClouds(); i++)
    {
        cloudcollection->add(Cloud(Coordinate(confighandler->getCloudX()[i],
                                              confighandler->getCloudY()[i],
                                              m_frame),
                                   confighandler->getCloudSize()[i]));
    }

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(1000);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    //update new cloud positions
    for (int i = 0; i < cloudcollection->size(); i++) {
        cloudcollection->get(i).updateByTime(m_stickman->getVelocity());
    }

    cloudcollection->renderAll(painter);
    m_stickman->render(painter);
}

void Dialog::updateConfigFile()
{

    //check whether user don't change position and size of the stickman
    if (m_stickman->getUpdateVariable()==false) return;

    QFile file("new.config");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);


    out << "size: " <<  QString::fromStdString(m_stickman->getSize()) <<endl;
    out << "starting_position: " << m_stickman->getCoordinate().getXCoordinate() <<endl;
    out << "starting_velocity: " << m_stickman->getVelocity() << endl;
    out << "num_clouds: " << cloudcollection->size() << endl;
    out << "cloud_size: ";
    for (int i=0; i< cloudcollection->size() - 1; i++) {
        out << QString::fromStdString(cloudcollection->get(i).getSize()) << ", ";
    }
    out << QString::fromStdString(cloudcollection->get(cloudcollection->size() - 1).getSize()) <<endl;

    out << "cloud_x: ";
    for (int i=0; i< cloudcollection->size() - 1; i++) {
        out << cloudcollection->get(i).getInitalCoordinate().getXCoordinate()<< ", ";
    }
    out << cloudcollection->get(cloudcollection->size() - 1).getInitalCoordinate().getXCoordinate() <<endl;

    out << "cloud_y: ";
    for (int i=0; i< cloudcollection->size() - 1; i++) {
        out << cloudcollection->get(i).getInitalCoordinate().getYCoordinate()<< ", ";
    }
    out << cloudcollection->get(cloudcollection->size() - 1).getInitalCoordinate().getYCoordinate() <<endl;

    out <<"stickman_colour: " << m_stickman->getColour().name() <<endl;
    file.close();
    m_stickman->changeUpdateVariable();
}

void Dialog::nextFrame()
{
    updateConfigFile();
    update();
}

void Dialog::mouseReleaseEvent ( QMouseEvent * event )
{
    int x = event->x();
    int y = event->y();

    int m_radius ;
    if (m_stickman->getSize()== "tiny")
    {
        m_radius = 10;
    } else  if (m_stickman->getSize() == "normal")
    {
        m_radius = 20;
    } else  if (m_stickman->getSize() == "large")
    {
        m_radius = 30;
    } else m_radius = 40;

    double sx = m_stickman->getCoordinate().getQtRenderingX();
    double sy = m_stickman->getCoordinate().getQtRenderingY()-2 * m_radius - 1;
    double a = std::abs(x - (sx + m_radius)); // a is the x-distance to centre
    double b = std::abs(y - (sy + m_radius)); // b is the y-distance to centre

    //check whether click coordinate outside the stickman
    if ( a* a + b * b > m_radius * m_radius)
        return;

    // update the 'changed' variable. it means that it's needed to update a new config file
    m_stickman->changeUpdateVariable();

    if(event->button() == Qt::RightButton)
    {
        m_stickman->changeSize();
    } else if(event->button() == Qt::LeftButton) {
        m_stickman->changePosition();
    }
};

void Dialog::keyPressEvent(QKeyEvent* event)
{
    // if "C" is pressed
    if (event->key() == Qt::Key_C)
    {
       m_stickman->changeColour();
    }

    m_stickman->changeUpdateVariable();

}

