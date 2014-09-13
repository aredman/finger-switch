//this is the program to find angle measurements reltive to the ground and north
//see the lib folder for more information

#include <Accel.h>
#include <Magnet.h>
#include <Serial.h>
#include <Wire.h>

//simple function to block. I'm too lazy to make a class
bool block(){
	if(Serial.available() == 0) return true;
	Serial.read();
	return false;
}

void setup() {
	Serial.begin(115200);
	Wire.begin();
	while(!Serial);
	Accel accelerometer;
	Magnet magnetometer;

	for(;;){
		Serial << "Accel:";
		accelerometer.read().print();
		Serial << "Magnet:";
		magnetometer.read().print();
		Serial << endl;

		delay(300);
	}
}

void loop() {
}
