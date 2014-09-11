//this is the program to find angle measurements reltive to the ground and north
//see the lib folder for more information

#include <Accel.h>
#include <Magnet.h>
#include <Serial.h>


void setup() {
	Serial.begin(115200);
	while(!Serial);

	Accel accelerometer;
	Magnet magnetometer;

	for(;;){
		accelerometer.read().print();
	}
}

void loop() {
}
