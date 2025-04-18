#include "Headers.h"

Tower::Tower(sf::Vector2f& Position) {
	shape.setSize(TOWER_SIZE);
	shape.setOrigin(shape.getSize().x / 2.f, shape.getSize().y / 2.f);
	//shape.setTexture();
	shape.setPosition(Position);
	this->Position = Position;
	attackCooldown = TOWER_COOLDOWN;
	Range = TOWER_RANGE;
	Damage = TOWER_DAMAGE;

	RangeCircle.setRadius(Range);
	RangeCircle.setFillColor(sf::Color::Transparent);
	RangeCircle.setOutlineColor(sf::Color::Red);
	RangeCircle.setOutlineThickness(2.f);
	RangeCircle.setOrigin(RangeCircle.getRadius(), RangeCircle.getRadius());
	RangeCircle.setPosition(Position);

	TextLevel.setCharacterSize(12);
	TextLevel.setFont(ResourceManager::get().font);
	TextLevel.setString("Level: " + std::to_string((int)Level));
	TextLevel.setFillColor(sf::Color::Black);
	sf::FloatRect textRect = TextLevel.getLocalBounds();
	TextLevel.setOrigin(textRect.width / 2.f, textRect.height / 2.f);
	TextLevel.setPosition(shape.getPosition().x, shape.getPosition().y + shape.getSize().y / 2.f);
}

void Tower::Update(float Timer, std::vector<std::unique_ptr<Enemy>>& Enemies, sf::RenderWindow& Game) {
	attackTimer += Timer;

	if (Target && (!Target->alive || !isInRange(Target->shape.getPosition()))) {
		Target = nullptr;
		drawLaser = false;
		laserActive = false;
	}

	if (!Target) {
		for (auto& enemy : Enemies) {
			if (enemy->alive && isInRange(enemy->shape.getPosition())) {
				Target = enemy.get();
				break;
			}
		}
	}

	if (Target && Target->alive && attackTimer >= attackCooldown) {
		Attack(*Target);
		attackTimer = 0.f;
	}

	if (drawLaser) {
		laserTimer -= Timer;
		if (laserTimer <= 0.f) {
			drawLaser = false;
			laserActive = false;
		}
	}

}

bool Tower::isInRange(const sf::Vector2f& enemy) {
	float dx = shape.getPosition().x - enemy.x;
	float dy = shape.getPosition().y - enemy.y;
	return (dx * dx + dy * dy <= Range * Range);
}

void Tower::Attack(Enemy& enemy) {
	if (!enemy.alive) return;
	enemy.Health -= Damage;
	ResourceManager::get().LaserSound.play();

	if (enemy.Health <= 0) {
		enemy.alive = false;
		Target = nullptr;
		drawLaser = false;
		laserActive = false;
		return;
	}
	laserTargetPos = enemy.shape.getPosition();
	drawLaser = true;
	laserTimer = maxLaserTimer;
	laserActive = true;
}

void Tower::DrawLaser(sf::RenderWindow& Game) {
	if (laserActive) {
		sf::VertexArray laser(sf::LinesStrip, 2);
		laser[0].position = laserTargetPos;
		laser[0].color = sf::Color::Red;
		laser[1].position = Position;
		laser[1].color = sf::Color::Red;
		Game.draw(laser);
		sf::CircleShape dot(3.f);
		dot.setFillColor(sf::Color::Green);
		dot.setPosition(laserTargetPos);
		Game.draw(dot);
	}
}

void Tower::Upgrade() {
	attackCooldown *= 0.75f;
	Range *+ 1.2f;
	Damage *= 1.5f;
	isUpgraded = true;
	RangeCircle.setRadius(Range);
	Level++;
	TextLevel.setString("Level: " + std::to_string((int)Level));
}
