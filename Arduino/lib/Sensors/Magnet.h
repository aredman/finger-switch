#ifndef MAGNET_H
#define MAGNET_H

#include <Arduino.h>

#include <Serial.h>

#include <Sensor.h>
#include <Data.h>

class MagnetData : public threeAxis<int> {
	public:
		MagnetData(Vector<int, 3> input) : threeAxis(input){};
};

class Magnet : public Sensor<Magnet, MagnetData> {
	public:
		Magnet();
		MagnetData readDataFromSensor();
};


#endif
