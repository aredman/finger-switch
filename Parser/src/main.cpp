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
	Import importedData;
	dTable rawData;
	dTable calibratedData;
	rawData = importedData.tabulate(args.get()[1]);
	

	//after getting a vector of the data (of accelerometer data) calibrate the vectors
	//using the calibration files (requires another library to load the vectors)
	//TODO This NEEDS to be turned into doubles. Otherwise this is extremely inaccurate
	Import importCal;
	dTable importedCalVector = importCal.tabulate(args.get()[2]);
	if(importedCalVector.size() != 2){
		cout << "Wrong vector size" << endl;
		exit(2);
	}

	cout << "Putting data into the calibration vectors" << endl;
		vector< Calibration > accelCalVector;
		vector< Calibration > magnetCalVector;

Calibration xAccel(importedCalVector[0][0],importedCalVector[0][1]);
Calibration yAccel(importedCalVector[0][3],importedCalVector[0][4]);
Calibration zAccel(importedCalVector[0][6],importedCalVector[0][7]);
Calibration xMagnet(importedCalVector[1][0],importedCalVector[1][1]);
Calibration yMagnet(importedCalVector[1][3],importedCalVector[1][4]);
Calibration zMagnet(importedCalVector[1][6],importedCalVector[1][7]);

accelCalVector.push_back(xAccel);
accelCalVector.push_back(yAccel);
accelCalVector.push_back(zAccel);
magnetCalVector.push_back(xMagnet);
magnetCalVector.push_back(yMagnet);
magnetCalVector.push_back(zMagnet);

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
