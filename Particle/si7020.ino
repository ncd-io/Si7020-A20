// This #include statement was automatically added by the Particle IDE.
#include "SI7020.h"

SI7020 Sensor;

void setup() {
    Sensor.scale=SI7020_TEMP_FAHRENHEIT;
    Sensor.heater_status = SI7020_HEATER_ENABLED;
    Sensor.heater_level = 12;
    Sensor.init();
    Particle.variable("temperature", Sensor.temperature);
    Particle.variable("humidity", Sensor.humidity);
    Particle.variable("dew_point", Sensor.dew_point);
}

void loop() {
    Sensor.takeReading();
}
