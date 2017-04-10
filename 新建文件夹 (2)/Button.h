#pragma once
#include "Control.h"
class Button :public Control
{
private:
	const char * text;
public:
	bool  updateControl(mouseState &state) override;
	const char * getText();
	Button(const char * text ,int positionX,int positionY,int width,int height);
	~Button();
	void  drawControl();
	 string getType();
};

