#pragma once
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
//USING_NS_CC_EXT;
#define winSize Director::getInstance()->getWinSize()
class Common {

public :
	
	static Scene *createScene(Layer *layer) {

		Scene * s = Scene::create();
		s->addChild(layer);
		return s;
	}
static	char* getRound(char * prefix,char *suffix,int level) {
	char* buf= new char [50];
	memset(buf, 0, sizeof(buf));
	sprintf(buf, "%s%d.%s", prefix,level, suffix);
	return buf;
}
static Vec2& tile2Local(TMXTiledMap *map,Vec2 &v) {
	Size s=map->getTileSize();
	int x= s.width*v.x;
	Size mapSize=map->getMapSize();
	int y = mapSize.height*s.height - s.height*v.y;
	v.x = x;
	v.y = y;
	return v;
}

};