#include <fstream>
#include <stdlib.h>
#include "import.h"
#include <iostream>

using namespace std;

int main(){
	intTable table;
	intTable parsedTable;
	std::string filename = "test1";

	Import data;
	table = data.tabulate(filename);

	parsedTable = data.tableCut(table,4,4,6);

	for(int i = 0; i<parsedTable.size();i++){
		for(int j = 0;j<parsedTable[i].size();j++){
			cout << parsedTable[i][j];
			cout << ",";
		}
		cout << endl;
	}
};

