#include <fstream>
#include <stdlib.h>
#include "import.h"
#include <iostream>

using namespace std;

int main(){
	intTable table;
	vector<intTable> parsedTable;
	std::string filename = "test1";

	Import data;
	table = data.tabulate(filename);

	parsedTable = data.getMagnet(table,6);

	for(int i = 0; i<parsedTable.size();i++){
		for(int j = 0;j<parsedTable[i].size();j++){
			for(int k = 0; k < parsedTable[i][j].size();k++){
				cout << parsedTable[i][j][k];
				cout << ",";
			}
			cout << endl;
		}
			cout << "------" << endl;
	}
};

