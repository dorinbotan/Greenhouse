#include "Greenhouse.h"

Greenhouse& Greenhouse::Instance()
{
    static Greenhouse instance;
    return instance;
}

Greenhouse::Greenhouse()
{
    hih8120 = new HIH8120(2, 0x27);
    adc = new ADC();
    dac = new DAC();

    setLamp( 0 );
}

int Greenhouse::getHumidity()
{
    return hih8120->getHumidity();
}

int Greenhouse::getTemperature()
{
    return hih8120->getTemperature();
}

int Greenhouse::getLight()
{
    return adc->readAnalog( 0 );
}

void Greenhouse::setLight( int value )
{
//    lightController.value = value;
//    lightController.start();
}

int Greenhouse::getLid()
{
    return lidValue;
}

bool Greenhouse::getHeater()
{
    return heaterValue;
}

int Greenhouse::getLamp()
{
    return lampValue;
}

void Greenhouse::setLamp( int value )
{
    lampValue = value;
    dac->setIntensity( lampValue );
}
