#include "TileTest.h"


bool TileTest::init() {
	Layer::init();

	TMXTiledMap* map=TMXTiledMap::create("Round1.tmx");
	map->setAnchorPoint(Vec2(0, 0));
	map->setPosition(Vec2(0, 0));
	TMXLayer *layer=map->getLayer("layer_0");
	addChild(map);
	Sprite * sor=layer->tileAt(Vec2(3,3));
	
	JumpBy * to = JumpBy::create(2, Vec2(20, 20), 20, 55);
	sor->runAction(to);
	return true;
}
	