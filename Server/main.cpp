#include <QCoreApplication>
#include <QDebug>
#include "REST_Server.h"

#include "Greenhouse.h"

int main( int argc, char **argv )
{
    QCoreApplication app( argc, argv );

//    REST_Server server;

    Greenhouse &greenhouse = Greenhouse::Instance();

    while( 1 )
    {
        qDebug() << greenhouse.getHumidity() << greenhouse.getTemperature();
    }

//    return app.exec();
}
