#!/bin/bash
set -eu

GPIO_VALUE="/sys/class/gpio/gpio60/value"

if [ $1 -eq 0 ];
then
    echo 0 > ${GPIO_VALUE}
    exit 0
elif [ $1 -eq 1 ];
then
    echo 1 > ${GPIO_VALUE}
    exit 0
fi

exit 1
