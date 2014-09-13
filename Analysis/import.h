#ifndef IMPORT_H
#define IMPORT_H

#include <fstream>;
#include <stdlib.h>;
#include <sstream>;
#include <iostream>;
#include <vector>;

class Import{	
	public:
		std::vector<std::string> addline(istream& inputFile){
			std::vector<std::string> inputVector;
			while(inputFile.eof == 0){
				std::string line;
				std::getline(inputFile,line);	
				inputVector.push_back(line);
			}
			return inputVector;
		}

		std::vector<int> parseLine(std::string inputLine){
			std::vector<std::int> numberData;
			stringstream inputStream(inputLine);
			std::string piece;
			while(inputStream.eof==0){
				std::getline(inputStream,piece,';');
				numberData.push_back(atoi(piece.c_str()));
			}
			return numberData;
		}

		std::vector<std::vector<int>> returnVector(std::vector<std::string> inputLine){
			std::vector<std::vector<int>> final;
			for(int i = 0;i < inputLine.size();i++){
				final.push_back = parseLine(inputLine[i]);
			}
			return final;
		}

};

#endif
