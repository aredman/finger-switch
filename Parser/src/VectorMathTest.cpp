//this program tests the vector math program

#include "VectorMath.h"
#include <vector>

using namespace std;

int main(){
	//try the library with normal vectors
	vector<double> first(3);
	first[0] = 213;
	first[1] = 355;
	first[2] = 64;

	vector<double> second(3);
	second[0] = 1;
	second[1] = 0;
	second[2] = 0;

	for(int i = 0; i < 3; i++) cout << first[i] << ';';
	cout << endl;
	for(int i = 0; i < 3; i++) cout << second[i] << ';';
	cout << endl;

	//Dot Product
	double dot = dotProduct(first, second);
	cout << dot << endl;

	//Vector Projection
	vector<double> projected = projection(first, second);
	for(int i = 0; i < 3; i++) cout << projected[i] << ';';
	cout << endl;

	//Vector Rejection
	vector<double> rejected = rejection(first, second);
	for(int i = 0; i < 3; i++) cout << rejected[i] << ';';
	cout << endl;

	//return the orientation of a vector
	vector<double> orientVector;
	orientVector.push_back(123);
	orientVector.push_back(0);

	double orientDouble = orientation(orientVector);
	cout << orientDouble * 180 / 3.14159 << endl;

	//now we try a bunch of dummy variables to see if it works correctly
	vector< vector<double> > dummyVectors;
	vector<double> v1, v2, v3, v4, v5, v6, v7, v8;
	v1.push_back(0); v1.push_back(1);
	v2.push_back(1); v2.push_back(1);
	v3.push_back(1); v3.push_back(0);
	v4.push_back(1); v4.push_back(-1);
	v5.push_back(0); v5.push_back(-1);
	v6.push_back(-1); v6.push_back(-1);
	v7.push_back(-1); v7.push_back(0);
	v8.push_back(-1); v8.push_back(1);

	dummyVectors.push_back(v1);
	dummyVectors.push_back(v2);
	dummyVectors.push_back(v3);
	dummyVectors.push_back(v4);
	dummyVectors.push_back(v5);
	dummyVectors.push_back(v6);
	dummyVectors.push_back(v7);
	dummyVectors.push_back(v8);

	for(int i = 0; i < dummyVectors.size(); i++){
		cout << orientation180(dummyVectors[i]) << endl;
	}
}
