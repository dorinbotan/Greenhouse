#include "HumidityController.h"
#include "Greenhouse.h"

#include <QDebug>

void HumidityController::run()
{
    Greenhouse &greenhouse = Greenhouse::Instance();

    while( 1 )
    {
        usleep(1000000);
    }
}
