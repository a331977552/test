#pragma once
#include "Common.h"
class LayerMain :public Layer
{
public:
	TMXTiledMap*  map;
	bool init(int level);
	static LayerMain * create(int level);
	void initMap(int level);
	void addFriendTank();
	
};

