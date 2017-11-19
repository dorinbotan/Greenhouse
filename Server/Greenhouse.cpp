#include "Greenhouse.h"

Greenhouse::Greenhouse()
{
    hih8120 = new HIH8120(2, 0x27);
    adc = new ADC();
}

Greenhouse::~Greenhouse()
{
    delete hih8120;
    delete adc;
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
