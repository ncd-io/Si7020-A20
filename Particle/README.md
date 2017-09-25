# Usage

This library provides a class for reading the temperature and humidity from the Si7020-A20. The si7020.ino file provides a simple use case for the Psrticle cloud.

>Create a new instance of the sensor
```cpp
SI7020 Sensor;
```

>Initialize the sensor
```cpp
Sensor.init();
```

>Take readings from the sensor
```cpp
Sensor.takeReading();
```

>Get the current values
```cpp
double humidity = Sensor.humidity;
double temperature = Sensor.temperature;
```

>Turn the internal heater on or off, init() must be called after this
```cpp
//turn on
Sensor.heater_status = SI7020_HEATER_ENABLED;
//turn off
Sensor.heater_status = SI7020_HEATER_DISABLED;
```

>The scale used for the temperature property can be set at any time, but defaults to celsius
```cpp
//set to fahrenheit
Sensor.scale=TEMP_FAHRENHEIT;
//set to celsius
Sensor.scale=TEMP_CELSIUS;
//set to kelvin
Sensor.scale=TEMP_KELVIN;
