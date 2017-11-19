#ifndef HUMIDITYCONTROLLER_H
#define HUMIDITYCONTROLLER_H

#include <QObject>
#include <QThread>

class HumidityController : public QThread
{
    Q_OBJECT

public:
    int value;

protected:
    void run();
};

#endif // HUMIDITYCONTROLLER_H
