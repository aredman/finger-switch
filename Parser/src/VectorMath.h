//this library is for doing math 3 dimensional vectors

#include <valarray>
#include <iostream>

template <class Type>
double dotProduct(Type v1, Type v2){
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
Type projection(Type v1, Type v2){
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
Type rejection(Type v1, Type v2){
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
