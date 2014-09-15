//this tests the argument parsing class

#include <string>
#include <vector>
#include <iostream>

#include "ArgString.h"

using namespace std;

int main(int argc, char** argv){

	//put it into the contstructor
	ArgString args(argc, argv);
	for(int i = 0; i < args.get().size(); i++){
		cout << args.get()[i] << endl;
	}
}
