//this is the main program to parse the data.
//As arguments, it takes the data file, and two calibration files for the sensors

#include "AngleAnalyzer.h"
#include "import.h"
#include "linearCal.h"
#include "Measurements.h"
#include "Stats.h"
#include "ArgString.h"

#include <vector>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv){
	//get the aruments as a string object
	if(argc != 3){
		cout << "Wrong numnber of arguments supplied" << endl;
		exit(1);
	}
	ArgString args(argc, argv);

	//print information
	cout << "Extracting data from:       " << args.get()[1] << endl;
	cout << "Accelerometer Calibrations: " << args.get()[2] << endl;


	//with this information, import the data file
	//create five tables to hold data.
	dTable rawData;
	dTable accelData;
	dTable magnetData;
	dTable calibratedAccelData;
	dTable calibratedMagnetData;
	//Create an import object which pulls information from
	//a csv and converts it two doubles
	Import importedData;
	//Load the imported data into the raw data object
	rawData = importedData.tabulate(args.get()[1]);
	//Cut up rawData table into magnetometer and accelerometer tables
	accelData = importedData.columnCut(rawData,4,6);
	magnetData = importedData.columnCut(rawData,1,3);
	

	//after getting a vector of the data (of accelerometer data) calibrate the vectors
	//using the calibration files (requires another library to load the vectors)
	//TODO This NEEDS to be turned into doubles. Otherwise this is extremely inaccurate
	//Import the calibrations from a file
	Import importCal;
	dTable importedCalVector = importCal.tabulate(args.get()[2]);
	if(importedCalVector.size() != 2){
		cout << "Wrong vector size" << endl;
		exit(2);
	}

	cout << "Putting data into the calibration vectors" << endl;
		vector< Calibration > accelCalVector;
		vector< Calibration > magnetCalVector;

	//Creates calibration objects with their respective calibrations
	Calibration xAccel(importedCalVector[0][0],importedCalVector[0][1]);
	Calibration yAccel(importedCalVector[0][3],importedCalVector[0][4]);
	Calibration zAccel(importedCalVector[0][6],importedCalVector[0][7]);
	Calibration xMagnet(importedCalVector[1][0],importedCalVector[1][1]);
	Calibration yMagnet(importedCalVector[1][3],importedCalVector[1][4]);
	Calibration zMagnet(importedCalVector[1][6],importedCalVector[1][7]);

	//if the calibration is loaded correctly, we output the coefficients
	cout << "Accelerometer x = "; printf("%fx + %f", importedCalVector[0][0], importedCalVector[0][1]); cout << endl;
	cout << "Accelerometer y = "; printf("%fx + %f", importedCalVector[0][3], importedCalVector[0][4]); cout << endl;
	cout << "Accelerometer z = "; printf("%fx + %f", importedCalVector[0][6], importedCalVector[0][7]); cout << endl;
	cout << "Magnettometer x = "; printf("%fx + %f", importedCalVector[1][0], importedCalVector[1][1]); cout << endl;
	cout << "Magnettometer y = "; printf("%fx + %f", importedCalVector[1][3], importedCalVector[1][4]); cout << endl;
	cout << "Magnettometer z = "; printf("%fx + %f", importedCalVector[1][6], importedCalVector[1][7]); cout << endl;

	//Load the calibration objects into vectors based on sensor and axis
	//All accelerometer calibrations are in the same vector
	//All magnetometer calibrations are in the same vector
	//positions 0,1,2 are x,y,z respectively
	accelCalVector.push_back(xAccel);	//AccelCalVector[0]
	accelCalVector.push_back(yAccel);	//AccelCalVector[1]
	accelCalVector.push_back(zAccel);	//AccelCalVector[2]
	magnetCalVector.push_back(xMagnet);	//MagnetCalVector[0]
	magnetCalVector.push_back(yMagnet);	//MagnetCalVector[1]
	magnetCalVector.push_back(zMagnet);	//MagnetCalVector[2]

	//Create sensor calibration objects for accelerometer and magnetometer
	SensorCalibration fixAcceleration(accelCalVector);
	SensorCalibration fixMagnetometer(magnetCalVector);

	//Apply sensor calibration objects to tables
	cout << "Beginning Calibration process" << endl;
	calibratedAccelData = fixAcceleration.fixTable(accelData);
	calibratedMagnetData = fixMagnetometer.fixTable(magnetData);
	cout << "Calibration Completed" << endl;

	//Create output file stream to save calibrated data
	ofstream accelFile;
	string afilename = args.get()[1]+"-accel.data";
	string mfilename = args.get()[1]+"-magnet.data";
	accelFile.open(afilename.c_str());

	for(int i = 0; i<calibratedAccelData.size();i++){
		accelFile << i/5000+1 << ",";
		for(int j = 0;j<calibratedAccelData[i].size();j++){
			accelFile << calibratedAccelData[i][j] << ",";
		}
		accelFile << endl;
	}
	accelFile.close();

	ofstream magnetFile;
	magnetFile.open(mfilename.c_str());
	for(int i = 0; i<calibratedMagnetData.size();i++){
		magnetFile << i/5000+1 << ",";
		for(int j = 0;j<calibratedMagnetData[i].size();j++){
			magnetFile << calibratedMagnetData[i][j] << ",";
		}
		magnetFile << endl;
	}
	magnetFile.close();

	//==========================================================================================
	//with the calibrated data, calculate the angle measurements, taking care to propagate error
	//vector of calibrations
	//vector< Measurement<double> > accelCals;
	//vector< Measurement<double> > magnetCals;

	//calibrate the magnetometer data
	//SensorCalibration accelSensorCal(calibrations);
	//SensorCalibration magnetSensorCal(calibrations);

	//vector< vector< vector<long double> > > accelFixed;
	//vector< vector< vector<long double> > > magnetFixed;

	//for(int i = 0; i < importedData.getAccel().size(); i++){
		////fix both the acceleration and magnetometer data
		//accelSensorCal.fixTable(importedData.getAccel()[i]);
		//magnetSensorCal.fixTable(importedData.getMagnet()[i]);
	//}
	
	//output to files representing the calibrated angles
	//for(int i = 0; i < accelFixed.size(); i++){
		//accel
		//string accelName("accel");
		//accelName += to_string(i);
		//ofstream AccelFile;
		//AccelFile.open(accelName, ios::trunc);
		//printVector(AccelFile, accelName);

		//magnet
		//string magnetName("magnet");
		//magnetName += to_string(i);
		//ofstream MagnetFile;
		//MagnetAccelFile.open(magnetName, ios::trunc);
		//printVector(MagnetFile, magnetName);
	//}

	//=======================================================================
	//with the angles, construct an array of ijk vectors, using the simple algorithm, and add the error measurements
	//spit them out, too, so we can calculate the stuff by hand if need be

}
