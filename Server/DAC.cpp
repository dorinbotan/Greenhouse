#include "DAC.h"

using namespace std;

DAC::DAC()
{
    int slotNumbers[2];
    getSlotNumbers( slotNumbers );

    if( slotNumbers[0] == -1 || slotNumbers[1] == -1 )
    {
        load();

        fstream fs;
        fs.open( PWM_PATH, fstream::out );
        fs << 0;
        fs.close();

        fs.open( PWM_PATH, fstream::out );
        fs << 1;
        fs.close();

        fs.open( PWM1A_PERIOD, fstream::out );
        fs << 20000000;
        fs.close();

        fs.open( PWM1B_PERIOD, fstream::out );
        fs << 20000000;
        fs.close();

        fs.open( PWM1A_DUTY_CYCLE, fstream::out );
        fs << 20000000;
        fs.close();

        fs.open( PWM1B_DUTY_CYCLE, fstream::out );
        fs << 820000;
        fs.close();

        fs.open( PWM1A_ENABLE, fstream::out );
        fs << 1;
        fs.close();

        fs.open( PWM1B_ENABLE, fstream::out );
        fs << 1;
        fs.close();

        usleep( 200000 );

        fs.open( PWM1B_ENABLE, fstream::out );
        fs << 0;
        fs.close();
    }
}

DAC::~DAC()
{
    int slotNumbers[2];
    getSlotNumbers( slotNumbers );

    if( slotNumbers[0] != -1 && slotNumbers[1] != -1 )
    {
        unload();
    }
}

void DAC::setIntensity1A( int intensity )
{
    fstream fs;
    fs.open( PWM1A_DUTY_CYCLE, fstream::out );
    fs << (uint32_t)( 20000000 - ( intensity * 200000 ) );
    fs.close();
}

void DAC::setIntensity1B( int intensity )
{
    fstream fs;
    fs.open( PWM1B_DUTY_CYCLE, fstream::out );
    fs << (uint32_t)( 800000 + ( intensity * 19000 ) );
    fs.close();

    fs.open( PWM1B_ENABLE, fstream::out );
    fs << 1;
    fs.close();

    usleep( 500000 );

    fs.open( PWM1B_ENABLE, fstream::out );
    fs << 0;
    fs.close();
}

void DAC::load()
{
    fstream fs;
    fs.open( SLOTS, fstream::out );
    fs << "BB-PWM1";
    fs.close();
    fs.open( SLOTS, fstream::out );
    fs << "am33xx_pwm";
    fs.close();
}

void DAC::unload()
{
    int slotNumbers[2];
    getSlotNumbers( slotNumbers );

    fstream fs;
    fs.open( SLOTS, fstream::out );
    fs << "-" << slotNumbers[0];
    fs.flush();
    fs << "-" << slotNumbers[1];
    fs.close();
}

void DAC::getSlotNumbers( int *slotNumbers )
{
    slotNumbers[0] = -1;
    slotNumbers[1] = -1;
    string a, b, c, d, e, f, g;

    fstream fs;
    fs.open( SLOTS, fstream::in );

    while( !fs.eof() )
    {
        fs >> a >> b >> c;

        if(c != "-1")
        {
            fs >> d >> e >> f >> g;

            if( g == "Manuf,am33xx_pwm" )
            {
                slotNumbers[0] = stoi( a.substr( 0, a.find( ":" ) ) );
            }
            else if( g == "Manuf,BB-PWM1" )
            {
                slotNumbers[1] = stoi( a.substr( 0, a.find( ":" ) ) );
            }
        }
    }

    fs.close();
}
