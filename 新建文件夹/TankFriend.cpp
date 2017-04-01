#include "TankFriend.h"



bool TankFriend::init() {
	SpriteFrame * frame=SpriteFrame::create("tank/player2/player2U.png",Rect(0,0,60,60));
	Sprite::initWithSpriteFrame(frame);
	return true;
}
