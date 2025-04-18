#pragma once
#include "Headers.h"

const sf::Vector2f ENEMY_SIZE(40, 60);
const float ENEMY_SPEED = 80.f;
const float ENEMY_DMG = 50.f;
const float ENEMY_HEALTH = 100.f;


class Enemy {
public:
	Enemy();
	virtual ~Enemy() = default;
	sf::RectangleShape shape;
	float Speed;
	float Damage;
	float Health;
	float attackCooldown = 2.f;
	float attackTimer = 0.f;
	int currentTarget = 0;
	bool alive = true;

	int ValueForKill;

	sf::Text HPtext;

	void Update(float, float&);
	void Attack(float&);

};