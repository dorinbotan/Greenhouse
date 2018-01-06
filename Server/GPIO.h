#ifndef GPIO_H
#define GPIO_H

#include <fstream>
#include <string>
#include <sstream>

#define GPIO_PATH "/sys/class/gpio"

class GPIO
{
public:
    GPIO( int );

    // False - in
    // True - out
    void setDirection( bool );
    bool getDirection();

//    void setValue( int );
//    int getValue();

private:
    void init();

    int port;
};

#endif // GPIO_H
