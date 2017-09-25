#include "spark_wiring_i2c.h"
#include "spark_wiring_constants.h"

//Configuration Register
#define SI7020_CONFIG_REG_READ 0xE7
#define SI7020_CONFIG_REG_WRITE 0xE6

#define SI7020_RES_RH12_TMP14 0x00 // 22.8
#define SI7020_RES_RH8_TMP12 0x01 // 6.9
#define SI7020_RES_RH10_TMP_13 0x80 // 10.7
#define SI7020_RES_RH11_TMP11 0x81 // 9.4

#define SI7020_HEATER_ENABLED 0x04

#define SI7020_CONFIG_RSVD 0x3A

#define SI7020_HOLD_MODE 0x00
#define SI7020_NO_HOLD_MODE 0x10

#define SI7020_HUMIDITY_REG 0xE5
#define SI7020_TEMP_REG 0xE3
#define SI7020_TEMP_AFTER_RH 0xE0

#define SI7020_RESET 0xFE

//Heater setting, allows value between 0 and 15
#define SI7020_HEATER_WRITE 0x51
#define SI7020_HEATER_READ 0x11

#define SI7020_HEATER_RESERVED 0xF0

#define TEMP_CELSIUS 0x00
#define TEMP_FAHRENHEIT 0x01
#define TEMP_KELVIN 0x02

class SI7020{
public:
    //Constructor
    int address=0x40;
    void init();
    
    int hold_mode = SI7020_HOLD_MODE;
    int reading_waiting = 0;
    int getDelay();
    
    int resolution = SI7020_RES_RH12_TMP14;
    int heater_status = 0;
    int heater_level = 0;
    
    int scale = TEMP_CELSIUS;
    double humidity;
    double temperature;
    
    void takeReading();
private:
    void begin();
    void writeByte(int reg, int data);
    int readByte(int reg);
    void readBuffer(int reg, int *buff, int length);
};
