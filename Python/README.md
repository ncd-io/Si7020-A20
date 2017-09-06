

# About

This Library is intended for use with any SI7020-A20 board available from ncd.io

###Developer information
NCD has been designing and manufacturing computer control products since 1995.  We have specialized in hardware design and manufacturing of Relay controllers for 20 years.  We pride ourselves as being the industry leader of computer control relay products.  Our products are proven reliable and we are very excited to support Particle.  For more information on NCD please visit ncd.io

###Requirements
- The Python SMBus Module: https://pypi.python.org/pypi/smbus-cffi/
- An I2C connection to an SI2070-A20 Chip
- Knowledge base for developing and programming with Python.

### Version
1.0.0

### How to use this library

The libary must be imported into your application. Once it is imported you can create an SI2070_A20 object and start to communicate to the chip. You can optionally pass in a kwarg to the object that contains an I2C Address.

###Public accessible methods
```cpp
take_reading(temperature_measurement)
```
>This function returns a set of readings.
>One is keyed as 'humidity' and contains the relative humidity in %rh.
>The other is keyed as 'temperature' and contains the temperature in either Celsius or Fahrenheit depending on the argument
>passed to the method.
>The argument temperature_measurement is an optional argument that defaults to Celsius if 'fahrenheit' isn't passed.
>This argument is case sensitive.


```cpp
get_humidity()
```
>This function returns the humidity reading in % relative humidity.


```cpp
get_temperature(temperature_measurement)
```
>This method returns the temperature in either Celsius or Fahrenheit depending on the argument passed to the method.
>The argument temperature_measurement is an optional argument that defaults to Celsius if 'fahrenheit' isn't passed.
>This argument is case sensitive.
