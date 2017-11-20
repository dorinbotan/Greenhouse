#ifndef REST_API_H
#define REST_API_H

#include <QHttpResponseHeader>
#include "MediaType.h"
#include "JSON.h"
#include "Greenhouse.h"

class REST_API
{
public:
    QString processTemperature( QHttpRequestHeader header, QString body );
    QString processTemperatureMode( QHttpRequestHeader header );
    QString processHumidity( QHttpRequestHeader header, QString body );

    QString processHumidityMode( QHttpRequestHeader header );
    QString processLight( QHttpRequestHeader header, QString body );
    QString processLightMode( QHttpRequestHeader header );

    QString processHeater( QHttpRequestHeader header, QString body );
    QString processLid( QHttpRequestHeader header, QString body );
    QString processLamp( QHttpRequestHeader header, QString body );

private:
    QHttpResponseHeader getResponseHeader( quint16 responseCode,
                                           int contentLength = 0,
                                           QString contentType = "" );

    MediaType mediaType;
    Greenhouse &greenhouse = Greenhouse::Instance();
};

#endif // REST_API_H
