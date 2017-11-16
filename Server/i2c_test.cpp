#include <iostream>
#include <string>
#include "HIH8120.h"

using namespace exploringBB;

int main(int argc, char **args)
{
    HIH8120 sensor(2, 0x27);
    float temperature = sensor.getTemperature();
    float humidity = sensor.getHumidity();
    std::cout << "Humidity: " << humidity << std::endl;
    std::cout << "Temperature: " << temperature << std::endl;
  
}
