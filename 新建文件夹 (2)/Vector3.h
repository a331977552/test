#pragma once
#include <math.h>
class Vector3
{

public:
	float x, y, z;
	Vector3(float x=0,float y=0,float z=0);
	float dot(Vector3 vec);
	Vector3 operator+(Vector3 vec);
	Vector3 operator++();
	Vector3 operator-(Vector3 vec);
	Vector3 operator-();
	Vector3 operator-=(Vector3 vec);
	Vector3 operator--();
	Vector3 operator+=(Vector3 vec);
	Vector3 operator*(Vector3 vec);
	Vector3 operator*(float vec);
	Vector3 operator*=(Vector3 vec);
	Vector3 operator/=(float vec);
	Vector3 operator/(float vec);
	float getLenght();
	Vector3 normalize();

	
};

