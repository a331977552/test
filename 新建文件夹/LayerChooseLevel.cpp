#include "LayerChooseLevel.h"
#include "LayerMain.h"

bool LayerChooseLevel::init() {
	Layer::init();
	_level = 1;
	Vector<MenuItem*>  v;
	for (int i = 0; i < 20; i++) {
		char * buf=	Common::getRound("Round", "", i + 1);
		MenuItem * item = MenuItemFont::create(buf);
		delete []buf;
		v.pushBack(item);
	}
	MenuItemToggle *  toggle=MenuItemToggle::createWithTarget(this, SEL_MenuHandler(&LayerChooseLevel::onSelectedLevel),v);
	MenuItem * item = MenuItemFont::create("startGame", this,SEL_MenuHandler(&LayerChooseLevel::onStartGame));
	Menu *men = Menu::create(toggle, item, NULL);
	addChild(men);
	men->alignItemsVerticallyWithPadding(8);

	return true;	
}

void LayerChooseLevel::onSelectedLevel(Ref * f) {
	MenuItemToggle  * toggle = dynamic_cast<MenuItemToggle  *>(f);
	_level= toggle->getSelectedIndex();
}
void LayerChooseLevel::onStartGame(Ref * f) {

	Director::getInstance()->replaceScene(TransitionFlipX::create(1, Common::createScene(LayerMain::create(_level))));


}