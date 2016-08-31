#include "confighandler.h"
#define STR_MATCH(x,y) (x).compare((y), Qt::CaseInsensitive) == 0

ConfigHandler::ConfigHandler(string size, double x, double v):
    m_size(size),
    m_XCoodinate(x),
    m_velocity(v)
{
}

ConfigHandler::~ConfigHandler()
{

}

string ConfigHandler::getSize() const
{
    return m_size;
}

double ConfigHandler::getXCoordinate() const
{
    return m_XCoodinate;
}

double ConfigHandler::getVelocity() const
{
    return m_velocity;
}

int ConfigHandler::getNumClouds() const
{
    return num_clouds;
}

vector<string> ConfigHandler::getCloudSize()  const
{
    return *cloud_size;
}

vector<double> ConfigHandler::getCloudX() const
{
    return *cloud_x;
}

vector<double> ConfigHandler::getCloudY() const
{
    return *cloud_y;
}

void ConfigHandler::setNumClouds(int num)
{
    num_clouds = num;
}

void ConfigHandler::setCloudSize(vector<string>* v)
{
    cloud_size = v;
}

void ConfigHandler::setCloudX(vector<double>* v)
{
    cloud_x = v;

}

void ConfigHandler::setCloudY(vector<double>* v)
{
    cloud_y = v;
}


