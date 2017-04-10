#include "stdafx.h"
#include "ListBox.h"


ListBox::ListBox(int positionX,int positionY,int width,int height):Control( positionX, positionY, width, height)
{
	index = 0;
}
void ListBox::addItem(char *itemName, int  index)
{
	if (index > items.size()) {
		index = items.size();
	}
	else if (index < 0) {
		index = 0;
	}
	items.insert(items.begin() + index, string(itemName));
	
}
void ListBox::addItem(char * itemName) {
	addItem(itemName, 0);
}
void ListBox::removeItemByIndex(int index) {
	if (index > items.size()) {
		index = items.size();
	}
	else if (index < 0) {
		index = 0;
	}
	items.erase(items.begin() + index);

}


ListBox::~ListBox()
{

	for (vector<string>::iterator it = items.begin(); it != items.end(); it++) {

	}
}
void ListBox::setCurrentIndex(int index) {
	this->index = index;
}
bool  ListBox::updateControl(mouseState &state) {
	Control::updateControl(state);
	if (inside &&state.leftButtonDown) {
		int tempIndex = (state.y - posY) / itemHeight;
		if (tempIndex >= items.size())
			index = items.size()-1;
		else if (tempIndex < 0) {
			index = 0;
		}
		else {
			index = tempIndex;
		}
		return true;
	}

	return false;
}
void  ListBox::drawControl() {
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
	glColor4f(0.2, 0.2f, 0.8f, 0.5f);
	glBegin(GL_QUADS);

	int currentY = posY + itemHeight*index;
	glVertex2d(posX ,      currentY);
	glVertex2d(posX,       currentY+itemHeight);
	glVertex2d(posX+width, currentY+itemHeight);
	glVertex2d(posX+width, currentY);
	glEnd();

	glPopMatrix();
	
	glColor4f(0.2f, 0.2f, 0.2f, 0.8f);
	for (int i = 0; i < items.size(); i++) {
		string str=items.at(i);
		GlEngine::getInstance()->drawText(str.data(),posX,posY+i*itemHeight);

	}



}
string ListBox::getType() {
	 
	return  "listBox";
}