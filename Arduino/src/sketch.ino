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

void setup() {
	Serial.begin(115200);
	Wire.begin();
	Accel accelerometer;
	Magnet magnetometer;
	VectPrinter<int> printer;

	while(!Serial);

	for(;;){
		while(block());
		while(block()){
			printer.add(accelerometer.read().getData());
			printer.add(magnetometer.read().getData());
			printer.print();
		}
		printer.next();
	}
}

void loop() {
}
