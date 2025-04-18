#include "Headers.h"

Tower_SlowAndStrong::Tower_SlowAndStrong(sf::Vector2f& Position) : Tower(Position){
	shape.setSize(TOWER_SIZE);
	shape.setOrigin(shape.getSize().x / 2.f, shape.getSize().y / 2.f);
	//shape.setTexture();
	shape.setFillColor(sf::Color::Blue);
	shape.setPosition(Position);
	this->Position = Position;
	attackCooldown = TOWER_COOLDOWN * 2.f;
	Range = TOWER_RANGE * 0.6f;
	Damage = TOWER_DAMAGE * 3.f;

	RangeCircle.setRadius(this->Range);
	RangeCircle.setFillColor(sf::Color::Transparent);
	RangeCircle.setOutlineColor(sf::Color::Red);
	RangeCircle.setOutlineThickness(2.f);
	RangeCircle.setOrigin(RangeCircle.getRadius(), RangeCircle.getRadius());
	RangeCircle.setPosition(Position);
}