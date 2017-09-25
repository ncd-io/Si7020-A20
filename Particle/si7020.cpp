#include "SI7020.h"
#include "spark_wiring_usbserial.h"
#include "Particle.h"

void SI7020::init(){
    begin();
    
    int config = readByte(SI7020_CONFIG_REG_READ) & SI7020_CONFIG_RSVD;
    writeByte(SI7020_CONFIG_REG_WRITE, config | resolution | heater_status);
    
    if(heater_status == SI7020_HEATER_ENABLED){
        int heater = readByte(SI7020_HEATER_READ) & SI7020_HEATER_RESERVED;
        writeByte(SI7020_HEATER_WRITE, heater & heater_level);
    }
    
    if(hold_mode == SI7020_NO_HOLD_MODE){
        writeByte(SI7020_HUMIDITY_REG, 256);
        reading_waiting = getDelay();
    }
}

void SI7020::takeReading(){
    if(hold_mode == SI7020_NO_HOLD_MODE){
        int now = millis();
        if(now > reading_waiting){
            Wire.requestFrom(address, 2);
            int rh_code = (Wire.read() << 8) + Wire.read();
            humidity = ((125*rh_code)/65536)-6;
            
            writeByte(SI7020_HUMIDITY_REG, 256);
            reading_waiting = getDelay();
        }
    }else{
        int rh_buff[2];
        readBuffer(SI7020_HUMIDITY_REG | SI7020_HOLD_MODE, rh_buff, 2);
        int rh_code = (rh_buff[0] << 8) + rh_buff[1];
        humidity = ((125*rh_code)/65536)-6;
    }
    
    int tmp_buff[2];
    readBuffer(SI7020_TEMP_AFTER_RH, tmp_buff, 2);
    int temp_code = (tmp_buff[0] << 8) + tmp_buff[1];
    
    temperature = ((175.72*temp_code)/65536)-46.85;
    
    if(scale == SI7020_TEMP_FAHRENHEIT){
        temperature = temperature * 1.8 + 32;
    }else if(scale == SI7020_TEMP_KELVIN){
        temperature += 273.15;
    }
}

int SI7020::getDelay(){
    switch(resolution){
        case SI7020_RES_RH12_TMP14: return 23;
        case SI7020_RES_RH8_TMP12: return 7;
        case SI7020_RES_RH10_TMP_13: return 11;
        case SI7020_RES_RH11_TMP11: return 10;
    }
}

void SI7020::begin(){
    if(!Wire.isEnabled()){
        Wire.begin();
    }
}

void SI7020::writeByte(int reg, int data){
    Wire.beginTransmission(address);
    Wire.write(reg);
    if(data < 256) Wire.write(data);
    Wire.endTransmission();
}

int SI7020::readByte(int reg){
    writeByte(reg, 256);
    Wire.requestFrom(address, 1);
    return Wire.read();
}

void SI7020::readBuffer(int reg, int *buff, int length){
    writeByte(reg, 256);
    Wire.requestFrom(address, length);
    for(int i=0;i<length;i++){
        buff[i] = Wire.read();
    }
}
