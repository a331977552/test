#pragma once
#include "Control.h"
class Slider :public Control
{
private :
	float current;
public:
	const int tickWidth = 5;
	string label;
	float min, max;
	bool dragging;
	float offsetx;
	Slider(string &lable, float min,float max,int positionX,int positionY,int width,int height);
	~Slider();
	void setValue(float current);
	const float getCurrentValue();
	bool  updateControl(mouseState &state);
	void  drawControl();
	string getType();
};

