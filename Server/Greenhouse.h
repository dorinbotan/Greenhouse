#ifndef GREENHOUSE_H
#define GREENHOUSE_H

#include <QThread>
#include <unistd.h>
#include "ADC.h"
#include "DAC.h"
#include "HIH8120.h"
#include "HumidityController.h"
#include "TemperatureController.h"
#include "LightController.h"

#include <QDebug>

class Greenhouse
{
public:
    static Greenhouse& Instance();

    Greenhouse( Greenhouse const& ) = delete;
    void operator = ( Greenhouse const& ) = delete;

    int getHumidity();
    int getTemperature();
    int getLight();

//    void setHumidity( int );
//    void setTemperature( int );
    void setLight( int );

    int getLid();
    bool getHeater();
    int getLamp();

//    void setLid( int );
//    void setHeater( bool );
    void setLamp( int );

private:
    Greenhouse();

    HumidityController humidityController;
    TemperatureController temperatureController;
    LightController lightController;
    HIH8120 *hih8120;
    ADC *adc;
    DAC *dac;

    int lampValue, lidValue;
    bool heaterValue;
};

#endif // GREENHOUSE_H
