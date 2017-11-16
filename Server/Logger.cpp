#include "Logger.h"
#include <QFile>
#include <QTextStream>
#include <QProcess>

Logger::Logger()
{

}

void Logger::logAction( QString message )
{
    QFile file( msgLogFile );

    if ( file.open( QIODevice::ReadWrite | QIODevice::Append ) )
    {
        QProcess process;
        process.start( "date", QStringList() );

        process.waitForStarted();
        process.waitForFinished();

        QString timeStamp = process.readAll();

        QTextStream stream( &file );
        stream << timeStamp << message << endl;

        file.close();
    }
}

void Logger::logSensorValues()
{

}
