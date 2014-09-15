#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <vector>

typedef std::vector< std::vector<int> > intTable;

//A class made to store the data measurements in lists of tables for easier
//handeling. The functions are simple set and get methods. The objects are
//vectors containing intTables. Which are defined above as two vectors 
//containing integers


class RawMeasurementTables{
	private:
		std::vector<intTable> accelerometerData;
		std::vector<intTable> magnetometerData;
	public:
		void setAccelerometerData(std::vector<intTable> AD){
			accelerometerData = AD;
		}
		void setMagnetometerData(std::vector<intTable> MD){
			magnetometerData = MD;
		}
		std::vector<intTable> getAccelerometerData(){
			return accelerometerData;
		}
		std::vector<intTable> getMagnetometerData(){
			return magnetometerData;
		}
};

#endif
