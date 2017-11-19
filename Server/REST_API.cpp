#include "REST_API.h"
#include <QDebug>

using QtJson::JsonObject;
using QtJson::JsonArray;

QString REST_API::processTemperature( QHttpRequestHeader header, QString body )
{
    QString responseHeader, responseBody;

    if( header.method().compare( "GET" ) == 0 )
    {
        // Return temperature value
        responseBody = QString::number( greenhouse.getTemperature() );
        responseHeader = getResponseHeader( 200, responseBody.size(),
                                            mediaType.toMIME( "text/plain" ) ).toString();
    }
    else if( header.method().compare( "POST" ) == 0 )
    {
        // Enable automatic temperature control at given value
        // TODO: implement
    }
    else if( header.method().compare( "PUT" ) == 0 )
    {
        // Reset desired temperature value
        // TODO: implement
    }
    else if( header.method().compare( "DELETE" ) == 0 )
    {
        // Disable automatic temperature control
        greenhouse.setHeater( greenhouse.getHeater() );
        responseHeader = getResponseHeader( 200 ).toString();
    }

    return responseHeader + responseBody;
}

QString REST_API::processTemperatureMode( QHttpRequestHeader header, QString body )
{
    // TODO: implement
    return getResponseHeader( 404 ).toString();
}

QString REST_API::processHumidity( QHttpRequestHeader header, QString body )
{
    QString responseHeader, responseBody;

    if( header.method().compare( "GET" ) == 0 )
    {
        // Return humidity value
        responseBody = QString::number( greenhouse.getHumidity() );
        responseHeader = getResponseHeader( 200, responseBody.size(),
                                            mediaType.toMIME( "text/plain" ) ).toString();
    }
    else if( header.method().compare( "POST" ) == 0 )
    {
        // Enable automatic humidity control at given value
        // TODO: implement
    }
    else if( header.method().compare( "PUT" ) == 0 )
    {
        // Reset desired humidity value
        // TODO: implement
    }
    else if( header.method().compare( "DELETE" ) == 0 )
    {
        // Disable automatic humidity control
        greenhouse.setLid( greenhouse.getLid() );
        responseHeader = getResponseHeader( 200 ).toString();
    }

    return responseHeader + responseBody;
}

QString REST_API::processHumidityMode( QHttpRequestHeader header, QString body )
{
    // TODO: implement
    return getResponseHeader( 404 ).toString();
}

QString REST_API::processLight( QHttpRequestHeader header, QString body )
{
    QString responseHeader, responseBody;

    if( header.method().compare( "GET" ) == 0 )
    {
        // Return light value
        responseBody = QString::number( greenhouse.getLight() );
        responseHeader = getResponseHeader( 200, responseBody.size(),
                                            mediaType.toMIME( "text/plain" ) ).toString();
    }
    else if( header.method().compare( "POST" ) == 0 )
    {
        // Enable automatic light control at given value
        // TODO: implement
    }
    else if( header.method().compare( "PUT" ) == 0 )
    {
        // Reset desired light value
        // TODO: implement
    }
    else if( header.method().compare( "DELETE" ) == 0 )
    {
        // Disable automatic light control
        greenhouse.setLamp( greenhouse.getLamp() );
        responseHeader = getResponseHeader( 200 ).toString();
    }

    return responseHeader + responseBody;
}

QString REST_API::processLightMode( QHttpRequestHeader header, QString body )
{
    // TODO: implement
    return getResponseHeader( 404 ).toString();
}

QString REST_API::processHeater( QHttpRequestHeader header, QString body )
{
    // TODO: implement
    return getResponseHeader( 404 ).toString();
}

QString REST_API::processLid( QHttpRequestHeader header, QString body )
{
    // TODO: implement
    return getResponseHeader( 404 ).toString();
}

QString REST_API::processLamp( QHttpRequestHeader header, QString body )
{
    // TODO: implement
    return getResponseHeader( 404 ).toString();
}

QHttpResponseHeader REST_API::getResponseHeader( quint16 responseCode,
                                                 int contentLength,
                                                 QString contentType )
{
    QHttpResponseHeader toReturn( responseCode );
    if( !contentType.isEmpty() )
    {
        toReturn.setContentType( contentType );
    }
    toReturn.setContentLength( contentLength );
    toReturn.setValue( "server", "BeagleBone Black Greenhouse" );
    return toReturn;
}
