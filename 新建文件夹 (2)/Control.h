#pragma once
#include <gl/glut.h>
#include <list>
using std::list;
using std::string;
class Control
{
	
protected :
	bool inside;
	int posX, posY;
	int width, height;

public:
	struct mouseState { 
		int x;
		int y;
		bool leftButtonDown;
		bool rightButtonDown;
		bool middleuttonDown;
		mouseState() {
			x = 0;
			y = 0;
			leftButtonDown = false;
			rightButtonDown = false;
			middleuttonDown = false;
		}
	};
	static list<Control *> controls;
	int x;
	int y;
	bool  updateControl(mouseState &state);
	Control(int positionX,int positionY,int width,int height);
	virtual void  drawControl() =0;
    virtual ~Control();
	virtual string getType()=0;
	void setPosition(int x,int y);
	void setSize(int width, int height);
	int getHeight();
	int getWidth();
	static Control  * addControl(Control * control);


};

