#pragma once
#include "cocos2d.h"
USING_NS_CC;
class Hero :public Sprite
{
private :
	Hero();
	static Hero * hero;
	bool init();
public:
	static Hero* getInstance();
	void blowup();
	void destory();
	
	
	
		
	
};

