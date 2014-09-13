#include <fstream>
#include <stdlib.h>
#include "import.h"
#include <iostream>

using namespace std;

int main(){
	intTable table;
	std::string filename = "test1";
	Import data;
	table = data.tabulate(filename);
	for(int j = 0; j<table.size();j++){
		for(int i = 0;i<table[i].size();i++){
			std::cout << table[j][i];
			std::cout << ",";
		}
		std::cout << std::endl;
	}
};

