#include "Stats.h"

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <vector>
#include <iostream>

int main(){
	//make a vector of random numbers
	srand (time(NULL));
	std::vector<int> random;
	for(int i = 0; i < 100000000; i++){
		random.push_back(rand()/1000000);
	}

	//perform statistical analysis
	std::cout << "Mean:     " << Stats<int>().mean(random) << std::endl;
	std::cout << "Variance: " << Stats<int>().variance(random) << std::endl;
	std::cout << "StdDev:   " << Stats<int>().stdDev(random) << std::endl;
	std::cout << "Accuracy: " << Stats<int>().accuracy(random) << std::endl;
}
