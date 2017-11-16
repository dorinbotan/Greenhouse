#ifndef ADC_H
#define ADC_H

#include <fstream>
#include <string>
#include <sstream>

#define SLOTS "/sys/devices/platform/bone_capemgr/slots"
#define LDR_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"

class ADC
{
public:
    ADC();
    ~ADC();

    // Read analog value (0 - 4095)
    int readAnalog( int );

private:
    // Load BB-ADC overlay
    void load();
    // Unload BB-ADC overlay
    void unload();
    // Return -1 if BB-ADC overlay is not loaded
    int getSlotNumber();
};

#endif // ADC_H
