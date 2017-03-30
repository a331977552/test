#include "Hero.h"

Hero* Hero::hero = NULL;
Hero::Hero() {

}
bool Hero::init()
{
	Sprite::initWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero1.png"));
	setPosition(Director::getInstance()->getWinSize().width / 2, 50);
	Blink * b = Blink::create(2, 3);
	Animation * ani=Animation::create();
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero1.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero2.png"));	
	ani->setDelayPerUnit(0.3);
	ani->setLoops(-1);

	Sequence * sequ = Sequence::create(b, Animate::create(ani),NULL);
	runAction(sequ);
	
	return true;
}

Hero*  Hero::getInstance() {
	if (hero == NULL) {
		hero = new Hero;
		hero->init();
	}
	return hero;
}

void Hero::blowup() {
	Animation * ani=Animation::create();
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero_blowup_n1.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero_blowup_n2.png"));	
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero_blowup_n3.png"));	
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero_blowup_n4.png"));	
	ani->setDelayPerUnit(0.3);
	ani->setLoops(1);
	CCCallFunc * fun = CCCallFunc::create(this, SEL_CallFunc(&Hero::destory));
	Sequence * sequ = Sequence::create(Animate::create(ani),fun ,NULL);
	runAction(sequ);
}
void Hero::destory() {
	removeFromParent();
}