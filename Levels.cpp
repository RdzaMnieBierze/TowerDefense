#include "Headers.h"


void Levels::LevelEnd(std::vector<std::unique_ptr<Enemy>>& Enemies) {
	if (Enemies.empty() && isStarted) {

		levelTimer = 0.f;
		spawnTimer = 0.f;
		Level++;
		Ready = false;
		isStarted = false;
		Money += LEVEL_MONEY_BONUS;
		std::cout << "Koniec	level: " << Level << std::endl;
	}
}

void Levels::Level_1(std::vector<std::unique_ptr<Enemy>>& Enemies, float Timer) {
	if (!isStarted) {
		enemiesToSpawn.push([]() { return std::make_unique<Enemy_Giant>(); });
		enemiesToSpawn.push([]() { return std::make_unique<Enemy>(); });
		enemiesToSpawn.push([]() { return std::make_unique<Enemy_fast>(); });
		enemiesToSpawn.push([]() { return std::make_unique<Enemy>(); });
	}
	isStarted = true;
	spawnTimer += Timer;
	levelTimer += Timer;
	if (!enemiesToSpawn.empty() && spawnCooldown <= spawnTimer) {
		Enemies.push_back(enemiesToSpawn.front()());
		enemiesToSpawn.pop();
		spawnTimer = 0.f;
	}

	if (enemiesToSpawn.empty() && levelTimer > 10.f) {
		LevelEnd(Enemies);
	}
}

void Levels::Level_2(std::vector<std::unique_ptr<Enemy>>& Enemies, float Timer) {
	if (!isStarted) {
		enemiesToSpawn.push([]() { return std::make_unique<Enemy_Giant>(); });
		enemiesToSpawn.push([]() { return std::make_unique<Enemy>(); });
		enemiesToSpawn.push([]() { return std::make_unique<Enemy_fast>(); });
		enemiesToSpawn.push([]() { return std::make_unique<Enemy_fast>(); });
		enemiesToSpawn.push([]() { return std::make_unique<Enemy_fast>(); });
		enemiesToSpawn.push([]() { return std::make_unique<Enemy>(); });
	}
	isStarted = true;
	spawnTimer += Timer;
	levelTimer += Timer;
	if (!enemiesToSpawn.empty() && spawnCooldown <= spawnTimer) {
		Enemies.push_back(enemiesToSpawn.front()());
		enemiesToSpawn.pop();
		spawnTimer = 0.f;
	}

	if (enemiesToSpawn.empty() && levelTimer > 10.f) {
		LevelEnd(Enemies);
	}
}

void Levels::Level_3(std::vector<std::unique_ptr<Enemy>>& Enemies, float Timer) {
	if (!isStarted) {
		enemiesToSpawn.push([]() { return std::make_unique<Enemy_Giant>(); });
		enemiesToSpawn.push([]() { return std::make_unique<Enemy>(); });
		enemiesToSpawn.push([]() { return std::make_unique<Enemy_fast>(); });
		enemiesToSpawn.push([]() { return std::make_unique<Enemy_fast>(); });
		enemiesToSpawn.push([]() { return std::make_unique<Enemy_fast>(); });
		enemiesToSpawn.push([]() { return std::make_unique<Enemy>(); });
		enemiesToSpawn.push([]() { return std::make_unique<Enemy_Giant>(); });
		enemiesToSpawn.push([]() { return std::make_unique<Enemy_Giant>(); });
	}
	isStarted = true;
	spawnTimer += Timer;
	levelTimer += Timer;
	if (!enemiesToSpawn.empty() && spawnCooldown <= spawnTimer) {
		Enemies.push_back(enemiesToSpawn.front()());
		enemiesToSpawn.pop();
		spawnTimer = 0.f;
	}

	if (enemiesToSpawn.empty() && levelTimer > 10.f) {
		LevelEnd(Enemies);
	}
}