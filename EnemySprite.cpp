#include "EnemySprite.h"
#include "EnemyLayer.h"

bool EnemySprite::init(int degree) {

	if (degree == 0) {
		life = 1;
		SpriteFrame * frame=SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy1.png");
		Sprite::initWithSpriteFrame(frame);
	}
	else if (degree == 1) {
		life = 3;
		SpriteFrame * frame=SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy2.png");
		Sprite::initWithSpriteFrame(frame);
	}
	else if (degree == 2) {
		layer->hasBoss = true;
		life = 6;
		SpriteFrame * frame=SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy3_n1.png");
		Sprite::initWithSpriteFrame(frame);
	}
	Size s=getContentSize();
	int  availableWith=Director::getInstance()->getWinSize().width - s.width;
	int xpos=rand()%availableWith+ s.width/2;
	setPosition(xpos,Director::getInstance()->getWinSize().height+50);
	setdegree(degree);
	if (degree < 2) {
		MoveTo * to = MoveTo::create(5,Vec2(xpos,-50));
		CCCallFuncN *func = CCCallFuncN::create(this,SEL_CallFuncN(&EnemySprite::FinishedTravelCallBack));
		Sequence * se = Sequence::create(to, func, NULL);
		runAction(se);
	}
	else {
		MoveTo * to = MoveTo::create(2,Vec2(xpos,Director::getInstance()->getWinSize().height-60));
		CCCallFuncN *func = CCCallFuncN::create(this,SEL_CallFuncN(&EnemySprite::onBossShowUp));
		Sequence * se = Sequence::create(to, func, NULL);
		runAction(se);
	}
	return true;
}
void EnemySprite::FinishedTravelCallBack(Node * n){

//	removeFromParent();
	layer->arrEnemy->removeObject(this);
	removeFromParent();
}

EnemySprite * EnemySprite::create(EnemyLayer *layer,int degree) {
	
	EnemySprite * spr = new EnemySprite;
	spr->layer =layer;
		if (spr &&spr->init(degree)) {
			spr->autorelease();
		}
	return   spr;
}
void EnemySprite::onBossShowUp(Node *n) {
	CCLOG("plane ::  onBossShowUp");
	Animation *a=AnimationCache::getInstance()->getAnimation("enemy3Attack");
	Animate  *ani = Animate::create(a);
	runAction(ani);
}