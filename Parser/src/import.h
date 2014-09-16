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

		//Takes a string and converts it into a vector of doubles 
		//Parses the data using getline based on semi-colons and 
		//converts them from ascii to doubles using atof()
		std::vector<double> parseLine(std::string inputLine){
			std::vector<double> numberData;
			std::stringstream inputStream(inputLine);
			std::string piece;
			while(inputStream.eof()==0){
				std::getline(inputStream,piece,';');
				numberData.push_back(atof(piece.c_str()));
			}
			return numberData;
		}

		//Takes a string of data and separates it into an dTable
		dTable returnTable(std::vector<std::string> inputLine){
			dTable final;
			for(int i = 0;i < inputLine.size();i++){
				final.push_back(parseLine(inputLine[i]));
			}
			return final;
		}

		//Takes a file name and opens a filestream to that data file
		//Parses the semi-colon separated data into a dTable
		dTable tabulate(std::string filename){
			std::ifstream inputStream;
			inputStream.open(filename.c_str());
			std::vector<std::string> lineArray;
			lineArray = addline(inputStream);

			dTable dataArray;
			dataArray = returnTable(lineArray);
			return dataArray;
		}

		//Cuts a big table into smaller tables based on row index numbers
		dTable rowCut(dTable bigTable,int index){
			dTable smallTable;
			for(int i = 0;i<bigTable.size();i++){
					if(bigTable[i][0] == index){
						smallTable.push_back(bigTable[i]);
					}
			}
			return smallTable;
		}

		//Cuts a big table into smaller tables based on columns
		dTable columnCut(dTable bigTable,int abound, int bbound){
			dTable smallTable;
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
		dTable tableCut(dTable bigTable,int index,int abound,int bbound){
				dTable mediumTable;
				dTable smallTable;

				mediumTable = rowCut(bigTable,index);
				smallTable = columnCut(mediumTable,abound,bbound);
				return smallTable;
		}

		//Pulls accelerometer data out of an dTable
		std::vector<dTable> getAccel(dTable bigTable,int start,int end){
			std::vector<dTable> accelerometerData;
			for(int i = start; i < end;i++){
				accelerometerData.push_back(tableCut(bigTable,i,1,3));
			}
			return accelerometerData;
		}

		//Pulls magnetometer data out of an dTable 
		std::vector<dTable> getMagnet(dTable bigTable,int start,int end){
			std::vector<dTable> magnetometerData;
			for(int i = start; i < end;i++){
				magnetometerData.push_back(tableCut(bigTable,i,4,6));
			}
			return magnetometerData;
		}

		//"explodes" an dTable into multiple smaller dTables 
		//and returns a vector of smaller dTables
		std::vector<dTable> explode(dTable bigTable,int rows){
			std::vector<dTable> array;
			for(int i = 0; i<rows;i++){
				array.push_back(tableCut(bigTable,i,1,3));
				array.push_back(tableCut(bigTable,i,4,6));
			}
			return array;
		}

};
#endif
