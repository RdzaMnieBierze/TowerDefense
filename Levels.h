#pragma once

const int LEVEL_MONEY_BONUS = 500;

class Levels
{
public:
	int Level = 0;
	std::queue<std::function<std::unique_ptr<Enemy>()>> enemiesToSpawn;
	float spawnTimer = 0.f;
	float levelTimer = 0.f;
	bool isStarted = false;
	bool GameStarted = false;
	bool Ready = false;

	int Money = 1000;


	void Level_1(std::vector<std::unique_ptr<Enemy>>& Enemies, float Timer);
	void Level_2(std::vector<std::unique_ptr<Enemy>>& Enemies, float Timer);
	void Level_3(std::vector<std::unique_ptr<Enemy>>& Enemies, float Timer);

	void LevelEnd(std::vector<std::unique_ptr<Enemy>>& Enemies);
};

