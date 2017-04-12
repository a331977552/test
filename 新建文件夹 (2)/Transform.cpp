#include "Transform.h"


void Transform::setTranslate(int x, int y, int z) {
	translate.x = x;
	translate.y = y;
	translate.z = z;
}
	void Transform::setScale(int x, int y, int z) {
		scale.x = x;
		scale.y = y;
		scale.z = z;
}
	void Transform::setRotation(int x, int y, int z) {
		rotation.x = x;
		rotation.y = y;
		rotation.z = z;
}
	Transform::Transform() :Node(){

	}

 Transform::~Transform() {

}

