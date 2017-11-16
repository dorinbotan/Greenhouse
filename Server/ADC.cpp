#include "ADC.h"

using namespace std;

ADC::ADC()
{
    if( getSlotNumber() == -1 )
    {
        load();
    }
}

ADC::~ADC()
{
    if( getSlotNumber() != -1 )
    {
        unload();
    }
}

int ADC::readAnalog( int number )
{
    stringstream ss;
    ss << LDR_PATH << number << "_raw";
    fstream fs;
    fs.open( ss.str().c_str(), fstream::in );
    fs >> number;
    fs.close();
    return number;
}

void ADC::load()
{
    fstream fs;
    fs.open( SLOTS, fstream::out );
    fs << "BB-ADC";
    fs.close();
}

void ADC::unload()
{
    fstream fs;
    fs.open( SLOTS, fstream::out );
    fs << "-" << getSlotNumber();
    fs.close();
}

int ADC::getSlotNumber()
{
    string a, b, c, d, e, f, g;

    fstream fs;
    fs.open( SLOTS, fstream::in );

    while( !fs.eof() )
    {
        fs >> a >> b >> c;

        if( c != "-1" )
        {
            fs >> d >> e >> f >> g;

            if( g == "Manuf,BB-ADC" )
            {
                return std::stoi( a.substr( 0, a.find( ":" ) ) );
            }
        }
    }

    fs.close();

    return -1;
}
