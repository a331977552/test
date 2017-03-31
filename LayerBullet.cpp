#include "LayerBullet.h"
#include "Hero.h"


bool LayerBullet::init() {
	Layer::init();
	//batchNode = SpriteBatchNode::create("shoot/bullet1.png");
	
	arrBullets = Array::create();
	arrBullets->retain();
	schedule(SEL_SCHEDULE(&LayerBullet::addBullet), 0.3);
	return true;
}
void LayerBullet::addBullet(float de) {
	Vec2 v= Hero::getInstance()->getPosition();
	int type=getbulletType();
	Sprite *spr=Sprite::createWithSpriteFrameName(type==0?"bullet1.png":"bullet2.png");
	v.y += Hero::getInstance()->getContentSize().height/2+2;
	spr->setPosition(v);
	if (arrBullets == NULL) {
		CCLOG("KONGLA!!!!!!!!! ");
	}
	arrBullets->addObject(spr);
	addChild(spr);
	float distance=Director::getInstance()->getWinSize().height - v.y;
	float time=distance/ 150;
	MoveTo* move = MoveTo::create(time,Vec2(v.x,Director::getInstance()->getWinSize().height));
	CCCallFuncN *func = CCCallFuncN::create(spr,SEL_CallFuncN(&LayerBullet::bulletFinishedTravelCallBack));
	Sequence * se = Sequence::create(move, func, NULL);
	spr->runAction(se);
}

void LayerBullet::bulletFinishedTravelCallBack(Node * n) {
	if (n != NULL) {
		n->removeFromParent();
	}
}
void LayerBullet::removeBulletIfNecessay() {

}