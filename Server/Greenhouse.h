#ifndef GREENHOUSE_H
#define GREENHOUSE_H

#include <QThread>
#include <unistd.h>
#include "ADC.h"
#include "DAC.h"
#include "GPIO.h"
#include "HIH8120.h"

#include <QDebug>

class Greenhouse;

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
    static Greenhouse& Instance();

    Greenhouse( Greenhouse const& ) = delete;
    void operator = ( Greenhouse const& ) = delete;

    // Return humidity value
    int getHumidity();
    int getTemperature();
    int getLight();

    // Automaticaly set humidity to given value
    void setHumidity( int );
    void setTemperature( int );
    void setLight( int );

    // Return true is humidity is being automaticaly controlled
    bool getAutoHumidity();
    bool getAutoTemperature();
    bool getAutoLight();

    // Automaticaly keep humidity at it's current value
    void setAutoHumidity( bool );
    void setAutoTemperature( bool );
    void setAutoLight( bool );

    // Return lid value
    int getLid();
    bool getHeater();
    int getLamp();

    // Set lid value
    void setLid( int );
    void setHeater( bool );
    void setLamp( int );

private:
    Greenhouse();

    HumidityController humidityController;
    TemperatureController temperatureController;
    LightController lightController;
    HIH8120 *hih8120;
    ADC *adc;
    DAC *dac;
    GPIO *gpio49;
    GPIO *gpio115;

    int lampValue, lidValue;
    bool heaterValue;
};

#endif // GREENHOUSE_H
