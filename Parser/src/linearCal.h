//library to facilitate linear calibration curves

#include <vector>
#include <iostream>

class Calibration {
	public:
		double m;
		double b;

		Calibration(double mInput, double bInput){
			m = mInput;
			b = bInput;
		}

		double fix(double input){
			return (input - b) / m;
		}

		std::vector<double> fixVector(std::vector<double> input){
			int size = input.size();
			std::vector<double> output;
			for(int i = 0; i < size; i++) output.push_back(fix(input[i]));
			return output;
		}
};


class SensorCalibration {
	public:
		std::vector< Calibration> xyzCal;

		SensorCalibration(std::vector< Calibration > inputCals){
			xyzCal = inputCals;
		}

		std::vector< std::vector<double> > fixTable(std::vector< std::vector<double> > input){
			//make new vector for xyz
			std::vector<double> xvector, yvector, zvector;
			for(int i = 0; i < input.size(); i++){
				xvector.push_back(input[i][0]);
				yvector.push_back(input[i][1]);
				zvector.push_back(input[i][2]);
			}

			//calibrate the vectors individually
			std::vector<double> xvectorCal, yvectorCal, zvectorCal;
			xvectorCal = xyzCal[0].fixVector(xvector);
			yvectorCal = xyzCal[1].fixVector(yvector);
			zvectorCal = xyzCal[2].fixVector(zvector);

			//put them back into a calibrated vector and return it
			std::vector< std::vector<double> > output;
			for(int i = 0; i < input.size(); i++){
				std::vector<double> tmp;
				tmp.push_back(xvectorCal[i]);
				tmp.push_back(yvectorCal[i]);
				tmp.push_back(zvectorCal[i]);
				output.push_back(tmp);
			}
			return output;
		}
};
