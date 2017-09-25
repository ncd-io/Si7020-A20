# Usage

This library provides a class for reading the temperature and humidity from the Si7020-A20. The si7020.ino file provides a simple use case for the Particle cloud.

>Create a new instance of the sensor
```cpp
SI7020 Sensor;
```

>Turn the internal heater on or off (defaults to off)
>init() must be called after this
```cpp
//turn on
Sensor.heater_status = SI7020_HEATER_ENABLED;
//turn off
Sensor.heater_status = SI7020_HEATER_DISABLED;
```

>Set the power level of the heater, expects a value <16 (defaults to 0)
>init() must be called after this
```cpp
Sensor.heater_level = 12;
```

>Set the resolution of the sensor (defaults to max resolution, RH 12bit Temp 14bit)
>init() must be called after this
```cpp
Sensor.resolution = SI7020_RES_RH10_TMP_13;
```

>Set No Hold Master mode (Defaults to Hold Master Mode)
>init() must be called after this
```cpp
Sensor.hold_mode = SI7020_NO_HOLD_MODE;
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
double temperature = Sensor.dew_point;
```

>The scale used for the temperature property can be set at any time (defaults to celsius)
```cpp
//set to fahrenheit
Sensor.scale=TEMP_FAHRENHEIT;
//set to celsius
Sensor.scale=TEMP_CELSIUS;
//set to kelvin
Sensor.scale=TEMP_KELVIN;
