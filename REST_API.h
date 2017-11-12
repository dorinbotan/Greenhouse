#ifndef REST_API_H
#define REST_API_H

#include <QHttpResponseHeader>
#include "MediaType.h"
#include "JSON.h"

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
};

#endif // REST_API_H
