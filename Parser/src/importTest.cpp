#include <fstream>
#include <stdlib.h>
#include "import.h"
#include <iostream>

using namespace std;

int main(){
	intTable table;
	intTable point0;
	intTable point01;
	std::string filename = "test1";
	Import data;
	table = data.tabulate(filename);
	point0 = data.rowCut(table,4);
	cout << "H2llo World" << endl;
	point01 = data.columnCut(point0,0,2);
	cout << "H1llo World" << endl;
	for(int i = 0; i<point0.size();i++){
		for(int j = 0;j<point01[i].size();j++){
			cout << point01[i][j];
			cout << ",";
		}
		cout << endl;
	}
};

