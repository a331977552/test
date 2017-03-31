#pragma once
#include "cocos2d.h"
#include "EnemyLayer.h"
USING_NS_CC;
class EnemySprite :public Sprite
{
public:
	EnemyLayer *layer;

	int life;
	bool init(int degree);
	static EnemySprite * create(EnemyLayer *layer,int degree);
	CC_SYNTHESIZE(int, degree, degree);
	void FinishedTravelCallBack(Node * n);
	void onBossShowUp(Node *n);
};

