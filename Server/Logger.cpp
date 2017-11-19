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
        QStringList values = timeStamp.split(' ');

        QTextStream stream( &file );
        stream << values[time] << values[date] << values[month] << message << endl;

        file.close();
    }
}

void Logger::logSensorValues()
{
    QFile file( sensorLogFile );

    if ( file.open( QIODevice::ReadWrite | QIODevice::Append ) )
    {
        QTextStream stream( &file );
        stream << QString::number( adc.readAnalog( 0 ) ) << endl;

        file.close();
    }
}
