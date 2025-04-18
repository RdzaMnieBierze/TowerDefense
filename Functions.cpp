#include "Headers.h"

std::pair<bool, sf::Vector2f> validBuildZone(const sf::Vector2f& position, std::vector<Tower>& Towers) {
	for (auto e : TOWER_POINTS) {
		if (position.x >= e.x - 5.f && position.x <= e.x + 5.f &&
			position.y >= e.y - 5.f && position.y <= e.y + 5.f) {
			std::pair<bool, sf::Vector2f> result(true, e);
			for (auto tower : Towers) {
				if (e == tower.Position) {
					result.first = false;
					result.second = e;
					break;
				}
			}
			return result;
		}			
	}
	
	std::pair<bool, sf::Vector2f> result(false, sf::Vector2f (0.f, 0.f));
	return result;
}

std::string resourcesDir() {
	return "resources/";
}

