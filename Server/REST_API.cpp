#include "REST_API.h"

#include <QDebug>

using QtJson::JsonObject;
using QtJson::JsonArray;

QString REST_API::processTemperature( QHttpRequestHeader header, QString body )
{
    QString responseHeader = getResponseHeader( 404 ).toString();
    QString responseBody;

    if( header.method().compare( "GET" ) == 0 )
    {
        // Return temperature value
        responseBody = QString::number( greenhouse.getTemperature() );
        responseHeader = getResponseHeader( 200, responseBody.size(),
                                            mediaType.toMIME( "text/plain" ) ).toString();

        qDebug() << "GET /temperature" << responseBody;
    }
    else if( header.method().compare( "POST" ) == 0 )
    {
        // Enable automatic temperature control at given value
        greenhouse.setTemperature( body.toInt() );
        responseHeader = getResponseHeader( 200 ).toString();

        qDebug() << "POST /temperature" << body;
    }
    else if( header.method().compare( "DELETE" ) == 0 )
    {
        // Disable automatic temperature control (turn off heater)
        greenhouse.setAutoTemperature( false );
        greenhouse.setHeater( 0 );
        responseHeader = getResponseHeader( 200 ).toString();

        qDebug() << "DELETE /temperature";
    }

    return responseHeader + responseBody;
}

QString REST_API::processTemperatureMode( QHttpRequestHeader header )
{
    QString responseHeader = getResponseHeader( 404 ).toString();
    QString responseBody;

     if( header.method().compare( "GET" ) == 0 )
     {
         // Return auto temperature value
         responseBody = QString::number( greenhouse.getAutoTemperature() );
         responseHeader = getResponseHeader( 200, responseBody.size(),
                                             mediaType.toMIME( "text/plain" ) ).toString();

         qDebug() << "GET /temperature/mode" << responseBody;
     }
     else if( header.method().compare( "POST" ) == 0 )
     {
         // Automaticaly maintain current temperature
         greenhouse.setAutoTemperature( true );
         responseHeader = getResponseHeader( 200 ).toString();

         qDebug() << "POST /temperature/mode";
     }
     else if( header.method().compare( "DELETE" ) == 0 )
     {
         // Disable automatic temperature control
         greenhouse.setAutoTemperature( false );
         greenhouse.setHeater( 0 );
         responseHeader = getResponseHeader( 200 ).toString();

         qDebug() << "DELETE /temperature/mode";
     }

     return responseHeader + responseBody;
}

QString REST_API::processHumidity( QHttpRequestHeader header, QString body )
{
    QString responseHeader = getResponseHeader( 404 ).toString();
    QString responseBody;

    if( header.method().compare( "GET" ) == 0 )
    {
        // Return humidity value
        responseBody = QString::number( greenhouse.getHumidity() );
        responseHeader = getResponseHeader( 200, responseBody.size(),
                                            mediaType.toMIME( "text/plain" ) ).toString();

        qDebug() << "GET /humidity" << responseBody;
    }
    else if( header.method().compare( "POST" ) == 0 )
    {
        // Enable automatic humidity control at given value
        greenhouse.setHumidity( body.toInt() );
        responseHeader = getResponseHeader( 200 ).toString();

        qDebug() << "POST /humidity" << body;
    }
    else if( header.method().compare( "DELETE" ) == 0 )
    {
        // Disable automatic humidity control (close the lid)
        greenhouse.setAutoHumidity( false );
        greenhouse.setLid( 0 );
        responseHeader = getResponseHeader( 200 ).toString();

        qDebug() << "DELETE /humidity";
    }

    return responseHeader + responseBody;
}

QString REST_API::processHumidityMode( QHttpRequestHeader header )
{
    QString responseHeader = getResponseHeader( 404 ).toString();
    QString responseBody;

     if( header.method().compare( "GET" ) == 0 )
     {
         // Return auto humidity value
         responseBody = QString::number( greenhouse.getAutoHumidity() );
         responseHeader = getResponseHeader( 200, responseBody.size(),
                                             mediaType.toMIME( "text/plain" ) ).toString();

         qDebug() << "GET /humidity/mode" << responseBody;
     }
     else if( header.method().compare( "POST" ) == 0 )
     {
         // Automaticaly maintain current humidity
         greenhouse.setAutoHumidity( true );
         responseHeader = getResponseHeader( 200 ).toString();

         qDebug() << "POST /humidity";
     }
     else if( header.method().compare( "DELETE" ) == 0 )
     {
         // Disable automatic humidity control
         greenhouse.setAutoHumidity( false );
         greenhouse.setLid( 0 );
         responseHeader = getResponseHeader( 200 ).toString();

         qDebug() << "DELETE /humidity";
     }

     return responseHeader + responseBody;
}

