#include <fstream>
#include <stdlib.h>
#include "import.h"
#include <iostream>

int main(){
	Import object;
	std::ifstream is;
	is.open("test.txt");
	std::vector<std::string> vs;
	vs = object.addline(is);
	
	std::vector< std::vector<int> > vvi;
	vvi = object.returnVector(vs);

	std::cout << vvi[1][1]+vvi[0][0] << std::endl;


}
