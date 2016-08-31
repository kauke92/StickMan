#ifndef CONFIGHANDLERDIRECTOR_H
#define CONFIGHANDLERDIRECTOR_H
#define CONFIGPATH ".config"
#define STR_MATCH(x,y) (x).compare((y), Qt::CaseInsensitive) == 0

#include "confighandlerbuilder.h"
#include <QDebug>
class ConfigHandlerDirector
{
public:
    ConfigHandlerDirector();
    ~ConfigHandlerDirector();
    ConfigHandlerBuilder* read() ;
    vector<string>* toStringVector(const QString &value_list,  QFile* file, ConfigHandlerBuilder* b);
    vector<double>* toDoubleVector(const QString &value_list,  QFile* file, ConfigHandlerBuilder* b);
    void setBuilder(ConfigHandlerBuilder* builder);

private:
    ConfigHandlerBuilder* builder;
};

#endif // CONFIGHANDLERDIRECTOR_H
