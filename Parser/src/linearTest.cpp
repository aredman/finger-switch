#include "linearCal.h"

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <vector>
#include <iostream>

int main(){
	srand (time(NULL));
	std::vector<int> random;
	for(int i = 0; i < 10; i++){
		random.push_back(rand()/1000000);
	}

	//test the fix portion of the linear regression
	Calibration<int> testCal(100,34);
	for(int i = 0; i < random.size(); i++){
		std::cout << random[i] << "   " << testCal.fix(random[i]) << std::endl;
	}

	std::vector<long double> newVector = testCal.fixVector(random);
	for(int i = 0; i < newVector.size(); i++) std::cout << newVector[i] << std::endl;
}
