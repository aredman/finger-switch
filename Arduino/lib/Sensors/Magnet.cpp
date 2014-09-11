//Implementation of the magnet header

#include <Arduino.h>
#include <Wire.h>

#include <Serial.h>

#include <Data.h>
#include <Magnet.h>

#define ADDRESS 0x1E //0011110b, I2C 7bit address of HMC5883

using namespace std;


Magnet::Magnet(){
	if(isInitialized) return;

	Wire.beginTransmission(ADDRESS);
	//select mode register, then continuous measurement mode
	Wire.write(0x02);
	Wire.write(0x00);
	Wire.endTransmission();

	isInitialized = true;
}

MagnetData Magnet::readDataFromSensor(){
	//Tell the HMC5883 where to begin reading data
	Wire.beginTransmission(ADDRESS);
	//select register 3, X MSB register
	Wire.write(0x03);
	Wire.endTransmission();

	Vector<int, 3> compass;

	Wire.requestFrom(ADDRESS, 6);
	if(Wire.available() >= 6 ){
		//x,z,y
		compass[0] = (Wire.read() << 8) | (Wire.read());
		compass[2] = (Wire.read() << 8) | (Wire.read());
		compass[1] = (Wire.read() << 8) | (Wire.read());
	}

	return MagnetData(compass);
}
