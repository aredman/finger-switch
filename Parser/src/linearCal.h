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
