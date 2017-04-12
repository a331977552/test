
#include "Vector3.h"

 Vector3::Vector3(float x , float y, float z):x(x),y(y),z(z){
	
}
	  float Vector3::dot(Vector3 vec) {

		return   x*vec.x + y*vec.y + z*vec.z;
	  }
	  Vector3 Vector3::operator+(Vector3 vec) {
		 return Vector3( x + vec.x,y+vec.y,z+vec.z);
	  }
	Vector3 Vector3::operator++() {
		x++;
		y++;
		z++;
		return *this;
	  }
	Vector3 Vector3::operator+=(Vector3 vec) {

		 return (*this= (*this * vec));
	  }
	Vector3 Vector3::operator-(Vector3 vec) {
			
		return Vector3( x - vec.x,y-vec.y,z-vec.z);
	  }
	Vector3 Vector3::operator-() {
		x=-x;
		y = -y;
		z = -z;
		return *this;
	}
	Vector3 Vector3::operator*(Vector3 vec) {
	return Vector3(y* vec.z - z*vec.y ,-(x*vec.z -y*vec.x),x*vec.y - vec.x*y);
	  }
	Vector3 Vector3::operator*(float vec) {

		return Vector3( x*vec,y*vec,z*vec);
	  }
	Vector3 Vector3::operator*=(Vector3 vec) {
	  	return (*this  =  (*this * vec));
	  }

	Vector3 Vector3::operator/=(float vec) {
		 	return (*this  =  (*this / vec));
	  }
	Vector3  Vector3::operator/(float vec)
	{
		return Vector3( x/vec,y/vec,z/vec);
	}
	float   Vector3::getLenght() {
		return sqrtl(x*x + y*y + z*z);
	}
	Vector3 Vector3::normalize() {
		float length=getLenght();
		x/=length;
		y/=length;
		z/=length;
		return *this;
	 }

	Vector3 Vector3::operator-=(Vector3 vec) {
		return (*this = (*this - vec));
	}
	Vector3 Vector3::operator--() {
		x--;
		y--;
		z--;
		return *this;
	}