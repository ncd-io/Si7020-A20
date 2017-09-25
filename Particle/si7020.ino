// This #include statement was automatically added by the Particle IDE.
#include "SI7020.h"

SI7020 sensor;

void setup() {
    sensor.scale=TEMP_FAHRENHEIT;
    sensor.heater_status = SI7020_HEATER_ENABLED;
    sensor.heater_level = 12;
    sensor.init();
    Particle.variable("temperature", sensor.temperature);
    Particle.variable("humidity", sensor.humidity);
}

void loop() {
    sensor.takeReading();
}
