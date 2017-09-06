# Distributed with a free-will license.
# Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
# SI7020-A20
# This code is designed to work with the SI7020-A20_I2CS I2C Mini Module available from ControlEverything.com.
# https://www.controleverything.com/content/Humidity?sku=SI7020-A20_I2CS#tabs-0-product_tabset-2

# I2C Address of the device
SI7020_A20_DEFAULT_ADDRESS            = 0x40

# SI7020_A20 Command Set
SI7020_A20_MEAS_RH_HOLD                = 0xE5 # Measure Relative Humidity, Hold Master Mode
SI7020_A20_MEAS_RH_NOHOLD            = 0xF5 # Measure Relative Humidity, No Hold Master Mode
SI7020_A20_MEAS_TEMP_HOLD            = 0xE3 # Measure Temperature, Hold Master Mode
SI7020_A20_MEAS_TEMP_NOHOLD            = 0xF3 # Measure Temperature, No Hold Master Mode
SI7020_A20_READ_PREV_TEMP            = 0xE0 # Read Temperature Value from Previous RH Measurement
SI7020_A20_RESET                    = 0xFE # Reset
SI7020_A20_WRITERHT_REG                = 0xE6 # Write RH/T User Register 1
SI7020_A20_READRHT_REG                = 0xE7 # Read RH/T User Register 1
SI7020_A20_WRITEHEATER_REG            = 0x51 # Write Heater Control Register
SI7020_A20_READHEATER_REG            = 0x11 # Read Heater Control Register

class SI7020_A20():
    def __init__(self, smbus, kwargs):
        self.__dict__.update(kwargs)
        if not hasattr(self, 'address'):
            self.address = SI7020_A20_DEFAULT_ADDRESS
        self.smbus = smbus
        
    def take_reading(self, temperature_measurement = 'celsius'):

        humidity = self.get_humidity()
        temperature = self.get_temperature(temperature_measurement)
        return {'humidity': humidity, 'temperature': temperature}
        
    def get_humidity(self):
        self.smbus.write_byte(self.address, SI7020_A20_MEAS_RH_HOLD)
        humidity = self.smbus.read_i2c_block_data(self.address, SI7020_A20_MEAS_RH_HOLD, 2)
        humidity = ((humidity[0] * 256 + humidity[1]) * 125 / 65536.0) - 6
        return humidity
        
    def get_temperature(self, temperature_measurement = 'celsius'):
        if(temperature_measurement != 'fahrenheit'):
            temperature_measurement = 'celsius'
        self.smbus.write_byte(self.address, SI7020_A20_MEAS_TEMP_HOLD)
        temperature = self.smbus.read_i2c_block_data(self.address, SI7020_A20_MEAS_TEMP_HOLD, 2)
        temperature = ((temperature[0] * 256 + temperature[1]) * 175.72 / 65536.0) - 46.85
        if temperature_measurement == 'fahrenheit':
            temperature = temperature * 1.8 +32
        return temperature


