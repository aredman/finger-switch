//this program tests the angle analyzer

#include <AngleAnalyzer.h>
#include <iostream>

typedef long double ldouble

using namespace std;

int main(){
	//test the measurement class
	Measurement<ldouble> testM(234, 23);

	cout << "value " << testM.getValue() << endl;
	cout << "uncertainty " << testM.getInaccuracy() << endl;
}
