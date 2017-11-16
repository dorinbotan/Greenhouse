#ifndef LOGGER_H
#define LOGGER_H

#include <QString>

class Logger
{
public:
    Logger();

    void logAction( QString );
    void logSensorValues();

private:
    const QString msgLogFile = "/home/debian/Server/Actions.log";
    const QString sensorLogFile = "/home/debian/Server/SensorReadings.log";
};

#endif // LOGGER_H
