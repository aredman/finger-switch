#ifndef IMPORT_H
#define IMPORT_H

#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <vector>

typedef std::vector<int> row;
typedef std::vector< std::vector<int> > intTable;

class Import{	
	public:
		std::vector<std::string> addline(std::istream& inputFile){
			std::vector<std::string> inputVector;
			while(inputFile.eof() == 0){
				std::string line;
				std::getline(inputFile,line);	
				inputVector.push_back(line);
			}
			inputVector.pop_back();
			return inputVector;
		}

		row parseLine(std::string inputLine){
			row numberData;
			std::stringstream inputStream(inputLine);
			std::string piece;
			while(inputStream.eof()==0){
				std::getline(inputStream,piece,';');
				numberData.push_back(atoi(piece.c_str()));
			}
			return numberData;
		}

		intTable returnTable(std::vector<std::string> inputLine){
			intTable final;
			for(int i = 0;i < inputLine.size();i++){
				final.push_back(parseLine(inputLine[i]));
			}
			return final;
		}

		intTable tabulate(std::string filename){
			std::ifstream inputStream;
			inputStream.open(filename.c_str());
			std::vector<std::string> lineArray;
			lineArray = addline(inputStream);

			intTable dataArray;
			dataArray = returnTable(lineArray);
			return dataArray;
		}

		intTable cut(intTable bigTable,int index){
			intTable smallTable;
			for(int i = 0;i<bigTable.size();i++){
					if(bigTable[i][0] == index){
						smallTable.push_back(bigTable[i]);
					}
			}
			return smallTable;
		}
};

#endif
