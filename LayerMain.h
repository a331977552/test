#pragma once
#include "cocos2d.h"
#include "LayerBackground.h"
#include "Hero.h"
#include "LayerEnemy.h"
#include "LayerBullet.h"
#include "LayerBackground.h"
USING_NS_CC;
class LayerMain :public Layer
{
public:
	LayerBullet * bulletLayer;
	LayerBackground *back;
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

