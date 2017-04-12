
#include "Button.h"
#include "GlEngine.h"


Button::Button(const char * text, int positionX, int positionY, int width, int height):Control(  positionX,  positionY,  width,  height){
	this->text = text;
}
Button::~Button() {
}
void  Button::drawControl() {
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
	if (inside) {
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
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glColor3f(0.8f, 0.8f, 0.8f);
	float  textWidth=(float)GlEngine::getInstance()->getTextLength(text);
	float  textHeight=(float)GlEngine::getInstance()->getTextHeight(text);
	float  textX =  posX+ ( width - textWidth)/2.f;
	float  textY =  posY+ (height - textHeight)/2.f;
	GlEngine::getInstance()->drawText(text, textX, textY);
}
bool  Button::updateControl(mouseState &state) {
	
	
	return Control::updateControl(state);
}
const char * Button::getText() {
	return text;
}
string Button::getType() {

return "button";
}
