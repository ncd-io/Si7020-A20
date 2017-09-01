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

>Temperature values can be read in Celsius, Fahrenheit, or Kelvin using the provided methods
```cpp
double tempK = Sensor.getTempK();
double tempC = Sensor.getTempC();
double tempF = Sensor.getTempF();
```

>Turn the internal heater on or off
```cpp
//turn on
Sensor.setHeater(true);
//turn off
Sensor.setHeater(false);
```

>The scale used for the temperature property can be set at any time, but defaults to celsius
```cpp
//set to fahrenheit
Sensor.scale="f";
//set to celsius
Sensor.scale="c";
//set to kelvin
Sensor.scale="k";
