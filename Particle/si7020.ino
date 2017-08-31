// This #include statement was automatically added by the Particle IDE.
#include "SI7020.h"

SI7020 sensor;

void setup() {
    sensor.scale="f";
    sensor.init();
    Particle.variable("temperature", sensor.temperature);
    Particle.variable("humidity", sensor.humidity);
    Particle.function("getTemp", getTemp);
}

int last_read = 0;
void loop() {
    int now = millis();
    if(now-last_read > 1000){
        last_read = now;
        sensor.takeReading();
    }
    
}

int getTemp(String scale){
    if(scale.equalsIgnoreCase("f")){
        return sensor.getTempF();
    }
    if(scale.equalsIgnoreCase("c")){
        return sensor.getTempC();
    }
    if(scale.equalsIgnoreCase("k")){
        return sensor.getTempK();
    }
    return 0;
}
