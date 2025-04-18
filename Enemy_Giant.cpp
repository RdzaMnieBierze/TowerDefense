#include "Headers.h"

Enemy_Giant::Enemy_Giant() {
	Speed = ENEMY_SPEED * 0.35f;
	Damage = ENEMY_DMG / 2.f;
	Health = ENEMY_HEALTH * 3.f;

	ValueForKill = 100;

	shape.setSize(ENEMY_SIZE * 1.5f);
	shape.setOrigin(shape.getSize().x / 2.f, shape.getSize().y / 2.f);
	//shape.setTexture();
	shape.setPosition(START_POSITION);
}
