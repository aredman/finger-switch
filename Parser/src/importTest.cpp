#include <fstream>
#include <stdlib.h>
#include "import.h"
#include <iostream>

using namespace std;

int main(){
	intTable table;
	intTable point0;
	std::string filename = "test1";
	Import data;
	table = data.tabulate(filename);
	cout << "hello World" << endl;
	point0 = data.cut(table,4);
	cout << "hello World" << endl;


	for(int i = 0; i<point0.size();i++){
		for(int j = 0;j<point0[i].size();j++){
			std::cout << point0[i][j];
			std::cout << ",";
		}
		std::cout << std::endl;
	}
};

