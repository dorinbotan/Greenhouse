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
        responseBody = QString::number( hih8120.getTemperature() );
        responseHeader = getResponseHeader( 200, responseBody.size(),
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

    return responseHeader + responseBody;
}

QString REST_API::processHumidity( QHttpRequestHeader header, QString body )
{
    QString responseHeader, responseBody;

    if( header.method().compare( "GET" ) == 0 )
    {
        // Return humidity value
        responseBody = QString::number( hih8120.getHumidity() );
        responseHeader = getResponseHeader( 200, responseBody.size(),
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
        responseBody = QString::number( adc.readAnalog( 0 ) );
        responseHeader = getResponseHeader( 200, responseBody.size(),
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
    toReturn.setValue( "server", "BeagleBone Black Greenhouse" );
    return toReturn;
}
