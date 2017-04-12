#pragma once
#include "Primitive.h"
class Plane : public Primitive
{
public:
	void setSize(float width, float height);
	void setDivisions(int divisions);

 	void createPrimitive() ;
	
protected:
	float width;
	float  height;
	int divisions;
};

