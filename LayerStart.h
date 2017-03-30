#pragma once
#include "cocos2d.h"
USING_NS_CC;
class LayerStart :public Layer
{
public:
	CREATE_FUNC(LayerStart);
	bool init();
	static Scene * createScene();
	void startGameCallBack(Ref *f);
	void quitGameCallBack(Ref *f);
	void onStartGameCallBack();

};

