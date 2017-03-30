#pragma once
#include "cocos2d.h"
USING_NS_CC;
class LayerBackground :public Layer
{
public:
	Sprite * bg1;
	Sprite * bg2;
	CREATE_FUNC(LayerBackground);
	bool init();
	void updateBackgroud(float de);
};

