#pragma once
#include "Headers.h"
const sf::Vector2f TOWER_SIZE(50, 100);
//const float TOWER_RADIUS = 25.f;
const float TOWER_COOLDOWN = 1.5f;
const float TOWER_RANGE = 250.f;
const float TOWER_DAMAGE = 20.f;

const int TOWER_PRICE = 200;
const int TOWER_SLOWANDSTRONG_PRICE = 300;

const int TOWER_UPGRADE = 300;
const int TOWER_SLOWANDSTRONG_UPGRADE = 400;

const std::vector<sf::Vector2f> TOWER_POINTS = {
	{175, 144},
	{281, 480},
	{392, 156},
	{741, 143},
	{1064, 410}
};

class Tower
{
public:
	Tower(sf::Vector2f&);
	sf::RectangleShape shape;
	sf::CircleShape RangeCircle;
	sf::Text TextLevel;
	float attackCooldown;
	float attackTimer = 0.f;
	float Range;
	float Damage;
	sf::Vector2f Position;
	sf::Vector2f laserTargetPos;
	bool laserActive = false;
	bool drawLaser = false;
	float laserTimer = 0.f;
	float maxLaserTimer = 0.3f;
	bool isUpgraded = false;
	int Level = 1;

	std::string Name = "Tower";

	Enemy* Target = nullptr;

	void Update(float Timer, std::vector<std::unique_ptr<Enemy>>& Enemies, sf::RenderWindow& Game);
	bool isInRange(const sf::Vector2f&);
	void Attack(Enemy&);
	void DrawLaser(sf::RenderWindow&);
	void Upgrade();
};