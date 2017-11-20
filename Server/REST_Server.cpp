#include "REST_Server.h"
#include "JSON.h"

using QtJson::JsonObject;
using QtJson::JsonArray;

REST_Server::REST_Server( QObject *parent )
    : QObject( parent ), tcpServer(0)
{
    api = new REST_API();
    tcpServer = new QTcpServer(this);

    if( !tcpServer->listen( QHostAddress::Any, 8091 ) )
    {
        qDebug() << QString( "Unable to start the server: %1." )
                    .arg( tcpServer->errorString() );
        return;
    }
    else
    {
        // Print information about the running server
        foreach( const QHostAddress &address, QNetworkInterface::allAddresses() )
        {
            if( address != QHostAddress::LocalHost && address.toIPv4Address())
            {
                qDebug() << QString( "REST API is running.\nIPv4: %1\nPORT: %2" )
                            .arg( address.toString() )
                            .arg( tcpServer->serverPort() );

                break;
            }
        }
    }

    connect( tcpServer, SIGNAL( newConnection() ),
             this, SLOT( newClient() ) );
}

REST_Server::~REST_Server()
{
    delete api;
    delete tcpServer;
}

void REST_Server::newClient()
{
    QTcpSocket *clientSocket = tcpServer->nextPendingConnection();
    int idusersocs = clientSocket->socketDescriptor();

    qDebug() << "User ID: " << idusersocs;

    SClients[ idusersocs ] = clientSocket;
    connect( clientSocket, SIGNAL( readyRead() ),
             this, SLOT( readClient() ));
}

void REST_Server::readClient()
{
    QTcpSocket *clientSocket = reinterpret_cast<QTcpSocket*>( sender() );
    int idusersocs = clientSocket->socketDescriptor();
    QTextStream os( clientSocket );
    os.setAutoDetectUnicode( true );

    QString request = clientSocket->readAll();
    QHttpRequestHeader requestHeader( request );
    QString requestBody = getRequestBody( request );

    if( QString::compare( requestHeader.path(), "/temperature", Qt::CaseInsensitive) == 0 )
    {
        os << api->processTemperature( requestHeader, requestBody );
    }
    else if( QString::compare( requestHeader.path(), "/temperature/mode", Qt::CaseInsensitive) == 0 )
    {
        os << api->processTemperatureMode( requestHeader );
    }
    else if( QString::compare( requestHeader.path(), "/humidity", Qt::CaseInsensitive) == 0 )
    {
        os << api->processHumidity( requestHeader, requestBody );
    }
    else if( QString::compare( requestHeader.path(), "/humidity/mode", Qt::CaseInsensitive) == 0 )
    {
        os << api->processHumidityMode( requestHeader );
    }
    else if( QString::compare( requestHeader.path(), "/light", Qt::CaseInsensitive) == 0 )
    {
        os << api->processLight( requestHeader, requestBody );
    }
    else if( QString::compare( requestHeader.path(), "/light/mode", Qt::CaseInsensitive) == 0 )
    {
        os << api->processLightMode( requestHeader );
    }
    else if( QString::compare( requestHeader.path(), "/heater", Qt::CaseInsensitive) == 0 )
    {
        os << api->processHeater( requestHeader, requestBody );
    }
    else if( QString::compare( requestHeader.path(), "/lid", Qt::CaseInsensitive) == 0 )
    {
        os << api->processLid( requestHeader, requestBody );
    }
    else if( QString::compare( requestHeader.path(), "/lamp", Qt::CaseInsensitive) == 0 )
    {
        os << api->processLamp( requestHeader, requestBody );
    }

    clientSocket->close();
    SClients.remove( idusersocs );
}

QString REST_Server::getRequestBody( QString request )
{
    int bodyIndex = request.indexOf(QString( "\r\n\r\n" ) ) + 4;
    return request.right( request.length() - bodyIndex );
}
