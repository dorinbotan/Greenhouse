#include "LightController.h"
#include "Greenhouse.h"

#include <QDebug>

void LightController::run()
{
    Greenhouse &greenhouse = Greenhouse::Instance();

    while( 1 )
    {
        qDebug() << greenhouse.getLight();
        usleep(1000000);
    }
}
