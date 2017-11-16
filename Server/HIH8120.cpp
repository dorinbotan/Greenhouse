#include"HIH8120.h"

/**
 * Constructor. Sets the object of type I2CDevice, to access its functions.
 * @param bus    The bus number. Usually 0 or 1 on the BBB
 * @param device The device i2c address.
 */

HIH8120::HIH8120(unsigned int bus, unsigned int device) {
    sensor = new I2CDevice(bus, device);
}

/**
 * Get humidity value in percentage
 * @return float between 0 and 100
 */
float HIH8120::getTemperature()
{
   unsigned char* data = (sensor->readDevice(4));
   float temperature = (data[2] << 6) | (data[3] >> 2);
   return temperature * (165.0/((1<<14) - 2)) - 40;
}
/**
 * Get temperature value 
 * @return float between -40 and 125
 */
float HIH8120::getHumidity()
{
   unsigned char* data = (sensor->readDevice(2));
   float humidity = ((data[0] << 8) | data[1]) & 0b0011111111111111;
   return humidity * (100.0/((1<<14) - 2));
}