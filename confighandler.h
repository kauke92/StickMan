#ifndef CONFIGHANDLER_H
#define CONFIGHANDLER_H
using namespace std;

#include <string>
#include <QFile>
#include <QApplication>
#include <QString>
#include <QTextStream>
#include <QStringList>
#include <QFile>


class ConfigHandler
{
public:
    ConfigHandler(string size, double x, double v);
    ~ConfigHandler();
    string getSize() const;
    double getXCoordinate() const;
    double getVelocity() const;
    bool parse();
    bool toStringVector(vector<string> * &v, const QString &value_list, const QString &param_name);
    bool toDoubleVector(vector<double> * &v, const QString &value_list, const QString &param_name);

    int getNumClouds() const;
    vector<string> getCloudSize() const;
    vector<double> getCloudX() const;
    vector<double> getCloudY() const;

    void setNumClouds(int num);
    void setCloudSize(vector<string>* v);
    void setCloudX(vector<double>* v);
    void setCloudY(vector<double>* v);



private:
    string m_size;
    double m_XCoodinate;
    double m_velocity;
    int num_clouds;
    vector<string> *cloud_size; // list of cloud's sizes
    vector<double> *cloud_x;    //list of cloud's XCooridates
    vector<double> *cloud_y;    //list of cloud's YCoordinates

};

#endif // CONFIGHANDLER_H
