#include "stdafx.h"
#include "Slider.h"
#include "GlEngine.h"

Slider::Slider(string &label, float min, float max, 
			   int positionX, int positionY, int width, int height):
		Control(positionX,  positionY,  width,  height),
	min(min),max(max),label(label),dragging(false),current(0){
	offsetx = 0;
	}
	Slider::~Slider() {

	}
	void    Slider::setValue(float current) {
		offsetx = current / (max - min) *width;
		this->current = current;
	}
const float Slider::getCurrentValue(){

	return current;
}
	bool    Slider::updateControl(mouseState &state){
		Control::updateControl(state);
		if (inside &&state.leftButtonDown) {
			dragging = true;
		}
		if (dragging) {
		 offsetx = state.x - posX;
			
	
		if (offsetx+tickWidth> width) {
				offsetx = width-tickWidth;
		}
		else if (offsetx < 0) {
				offsetx = 0;
		}
		if (offsetx == (width - tickWidth)) {
		 current = (float)(offsetx+tickWidth)/(float)width*(max - min)+min;
		}
		else {
			current = (float) (offsetx/(float)width)*(max - min)+min;
		}	
		//std::cout << "current" << current<<std::endl;
		}
		if (!state.leftButtonDown)
		{
			dragging = false;
		}
		if (inside &&state.rightButtonDown) {
			current =min;
			offsetx = 0;
			dragging = false;
		}
		return dragging;
	}
	void    Slider::drawControl(){
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_TEXTURE_2D);
	
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glColor4f(0.7f, 0.7f, 0.7f,0.8f);
	glBegin(GL_QUADS);
	glVertex2d(posX , posY);
	glVertex2d(posX, posY+height);
	glVertex2d(posX + width, posY+height);
	glVertex2d(posX  +width, posY);
	glEnd();
	/*if (inside) {
		glColor4f(0.2f, 0.2f, 0.7f, 0.8f);
		glLineWidth(2.f);
	}else{
	glColor4f(0.2f, 0.2f, 0.7f, 0.5f);
		glLineWidth(1.f);
	}
	glBegin(GL_QUADS);
	glVertex2d(posX , posY);
	glVertex2d(posX, posY+height);
	glVertex2d(posX + width, posY+height);
	glVertex2d(posX  +width, posY);
	glEnd();
	*/

	glColor3f(0.2f, 0.2f, 1.f);
	glBegin(GL_QUADS);
	glVertex2d(posX +offsetx, posY);
	glVertex2d(posX+offsetx, posY+height);
	glVertex2d(posX + tickWidth+offsetx, posY+height);
	glVertex2d(posX+tickWidth+offsetx, posY);
	glEnd();

	glPopMatrix();
	glColor3f(0.8f, 0.8f, 0.8f);
	float  textWidth=(float)GlEngine::getInstance()->getTextLength(label.data());
	float  textHeight=(float)GlEngine::getInstance()->getTextHeight(label.data());
	float  textX =  posX+ ( width - textWidth)/2.f;
	float  textY =  posY+ (height - textHeight)/2.f;
	GlEngine::getInstance()->drawText(label.data(), textX, textY);
	
}
	string  Slider::getType(){

		return "slider";
	}

