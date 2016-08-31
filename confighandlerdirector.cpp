#include "confighandlerdirector.h"

ConfigHandlerDirector::ConfigHandlerDirector()
{
}

ConfigHandlerDirector::~ConfigHandlerDirector()
{

}
void ConfigHandlerDirector::setBuilder(ConfigHandlerBuilder* builders)
{
    this->builder= builder;
}

/*
 * read data from config file
 *
*/
ConfigHandlerBuilder* ConfigHandlerDirector::read()
{
    ConfigHandlerBuilder* builder;
    string m_size;
    double m_XCoordinate;
    double m_velocity;
    int num_clouds;
    bool ok;

    QFile file(CONFIGPATH);
    file.open(QIODevice::ReadOnly);

    if (!file.isOpen())
    {
        exit(1);
    }

    QTextStream input(&file);

    while (!input.atEnd())
    {
        QString line = input.readLine();

        //blank line
        if (line.length() == 0)
        {
            continue;
        }

        QStringList list = line.split(": ");

        //not enough required data
        if (list.length() < 2)
        {
            file.close();
            exit(1);
        }

        if (STR_MATCH(list[0], "size"))
        {
            m_size = list[1].toStdString();
            //not correct size format
            ok = ((m_size=="tiny") || (m_size=="normal") || (m_size=="large") || (m_size=="giant"));
            if (!ok)
            {
                qDebug() << "wrong format of size of stickman" << endl;
                file.close();
                exit(1);
            }
        } else if (STR_MATCH(list[0], "starting_position"))
        {
            m_XCoordinate = list[1].toDouble(&ok);

            // not double type

            if (!ok)
            {
                qDebug() << "wrong format of starting position of stickman" << endl;
                file.close();
                exit(1);
            }
        } else  if (STR_MATCH(list[0], "starting_velocity"))
        {
            m_velocity = list[1].toDouble(&ok);

            //not double type
            if (!ok)
            {
                qDebug() << "wrong format of velocity of stickman" << endl;
                file.close();
                exit(1);
            }
            builder = new ConfigHandlerBuilder(m_size,m_XCoordinate, m_velocity);
        } else if (STR_MATCH(list[0], "num_clouds"))
        {
            num_clouds = list[1].toUInt(&ok);

            //not double type
            if (!ok)
            {
                qDebug() << "wrong format of number of clouds" << endl;
                file.close();
                delete builder;
                exit(1);
            }
               builder->getConfigHandler()->setNumClouds(num_clouds);

        } else if (STR_MATCH(list[0], "cloud_size"))
        {
            builder->getConfigHandler()->setCloudSize(toStringVector(list[1], &file, builder));

            //not enough number of clouds' size
            if (builder->getConfigHandler()->getCloudSize().size()!= num_clouds)
            {
                qDebug() << "enough number of clouds' sizes or wrong format" << endl;
                file.close();
                builder->getConfigHandler()->getCloudSize().clear();
                delete builder;
                exit(1);
            }
        } else if (STR_MATCH(list[0], "cloud_x"))
        {
            builder->getConfigHandler()->setCloudX(toDoubleVector(list[1], &file, builder));

            //not enough clouds' X-coordinates
            if (builder->getConfigHandler()->getCloudX().size()!= num_clouds)
            {
                qDebug() << "enough number of clouds' XCoordinates or wrong format" << endl;
                file.close();
                builder->getConfigHandler()->getCloudSize().clear();
                builder->getConfigHandler()->getCloudX().clear();builder->getConfigHandler()->getCloudX().clear();
                delete builder;
                exit(1);
            }

        } else if (STR_MATCH(list[0], "cloud_y"))
        {
            builder->getConfigHandler()->setCloudY(toDoubleVector(list[1], &file, builder));

            //not enough clouds' Y-coordinates
            if (builder->getConfigHandler()->getCloudY().size()!= num_clouds)
            {
                qDebug() << "enough number of clouds' YCoordinates or wrong format" << endl;
                file.close();
                builder->getConfigHandler()->getCloudSize().clear();
                builder->getConfigHandler()->getCloudX().clear();
                builder->getConfigHandler()->getCloudY().clear();
                delete builder;
                exit(1);
            }
        }

    }
    file.close();

    return builder;
}

/*
 * convert list of QString to list of std::string type
*/
vector<string>* ConfigHandlerDirector::toStringVector(const QString &value_list, QFile* file, ConfigHandlerBuilder* b)
{
    vector<string>* v = new vector<string>;
    try
    {
        QStringList split_values = value_list.split(", ");
        for (int i = 0; i < split_values.length(); i++)
        {
            v->push_back(split_values[i].toStdString());
        }
    }
    catch (exception e)
    {
        delete b;
        file->close();
        exit(1);
    }

    return v;
}


/*
 * convert list of QString to list of double type
*/
vector<double>* ConfigHandlerDirector::toDoubleVector(const QString &value_list , QFile* file, ConfigHandlerBuilder* b)
{
    bool ok;
    vector<double> * v = new vector<double>;
    try
    {
        QStringList split_values = value_list.split(", ");
        for (int i = 0; i < split_values.length(); i++)
        {
            v->push_back(split_values[i].toDouble(&ok));
            if (!ok)
            {
                delete b;
                file->close();
                exit(1);
            }
        }
    }
    catch (exception e)
    {
        delete b;
        file->close();
        exit(1);
    }

    return v;
}
