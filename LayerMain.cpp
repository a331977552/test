#include "LayerMain.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"
#include "EnemySprite.h"
USING_NS_CC;
using namespace  CocosDenshion;
#define winSize  Director::getInstance()->getWinSize() 

Scene * LayerMain::createScene() {
	Scene * s = Scene::create();
	s->addChild(LayerMain::create());
	return s;
 }
bool LayerMain::init() {
	
	Layer::init();
	addBackground();
	addHero();
	startShoot();
	addEnemy();
	scheduleUpdate();
	return true;
}
void LayerMain::addBackground(){
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/game_music.wav");
	back = LayerBackground::create();
	addChild(back);
	schedule(SEL_SCHEDULE(&LayerMain::moveBackgroud),0.03);
}
void LayerMain::moveBackgroud(float dt) {
	back->updateBackgroud(dt);
}


void LayerMain::addHero(){

   Hero *hero=	Hero::getInstance();
   addChild(hero);
   setTouchEnabled(true);
   setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
}
void LayerMain::addEnemy(){
	  enemyLayer= EnemyLayer::create();
	addChild(enemyLayer);
}
void LayerMain::addFood(){

}
void LayerMain::pauseCallBack(Ref *f){

}
void LayerMain::resumeCallBack(Ref *f){

}
void LayerMain::update(float dt){
	Array * bullets=bulletLayer->arrBullets;
	Array  *tempbullets=Array::create();
	Array  *tempEnemy=Array::create();
	for (int i = 0; i < bullets->count(); i++) {
	   Sprite * spr=dynamic_cast< Sprite *>	(bullets->getObjectAtIndex(i));	
	   if (spr->getPosition().y >= winSize.height) {
		   tempbullets->addObject(spr);
	   }
	}
	

	bullets->removeObjectsInArray(tempbullets);
	tempbullets->removeAllObjects();

	//CCLOG("bullets'Count is  %d", bullets->count());
	Array *enemies=enemyLayer->arrEnemy;
	//CCLOG("enemies'Count is  %d", enemies->count());
	for (int i = 0; i < bullets->count(); i++) {
	   Sprite * bullet=dynamic_cast< Sprite *>	(bullets->getObjectAtIndex(i));	
	 
	 for (int j = 0; j < enemies->count(); j++) {
		  Sprite * enemy=dynamic_cast< Sprite *>	(enemies->getObjectAtIndex(j));	
		  if (enemy->getBoundingBox().containsPoint(bullet->getPosition())) {
			  tempbullets->addObject(bullet);
			  EnemySprite * en =( EnemySprite *) enemy;
			  en->life--;
			  if (en->life <= 0) {
			  tempEnemy->addObject(enemy);
			  enemyLayer->blowup(enemy);
			  }
		  }
	   }
	}
	 for (int j = 0; j < enemies->count(); j++) {
		  Sprite * enemy=dynamic_cast< Sprite *>	(enemies->getObjectAtIndex(j));	
		  if (enemy->getBoundingBox().containsPoint(Hero::getInstance()->getPosition())) {
			  Hero::getInstance()->removeFromParent();		
			  EnemySprite * en =( EnemySprite *) enemy;
			  en->life--;
			  if (en->life <= 0) {
			  tempEnemy->addObject(enemy);
			  enemyLayer->blowup(enemy);
		  }
	   }
	}
	
	for (int j = 0; j < tempbullets->count(); j++) {
		Sprite * d=(Sprite *)tempbullets->getObjectAtIndex(j);
		d->removeFromParent();
	}
	enemies->removeObjectsInArray(tempEnemy);
	bullets->removeObjectsInArray(tempbullets);


}
bool LayerMain::onTouchBegan(Touch *touch, Event *unused_event){
	Rect rec= Hero::getInstance()->getBoundingBox();
	rec.setRect(rec.origin.x -= 20, rec.origin.y -= 20,rec.size.width+=20,rec.size.height+=20);
	if (rec.containsPoint(touch->getLocation())) {

		return true;
	}
	return true;
}
void LayerMain::onTouchMoved(Touch *touch, Event *unused_event){
	Vec2  v=Hero::getInstance()->getPosition() + touch->getDelta();
	v.x < 0 ? v.x = 0:v.x=v.x;
	v.y < 0 ? v.y = 0:v.y=v.y;
	v.x > winSize.width ? v.x =  winSize.width: v.x=v.x;
	v.y > winSize.height? v.y =  winSize.height:v.y =v.y ;
	Hero::getInstance()->setPosition(v);
}
void LayerMain::removeHero(){

}
void LayerMain::startShoot(){
	bulletLayer=	LayerBullet::create();
 addChild(bulletLayer);

}

