#include <Arduino.h>
#include <Wire.h>

#include <Serial.h>

#include <Data.h>
#include <Accel.h>
#include <Vector.h>

#define DEVICE       0x53     //Device address as specified in data sheet 
#define POWER_CTL    0x2D     //Power Control Register
#define DATA_FORMAT  0x31
#define DATAX0       0x32     //X-Axis Data 0
#define DATAX1       0x33     //X-Axis Data 1
#define DATAY0       0x34     //Y-Axis Data 0
#define DATAY1       0x35     //Y-Axis Data 1
#define DATAZ0       0x36     //Z-Axis Data 0
#define DATAZ1       0x37     //Z-Axis Data 1

using namespace std;

Accel::Accel(){
	if(isInitialized) return;

	//Put the ADXL345 into +/- 4G range by writing the value 0x01 to the DATA_FORMAT register.
	writeTo(DATA_FORMAT, 0x01);
	//Put the ADXL345 into Measurement Mode by writing 0x08 to the POWER_CTL register.
	writeTo(POWER_CTL, 0x08);

	isInitialized = true;
}


AccelData Accel::readDataFromSensor(){

	Wire.beginTransmission(DEVICE);
	Wire.write(DATAX0);
	Wire.endTransmission();


	Wire.beginTransmission(DEVICE);
	Wire.requestFrom(DEVICE, 6);

	Vector<int, 3> accelerationVector;

	//each axis reading comes in 10 bit resolution
	//Least Significant Byte first
	if(Wire.available()){
		int tmp = Wire.read();
		accelerationVector[0] = ((int)Wire.read() << 8) | tmp;
		tmp = Wire.read();
		accelerationVector[1] = ((int)Wire.read() << 8) | tmp;
		tmp = Wire.read();
		accelerationVector[2] = ((int)Wire.read() << 8) | tmp;
	}

	Wire.endTransmission();

	
	return AccelData(accelerationVector);
}

void Accel::writeTo(char address, char value){
	Wire.beginTransmission(DEVICE); 
	Wire.write(address); 
	Wire.write(value); 
	Wire.endTransmission();
}

