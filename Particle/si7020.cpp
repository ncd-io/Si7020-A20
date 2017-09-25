#include "SI7020.h"
#include "spark_wiring_usbserial.h"
#include "Particle.h"

SI7020::SI7020(){}

void SI7020::init(){
    Wire.begin();
    setHeater(false);
}

void SI7020::takeReading(){
    Wire.beginTransmission(address);
    Wire.write(0xE5);
    Wire.endTransmission();
    
    Wire.requestFrom(address, 2);
    
    int rh_code = Wire.read();
    rh_code = (rh_code << 8) + Wire.read();
    humidity = ((125*rh_code)/65536)-6;
    
    Wire.beginTransmission(address);
    Wire.write(0xE0);
    Wire.endTransmission();
    
    Wire.requestFrom(address, 2);
    
    temp_code = Wire.read();
    temp_code = (temp_code << 8) + Wire.read();
    
    if(scale.equalsIgnoreCase("f")){
        temperature = getTempF();
    }
    if(scale.equalsIgnoreCase("c")){
        temperature = getTempC();
    }
    if(scale.equalsIgnoreCase("k")){
        temperature = getTempK();
    }
}

double SI7020::getTempC(){
    return ((175.72*temp_code)/65536)-46.85;
}

double SI7020::getTempK(){
    return ((175.72*temp_code)/65536)+226.3;
}

double SI7020::getTempF(){
    return getTempC() * 1.8 + 32;
}

void SI7020::setHeater(bool on){
    int heaterState = on ? 0x3E : 0x3A;
    Wire.beginTransmission(address);
    Wire.write(0xE6);
    Wire.write(heaterState);
    Wire.endTransmission();
}
