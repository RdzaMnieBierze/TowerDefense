#include "Headers.h"

Enemy_fast::Enemy_fast() {
	Speed = ENEMY_SPEED * 1.75f;
	Damage = ENEMY_DMG * 1.5f;
	Health = ENEMY_HEALTH / 3.f;

	ValueForKill = 30;

	shape.setSize(ENEMY_SIZE / 2.f);
	shape.setOrigin(shape.getSize().x / 2.f, shape.getSize().y / 2.f);
	//shape.setTexture();
	shape.setPosition(START_POSITION);
}