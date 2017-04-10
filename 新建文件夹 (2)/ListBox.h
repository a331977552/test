#pragma once
#include "Control.h"
#include <vector>
#include "GlEngine.h"
using std::vector;
class ListBox :public Control
{
private :
	const int itemHeight=18;
public:

	vector<string> items;
	int index;
	void addItem(char *itemName,int  index);
	void addItem(char * itemName);
	void removeItemByIndex(int index);

	void setCurrentIndex(int index);
	bool  updateControl(mouseState &state);
	void  drawControl();
	string getType();
	ListBox(int positionX,int positionY,int width,int height);
	~ListBox();
	
};

