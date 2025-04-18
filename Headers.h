#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <iostream>
#include <cmath>

#include <queue>
#include <functional>

#include "Enemy.h"
#include "Enemy_fast.h"
#include "Enemy_Giant.h"

#include "Tower.h"
#include "Tower_SlowAndStrong.h"

#include "Levels.h"
#include "ResourceManager.h"

const float M_PI = 3.141592;


const float GAME_HEIGHT = 720;
const float GAME_WIDTH = 1280;


const std::vector<sf::Vector2f> WayPoints = {
	{59, 274},
	{114, 354},
	{112, 482},
	{159, 541},
	{399, 541},
	{447, 493},
	{447, 338},
	{302, 193},
	{302, 120},
	{373, 48},
	{809, 48},
	{977, 216},
	{977, 431},
	{1031, 480},
	{1120, 480},
	{1169, 527},
	{1169, 588}
};

const sf::Vector2f START_POSITION(59, 0);
const sf::Vector2f BASE_POSITION(1169, 588);

const float BASE_HEALTH = 1000.f;

const float spawnCooldown = 1.5f;

enum class Scene {Menu = 0, Game, Win, Loss, Instruction};

std::pair<bool, sf::Vector2f> validBuildZone(const sf::Vector2f&, std::vector<Tower>&);
std::string resourcesDir();