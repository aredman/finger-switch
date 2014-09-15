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
	if(argc == 0){
		cout << "No arguments supplied" << endl;
		exit(1);
	}
	ArgString args(argc, argv);

	//print information
	cout << "Extracting data from:       " << args.get()[0] << endl;
	cout << "Accelerometer Calibrations: " << args.get()[1] << endl;
	cout << "Magnetometer Calibrations:  " << args.get()[2] << endl;


}
