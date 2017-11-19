#ifndef LOGGER_H
#define LOGGER_H

#include <QString>
#include "ADC.h"

class Logger
{
public:
    Logger();

    void logAction( QString );
    void logSensorValues();

private:
    enum TimeStamp { weekDay, month, date, time, format, year };

    const QString msgLogFile = "/home/debian/Server/Actions.log";
    const QString sensorLogFile = "/home/debian/Server/SensorReadings.log";

    ADC adc;
};

#endif // LOGGER_H