QString REST_API::processLight( QHttpRequestHeader header, QString body )
{
    QString responseHeader = getResponseHeader( 404 ).toString();
    QString responseBody;

    if( header.method().compare( "GET" ) == 0 )
    {
        // Return light value
        responseBody = QString::number( greenhouse.getLight() );
        responseHeader = getResponseHeader( 200, responseBody.size(),
                                            mediaType.toMIME( "text/plain" ) ).toString();

        qDebug() << "GET /light" << responseBody;
    }
    else if( header.method().compare( "POST" ) == 0 )
    {
        // Enable automatic light control at given value
        greenhouse.setLight( body.toInt() );
        responseHeader = getResponseHeader( 200 ).toString();

        qDebug() << "POST /light" << body;
    }
    else if( header.method().compare( "DELETE" ) == 0 )
    {
        // Disable automatic light control (turn off lamp)
        greenhouse.setAutoLight( false );
        greenhouse.setLamp( 0 );
        responseHeader = getResponseHeader( 200 ).toString();

        qDebug() << "DELETE /light";
    }

    return responseHeader + responseBody;
}

QString REST_API::processLightMode( QHttpRequestHeader header )
{
    QString responseHeader = getResponseHeader( 404 ).toString();
    QString responseBody;

     if( header.method().compare( "GET" ) == 0 )
     {
         // Return auto light value
         responseBody = QString::number( greenhouse.getAutoLight() );
         responseHeader = getResponseHeader( 200, responseBody.size(),
                                             mediaType.toMIME( "text/plain" ) ).toString();

         qDebug() << "GET /light/mode" << responseBody;
     }
     else if( header.method().compare( "POST" ) == 0 )
     {
         // Automaticaly maintain current light level
         greenhouse.setAutoLight( true );
         responseHeader = getResponseHeader( 200 ).toString();

         qDebug() << "POST /light/mode";
     }
     else if( header.method().compare( "DELETE" ) == 0 )
     {
         // Disable automatic light control
         greenhouse.setAutoLight( false );
         greenhouse.setLamp( 0 );
         responseHeader = getResponseHeader( 200 ).toString();

         qDebug() << "DELETE /light/mode";
     }

     return responseHeader + responseBody;
}

QString REST_API::processHeater( QHttpRequestHeader header, QString body )
{
    QString responseHeader = getResponseHeader( 404 ).toString();
    QString responseBody;

    if( header.method().compare( "GET" ) == 0 )
    {
        // Return heater value
        responseBody = QString::number( greenhouse.getHeater() );
        responseHeader = getResponseHeader( 200, responseBody.size(),
                                            mediaType.toMIME( "text/plain" ) ).toString();

        qDebug() << "GET /heater" << responseBody;
    }
    else if( header.method().compare( "POST" ) == 0 )
    {
        // Enable manual temperature control and set heater to desired value
        greenhouse.setAutoTemperature( false );
        greenhouse.setHeater( body.toInt() );
        responseHeader = getResponseHeader( 200 ).toString();

        qDebug() << "POST /heater" << body;
    }
    else if( header.method().compare( "DELETE" ) == 0 )
    {
        // Disable manual temperature control and keep current temperature
        greenhouse.setAutoTemperature( true );
        responseHeader = getResponseHeader( 200 ).toString();

        qDebug() << "DELETE /heater";
    }

    return responseHeader + responseBody;
}

QString REST_API::processLid( QHttpRequestHeader header, QString body )
{
    QString responseHeader = getResponseHeader( 404 ).toString();
    QString responseBody;

    if( header.method().compare( "GET" ) == 0 )
    {
        // Return lid value
        responseBody = QString::number( greenhouse.getLid() );
        responseHeader = getResponseHeader( 200, responseBody.size(),
                                            mediaType.toMIME( "text/plain" ) ).toString();

        qDebug() << "GET /lid" << responseBody;
    }
    else if( header.method().compare( "POST" ) == 0 )
    {
        // Enable manual humidity control and set lid to desired value
        greenhouse.setAutoHumidity( false );
        greenhouse.setLid( body.toInt() );
        responseHeader = getResponseHeader( 200 ).toString();

        qDebug() << "POST /lid" << body;
    }
    else if( header.method().compare( "DELETE" ) == 0 )
    {
        // Disable manual humidity control and keep current humidity level
        greenhouse.setAutoHumidity( true );
        responseHeader = getResponseHeader( 200 ).toString();

        qDebug() << "DELETE /lid";
    }

    return responseHeader + responseBody;
}

QString REST_API::processLamp( QHttpRequestHeader header, QString body )
{
    QString responseHeader = getResponseHeader( 404 ).toString();
    QString responseBody;

    if( header.method().compare( "GET" ) == 0 )
    {
        // Return lamp value
        responseBody = QString::number( greenhouse.getLamp() );
        responseHeader = getResponseHeader( 200, responseBody.size(),
                                            mediaType.toMIME( "text/plain" ) ).toString();

        qDebug() << "GET /lamp" << responseBody;
    }
    else if( header.method().compare( "POST" ) == 0 )
    {
        // Enable manual light control and set lamp to desired value
        greenhouse.setAutoLight( false );
        greenhouse.setLamp( body.toInt() );
        responseHeader = getResponseHeader( 200 ).toString();

        qDebug() << "POST /lamp" << body;
    }
    else if( header.method().compare( "DELETE" ) == 0 )
    {
        // Disable manual light control and keep current light level
        greenhouse.setAutoLight( true );
        responseHeader = getResponseHeader( 200 ).toString();

        qDebug() << "DELETE /lamp";
    }

    return responseHeader + responseBody;
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
