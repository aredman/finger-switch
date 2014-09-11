#ifndef ACCEL_H
#define ACCEL_H

//Accelerometer

#include <Arduino.h>

#include <Vector.h>
#include <Serial.h>

#include <Sensor.h>
#include <Data.h>

class AccelData : public threeAxis<int> {;
	public:
		AccelData(Vector<int, 3> input) : threeAxis(input){};
};

class Accel : public Sensor<Accel, AccelData> {
	public:
		Accel();
		AccelData readDataFromSensor();
	private:
		void writeTo(char address, char value);
};

#endif
