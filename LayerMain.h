#pragma once
#include "cocos2d.h"
#include "LayerBackground.h"
#include "Hero.h"
#include "LayerBullet.h"
#include "LayerBackground.h"
#include "EnemyLayer.h"
USING_NS_CC;
class LayerMain :public Layer
{
public:
	LayerBullet * bulletLayer;
	LayerBackground *back;
	EnemyLayer * enemyLayer;
	CREATE_FUNC(LayerMain);
	static Scene * createScene();
	bool init();
	void addBackground();
	void addHero();
	void addEnemy();
	void addFood();
	void pauseCallBack(Ref *f);
	void resumeCallBack(Ref *f);
	void update(float dt);
    bool onTouchBegan(Touch *touch, Event *unused_event);
    void onTouchMoved(Touch *touch, Event *unused_event);
	void removeHero();
	void startShoot();
	void moveBackgroud(float dt);


};

