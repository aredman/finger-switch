//library to facilitate linear calibration curves

template <class Type>
class Calibration {
	long double m;
	long double b;

	Calibration(long double mInput, long double bInput){
		m = mInput;
		b = bInput;
	}

	long double fix(Type input){
		return (input - b) / m;
	}
};
