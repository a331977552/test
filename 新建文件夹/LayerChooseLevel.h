#pragma once
#include "Common.h"
class LayerChooseLevel :public Layer
{
public:
	int _level;
	bool init();
	CREATE_FUNC(LayerChooseLevel);
	void onSelectedLevel(Ref * f);
	void onStartGame(Ref * f);
};

