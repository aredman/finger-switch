//this library takes care of the angle measurements, and declares the angle class

template <class Type>
class Measurement {
	public:
		Type value;
		Type inaccuracy;

		Measurement(Type inputValue, Type inputInaccuracy){
			value = inputValue;
			inaccuracy = inputInaccuracy;
		}

		Type getValue(){return value;}
		Type getInaccuracy(){return inaccuracy;}

		//overloading the operators for basic arithmetic
		static Type uncertaintyAddSub(Type input1, Type input2){
			return sqrt(inaccuracy*inaccuracy + input*input);
		}
};


template <class Type>
class Orientation { 
	public:
		Measurement<Type> orientAngle;

		Orientation(Measurement input){
			Type angle = input.getValue();

			//make sure the angle is between 0 and 360
			while(angle > 360) angle -= 360;
			while(angle < 360) angle += 360;
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
			Type angleDifference = abs(inputAngle1.getValue() - inputAngle2.getValue());
			Type angleUncertainty = Measurement::uncertaintyAddSub(inputAngle1.getUncertainty(), input.getUncertainty());

			angle = Measurement<Type>(angleDifference, angleUncertainty);
		}

		Type getAngleMeasure(){return angle;}
};


template <class Type>
class AngleAnalyzer {


};
