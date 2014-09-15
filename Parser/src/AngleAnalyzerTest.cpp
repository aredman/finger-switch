//this program tests the angle analyzer

#include "AngleAnalyzer.h"
#include <iostream>

typedef long double ldouble;

using namespace std;

int main(){
	//test the measurement class
	Measurement<ldouble> testM(549, 23);
	cout << "value " << testM.getValue() << endl;
	cout << "uncertainty " << testM.getInaccuracy() << endl;


	//try out the orientation
	Orientation<ldouble> testO(testM);
	cout << "value " << testO.getValue() << endl;
	cout << "uncertainty " << testO.getInaccuracy() << endl;


	//try out the Angle
	Measurement<ldouble> testM2(234,12);
	Orientation<ldouble> testO2(testM2);
	Angle<ldouble> testA(testO2, testO);

	Measurement<ldouble> angleMeasure = testA.getAngleMeasure();
	cout << "value " << angleMeasure.getValue() << endl;
	cout << "uncertainty " << angleMeasure.getInaccuracy() << endl;
}
