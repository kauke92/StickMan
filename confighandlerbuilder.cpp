#include "confighandlerbuilder.h"

ConfigHandlerBuilder::ConfigHandlerBuilder(string size, double x, double v)
{
    config = new ConfigHandler(size, x,v);
}

ConfigHandlerBuilder::~ConfigHandlerBuilder()
{
    delete config;
}

ConfigHandler* ConfigHandlerBuilder::getConfigHandler() const
{
    return config;
}


void ConfigHandlerBuilder::buildNumClouds(int num)
{
    config->setNumClouds(num);
}

void ConfigHandlerBuilder::buildCloudX(vector<double>* v)
{
    config->setCloudX(v);
}

void ConfigHandlerBuilder::buildCloudY(vector<double>* v)
{
    config->setCloudY(v);
}

void ConfigHandlerBuilder::buildCloudSize(vector<string>* v)
{
    config->setCloudSize(v);
}
