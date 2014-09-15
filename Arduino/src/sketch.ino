//this is the program to find angle measurements reltive to the ground and north
//see the lib folder for more information

#include <Accel.h>
#include <Magnet.h>
#include <Serial.h>
#include <Wire.h>
#include <VectPrint.h>

//simple function to block. I'm too lazy to make a class
bool block(){
	if(Serial.available() == 0) return true;
	Serial.read();
	return false;
}

void calibration(){
	Accel accelerometer;
	Magnet magnetometer;
	VectPrinter<int> printer;

	//we increment the angles for roll, pitch, and yaw
	double increment = 15;
	double roll = 0;
	double pitch = 0;
	double yaw = 0;
	bool blocked = true;
	while(1){
		printer.add(accelerometer.read().getData());
		printer.add(magnetometer.read().getData());
		if(!blocked){
			Serial << roll << ';';
			Serial << pitch << ';';
			Serial << yaw << ';';
			Serial << sin(roll) << ';';
			Serial << sin(pitch) << ';';
			Serial << sin(yaw) << ';';
			printer.print();
		}
		printer.flush();
		switch(Serial.read()){
			case 'c':
				return;
			case 'r':
				roll += 15;
				break;
			case 'p':
				pitch += 15;
				break;
			case 'y':
				yaw += 15;
				break;
			case ' ':
				blocked = !blocked;
				break;
		}
		while(roll > 360) roll -= 360;
		while(pitch > 360) pitch -= 360;
		while(yaw > 360) yaw -= 360;
	}
}

void setup() {
	Serial.begin(115200);
	Wire.begin();
	Accel accelerometer;
	Magnet magnetometer;
	VectPrinter<int> printer;

	while(!Serial);

	for(;;){
		while(block()) if(Serial.read() == 'c') calibration();
		for(int i = 0; i < 5000; i++){
			printer.add(accelerometer.read().getData());
			printer.add(magnetometer.read().getData());
			printer.print();
		}
		while(Serial.available()) Serial.read();
		printer.next();
	}
}

void loop() {
}
