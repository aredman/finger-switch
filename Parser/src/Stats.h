//this is a simple library to linear regression on a vector
#ifndef LINREG_H
#define LINREG_H

#include <vector>
#include <math.h>

template <class Type>
class Stats {
	public:
		Stats(){}
		long double mean(std::vector<Type> input){
			int size = input.size();
			long double sum = 0;
			for int(i = 0; i < size; i++) sum += input[i];
			sum /= size;
		}
		long double variance(std::vector<Type> input){
			//variance is the sum of the squares, divided by the DOF, subtracting the mean
			int size = input.size();
			long double sum = 0;
			for(int i = 0; i < size; i++) sum += input[i] * input[i];
			sum /= size;
			long double mean = mean(input);
			return (sum / size) - mean * mean;
		}
		long double stdDev(std::vector<Type> input){
			return sqrt(variance(input));
		}
};

#endif
