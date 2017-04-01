#pragma once
#include "Common.h"
class LayerStart :public Layer
{
public:
	bool init();
	CREATE_FUNC(LayerStart);
	void startCallBack(Ref * f);

};

