#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <vector>

typedef std::vector< std::vector<int> > intTable;

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
