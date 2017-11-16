#ifndef REST_API_H
#define REST_API_H

#include <QHttpResponseHeader>
#include "MediaType.h"
#include "JSON.h"
#include "ADC.h"
#include "HIH8120.h"

class REST_API
{
public:
    REST_API();

    QString processTemperature( QHttpRequestHeader header, QString body );
    QString processHumidity( QHttpRequestHeader header, QString body );
    QString processLight( QHttpRequestHeader header, QString body );

private:
    QHttpResponseHeader getResponseHeader( quint16 responseCode,
                                           int contentLength,
                                           QString contentType );

    MediaType mediaType;
    ADC adc;
    HIH8120 hih8120;
};

#endif // REST_API_H
