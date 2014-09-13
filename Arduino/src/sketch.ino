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
	if(Serial.read() == 'r') calibration();
	Serial.read();
	return false;
}

void calibration(){
	Accel accelerometer;
	Magnet magnetometer;
	VectPrinter<int> printer;

	while(1){
		printer.add(accelerometer.read().getData());
		printer.add(magnetometer.read().getData());
		printer.print();
		if(Serial.read() == 'r') return;
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
		while(block());
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
