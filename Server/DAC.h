#ifndef DAC_H
#define DAC_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <QDebug>

#define SLOTS "/sys/devices/platform/bone_capemgr/slots"
#define PWM_PATH "/sys/class/pwm/pwmchip0/export"
#define PWM1A_PERIOD "/sys/class/pwm/pwmchip0/pwm0/period"
#define PWM1A_DUTY_CYCLE "/sys/class/pwm/pwmchip0/pwm0/duty_cycle"
#define PWM1A_ENABLE "/sys/class/pwm/pwmchip0/pwm0/enable"
#define PWM1B_PERIOD "/sys/class/pwm/pwmchip0/pwm1/period"
#define PWM1B_DUTY_CYCLE "/sys/class/pwm/pwmchip0/pwm1/duty_cycle"
#define PWM1B_ENABLE "/sys/class/pwm/pwmchip0/pwm1/enable"

class DAC
{
public:
    DAC();
    ~DAC();

    // Set PWM1A intensity (0 - 100)
    void setIntensity1A( int );
    // Set PWM1B intensity (0 - 100)
    void setIntensity1B( int );

private:
    // Load am33xx_pwm and BB-PWM1 overlays
    void load();
    // Unload am33xx_pwm and BB-PWM1 overlays
    void unload();
    // Return a 2 element array with am33xx_pwm and BB-PWM1 slot numbers
    void getSlotNumbers( int* );
};

#endif // DAC_H
