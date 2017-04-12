#pragma once
#include "Node.h"
class Primitive :public Node
{
public:
	virtual void createPrimitive() = 0;
};

