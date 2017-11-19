#ifndef GREENHOUSE_H
#define GREENHOUSE_H

#include <QThread>
#include <unistd.h>
#include "HIH8120.h"
#include "ADC.h"
#include "DAC.h"

#include <QDebug>

class HumidityController : public QThread
{
    Q_OBJECT

public:
    int value;

protected:
    void run();
};

class TemperatureController : public QThread
{
    Q_OBJECT

public:
    int value;

protected:
    void run();
};

class LightController : public QThread
{
    Q_OBJECT

public:
    int value;

protected:
    void run();
};

class Greenhouse
{
public:
    Greenhouse();
    ~Greenhouse();

    uint8_t getHumidity();
    uint8_t getTemperature();
    uint16_t getLight();

//    void setHumidity( int );
//    void setTemperature( int );
    void setLight( int );

    uint8_t getLid();
    bool getHeater();
    uint8_t getLamp();

//    void setLid( uint8_t );
//    void setHeater( bool );
    void setLamp( uint8_t );

private:
    TemperatureController humidityController;
    TemperatureController temperatureController;
    TemperatureController lightController;
    HIH8120 *hih8120;
    ADC *adc;
    DAC *dac;

    uint8_t lampValue, lidValue;
    bool heaterValue;
};

#endif // GREENHOUSE_H
