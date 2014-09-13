//library to facilitate linear calibration curves

#include <vector>
#include <iostream>

template <class Type>
class Calibration {
	public:
		long double m;
		long double b;

		Calibration(long double mInput, long double bInput){
			m = mInput;
			b = bInput;
		}

		long double fix(Type input){
			return (input - b) / m;
		}

		std::vector<long double> fixVector(std::vector<Type> input){
			int size = input.size();
			std::vector<long double> output;
			for(int i = 0; i < size; i++) output.push_back(fix(input[i]));
			return output;
		}
};


template <class Type>
class SensorCalibration {
	public:
		std::vector< Calibration<int> > xyzCal;

		SensorCalibration(std::vector< Calibration<int> > inputCals){
			xyzCal = inputCals;
		}

		std::vector< std::vector<long double> > fixTable(std::vector< std::vector<Type> > input){
			//make new vector for xyz
			std::vector<Type> xvector, yvector, zvector;
			for(int i = 0; i < input.size(); i++){
				xvector.push_back(input[i][0]);
				yvector.push_back(input[i][1]);
				zvector.push_back(input[i][2]);
			}

			//calibrate the vectors individually
			std::vector<long double> xvectorCal, yvectorCal, zvectorCal;
			xvectorCal = xyzCal[0].fixVector(xvector);
			yvectorCal = xyzCal[1].fixVector(yvector);
			zvectorCal = xyzCal[2].fixVector(zvector);

			//put them back into a calibrated vector and return it
			std::vector< std::vector<long double> > output;
			for(int i = 0; i < input.size(); i++){
				std::vector<long double> tmp;
				tmp.push_back(xvectorCal[i]);
				tmp.push_back(yvectorCal[i]);
				tmp.push_back(zvectorCal[i]);
				output.push_back(tmp);
			}
			return output;
		}
};
