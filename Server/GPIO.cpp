#include "GPIO.h"

using namespace std;

GPIO::GPIO( int port )
{
    this->port = port;
    init();
}

void GPIO::setDirection( bool out )
{
    string buf( GPIO_PATH );
    buf.append( "/gpio" + to_string( port ) + "/direction" );

    fstream fs;
    fs.open( buf, fstream::out );
    fs << ( out ? "out" : "in" );
    fs.close();
}

bool GPIO::getDirection()
{
    string out;

    string buf( GPIO_PATH );
    buf.append( "/gpio" + to_string( port ) + "/direction" );

    fstream fs;
    fs.open( buf, fstream::in );
    fs >> out;

    if ( !out.compare( "out" ) )
    {
       return 1;
    }

    return 0;
}


// Obsolete.
// TODO: consider direction

//void GPIO::setValue( int value )
//{
//    string buf( GPIO_PATH );
//    buf.append( "/gpio" + to_string( port ) + "/direction" );

//    fstream fs;
//    fs.open( buf, fstream::out );
//    fs << value;
//    fs.close();
//}

//int GPIO::getValue()
//{
//    int out;

//    string buf( GPIO_PATH );
//    buf.append( "/gpio" + to_string( port ) + "/direction" );

//    fstream fs;
//    fs.open( buf, fstream::in );
//    fs >> out;

//    return out;
//}

void GPIO::init()
{
    string buf( GPIO_PATH );
    buf.append( "/export" );

    fstream fs;
    fs.open( buf, fstream::out );
    fs << port;
    fs.close();
}

