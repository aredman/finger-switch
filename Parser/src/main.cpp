//this is the main program to parse the data.
//As arguments, it takes the data file, and two calibration files for the sensors

#include "AngleAnalyzer.h"
#include "import.h"
#include "linearCal.h"
#include "Measurements.h"
#include "Stats.h"
#include "ArgString.h"
#include "VectorMath.h"

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
	//=====================================================================


	//Create an import object which pulls information from
	//a csv and converts it two doubles
	Import importedData;

	//Load the imported data into the raw data object
	cout << "Importing data" << endl;
	dTable rawData = importedData.tabulate(args.get()[1]);

	//Cut up rawData table into magnetometer and accelerometer tables
	cout << "Parsing raw data" << endl;
	dTable accelData = importedData.columnCut(rawData,1,3);
	dTable magnetData = importedData.columnCut(rawData,4,6);

	//Cut up rawData table into magnetometer and accelerometer tables by index
	cout << "Cutting by index" << endl;
	vector<dTable> accelDataVector;
	for(int i = 1; i < 22;i++){
		accelDataVector.push_back(importedData.tableCut(rawData,i,1,3));
	}
	vector<dTable> magnetDataVector;
	for(int i = 1; i < 22;i++){
		magnetDataVector.push_back(importedData.tableCut(rawData,i,4,6));
	}

	//=====================================================================
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

	//=====================================================================
	//Create sensor calibration objects for accelerometer and magnetometer
	SensorCalibration fixAcceleration(accelCalVector);
	SensorCalibration fixMagnetometer(magnetCalVector);

	//Apply sensor calibration objects to tables
	cout << "Beginning Calibration process" << endl;
	cout << "Accelerometer" << endl;
	dTable calibratedAccelData = fixAcceleration.fixTable(accelData);
	cout << "Magnetometer" << endl;
	dTable calibratedMagnetData = fixMagnetometer.fixTable(magnetData);
	cout << "Calibration Completed" << endl;

	//Apply sensor calibration objects to vectors of tables
	vector<dTable> calibratedAccelDataVector;
	vector<dTable> calibratedMagnetDataVector;

	for(int i = 0; i < accelDataVector.size();i++){
		calibratedAccelDataVector.push_back(fixAcceleration.fixTable(accelDataVector[i]));
	}
	for(int i = 0; i < magnetDataVector.size();i++){
		calibratedMagnetDataVector.push_back(fixMagnetometer.fixTable(magnetDataVector[i]));
	}

	//=====================================================================
	//Create output file stream to save calibrated data
	cout << "Outputing calibrated data to a file" << endl;
	ofstream accelFile;
	string afilename = args.get()[1]+"-accel.data";
	cout << afilename << endl;
	accelFile.open(afilename.c_str());

	for(int i = 0; i < calibratedAccelDataVector.size();i++){
		for(int j = 0;j < calibratedAccelDataVector[i].size();j++){
			accelFile << i + 1 << ",";
			for(int k = 0; k < calibratedAccelDataVector[i][j].size();k++){
				accelFile << calibratedAccelDataVector[i][j][k] << ",";
			}
			accelFile << endl;
		}
	}
	accelFile.close();

	ofstream magnetFile;
	string mfilename = args.get()[1]+"-magnet.data";
	cout << mfilename << endl;
	magnetFile.open(mfilename.c_str());
	for(int i = 0; i < calibratedMagnetDataVector.size();i++){
		for(int j = 0;j < calibratedMagnetDataVector[i].size();j++){
			magnetFile << i + 1 << ",";
			for(int k = 0; k < calibratedMagnetDataVector[i][j].size();k++){
				magnetFile << calibratedMagnetDataVector[i][j][k] << ",";
			}
			magnetFile << endl;
		}
	}
	magnetFile.close();

	//==========================================================================================
	//This is a basic implementation of the algorithm
	//first, get a table of the means
	
	cout << "Getting a table of the vector means" << endl;
	vector< vector<double> > accelMeans, magnetMeans, accelUn, magnetUn;
	accelMeans.push_back(vector<double>(3));
	magnetMeans.push_back(vector<double>(3));
	accelUn.push_back(vector<double>(3));
	magnetUn.push_back(vector<double>(3));
	for(int i = 0; i < calibratedMagnetDataVector.size(); i++){
		accelMeans.push_back(Stats().vectorMean(calibratedAccelDataVector[i]));
		magnetMeans.push_back(Stats().vectorMean(calibratedMagnetDataVector[i]));
		accelUn.push_back(Stats().vectorAccuracy(calibratedAccelDataVector[i]));
		magnetUn.push_back(Stats().vectorAccuracy(calibratedMagnetDataVector[i]));
	}
	cout << "Accelerometer" << endl;
	printVector(accelMeans);
	cout << "Magnetometer" << endl;
	printVector(magnetMeans);

	cout << "Accelerometer Uncertainty" << endl;
	printVector(accelUn);
	cout << "Magnetometer Uncertainty" << endl;
	printVector(magnetUn);

	cout << "Getting the perpendicular component of the magnetomter data" << endl;
	vector< vector<double> > magnetMeansPerp;
	for(int i = 0; i < accelMeans.size(); i++){
		magnetMeansPerp.push_back(rejection(magnetMeans[i], accelMeans[i]));
	}
	cout << "Magnetometer Rejection" << endl;
	printVector(magnetMeansPerp);

	cout << "angles from north" << endl;
	for(int i = 0; i < magnetMeansPerp.size(); i++){
		cout << i << ':'<< orientation(magnetMeansPerp[i]) << "\t|" << orientation180(magnetMeansPerp[i]) << endl;
		cout << i << "::" << orientation(magnetMeans[i]) << "\t|" << orientation180(magnetMeans[i]) << endl << endl;
	}


	//main path:
	//	-1 
	//	2
	//	5
	//	7
	//	9
	//	11
	//	13
	//	15
	//	17
	//	19

	//helpers:
	//	-4
	//	3
	//	6
	//	8
	//	10
	//	12
	//	14
	//	16
	//	18
	
	//make a table of angles and helpers using the calibrated magnetmeter data
	//theta refers to the angle of the paths on the edge, and phi refers to the helper angles
	vector<double> theta, phi;
	theta.push_back(orientation(magnetMeansPerp[1]) - 4 * atan(1));
	theta.push_back(orientation(magnetMeansPerp[2]));
	theta.push_back(orientation(magnetMeansPerp[5]) - 0.14);
	theta.push_back(orientation(magnetMeansPerp[7]));
	theta.push_back(orientation(magnetMeansPerp[9]));
	theta.push_back(orientation(magnetMeansPerp[11]));
	theta.push_back(orientation(magnetMeansPerp[13]));
	theta.push_back(orientation(magnetMeansPerp[15]));
	theta.push_back(orientation(magnetMeansPerp[17]));
	theta.push_back(orientation(magnetMeansPerp[19]));

	phi.push_back(orientation(magnetMeansPerp[4]) - 4 * atan(1));
	phi.push_back(orientation(magnetMeansPerp[3]));
	phi.push_back(orientation(magnetMeansPerp[6]) - 0.14);
	phi.push_back(orientation(magnetMeansPerp[8]));
	phi.push_back(orientation(magnetMeansPerp[10]));
	phi.push_back(orientation(magnetMeansPerp[12]));
	phi.push_back(orientation(magnetMeansPerp[14]));
	phi.push_back(orientation(magnetMeansPerp[16]));
	phi.push_back(orientation(magnetMeansPerp[18]));

	cout << "theta" << endl;
	printVector(theta);
	cout << "phi" << endl;
	printVector(phi);

	cout << "edge orientation" << endl;
	vector<int> thetaDeg = vectorMultiplication(theta, 180/3.14159);
	printVector(thetaDeg);
	cout << "helper orientation" << endl;
	vector<int> phiDeg = vectorMultiplication(phi, 180/3.14159);
	printVector(phiDeg);


	cout << endl << "Iteratively calculating the edges" << endl;
	vector<double> edge;
	edge.push_back(1);
	for(int n = 1; n < 10; n++){
		edge.push_back(abs((sin(abs(theta[n-1] - phi[n-1]))
		              / sin(abs((theta[n] - phi[n-1]))))
			      * edge[n-1]));
		cout << n << endl << "theta[n-1]: " << theta[n-1] << endl;
		cout << "theta[n]:   " << theta[n] << endl;
		cout << "phi[n-1]:   " << phi[n-1] << endl;
		cout << "edge[n-1]:  " << edge[n-1] << endl;
		
	}
	printVector(edge);

	cout << endl << "converting the vectors to cartesian" << endl;
	vector< vector<double> > edgeVector;
	for(int n = 0; n < edge.size(); n++){
		edgeVector.push_back(toCartesian(edge[n], theta[n]));
	}

	printVector(edgeVector);
	
	
	vector<double> vectorSum;
	vectorSum.push_back(0);
	vectorSum.push_back(0);
	vectorSum.push_back(0);
	for(int i = 0; i < edgeVector.size(); i++){
		for(int j = 0; j < edgeVector[i].size(); j++){
			vectorSum[j] += edgeVector[i][j];
		}
	}


	//=============================================================
	cout << "vector sum:";
	printVector(vectorSum);
	double vectorMag = vectorMagnitude(vectorSum);
	cout << "Mag: " << vectorMag << endl;


	//=============================================================


	//with this, we now have enough information to figure out the probable distance using the measured distances
	//this currently assumes that these are the xy ditances, with no j component

	//side	edge	edgeI	scale
	//2	2	1	1.25
	//3			8.57
	//5	3	2	8.57
	//7	4	3	20.78
	//11	6	5	31.74
	//13	7	6	26.9
	//17	9	8	12.03

	//create a vector of calculated scales
	vector<double> finalDistance;
	finalDistance.push_back(1.25 / edge[1] * vectorMag);
	finalDistance.push_back(8.57 / edge[2] * vectorMag);
	finalDistance.push_back(20.78 / edge[3] * vectorMag);
	finalDistance.push_back(31.74 / edge[5] * vectorMag);
	finalDistance.push_back(26.90 / edge[6] * vectorMag);
	finalDistance.push_back(12.03 / edge[8] * vectorMag);

	cout << endl << "Calculated distances" << endl;
	printVector(finalDistance);

	ofstream gnuplot_vector;
	gnuplot_vector.open("gnuplot_vector");
	vector<double> cumulativeVector;
	cumulativeVector.push_back(0);
	cumulativeVector.push_back(0);
	cumulativeVector.push_back(0);
	for(int i = 0; i < edgeVector.size(); i++){
		gnuplot_vector << edgeVector[i][0] + cumulativeVector[0] << ';';
		gnuplot_vector << edgeVector[i][1] + cumulativeVector[1] << endl;

		cumulativeVector[0] += edgeVector[i][0];
		cumulativeVector[1] += edgeVector[i][1];
	}
	gnuplot_vector.close();

	cout << "Mean:        " << Stats().mean(finalDistance) << endl;
	cout << "StdDev:      " << Stats().stdDev(finalDistance) << endl;
	cout << "Uncertainty: " << Stats().accuracy(finalDistance) << endl;
}
