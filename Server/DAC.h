#ifndef DAC_H
#define DAC_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#define SLOTS "/sys/devices/platform/bone_capemgr/slots"
#define PWM_PATH "/sys/class/pwm/pwmchip0/export"
#define PWM_PERIOD "/sys/class/pwm/pwmchip0/pwm0/period"
#define PWM_DUTY_CYCLE "/sys/class/pwm/pwmchip0/pwm0/duty_cycle"
#define PWM_ENABLE "/sys/class/pwm/pwmchip0/pwm0/enable"

class DAC
{
public:
    DAC();
    ~DAC();

    // Set PWM intensity (0 - 100)
    void setIntensity( uint8_t );

private:
    // Load am33xx_pwm and BB-PWM1 overlays
    void load();
    // Unload am33xx_pwm and BB-PWM1 overlays
    void unload();
    // Return a 2 element array with am33xx_pwm and BB-PWM1 slot numbers
    void getSlotNumbers( int* );
};

#endif // DAC_H
