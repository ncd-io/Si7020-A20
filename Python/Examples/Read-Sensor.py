#import the I2C library for python
import smbus
#import the SI7020 library
from si7020_a20 import SI7020_A20

# Get I2C bus, I'm using I2C port 1
bus = smbus.SMBus(1)

#Set the address of your SI7020. The default is 0x40
kwargs = {'address': 0x40}
#create the SI7020 object passing it the I2C bus and the address.
si7020_a20 = SI7020_A20(bus, kwargs)

while True:
    #get the himidity and the temperature in celsius
    sensor_data = si7020_a20.get_readings('celsius')
    print '---celsius and rh---'
    print str(sensor_data['temperature'])
    print str(sensor_data['humidity'])
    print ''
    
    #get the himidity and the temperature in fahrenheit
    sensor_data = si7020_a20.get_readings('fahrenheit')
    print '---fahrenheit and rh---'
    print str(sensor_data['temperature'])
    print str(sensor_data['humidity'])
    print ''
    
    #calls to get_readings without a specified unit of measurement are processed as celsius by default
    sensor_data = si7020_a20.get_readings()
    print '---celsius and rh---'
    print str(sensor_data['temperature'])
    print str(sensor_data['humidity'])
    print ''
    
    #get the humidity only
    humidity = si7020_a20.get_humidity()
    print '---humidity only---'
    print humidity
    print ''

    #get the temperature in celsius only
    temperature = si7020_a20.get_temperature('celsius')
    print '---temperature in celsius only---'
    print temperature
    print ''
    
    #get the temperature in celsius only
    temperature = si7020_a20.get_temperature('fahrenheit')
    print '---temperature in fahrenheit only---'
    print temperature
    print ''
