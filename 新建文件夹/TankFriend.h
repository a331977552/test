#pragma once
#include "Common.h"
class TankFriend :public Sprite
{
public:
	int _life;
	bool init();
	CREATE_FUNC(TankFriend);
	
};

