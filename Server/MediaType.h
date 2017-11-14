#ifndef MEDIATYPE_H
#define MEDIATYPE_H

#include <QMap>
#include <QString>

class MediaType
{
public:
    MediaType();

    QString toMIME( QString format );

private:
    QMap<QString, QString> map;
};

#endif // MEDIATYPE_H
