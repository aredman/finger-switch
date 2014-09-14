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

		intTable rowCut(intTable bigTable,int index){
			intTable smallTable;
			for(int i = 0;i<bigTable.size();i++){
					if(bigTable[i][0] == index){
						smallTable.push_back(bigTable[i]);
					}
			}
			return smallTable;
		}

		intTable columnCut(intTable bigTable,int abound, int bbound){
			intTable smallTable;
			for(int i = 0; i < bigTable.size();i++){
				smallTable.resize(smallTable.size()+1);
				for(int j = 0; j < bigTable[i].size();j++){
					if(j >= abound && j <= bbound){
						smallTable[i].push_back(bigTable[i][j]);
					}
				}
			}
			return smallTable;
		}

		intTable tableCut(intTable bigTable,int index,int abound,int bbound){
				intTable mediumTable;
				intTable smallTable;

				mediumTable = rowCut(bigTable,index);
				smallTable = columnCut(mediumTable,abound,bbound);
				return smallTable;
		}

		std::vector<intTable> getAccel(intTable bigTable,int rows){
			std::vector<intTable> accelerometerData;
			for(int i = 0; i<rows;i++){
				accelerometerData.push_back(tableCut(bigTable,i,1,3));
			}
			return accelerometerData;
		}

		std::vector<intTable> getMagnet(intTable bigTable,int rows){
			std::vector<intTable> magnetometerData;
			for(int i = 0; i<rows;i++){
				magnetometerData.push_back(tableCut(bigTable,i,4,6));
			}
			return magnetometerData;
		}
		std::vector<intTable> explode(intTable bigTable,int rows){
			std::vector<intTable> array;
			for(int i = 0; i<rows;i++){
				array.push_back(tableCut(bigTable,i,1,3));
				array.push_back(tableCut(bigTable,i,4,6));
			}
			return array;
		}

};
#endif
