#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <vector>

typedef std::vector< std::vector<float> > dTable;

//A class made to store the data measurements in lists of tables for easier
//handeling. The functions are simple set and get methods. The objects are
//vectors containing dTables. Which are defined above as two vectors 
//containing float


class RawMeasurementTables{
	private:
		std::vector<dTable> accelerometerData;
		std::vector<dTable> magnetometerData;
	public:
		void setAccelerometerData(std::vector<dTable> AD){
			accelerometerData = AD;
		}
		void setMagnetometerData(std::vector<dTable> MD){
			magnetometerData = MD;
		}
		std::vector<dTable> getAccelerometerData(){
			return accelerometerData;
		}
		std::vector<dTable> getMagnetometerData(){
			return magnetometerData;
		}
};

#endif
