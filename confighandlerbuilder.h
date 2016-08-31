#ifndef CONFIGHANDLERBUILDER_H
#define CONFIGHANDLERBUILDER_H
#include "confighandler.h"

//the ConfigHandler builder
class ConfigHandlerBuilder
{
public:
    ConfigHandlerBuilder(string size, double x, double v);
    ~ConfigHandlerBuilder();
    ConfigHandler* getConfigHandler() const;
    void buildNumClouds(int num);
    void buildCloudX(vector<double>* v);
    void buildCloudY(vector<double>* v);
    void buildCloudSize(vector<string>* v);
private:
    ConfigHandler* config;
};

#endif // CONFIGHANDLERBUILDER_H
