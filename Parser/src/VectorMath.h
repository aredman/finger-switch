//this library is for doing math 3 dimensional vectors

#include <valarray>
#include <iostream>
#include <math.h>
#include <vector>

template <class Type>
double dotProduct(Type& v1, Type& v2){
	if(v1.size() != v2.size()){
		std::cout << "Vectors have different sizes" << std::endl;
		return 0;
	}
	double sum = 0;
	for(int i = 0; i < v1.size(); i++){
		sum += v1[i] * v2[i];
	}
	return sum;
}

template <class Type>
Type projection(Type& v1, Type& v2){
	if(v1.size() != v2.size()){
		std::cout << "Vectors have different sizes" << std::endl;
		return Type(3);
	}
	double scalar = dotProduct(v1, v2) / dotProduct(v2, v2);
	Type returnVector(v1.size());
	for(int i = 0; i < v1.size(); i++){
		returnVector[i] = v2[i] * scalar;
	}
	return returnVector;
}

template <class Type>
Type rejection(Type& v1, Type& v2){
	if(v1.size() != v2.size()){
		std::cout << "Vectors have different sizes" << std::endl;
		return Type(3);
	}
	Type projectedVector = projection(v1, v2);
	Type returnVector(v1.size());
	for(int i = 0; i < v1.size(); i++){
		returnVector[i] = v1[i] - projectedVector[i];
	}
	return returnVector;
}

template <class Type>
double orientation(Type& input){
	if(input.size() < 2){
		std::cout << "Can't get orientation of vector with size " << input.size() << std::endl;
		return 0;
	}
	double output = atan2(input[0], input[1]);
	while(output < 0) output += 8*atan(1);
	return output;
}

template <class Type>
int orientation180(Type& input){
	int output = orientation(input) * 180 / 3.14159;
	return output;
}

template <class Type>
std::vector<int> vectorMultiplication(Type& input, double factor){
	std::vector<int> output;
	for(int i = 0; i < input.size(); i++){
		output.push_back(input[i] * factor);
	}
	return output;
}

template <class Type>
void printVector(std::vector<Type>& input){
	for(int i = 0; i < input.size(); i++){
		std::cout << input[i] << ';';
	}
	std::cout << std::endl;
}

template <class Type>
void printVector(std::vector< std::vector<Type> >& input){
	for(int i = 0; i < input.size(); i++){
		for(int j = 0; j < input[i].size(); j++){
			std::cout << input[i][j] << ';';
		}
		std::cout << std::endl;
	}
}
