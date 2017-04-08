
#include "Control.h"


 list<Control *> Control::controls;
	
 bool  Control::updateControl(mouseState &state) {
	 int x = state.x;
	 int y = state.y;
	 inside = false;
	 if (x >= posX &&x < (posX + width) &&
		 y >= posY &&y < (posY + height)) {
		 inside = true;
	 }
	 return false;
 }
	Control::Control(int positionX,int positionY,int width,int height) {
		setPosition(positionX, positionY);
		setSize(width,height);
		controls.push_back(this);
 }
	Control::~Control() {
			controls.remove(this);
	  }
	void Control::setPosition(int x,int y) {
		posX = x;
		posY = y;
 }
	void Control::setSize(int width, int height) {
		this->width = width;
		this->height = height;
 }
	int Control::getHeight() {
	
		return height;
	}
	int Control::getWidth() {
		return width;
 }
Control * Control::addControl(Control* control) {
		static int lastX = 5;
		static int lastY = 5;
		control->setPosition(lastX,lastY);
		lastY+=control->getHeight();
		lastX+=control->getWidth();
		return control;
}
	