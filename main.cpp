#include <QCoreApplication>
#include <QDebug>
#include "REST_Server.h"

int main( int argc, char **argv )
{
    QCoreApplication app( argc, argv );

    REST_Server server;

    return app.exec();
}
