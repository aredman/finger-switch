//this library takes care of the angle measurements, and declares the angle class

#include <iostream>
#include <math.h>

//simple template function to return the absolute value
template <class Type>
Type absVal(Type input){return input < 0 ? -1*input : input;}


template <class Type>
class Measurement {
	public:
		Type value;
		Type inaccuracy;

		Measurement(){};
		Measurement(Type inputValue, Type inputInaccuracy){
			value = inputValue;
			inaccuracy = inputInaccuracy;
		}

		Type getValue(){return value;}
		Type getInaccuracy(){return inaccuracy;}

		static Type uncertaintyAddSub(Type input1, Type input2){
			return sqrt(input1 * input1 + input2 * input2);
		}
};


template <class Type>
class Orientation { 
	public:
		Measurement<Type> orientAngle;

		Orientation(Measurement<Type> input){
			Type angle = input.getValue();

			//make sure the angle is between 0 and 360
			while(angle > 360) angle -= 360;
			while(angle < 0) angle += 360;
			orientAngle = Measurement<Type>(angle, input.getInaccuracy());
		}

		Type getValue(){return orientAngle.getValue();}
		Type getInaccuracy(){return orientAngle.getInaccuracy();}
};

template <class Type>
class Angle {
	public:
		Measurement<Type> angle;

		Angle(Orientation<Type> inputAngle1, Orientation<Type> inputAngle2){
			Type angleDifference = absVal(inputAngle1.getValue() - inputAngle2.getValue());
			Type angleUncertainty = Measurement<Type>::uncertaintyAddSub(inputAngle1.getInaccuracy(), inputAngle2.getInaccuracy());

			angle = Measurement<Type>(angleDifference, angleUncertainty);
		}

		Measurement<Type> getAngleMeasure(){return angle;}
};


template <class Type>
class AngleAnalyzer {


};
