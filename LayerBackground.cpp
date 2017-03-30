#include "LayerBackground.h"



bool LayerBackground::init() {
	Layer::init();
	Size winSize= Director::getInstance()->getWinSize();
	SpriteFrame  *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("background.png");
	bg1=Sprite::createWithSpriteFrame(frame);
	bg1->setContentSize(winSize);
	bg1->setAnchorPoint(Size(0, 0));
	bg1->setPosition(0, 0);
	bg2=Sprite::createWithSpriteFrame(frame);
	bg2->setAnchorPoint(Size(0, 0));
	bg2->setContentSize(winSize);
	bg2->setPosition(0, winSize.height-2);
	addChild(bg1);
	addChild(bg2);
	return true;
}
void LayerBackground::updateBackgroud(float de)
{
	Size winSize= Director::getInstance()->getWinSize();
	Vec2 s=bg1->getPosition();
	s.y -= 5;
	bg1->setPosition(s);
	bg2->setPosition(0,s.y+winSize.height-2);
	if (bg2->getPosition().y <= 0) {
		bg1->setPosition(0, 0);
	}
}
