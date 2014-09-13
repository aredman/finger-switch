#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>

//simple class for fixed length vectors
template <typename type, int length = 1>
class Vector {
	public:
		//constructor
		type array[length];
		int size(){return length;};

		type& operator[](int i){return array[i];};
		Vector<type, length> operator=(Vector<type,length>& rhs){ for(int i = 0; i < length; i++) array[i] = rhs[i]; return *this;};

		Vector<type, length>& operator+=(Vector<type,length>& rhs){ for(int i = 0; i < length; i++) array[i] += rhs[i]; return this;};
		Vector<type, length>& operator-=(Vector<type,length>& rhs){ for(int i = 0; i < length; i++) array[i] -= rhs[i]; return this;};
		Vector<type, length>& operator*=(Vector<type,length>& rhs){ for(int i = 0; i < length; i++) array[i] *= rhs[i]; return this;};
		Vector<type, length>& operator/=(Vector<type,length>& rhs){ for(int i = 0; i < length; i++) array[i] /= rhs[i]; return this;};
		Vector<type, length>& operator%=(Vector<type,length>& rhs){ for(int i = 0; i < length; i++) array[i] %= rhs[i]; return this;};

		bool operator<(Vector<type,length>& rhs){ return magnitude() < rhs.magnitude();}
		bool operator>(Vector<type,length>& rhs){ return magnitude() > rhs.magnitude();}
		bool operator<=(Vector<type,length>& rhs){ return magnitude() <= rhs.magnitude();}
		bool operator>=(Vector<type,length>& rhs){ return magnitude() >= rhs.magnitude();}

		bool operator==(Vector<type,length>& rhs){ 
			for(int i = length; i; i--) if(array[i] != rhs[i]) return false;
			return true;
		}
		bool operator!=(Vector<type,length>& rhs){ return *this == rhs;};

		Vector<type, length> operator+(Vector<type, length>& rhs){
			Vector<type, length> returnVector;
			for(int i = length; i; i--) returnVector[i] = array[i] + rhs[i];
			return returnVector;
		}
		Vector<type, length> operator-(Vector<type, length>& rhs){
			Vector<type, length> returnVector;
			for(int i = length; i; i--) returnVector[i] = array[i] - rhs[i];
			return returnVector;
		}
		Vector<type, length> operator*(Vector<type, length>& rhs){
			Vector<type, length> returnVector;
			for(int i = length; i; i--) returnVector[i] = array[i] * rhs[i];
			return returnVector;
		}
		Vector<type, length> operator/(Vector<type, length>& rhs){
			Vector<type, length> returnVector;
			for(int i = length; i; i--) returnVector[i] = array[i] / rhs[i];
			return returnVector;
		}
		Vector<type, length> operator%(Vector<type, length>& rhs){
			Vector<type, length> returnVector;
			for(int i = length; i; i--) returnVector[i] = array[i] % rhs[i];
			return returnVector;
		}

		type magnitude(){
			double returnValue = 0;
			for(int i = length; i; i--) returnValue += array[i]*array[i];
			return sqrt(returnValue);
		}
};

#endif
