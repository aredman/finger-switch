//This interface allows one to return generic data to a data collection

#ifndef DATA_H
#define DATA_H

#include <Serial.h>
#include <Vector.h>



///////////////////////////////////////

template <typename Type, int size>
class DataType {
	public:
		DataType(){
			dataTime = millis();
		}

		Vector<Type,size>& getData(){return data;};
		unsigned long getTime(){return dataTime;};

		void print(){
			Serial << dataTime;

			for(int i = 0; i < size; i++) Serial << ';' << data[i];
			Serial << endl;
		}
	protected:
		Vector<Type, size> data;
		unsigned long dataTime;
};

///////////////////////////////////////

template <typename base>
class threeAxis : public DataType<base,3> {
	public:
		threeAxis(Vector<base,3> input){ this->getData() = input; };
};

template <typename base>
class scalar : public DataType<base,1> {
	public:
		scalar(base input){ this->getData()[0] = input; };
};

#endif
