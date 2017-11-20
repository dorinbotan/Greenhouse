#!/bin/bash
set -eu

PWM_LID="/sys/class/pwm/pwmchip0"
ENABLE_LID="${PWM_LID}/pwm0/enable"
DUTY_CYCLE_LID="${PWM_LID}/pwm0/duty_cycle"
OPEN=1150000
CLOSED=1800000

if ((${1} >= 0 && ${1} <= 100))
then
    lid_value=$((${CLOSED} - $(($(($((${CLOSED} - ${OPEN})) / 100)) * $1))))
    echo ${lid_value} > ${DUTY_CYCLE_LID}
    echo 1 > ${ENABLE_LID}
    sleep 1
    echo 0 > ${ENABLE_LID}
    exit 0
fi
exit 1
