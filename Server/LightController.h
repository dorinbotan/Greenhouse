#ifndef LIGHTCONTROLLER_H
#define LIGHTCONTROLLER_H

#include <QObject>
#include <QThread>
//#include "Greenhouse.h"

class LightController : public QThread
{
    Q_OBJECT

public:
    int value;

protected:
    void run();
};

#endif // LIGHTCONTROLLER_H
