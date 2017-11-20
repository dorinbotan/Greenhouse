#include "Greenhouse.h"

void HumidityController::run()
{
    Greenhouse &greenhouse = Greenhouse::Instance();

    while( 1 )
    {
        // TODO: choose appropriate border values
        if( greenhouse.getHumidity() < value && greenhouse.getLid() < 45 )
        {
            greenhouse.setLid( greenhouse.getLid() + 1 );
        }
        else if( greenhouse.getHumidity() > value && greenhouse.getLid() > 0 )
        {
            greenhouse.setLid( greenhouse.getLid() - 1 );
        }

        usleep(100000);
    }
}

void TemperatureController::run()
{
    Greenhouse &greenhouse = Greenhouse::Instance();

    while( 1 )
    {
        if( greenhouse.getTemperature() < value && greenhouse.getHeater() == 0 )
        {
            greenhouse.setHeater( 1 );
        }
        else if( greenhouse.getTemperature() > value && greenhouse.getHeater() == 1 )
        {
            greenhouse.setHeater( 0 );
        }

        usleep(100000);
    }
}

void LightController::run()
{
    Greenhouse &greenhouse = Greenhouse::Instance();

    while( 1 )
    {
        if( greenhouse.getLight() < value && greenhouse.getLamp() < 100 )
        {
            greenhouse.setLamp( greenhouse.getLamp() + 1 );
        }
        else if( greenhouse.getLight() > value && greenhouse.getLamp() > 0 )
        {
            greenhouse.setLamp( greenhouse.getLamp() - 1 );
        }

        usleep(100000);
    }
}

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

    setAutoHumidity( 0 );
    setAutoTemperature( 0 );
    setAutoLight( 0 );
    setLid( 0 );
    setHeater( 0 );
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

void Greenhouse::setHumidity( int value )
{
    humidityController.value = value;

    if( !getAutoHumidity() )
    {
        humidityController.start();
    }
}

void Greenhouse::setTemperature( int value )
{
    temperatureController.value = value;

    if( !getAutoTemperature() )
    {
        temperatureController.start();
    }
}

void Greenhouse::setLight( int value )
{
    lightController.value = value;

    if( !getAutoLight() )
    {
        lightController.start();
    }
}

bool Greenhouse::getAutoHumidity()
{
    return humidityController.isRunning();
}

bool Greenhouse::getAutoTemperature()
{
    return temperatureController.isRunning();
}

bool Greenhouse::getAutoLight()
{
    return lightController.isRunning();
}

void Greenhouse::setAutoHumidity( bool value )
{
    humidityController.value = getHumidity();

    if( value && !getAutoHumidity() )
    {
        humidityController.start();
    }
    else if( !value && getAutoHumidity() )
    {
        humidityController.exit( 0 );
    }
}

void Greenhouse::setAutoTemperature( bool value )
{
    temperatureController.value = getTemperature();

    if( value && !getAutoTemperature() )
    {
        temperatureController.start();
    }
    else if( !value && getAutoTemperature() )
    {
        temperatureController.exit( 0 );
    }
}

void Greenhouse::setAutoLight( bool value )
{
    lightController.value = getLight();

    if( value && !getAutoLight() )
    {
        lightController.start();
    }
    else if( !value && getAutoLight() )
    {
        lightController.exit( 0 );
    }
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

void Greenhouse::setLid( int value )
{
    lidValue = value;
    // Set lid
}

void Greenhouse::setHeater( bool value )
{
    heaterValue = value;
    // Set heater
}

void Greenhouse::setLamp( int value )
{
    lampValue = value;
    dac->setIntensity( lampValue );
}
