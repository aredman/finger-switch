#include <fstream>
#include <stdlib.h>
#include "import.h"
#include <iostream>
#include "Measurements.h"
#include <vector>

using namespace std;

int main(){
	dTable table;
	vector<dTable> A;
	vector<dTable> M;
	std::string filename = "test1";

	Import data;
	table = data.tabulate(filename);

	RawMeasurementTables records;
	records.setMagnetometerData(data.getMagnet(table,5,6));
	records.setAccelerometerData(data.getAccel(table,5,6));

	A = records.getAccelerometerData();
	M = records.getMagnetometerData();

	for(int i = 0; i<A.size();i++){
		for(int j = 0;j<A[i].size();j++){
			for(int k = 0; k < A[i][j].size();k++){
				cout << A[i][j][k];
				cout << ",";
			}
			cout << endl;
		}
			cout << "------" << endl;
	}
};

