#pragma once
#include "cocos2d.h"
USING_NS_CC;
class EnemySprite :public Sprite
{
public:
	CREATE_FUNC(EnemySprite);
	bool init();
    void blowup();

	void FinishedTravelCallBack(Node * n);
};

