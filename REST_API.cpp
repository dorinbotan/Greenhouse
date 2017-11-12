#include "REST_API.h"

using QtJson::JsonObject;
using QtJson::JsonArray;

#include <QDebug>

REST_API::REST_API()
{
}

QString REST_API::processTemperature( QHttpRequestHeader header, QString body )
{
    QString responseHeader, responseBody;

    if( header.method().compare( "GET" ) == 0 )
    {
        // Return temperature value

        QString body = QString( "Temperature" );
        QString header = getResponseHeader( 200, body.size(),
                                            mediaType.toMIME( "text/plain" ) ).toString();
    }
    else if( header.method().compare( "POST" ) == 0 )
    {
        // Enable automatic temperature control at given value
    }
    else if( header.method().compare( "PUT" ) == 0 )
    {
        // Reset desired temperature value
    }
    else if( header.method().compare( "DELETE" ) == 0 )
    {
        // Disable automatic temperature control
    }

    qDebug() << responseHeader + responseBody;
    return responseHeader + responseBody;
}

QString REST_API::processHumidity( QHttpRequestHeader header, QString body )
{
    QString responseHeader, responseBody;

    if( header.method().compare( "GET" ) == 0 )
    {
        // Return humidity value

        QString body = QString( "Humidity" );
        QString header = getResponseHeader( 200, body.size(),
                                            mediaType.toMIME( "text/plain" ) ).toString();
    }
    else if( header.method().compare( "POST" ) == 0 )
    {
        // Enable automatic humidity control at given value
    }
    else if( header.method().compare( "PUT" ) == 0 )
    {
        // Reset desired humidity value
    }
    else if( header.method().compare( "DELETE" ) == 0 )
    {
        // Disable automatic humidity control
    }

    return responseHeader + responseBody;
}

QString REST_API::processLight( QHttpRequestHeader header, QString body )
{
    QString responseHeader, responseBody;

    if( header.method().compare( "GET" ) == 0 )
    {
        // Return light value

        QString body = QString( "Light" );
        QString header = getResponseHeader( 200, body.size(),
                                            mediaType.toMIME( "text/plain" ) ).toString();
    }
    else if( header.method().compare( "POST" ) == 0 )
    {
        // Enable automatic light control at given value
    }
    else if( header.method().compare( "PUT" ) == 0 )
    {
        // Reset desired light value
    }
    else if( header.method().compare( "DELETE" ) == 0 )
    {
        // Disable automatic light control
    }

    return responseHeader + responseBody;
}

QHttpResponseHeader REST_API::getResponseHeader( quint16 responseCode,
                                                 int contentLength,
                                                 QString contentType )
{
    QHttpResponseHeader toReturn( responseCode );
    toReturn.setContentType( contentType );
    toReturn.setContentLength( contentLength );
    toReturn.setValue( "server", "BeagleBona Black EOS project" );
    return toReturn;
}
