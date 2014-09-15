#include <fstream>
#include <stdlib.h>
#include "import.h"
#include <iostream>
#include "Measurements.h"
#include <vector>

using namespace std;

int main(){
	intTable table;
	vector<intTable> A;
	vector<intTable> M;
	std::string filename = "test1";

	Import data;
	table = data.tabulate(filename);

	RawMeasurementTables records;
	records.setMagnetometerData(data.getMagnet(table,6));
	records.setAccelerometerData(data.getAccel(table,6));

	A = records.getAccelerometerData();
	M = records.getMagnetometerData();

	for(int i = 0; i<M.size();i++){
		for(int j = 0;j<M[i].size();j++){
			for(int k = 0; k < M[i][j].size();k++){
				cout << M[i][j][k];
				cout << ",";
			}
			cout << endl;
		}
			cout << "------" << endl;
	}
};

