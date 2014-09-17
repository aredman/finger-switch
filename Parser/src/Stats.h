//this is a simple library to linear regression on a vector
#ifndef LINREG_H
#define LINREG_H

#include <vector>
#include <math.h>
#include <iostream>

class Stats {
	public:
		Stats(){}
		double mean(std::vector<double> input){
			int size = input.size();
			double sum = 0;
			for(int i = 0; i < size; i++) sum += input[i];
			return sum / size;
		}
		std::vector<double> vectorMean(std::vector< std::vector<double> > input){
			//create a new vector to hold the means
			std::vector<double> output;
			for(int i = 0; i < input[0].size(); i++){
				//make a vector of the input size
				std::vector<double> tmp;
				for(int j = 0; j < input.size(); j++){
					tmp.push_back(input[j][i]);
				}
				output.push_back(mean(tmp));
			}
			return output;
		}
		std::vector<double> vectorAccuracy(std::vector< std::vector<double> > input){
			//create a new vector to hold the means
			std::vector<double> output;
			for(int i = 0; i < input[0].size(); i++){
				//make a vector of the input size
				std::vector<double> tmp;
				for(int j = 0; j < input.size(); j++){
					tmp.push_back(input[j][i]);
				}
				output.push_back(accuracy(tmp));
			}
			return output;
		}
		double variance(std::vector<double> input){
			//variance is the sum of the squares, divided by the DOF, subtracting the mean
			int size = input.size();
			double average = mean(input);
			double sum = 0;
			for(int i = 0; i < size; i++){
				double difference = input[i] - average;
				sum += difference * difference;
			}
			return sum / size;
		}
		double stdDev(std::vector<double> input){
			return sqrt(variance(input));
		}
		double accuracy(std::vector<double> input){
			return stdDev(input) / sqrt(input.size());
		}
};

#endif
