#include "linearCal.h"

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <vector>
#include <iostream>

int main(){
	srand (time(NULL));
	std::vector<double> random;
	for(int i = 0; i < 10; i++){
		random.push_back(rand()/1000000);
	}

	//test the fix portion of the linear regression
	Calibration testCal(100,34);
	for(int i = 0; i < random.size(); i++){
		std::cout << random[i] << "   " << testCal.fix(random[i]) << std::endl;
	}

	std::vector<double> newVector = testCal.fixVector(random);
	for(int i = 0; i < newVector.size(); i++) std::cout << newVector[i] << std::endl;

	//test the calibration of a big table of values
	//first make the vector
	std::vector< std::vector<double> > testTable;
	for(int i = 0; i < 10; i++){
		std::vector<double> tmp(3);
		for(int j = 0; j < 3; j++){
			tmp[j] = rand()/1000000;
		}
		testTable.push_back(tmp);
	}


	for(int i = 0; i < testTable.size(); i++){
		for(int j = 0; j < 3; j++){
			std::cout << testTable[i][j] << ';';
		}
		std::cout << std::endl;
	}

	std::cout << "=====================" << std::endl;

	std::vector< Calibration > xyzCal;
	xyzCal.push_back(Calibration(100,345));
	xyzCal.push_back(Calibration(137,302));
	xyzCal.push_back(Calibration(275,163));

	SensorCalibration calibrator(xyzCal);
	std::vector< std::vector<double> > testTableCal = calibrator.fixTable(testTable);
	for(int i = 0; i < testTableCal.size(); i++){
		for(int j = 0; j < testTableCal[i].size(); j++){
			std::cout << testTableCal[i][j] << ';';
		}
		std::cout << std::endl;
	}
}
