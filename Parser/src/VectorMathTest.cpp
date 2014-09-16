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
}
