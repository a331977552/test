#pragma once
#include "Vector3.h"
#include "Node.h"
class Transform : public Node
{
public:

		
	void setTranslate(int x, int y, int z);
	void setScale(int x, int y, int z);
	void setRotation(int x, int y, int z);
	Transform();
	virtual ~Transform();
	Vector3  translate;
	Vector3  scale;
	Vector3  rotation;

};

