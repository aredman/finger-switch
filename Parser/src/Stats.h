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
			for(int i = 0; i < size; i++) sum += input[i];
			return sum / size;
		}
		long double variance(std::vector<Type> input){
			//variance is the sum of the squares, divided by the DOF, subtracting the mean
			int size = input.size();
			long double average = mean(input);
			long double sum = 0;
			for(int i = 0; i < size; i++){
				long double difference = input[i] - average;
				sum += difference * difference;
			}
			return sum / size;
		}
		long double stdDev(std::vector<Type> input){
			return sqrt(variance(input));
		}
		long double accuracy(std::vector<Type> input){
			return stdDev(input) / sqrt(input.size());
		}
};

#endif
