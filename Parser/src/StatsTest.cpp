#include "Stats.h"

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <vector>
#include <iostream>

using namespace std;

int main(){
	//make a vector of random numbers
	srand (time(NULL));
	std::vector<double> random;
	for(int i = 0; i < 100; i++){
		random.push_back(rand()/1000000);
	}

	//perform statistical analysis
	std::cout << "Mean:     " << Stats().mean(random) << std::endl;
	std::cout << "Variance: " << Stats().variance(random) << std::endl;
	std::cout << "StdDev:   " << Stats().stdDev(random) << std::endl;
	std::cout << "Accuracy: " << Stats().accuracy(random) << std::endl;


	vector< vector<double> > vectorTest;
	for(int i = 0; i < 10; i++){
		vector<double> tmp;
		for(int j = 0; j < 10; j++){
			tmp.push_back(rand()/1000000);
		}
		vectorTest.push_back(tmp);
	}

	vector<double> vectorTestMean = Stats().vectorMean(vectorTest);
	vector<double> vectorTestAccu = Stats().vectorAccuracy(vectorTest);

	for(int i = 0; i < vectorTestMean.size(); i++) cout << vectorTestMean[i] << ';';
	cout << endl;
	for(int i = 0; i < vectorTestMean.size(); i++) cout << vectorTestAccu[i] << ';';
	cout << endl;
	
}
