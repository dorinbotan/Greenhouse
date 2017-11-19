#ifndef TEMPERATURECONTROLLER_H
#define TEMPERATURECONTROLLER_H

#include <QObject>
#include <QThread>
//#include "Greenhouse.h"

class TemperatureController : public QThread
{
    Q_OBJECT

public:
    int value;

protected:
    void run();
};

#endif // TEMPERATURECONTROLLER_H
