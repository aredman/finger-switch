//this is the main program to parse the data.
//As arguments, it takes the data file, and two calibration files for the sensors

#include "AngleAnalyzer.h"
#include "import.h"
#include "linearCal.h"
#include "Measurements.h"
#include "Stats.h"
#include "ArgString.h"

#include <vector>

using namespace std;

int main(int argc, char** argv){
	//get the aruments as a string object
	if(argc == 1){
		cout << "No arguments supplied" << endl;
		exit(1);
	}
	ArgString args(argc, argv);

	//print information
	cout << "Extracting data from:       " << args.get()[1] << endl;
	cout << "Accelerometer Calibrations: " << args.get()[2] << endl;
	cout << "Magnetometer Calibrations:  " << args.get()[3] << endl;


	//with this information, import the data file

	//after getting a vector of the data (of accelerometer data) calibrate the vectors
	//using the calibration files (requires another library)

	//with the calibrated data, calculate the angle measurements, taking care to propagate error

	//with the angles, construct an array of ijk vectors, using the simple algorithm, and add the error measurements
	//spit them out, too, so we can calculate the stuff by hand if need be

}
