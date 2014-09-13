#ifndef SENSOR_H
#define SENSOR_H

#include <Data.h>

template <typename Type, typename DataType>
class Sensor {
	public:
		DataType read(){return static_cast<Type *>(this)->readDataFromSensor();};
	protected:
		static bool isInitialized;
};

template <typename Type, typename DataType>
bool Sensor<Type, DataType>::isInitialized = false;

#endif
