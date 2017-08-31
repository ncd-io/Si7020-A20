#include "spark_wiring_i2c.h"
#include "spark_wiring_constants.h"

class SI7020{
public:
    //Constructor
    SI7020(void);
    //Set Address.  Indicate status of jumpers on board.  Send 0 for not installed, send 1 for installed
    int address=0x40;
    void init();
    
    int temp_code;
    String scale="c";
    double humidity;
    double temperature;
    
    void takeReading();
    
    double getTempK();
    double getTempC();
    double getTempF();
};
