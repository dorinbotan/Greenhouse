#ifndef HIH_H_
#define HIH_H_
#include"I2CDevice.h"
using namespace exploringBB;
/**
 * @class HIH8120
 * @brief Allows user to get humidity or temperature from the sensor
 */
class HIH8120{
private:
    I2CDevice* sensor;
public:
	HIH8120(unsigned int bus, unsigned int device);
	virtual float getTemperature();
	virtual float getHumidity();
};
#endif /* HIH_H_ */
