#include "LayerStart.h"
#include "LayerChooseLevel.h"

bool LayerStart::init() {
	Layer::init();
	setAnchorPoint(Point(0,0));
	SpriteFrame * frame=SpriteFrame::create("ScenceStart.png",Rect(0,0,600,400));
	
	Sprite * logo=Sprite::createWithSpriteFrame(frame);
	logo->setPosition(winSize.width / 2, winSize.height / 2+25);
	logo->setScale(0.5f);
	addChild(logo);
	
	Menu * menu = Menu::createWithItem(MenuItemImage::create("playgameNormal.png", "playgameClose.png",this, SEL_MenuHandler(&LayerStart::startCallBack)));
	menu->setPosition(winSize.width / 2, (winSize.height / 2) -25);
	addChild(menu);
	return true;
}
void LayerStart::startCallBack(Ref * f) {
	Director::getInstance()->replaceScene(	TransitionCrossFade::create(1,Common::createScene(LayerChooseLevel::create())));

}
