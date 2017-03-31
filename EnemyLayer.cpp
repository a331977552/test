#include "EnemyLayer.h"
#include "EnemySprite.h"


bool EnemyLayer::init() {
	Layer::init();
	arrEnemy = Array::create();
	arrEnemy->retain();
	schedule(SEL_SCHEDULE(&EnemyLayer::generateNormalEnemy), 1);
	schedule(SEL_SCHEDULE(&EnemyLayer::generateAdvancedEnemy), 3);
	schedule(SEL_SCHEDULE(&EnemyLayer::generateBossEnemy), 6);
	return true;
}
void EnemyLayer::destoryEnemy(Node * n) {
	n->removeFromParent();
}
void EnemyLayer::blowup(Sprite  * ss) {
	EnemySprite * s =(EnemySprite *) ss;
	
	if (s->life > 0)
		return;
	Animation  *ani = NULL;
	int degree = s->getdegree();
	if (degree == 0) {
		ani= AnimationCache::getInstance()->getAnimation("enemy1blowup");
	}
	else if (degree == 1) {
		ani= AnimationCache::getInstance()->getAnimation("enemy2blowup");
	}
	else {
		ani= AnimationCache::getInstance()->getAnimation("enemy3blowup");
		hasBoss = false;
	}
	Animate * animate= Animate::create(ani);
	CCCallFuncN * func = CCCallFuncN::create(s, SEL_CallFuncN(&EnemyLayer::destoryEnemy));
	Sequence * se = Sequence::create(animate,func,NULL);
	s->runAction(se);
}

void EnemyLayer::generateNormalEnemy(float de) {

	EnemySprite * spr = EnemySprite::create(this, 0);
	arrEnemy->addObject(spr);
	addChild(spr);
}

void EnemyLayer::generateAdvancedEnemy(float de)
{
	EnemySprite * spr = EnemySprite::create(this, 1);
	arrEnemy->addObject(spr);
	addChild(spr);
}

void EnemyLayer::generateBossEnemy(float de) {
	if (hasBoss)
		return;
	EnemySprite * spr = EnemySprite::create(this, 2);
	arrEnemy->addObject(spr);
	addChild(spr);
}

void EnemyLayer::FinishedTravelCallBack(Node * n) {

}
