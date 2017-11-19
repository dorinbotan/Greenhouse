#ifndef GREENHOUSE_H
#define GREENHOUSE_H

#include "HIH8120.h"
#include "ADC.h"

class Greenhouse
{
public:
    Greenhouse();
    ~Greenhouse();

    int getHumidity();
    int getTemperature();
    int getLight();

private:
    HIH8120 *hih8120;
    ADC *adc;
};

#endif // GREENHOUSE_H
