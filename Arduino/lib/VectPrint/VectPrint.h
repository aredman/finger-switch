//this class takes vectors of a generic type and prints out the data in an array

#include <Vector.h>
#include <Serial.h>

template <class baseType, int bufferSize = 10, int vectorDimensions = 3>
class VectPrinter {
	public:
		int count;
		Vector<baseType, vectorDimensions> array[bufferSize];
		long int index;

		VectPrinter(){
			count = 0;
			index = 0;
		}

		void add(Vector<baseType, vectorDimensions> input){
			if(count >= bufferSize) return;
			array[count] = input;
			count++;
		}
		void print(){
			Serial << index;
			for(int i = 0; i < count; i++){
				for(int j = 0; j < vectorDimensions; j++){
					Serial << ';' << array[i][j];
				}
			}
			Serial << endl;
			count = 0;
		}
		void next(){index++;}
};
