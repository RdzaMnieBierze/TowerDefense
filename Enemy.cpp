#include "Headers.h"

Enemy::Enemy() {
	shape.setSize(ENEMY_SIZE);
	shape.setOrigin(shape.getSize().x / 2.f, shape.getSize().y / 2.f);
	//shape.setTexture();
	shape.setPosition(START_POSITION);

	Speed = ENEMY_SPEED;
	Damage = ENEMY_DMG;
	Health = ENEMY_HEALTH;

	ValueForKill = 50;

	HPtext.setCharacterSize(12);
	HPtext.setFont(ResourceManager::get().font);
	HPtext.setString("HP: " + std::to_string((int)Health));
	HPtext.setFillColor(sf::Color::Black);
	sf::FloatRect textRect = HPtext.getLocalBounds();
	HPtext.setOrigin(textRect.width / 2.f, textRect.height / 2.f);
	HPtext.setPosition(shape.getPosition().x, shape.getPosition().y - shape.getSize().y / 2.f);
}



void Enemy::Update(float Timer, float& BaseHealth) {
	if (currentTarget < WayPoints.size()) {
		sf::Vector2f position = shape.getPosition();
		sf::Vector2f target = WayPoints[currentTarget];

		sf::Vector2f direction = target - position;
		float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

		if (distance < 5.f) {
			currentTarget++;
		}
		else {
			direction /= distance;
			shape.move(direction * Speed * Timer);
		}
	}
	else {
		attackTimer += Timer;
		if (attackTimer >= attackCooldown) {
			Attack(BaseHealth);
			attackTimer = 0.f;
		}
	}

	HPtext.setString("HP: " + std::to_string((int)Health));
	HPtext.setPosition(shape.getPosition().x, shape.getPosition().y - shape.getSize().y / 2.f);

	if (Health <= 0) {
		alive = false;
	}
}

void Enemy::Attack(float &Base) {
	Base -= Damage;
}
