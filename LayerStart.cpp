#include "LayerStart.h"
#include "LayerMain.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
#define winSize  Director::getInstance()->getWinSize()
bool LayerStart::init() {
	Layer::init();
	MenuItem * item1 = MenuItemFont::create("start", CC_CALLBACK_1(LayerStart::startGameCallBack, this));
	MenuItem * item2 = MenuItemFont::create("quit", CC_CALLBACK_1(LayerStart::quitGameCallBack, this));
	Vector<MenuItem *> vector;
	vector.pushBack(item1);
	vector.pushBack(item2);
	Menu *menu = Menu::createWithArray(vector);
	menu->setTag(1000);
	menu->alignItemsVerticallyWithPadding(8);
	//Ìí¼Ó±³¾°
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("ui/shoot_background.plist");
	SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("background.png");
	Sprite * bg = Sprite::createWithSpriteFrame(frame);
	bg->setIgnoreAnchorPointForPosition(true);
	bg->setContentSize(winSize);
	addChild(bg);
	addChild(menu);
	Sprite * copyright = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("shoot_copyright.png"));
	copyright->setPosition(winSize.width / 2, winSize.height / 2 + 100);
	addChild(copyright);
	return true;
}
Scene * LayerStart::createScene() {
	Scene * scen = Scene::create();
	scen->addChild(LayerStart::create());
	return scen;
}

void LayerStart::startGameCallBack(Ref *f) {
	Node *n = getChildByTag(1000);
	n->setVisible(false);
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("sound/game_music.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("sound/achievement.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("sound/big_spaceship_flying.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("sound/bullet.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("sound/button.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("sound/enemy1_down.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("sound/enemy2_down.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("sound/enemy3_down.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("sound/game_over.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("sound/get_bomb.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("sound/get_double_laser.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("sound/out_porp.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("sound/use_bomb.wav");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("ui/shoot.plist");
	Animation *ani = Animation::create();
	SpriteFrame  * frame = SpriteFrameCache::getInstance()
		->getSpriteFrameByName("game_loading1.png");
	Sprite *load = Sprite::createWithSpriteFrame(frame);
	load->setPosition(winSize.width / 2, winSize.height / 2);
	SpriteFrame  * frame2 = SpriteFrameCache::getInstance()
		->getSpriteFrameByName("game_loading2.png");
	SpriteFrame  * frame3 = SpriteFrameCache::getInstance()
		->getSpriteFrameByName("game_loading3.png");
	ani->addSpriteFrame(frame);
	ani->addSpriteFrame(frame2);
	ani->addSpriteFrame(frame3);
	ani->setDelayPerUnit(0.3);
	ani->setLoops(2);
	Animation * enemy1blowup = Animation::create();
	enemy1blowup->setDelayPerUnit(0.2);
	enemy1blowup->setLoops(1);

	Animation * enemy2blowup = Animation::create();
	enemy2blowup->setDelayPerUnit(0.2);
	enemy2blowup->setLoops(1);

	Animation * enemy3blowup = Animation::create();
	enemy3blowup->setDelayPerUnit(0.2);
	enemy3blowup->setLoops(1);

	char buf[100];
	for (int i = 0; i < 4; i++) {
		memset(buf, 0, sizeof(buf));
		sprintf(buf, "enemy1_down%d.png", i + 1);
		SpriteFrame * frame1 = SpriteFrameCache::getInstance()->getSpriteFrameByName(buf);
		enemy1blowup->addSpriteFrame(frame1);
		memset(buf, 0, sizeof(buf));
		sprintf(buf, "enemy2_down%d.png", i + 1);
		SpriteFrame * frame2 = SpriteFrameCache::getInstance()->getSpriteFrameByName(buf);
		enemy2blowup->addSpriteFrame(frame2);

	}
	for (int i = 0; i < 6; i++) {
		memset(buf, 0, sizeof(buf));
		sprintf(buf, "enemy3_down%d.png", i + 1);
		SpriteFrame * frame1 = SpriteFrameCache::getInstance()->getSpriteFrameByName(buf);
		enemy3blowup->addSpriteFrame(frame1);
	}



	Animation * enemy3Attack = Animation::create();
	enemy3Attack->setDelayPerUnit(0.2);
	enemy3Attack->setLoops(-1);
	enemy3Attack->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy3_n1.png"));
	enemy3Attack->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy3_n2.png"));
	enemy3Attack->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy3_hit.png"));
	AnimationCache::getInstance()->addAnimation(enemy1blowup, "enemy1blowup");
	AnimationCache::getInstance()->addAnimation(enemy2blowup, "enemy2blowup");
	AnimationCache::getInstance()->addAnimation(enemy3blowup, "enemy3blowup");
	AnimationCache::getInstance()->addAnimation(enemy3Attack, "enemy3Attack");

	Animate *animate = Animate::create(ani);
	CCCallFunc*  func = CCCallFunc::create(this, SEL_CallFunc(&LayerStart::onStartGameCallBack));
	Vector<FiniteTimeAction*>  vector;
	vector.pushBack(animate);
	vector.pushBack(func);
	Sequence * s = Sequence::create(vector);
	addChild(load);
	load->runAction(s);
}
void LayerStart::quitGameCallBack(Ref *f) {
	exit(0);
}
void LayerStart::onStartGameCallBack() {
	Director::getInstance()->replaceScene(TransitionJumpZoom::create(1, LayerMain::createScene()));
}
