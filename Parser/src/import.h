#ifndef IMPORT_H
#define IMPORT_H

#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <vector>
#include "Measurements.h"

class Import{	

	private:

	public:

		//Takes an input stream from a file and saves it as a vector of 
		//strings.
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

		//Takes a string and converts it into a vector of integers
		//Parses the data using getline based on semi-colons and 
		//converts them from ascii to integers using atoi()
		std::vector<int> parseLine(std::string inputLine){
			std::vector<int> numberData;
			std::stringstream inputStream(inputLine);
			std::string piece;
			while(inputStream.eof()==0){
				std::getline(inputStream,piece,';');
				numberData.push_back(atoi(piece.c_str()));
			}
			return numberData;
		}

		//Takes a string of data and separates it into an intTable
		intTable returnTable(std::vector<std::string> inputLine){
			intTable final;
			for(int i = 0;i < inputLine.size();i++){
				final.push_back(parseLine(inputLine[i]));
			}
			return final;
		}

		//Takes a file name and opens a filestream to that data file
		//Parses the semi-colon separated data into a intTable
		intTable tabulate(std::string filename){
			std::ifstream inputStream;
			inputStream.open(filename.c_str());
			std::vector<std::string> lineArray;
			lineArray = addline(inputStream);

			intTable dataArray;
			dataArray = returnTable(lineArray);
			return dataArray;
		}

		//Cuts a big table into smaller tables based on row index numbers
		intTable rowCut(intTable bigTable,int index){
			intTable smallTable;
			for(int i = 0;i<bigTable.size();i++){
					if(bigTable[i][0] == index){
						smallTable.push_back(bigTable[i]);
					}
			}
			return smallTable;
		}

		//Cuts a big table into smaller tables based on columns
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

		//Cuts a table up based on row index and column boundaries
		intTable tableCut(intTable bigTable,int index,int abound,int bbound){
				intTable mediumTable;
				intTable smallTable;

				mediumTable = rowCut(bigTable,index);
				smallTable = columnCut(mediumTable,abound,bbound);
				return smallTable;
		}

		//Pulls accelerometer data out of an intTable
		std::vector<intTable> getAccel(intTable bigTable,int rows){
			std::vector<intTable> accelerometerData;
			for(int i = 0; i<rows;i++){
				accelerometerData.push_back(tableCut(bigTable,i,1,3));
			}
			return accelerometerData;
		}

		//Pulls magnetometer data out of an intTable 
		std::vector<intTable> getMagnet(intTable bigTable,int rows){
			std::vector<intTable> magnetometerData;
			for(int i = 0; i<rows;i++){
				magnetometerData.push_back(tableCut(bigTable,i,4,6));
			}
			return magnetometerData;
		}

		//"explodes" an intTable into multiple smaller intTables 
		//and returns a vector of smaller intTables
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
