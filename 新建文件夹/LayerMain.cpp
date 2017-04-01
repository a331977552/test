#include "LayerMain.h"
#include "TankFriend.h"


bool LayerMain::init(int level) {
	Layer::init();
	initMap(level);
	addFriendTank();
	
	return true;
}
void LayerMain::addFriendTank() {
	TankFriend * tank=TankFriend::create();
	tank->setScale(map->getTileSize().width*2 / tank->getContentSize().width);
	map->addChild(tank);
	tank->setPosition(Common::tile2Local(map, Vec2(10, 25)));
}
void LayerMain::initMap(int level) {
	char * le=Common::getRound("Round", "tmx", level);
	map= TMXTiledMap::create(le);
	addChild(map);
	delete[] le;
}
LayerMain * LayerMain::create(int level) {

	LayerMain *main = new LayerMain;
	if (main&&main->init(level)) {
		main->autorelease();
	}
	return main;
 }
	