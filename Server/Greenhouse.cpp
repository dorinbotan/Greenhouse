#include "Greenhouse.h"

void HumidityController::run()
{
    while( 1 )
    {
        usleep(1000000);
    }
}

void TemperatureController::run()
{
    while( 1 )
    {
        usleep(1000000);
    }
}

void LightController::run()
{
    while( 1 )
    {
        usleep(1000000);
    }
}

Greenhouse::Greenhouse()
{
    hih8120 = new HIH8120(2, 0x27);
    adc = new ADC();
    dac = new DAC();

    setLamp( 0 );
}

Greenhouse::~Greenhouse()
{
    delete hih8120;
    delete adc;
    delete dac;
}

uint8_t Greenhouse::getHumidity()
{
    return hih8120->getHumidity();
}

uint8_t Greenhouse::getTemperature()
{
    return hih8120->getTemperature();
}

uint16_t Greenhouse::getLight()
{
    return adc->readAnalog( 0 );
}

void Greenhouse::setLight( int value )
{
    lightController.value = value;
    lightController.start();
}

uint8_t Greenhouse::getLid()
{
    return lidValue;
}

bool Greenhouse::getHeater()
{
    return heaterValue;
}

uint8_t Greenhouse::getLamp()
{
    return lampValue;
}

void Greenhouse::setLamp( uint8_t value )
{
    lampValue = value;
    dac->setIntensity( lampValue );
}
