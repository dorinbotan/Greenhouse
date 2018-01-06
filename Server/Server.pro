QT += network

QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    JSON.h \
    MediaType.h \
    REST_API.h \
    REST_Server.h \
    ADC.h \
    DAC.h \
    HIH8120.h \
    I2CDevice.h \
    Logger.h \
    Greenhouse.h \
    GPIO.h

SOURCES += \
    JSON.cpp \
    main.cpp \
    MediaType.cpp \
    REST_API.cpp \
    REST_Server.cpp \
    ADC.cpp \
    DAC.cpp \
    HIH8120.cpp \
    I2CDevice.cpp \
    Logger.cpp \
    Greenhouse.cpp \
    GPIO.cpp
