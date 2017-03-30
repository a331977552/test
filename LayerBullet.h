#pragma once
#include "cocos2d.h"
USING_NS_CC;
class LayerBullet :public Layer
{
public:
	Array *arrBullets;
	SpriteBatchNode*  batchNode;
	enum BulletType{
		NORMAL=0,DOUBLE=1
	};
	CC_SYNTHESIZE(BulletType,bulletType,bulletType)
	
	CREATE_FUNC(LayerBullet);
	bool init();
	void addBullet(float de);
	void removeBulletIfNecessay();

	void bulletFinishedTravelCallBack(Node * n);

};

