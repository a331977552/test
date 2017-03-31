#pragma once
#include "cocos2d.h"
USING_NS_CC;
class EnemyLayer :public Layer
{
public:
	bool hasBoss;
	enum enumType {
		NORMAL=0,ADVANCED=1,BOSS=2
	};
	Array * arrEnemy;
	CREATE_FUNC(EnemyLayer);
	bool init();
    void blowup(Sprite   * s);
	void generateNormalEnemy(float de);
	void generateAdvancedEnemy(float de);
	void generateBossEnemy(float de);
	void FinishedTravelCallBack(Node * n);
	void destoryEnemy(Node * n);
};

